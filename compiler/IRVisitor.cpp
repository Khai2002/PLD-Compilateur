#include "IRVisitor.h"

using namespace std;

antlrcpp::Any IRVisitor::visitProg(ifccParser::ProgContext *ctx)
{

    // Naive function to interate through all functions listed
    for (auto func_ctx : ctx->func_decl())
    {
        // Only execute main
        visit(func_ctx);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{

    cout << "#visiting function declarations..." << endl;

    CFG *cfg = new CFG(ctx->ID(0)->getText());
    currentCFG = cfg;
    cfgs.push_back(cfg);
    if (ctx->type(0)->getText() == "int" || ctx->type(0)->getText() == "char")
    {
        functionTypesMap[ctx->ID(0)->getText()] = "int";
    }
    else
    {
        functionTypesMap[ctx->ID(0)->getText()] = "void";
    }
    int i = 1;
    while (ctx->ID(i) != nullptr)
    {
        string typeName = ctx->type(i)->getText();
        string name = ctx->ID(i)->getText();
        if (typeName == "int")
        {
            currentCFG->add_to_symbol_table(name, Type::TypeEnum::INT);
        }
        else if (typeName == "char")
        {
            currentCFG->add_to_symbol_table(name, Type::TypeEnum::CHAR);
        }

        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::InsertParam, currentCFG->getSymbolType()[name], {name, to_string(i)});
        i++;
    }

    for (auto line : ctx->line())
    {
        visit(line);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitLine(ifccParser::LineContext *ctx)
{
    cout << "#visiting lines..." << endl;
    if (ctx->expr())
    {
        visit(ctx->expr());
    }
    else if (ctx->stmt())
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
    else
    {
        for (auto line : ctx->block()->line())
        {
            visit(line);
        }
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    // cout << "#visiting variable declarations..." << endl ;
    cout << "# visitVar_decl" << endl;

    for (auto Dec : ctx->declareAssign())
    {
        visit(Dec);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitDeclareAssign(ifccParser::DeclareAssignContext *ctx)
{
    // cout << "#visiting visitDeclareAssign..." << endl;
    string var_name = ctx->ID()->getText();
    currentCFG->add_to_symbol_table(var_name, Type::TypeEnum::INT);
    if (ctx->expr())
    {
        string expr = visit(ctx->expr());
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[var_name], {var_name, expr});
    }

    return 0;
}
/*
antlrcpp::Any IRVisitor::visitVar_decl_ass(ifccParser::Var_decl_assContext *ctx)
{
    cout << "#visiting variable declarations Assignements..." << endl;
    //  var_decl : type ID (',' ID)* ';' ;

    string typeName = ctx->type()->getText();

    string name = ctx->ID()->getText();
    if (typeName == "int")
    {
        currentCFG->add_to_symbol_table(name, Type::TypeEnum::INT);
    }
    else if (typeName == "char")
    {
        currentCFG->add_to_symbol_table(name, Type::TypeEnum::CHAR);
    }

    string tempvar;
    string expr = visit(ctx->expr());
    tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {name, expr});

    return 0;
} */

antlrcpp::Any IRVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    // cout << "#visiting add sub expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->ADD_SUB->getText();
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        int res;
        if (op == "+")
        {
            res = stoi(param2) + stoi(param3);
        }
        else if (op == "-")
        {
            res = stoi(param2) - stoi(param3);
        }
        return to_string(res);
    }

    if (param3 == "0")
    { // x+0 or x-0
        return param2;
    }

    if (param2 == "0" && op == "+")
    { // 0+x
        return param3;
    }

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
    // cout << "#visiting mult div mod expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->MULT_DIV_MOD()->getText();

    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        int res;
        bool div0 = false;
        if (op == "*")
        {
            res = stoi(param2) * stoi(param3);
        }
        else if (op == "/")
        {
            if (stoi(param3) == 0)
            {
                div0 = true;
            }
            else
                res = stoi(param2) / stoi(param3);
        }
        else if (op == "%")
        {
            if (stoi(param3) == 0)
            {
                div0 = true;
            }
            else
                res = stoi(param2) % stoi(param3);
        }

        if (!div0)
        {
            return to_string(res);
        } // if divide by 0 we keep compiling without calculating the value
    }

    if (param2 == "0")
    { // 0*x or 0/x or 0%x
        return "0";
    }

    if (param3 == "1" && (op == "*" || op == "/"))
    { // x*1 or x/1
        return param2;
    }

    if (param2 == "1" && op == "*")
    { // 1*x
        return param3;
    }

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

antlrcpp::Any IRVisitor::visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx)
{
    // cout << "#visiting variable assignments..." << endl;

    string name = ctx->ID()->getText();
    string tempvar;

    if (ctx->expr())
    {
        string expr = visit(ctx->expr());
        tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {name, expr});
    }

    return name;
}

antlrcpp::Any IRVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    // cout << "#visiting return statements..." << endl;
    auto expr = ctx->expr();
    string name = visit(expr);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ret, Type::TypeEnum::INT, {name});
    return 0;
}

antlrcpp::Any IRVisitor::visitVar(ifccParser::VarContext *ctx)
{
    // cout << "#Visiting Var expression " << endl;
    string name = ctx->ID()->getText();
    int ind = currentCFG->getSymbolIndex()[name];
    // cout << "Var named " << name << " at " << ind << endl;

    return name;
}

antlrcpp::Any IRVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
#ifdef __APPLE__
    // cout << "#Visiting IntConst " << endl;
    string value = ctx->INT_CONST()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});

    // cout << "New Int Const with value [" << value << "] Decl as " << tempvar << endl;

    return tempvar;
    
#endif
    
    
    return ctx->INT_CONST()->getText();
}

antlrcpp::Any IRVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
#ifdef __APPLE__

    int char_value = (int)ctx->CHAR_CONST()->getText()[1];
    string value = to_string(char_value);
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::CHAR);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::CHAR, {tempvar, value});
    return tempvar;
#endif

    return to_string(ctx->CHAR_CONST()->getText()[1]);
}

antlrcpp::Any IRVisitor::visitIf_block(ifccParser::If_blockContext *ctx)
{
    // if_block : 'if' '(' expr ')' (line | block) else_block? ;
    auto testBB = currentCFG->current_bb;
    auto thenBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto elseBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto endifBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    currentCFG->add_bb(thenBB);
    currentCFG->add_bb(elseBB);
    currentCFG->add_bb(endifBB);

    // Adjust pointers
    thenBB->parent = testBB;
    elseBB->parent = testBB;
    endifBB->parent = testBB;

    endifBB->exit_true = testBB->exit_true;
    endifBB->exit_false = testBB->exit_false;
    testBB->exit_true = thenBB;
    testBB->exit_false = elseBB;
    thenBB->exit_true = endifBB;
    thenBB->exit_false = nullptr;
    elseBB->exit_true = endifBB;
    elseBB->exit_false = nullptr;

    currentCFG->current_bb = testBB;

    // Generate IRIntr in blocks
    string cond = visit(ctx->expr());

    vector<string> params;
    params.push_back(cond);
    params.push_back(testBB->exit_true->label);
    params.push_back(testBB->exit_false->label);

    testBB->add_IRInstr(IRInstr::Operation::jmp_cond, Type::TypeEnum::INT, params);

    currentCFG->current_bb = thenBB;
    visit(ctx->line());

    currentCFG->current_bb = elseBB;
    if (ctx->else_block())
    {
        visit(ctx->else_block());
    }

    currentCFG->current_bb = endifBB;
    return 0;
}

antlrcpp::Any IRVisitor::visitElse_block(ifccParser::Else_blockContext *ctx)
{
    visit(ctx->line());
    return 0;
}

antlrcpp::Any IRVisitor::visitWhile_block(ifccParser::While_blockContext *ctx)
{
    // while_block : 'while' '(' expr ')' (line | block);
    auto pretestBB = currentCFG->current_bb;
    auto testBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());
    auto bodyBB = new BasicBlock(currentCFG, currentCFG->new_BB_name());

    testBB->parent = pretestBB;
    bodyBB->parent = testBB;

    testBB->exit_false = pretestBB->exit_true;
    testBB->exit_true = bodyBB;
    pretestBB->exit_true = testBB;
    pretestBB->exit_false = nullptr;
    bodyBB->exit_true = testBB;
    bodyBB->exit_false = nullptr;

    currentCFG->add_bb(testBB);
    currentCFG->add_bb(bodyBB);

    currentCFG->current_bb = testBB;

    string cond = visit(ctx->expr());

    vector<string> params;
    params.push_back(cond);
    params.push_back(testBB->exit_true->label);
    params.push_back(testBB->exit_false->label);

    testBB->add_IRInstr(IRInstr::Operation::jmp_cond, Type::TypeEnum::INT, params);

    currentCFG->current_bb = bodyBB;
    visit(ctx->line());

    currentCFG->current_bb = testBB->exit_false;

    return 0;
}

antlrcpp::Any IRVisitor::visitStmt(ifccParser::StmtContext *ctx)
{
    // stmt : var_decl | var_ass | return_stmt ;
    if (ctx->var_decl())
    {
        visit(ctx->var_decl());
    }

    else if (ctx->return_stmt())
    {
        visit(ctx->return_stmt());
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitAndExpr(ifccParser::AndExprContext *ctx)
{
    // cout << "#visiting and expression..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        return to_string(stoi(param2) & stoi(param3));
    }

    if (param2 == "0" || param3 == "0")
    { // x&0 or 0&x
        return "0";
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::bit_and, Type::TypeEnum::INT, params);

    return tempvar;
}

antlrcpp::Any IRVisitor::visitEqualExpr(ifccParser::EqualExprContext *ctx)
{
    // cout << "visiting equal / not equal expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->EQ_NEQ()->getText();
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        int res;
        if (op == "==")
        {
            res = (param2 == param3);
        }
        else if (op == "!=")
        {
            res = (param2 != param3);
        }
        return to_string(res);
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    if (op == "==")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::eq, Type::TypeEnum::INT, params);
    }
    else if (op == "!=")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::neq, Type::TypeEnum::INT, params);
    }

    return tempvar;
}

antlrcpp::Any IRVisitor::visitUnaireExpr(ifccParser::UnaireExprContext *ctx)
{
    auto expr = ctx->expr();
    string op = ctx->UNAIRE->getText();

    string param = visit(expr);
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param);
    params.push_back(tempvar);

    if (op == "-")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::neg, Type::TypeEnum::INT, params);
    }
    else if (op == "!")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::unary_not, Type::TypeEnum::INT, params);
    }

    return tempvar;
}

antlrcpp::Any IRVisitor::visitXorExpr(ifccParser::XorExprContext *ctx)
{
    // cout << "visiting xor expression..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        return to_string(stoi(param2) ^ stoi(param3));
    }

    if (param3 == "0")
    { // x^0
        return param2;
    }

    if (param2 == "0")
    { // 0^x
        return param3;
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::bit_xor, Type::TypeEnum::INT, params);

    return tempvar;
}

antlrcpp::Any IRVisitor::visitParExpr(ifccParser::ParExprContext *ctx)
{
    auto expr = ctx->expr();
    string name = visit(expr);
    return name;
}

antlrcpp::Any IRVisitor::visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx)
{
    // cout << "#visiting more less expressions..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->MORE_LESS()->getText();
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        int res;
        if (op == "<")
        {
            res = stoi(param2) < stoi(param3);
        }
        else if (op == ">")
        {
            res = stoi(param2) > stoi(param3);
        }
        return to_string(res);
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    if (op == "<")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::lt, Type::TypeEnum::INT, params);
    }
    else if (op == ">")
    {
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::gt, Type::TypeEnum::INT, params);
    }

    return tempvar;
}

antlrcpp::Any IRVisitor::visitOrExpr(ifccParser::OrExprContext *ctx)
{
    // cout << "visiting or expression..." << endl;
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    // Visit left and right expressions and get their adress in memory
    string param2 = visit(left);
    string param3 = visit(right);

    if (isConstant(param2) && isConstant(param3))
    { // constant propagation
        return to_string(stoi(param2) | stoi(param3));
    }

    if (param3 == "0")
    { // x|0
        return param2;
    }

    if (param2 == "0")
    { // 0|x
        return param3;
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    vector<string> params;
    params.push_back(param2);
    params.push_back(param3);
    params.push_back(tempvar);

    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::bit_or, Type::TypeEnum::INT, params);

    return tempvar;
}

antlrcpp::Any IRVisitor::visitPutchar(ifccParser::PutcharContext *ctx)
{

    auto expr = ctx->expr();
    string param = visit(expr);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::putchar, Type::TypeEnum::CHAR, {param});
    return param;
}

antlrcpp::Any IRVisitor::visitGetchar(ifccParser::GetcharContext *ctx)
{
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::CHAR);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::getchar, Type::TypeEnum::CHAR, {tempvar});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx)
{

    // cout << "#visiting function call " << endl;
    int i = 0;

    while (ctx->expr(i) != nullptr)
    {

        string name = visit(ctx->expr(i));
        currentCFG->current_bb->add_IRInstr(IRInstr::Operation::CallParam, currentCFG->getSymbolType()[name], {name, to_string(i)});
        i++;
    }

    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    string func_name = ctx->ID()->getText();
    string return_type;
    if (functionTypesMap[func_name] == "int")
    {
        return_type = "int";
    }
    else
    {
        return_type = "void";
    }
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::call, Type::TypeEnum::CHAR, {func_name, tempvar, return_type});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitVarPostIncrement(ifccParser::VarPostIncrementContext *ctx)
{
    string name = ctx->ID()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {tempvar, name});
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::PostIncr, currentCFG->getSymbolType()[name], {name, tempvar});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitVarPostDecrement(ifccParser::VarPostDecrementContext *ctx)
{
    string name = ctx->ID()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {tempvar, name});
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::PostDecr, currentCFG->getSymbolType()[name], {name, tempvar});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitVarParPostIncrement(ifccParser::VarParPostIncrementContext *ctx)
{
    string name = ctx->ID()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {tempvar, name});
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::PostIncr, currentCFG->getSymbolType()[name], {name, tempvar});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitVarParPostDecrement(ifccParser::VarParPostDecrementContext *ctx)
{
    string name = ctx->ID()->getText();
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::copy, currentCFG->getSymbolType()[name], {tempvar, name});
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::PostDecr, currentCFG->getSymbolType()[name], {name, tempvar});
    return tempvar;
}

antlrcpp::Any IRVisitor::visitVarPreIncrement(ifccParser::VarPreIncrementContext *ctx)
{
    // Visit left and right expressions and get their adress in memory
    string value = "1";
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::add, Type::TypeEnum::INT, {name, tempvar, name});
    return name;
}
antlrcpp::Any IRVisitor::visitVarPreDecrement(ifccParser::VarPreDecrementContext *ctx)
{
    string value = "1";
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::sub, Type::TypeEnum::INT, {name, tempvar, name});
    return name;
}
antlrcpp::Any IRVisitor::visitVarParPreIncrement(ifccParser::VarParPreIncrementContext *ctx)
{
    string value = "1";
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::add, Type::TypeEnum::INT, {name, tempvar, name});
    return name;
}
antlrcpp::Any IRVisitor::visitVarParPreDecrement(ifccParser::VarParPreDecrementContext *ctx)
{
    string value = "1";
    string tempvar = currentCFG->create_new_tempvar(Type::TypeEnum::INT);
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::ldconst, Type::TypeEnum::INT, {tempvar, value});
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::sub, Type::TypeEnum::INT, {name, tempvar, name});
    return name;
}

antlrcpp::Any IRVisitor::visitVarAdditionAssignment(ifccParser::VarAdditionAssignmentContext *ctx)
{
    auto expr = ctx->expr();
    string param = visit(expr);
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::add, Type::TypeEnum::INT, {name, param, name});
    return name;
}

antlrcpp::Any IRVisitor::visitVarSubstractionAssignment(ifccParser::VarSubstractionAssignmentContext *ctx)
{
    auto expr = ctx->expr();
    string param = visit(expr);
    string name = ctx->ID()->getText();
    currentCFG->current_bb->add_IRInstr(IRInstr::Operation::sub, Type::TypeEnum::INT, {name, param, name});
    return name;
}
