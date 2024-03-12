#include "IRVisitor.h"

using namespace std;

antlrcpp::Any IRVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    // Naive function to interate through all functions listed
    for (auto func_ctx :  ctx->func_decl()) {
        // Only execute main
        if(func_ctx->ID()->getText() != "main") continue;
        visit(func_ctx);
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    cout << "visiting function declarations..." << endl;

    CFG* cfg  = new CFG(ctx->ID()->getText()) ;  
    currentCFG = cfg;
    cfgs.push_back(cfg);
    
    for (auto line : ctx->line()) {
        visit(line);
    }

    if (ctx->return_stmt()) {
        visit(ctx->return_stmt());
    }
    
    
    return 0;
}

antlrcpp::Any IRVisitor::visitLine(ifccParser::LineContext *ctx) 
{
    cout << "visiting lines..." << endl;
    if (ctx->stmt()){
        visit(ctx->stmt());
    } else if (ctx->if_block()) {
        visit(ctx->if_block());
    } else if (ctx->while_block()) {
        visit(ctx->while_block());
    }
    return 0;
}

antlrcpp::Any IRVisitor::visitVar_decl(ifccParser::Var_declContext *ctx) 
{
    cout << "visiting variable declarations..." << endl;

    string typeName = ctx->type()->getText();
    string name = ctx->ID()->getText();
 
    return 0;
}

antlrcpp::Any IRVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx) 
{
    
    return 0;
}

antlrcpp::Any IRVisitor::visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) 
{
    return 0;
}

antlrcpp::Any IRVisitor::visitVar_ass(ifccParser::Var_assContext *ctx) 
{
    return 0;
}

antlrcpp::Any IRVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    return 0;
}

antlrcpp::Any IRVisitor::visitVar(ifccParser::VarContext *ctx) 
{
    return 0;
}

antlrcpp::Any IRVisitor::visitIntConst(ifccParser::IntConstContext *ctx) 
{
    int value = stoi(ctx->INT_CONST()->getText());
    int ind = currentCFG->getNextFreeSymbolIndex();
    //currentCFG->add_to_symbol_table()
    return 0;
}

antlrcpp::Any IRVisitor::visitCharConst(ifccParser::CharConstContext *ctx) 
{
    char value = ctx->CHAR_CONST()->getText()[1];
    return 0;
}

antlrcpp::Any IRVisitor::visitIf_block(ifccParser::If_blockContext *ctx)
{
    return 0;
}

antlrcpp::Any IRVisitor::visitElse_block(ifccParser::Else_blockContext *ctx)
{
    return 0;
}

antlrcpp::Any IRVisitor::visitWhile_block(ifccParser::While_blockContext *ctx)
{
    return 0;
}

antlrcpp::Any IRVisitor::visitBlock(ifccParser::BlockContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitStmt(ifccParser::StmtContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitAndExpr(ifccParser::AndExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitEqualExpr(ifccParser::EqualExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitUnaire(ifccParser::UnaireContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitXorExpr(ifccParser::XorExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitParExpr(ifccParser::ParExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitOrExpr(ifccParser::OrExprContext *ctx)  {
    return 0;
}

antlrcpp::Any IRVisitor::visitType(ifccParser::TypeContext *ctx)  {
    return 0;
}
