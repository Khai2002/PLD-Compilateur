#include "IRVisitor.h"

using namespace std;

antlrcpp::Any IRVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    // Naive function to interate through all functions listed
    for (auto func_ctx : ctx->func_decl())
    {
        // Only execute main
        if (func_ctx->ID()->getText() != "main")
            continue;
        visit(func_ctx);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    // cout << "visiting function declarations..." << endl;

    CFG *cfg = new CFG(ctx->ID()->getText());
    currentCFG = cfg;
    cfgs.push_back(cfg);

    for (auto line : ctx->line())
    {
        visit(line);
    }

    if (ctx->return_stmt())
    {
        visit(ctx->return_stmt());
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitLine(ifccParser::LineContext *ctx)
{
    cout << "visiting lines..." << endl;
    if (ctx->stmt())
    {
        visit(ctx->stmt());
    }
    else if (ctx->if_block())
    {
        visit(ctx->if_block());
    }
    else if (ctx->while_block())
    {
        visit(ctx->while_block());
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    // cout << "visiting variable declarations..." << endl;
    // var_decl : type ID (',' ID)* ';' ;

    string typeName = ctx->type()->getText();
    string name;

    for (auto var : ctx->ID()){
        name = var->getText();
        // string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
        if (typeName == "int")
        {
            currentCFG->add_to_symbol_table(name, Type::TypeEnum::INT);
        }
        else if (typeName == "char")
        {
            currentCFG->add_to_symbol_table(name, Type::TypeEnum::CHAR);
        }
    }
    
    
    // Remove expression assignment
    /*
    if (ctx->expr())
    {
        string expr = visit(ctx->expr());
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {name, expr});
    }
    */

    return 0;
}

antlrcpp::Any IRVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    // cout << "visiting add sub expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->ADD_SUB()->getText();
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    if (op == "+")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::add, Type::TypeEnum::INT, params);
    }
    else if (op == "-")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::sub, Type::TypeEnum::INT, params);
    }

    return tempvar;
}

antlrcpp::Any IRVisitor::visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx)
{
    // cout << "visiting mult div mod expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->MULT_DIV_MOD()->getText();

    string param2 = visit(left);
    string param3 = visit(right);
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;

    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    if (op == "*")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::mul, Type::TypeEnum::INT, params);
    }
    else if (op == "/")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::div, Type::TypeEnum::INT, params);
    }
    else if (op == "%")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::mod, Type::TypeEnum::INT, params);
    }

    return tempvar;
}

antlrcpp::Any IRVisitor::visitVar_ass(ifccParser::Var_assContext *ctx)
{
    // cout << "visiting variable assignments..." << endl;

    string name = ctx->ID()->getText();

    if (ctx->expr())
    {
        string expr = visit(ctx->expr());
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {name, expr});
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    // cout << "visiting return statements..." << endl;
    auto expr = ctx->expr();
    string name = visit(expr);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ret, Type::TypeEnum::INT, {name});

    return 0;
}

antlrcpp::Any IRVisitor::visitVar(ifccParser::VarContext *ctx)
{
    string name = ctx->ID()->getText();
    int ind = currentCFG->getSymbolIndex()[name];
    // cout << "Var named " << name << " at " << ind << endl;

    return name;
}

antlrcpp::Any IRVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    string value = ctx->INT_CONST()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});

    // cout << "New Int Const with value [" << value << "] Decl as " << tempvar << endl;

    return tempvar;
}

antlrcpp::Any IRVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    int char_value = (int)ctx->CHAR_CONST()->getText()[1];
    string value = to_string(char_value);
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::CHAR);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::CHAR, {tempvar, value});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitIf_block(ifccParser::If_blockContext *ctx)
{
    //if_block : 'if' '(' expr ')' (line | block) else_block? ;
    cout << "Hello" << endl;
    auto testBB = currentCFG->current_bb;
    auto thenBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto elseBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto endifBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    currentCFG->add_bb(thenBB);
    currentCFG->add_bb(elseBB);
    currentCFG->add_bb(endifBB);

    // Adjust pointers
    endifBB->exit_true = testBB->exit_true;
    endifBB->exit_false = testBB->exit_false;
    testBB->exit_true = thenBB;
    testBB->exit_false = elseBB;
    thenBB->exit_true = endifBB;
    thenBB->exit_false = nullptr;
    elseBB->exit_true = endifBB;
    elseBB->exit_false = nullptr;

    // Generate IRIntr in blocks
    visit(ctx->expr());

    currentCFG->current_bb = thenBB;
    if(ctx->line()) {
        visit(ctx->line());
    }
    if(ctx->block()){
        visit(ctx->block());
    }


    currentCFG->current_bb = elseBB;
    if(ctx->else_block()){
        visit(ctx->else_block());
    }

    currentCFG->current_bb = endifBB;
    return 0;
}

antlrcpp::Any IRVisitor::visitElse_block(ifccParser::Else_blockContext *ctx)
{
    // else_block : 'else' (line | block) ;

    if(ctx->line()) {
        visit(ctx->line());
    }
    if(ctx->block()){
        visit(ctx->block());
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitWhile_block(ifccParser::While_blockContext *ctx)
{
    // while_block : 'while' '(' expr ')' (line | block);
    auto testBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto bodyBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    currentCFG->add_bb(testBB);
    currentCFG->add_bb(bodyBB);

    testBB->exit_false = currentCFG->current_bb->exit_true;
    testBB->exit_true = bodyBB;
    currentCFG->current_bb->exit_true = testBB;
    currentCFG->current_bb->exit_false = nullptr;
    bodyBB->exit_true = testBB;
    bodyBB->exit_false = nullptr;


    visit(ctx->expr());

    currentCFG->current_bb = bodyBB;
    if(ctx->line()) {
        visit(ctx->line());
    }
    if(ctx->block()){
        visit(ctx->block());
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitBlock(ifccParser::BlockContext *ctx)  {
    // block : '{' line* '}' ;
    for(auto line : ctx->line()){
        visit(line);
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitStmt(ifccParser::StmtContext *ctx)  {
    // stmt : var_decl | var_ass | return_stmt ;
    if(ctx->var_decl()){
        visit(ctx->var_decl());
    } else if (ctx->var_ass()){
        visit(ctx->var_ass());
    } else if (ctx->return_stmt()){
        visit(ctx->return_stmt());
    }
    return 0;
}

// antlrcpp::Any IRVisitor::visitAndExpr(ifccParser::AndExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitEqualExpr(ifccParser::EqualExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitUnaire(ifccParser::UnaireContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitXorExpr(ifccParser::XorExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitParExpr(ifccParser::ParExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitOrExpr(ifccParser::OrExprContext *ctx)  {
//     return 0;
// }

// antlrcpp::Any IRVisitor::visitType(ifccParser::TypeContext *ctx)  {
//     return 0;
// }
