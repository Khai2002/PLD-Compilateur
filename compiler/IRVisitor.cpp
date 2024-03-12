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

    CFG* cfg  = new cfg() ;  
    currentCFG = cfg;
    cfg.push_back(cfg) ; 
    if (ctx->ID()) {
        visit(ctx->ID());
    } else if (ctx->expr()) {
        visit(ctx->expr());
    } else if (ctx->type()) {
        visit(ctx->type());
    }
}

antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) 
{
    
    return visitChildren(ctx);
}

antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) 
{
    return visitChildren(ctx);
}

antlrcpp::Any visitVar_ass(ifccParser::Var_assContext *ctx) 
{
    return visitChildren(ctx);
}

antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) 
{
    return visitChildren(ctx);
}

antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) 
{
    return visitChildren(ctx);
}

antlrcpp::Any visitLine(ifccParser::LineContext *ctx) 
{
    return visitChildren(ctx);
}

antlrcpp::Any visitIf_block(ifccParser::If_blockContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any visitElse_block(ifccParser::Else_blockContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any visitWhile_block(ifccParser::While_blockContext *ctx)
{
    return visitChildren(ctx);
}

antlrcpp::Any visitBlock(ifccParser::BlockContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitIf_block(ifccParser::If_blockContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitElse_block(ifccParser::Else_blockContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitWhile_block(ifccParser::While_blockContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitStmt(ifccParser::StmtContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitAndExpr(ifccParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitEqualExpr(ifccParser::EqualExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitUnaire(ifccParser::UnaireContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitXorExpr(ifccParser::XorExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitOrExpr(ifccParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
}

antlrcpp::Any visitType(ifccParser::TypeContext *ctx) override {
    return visitChildren(ctx);
}
