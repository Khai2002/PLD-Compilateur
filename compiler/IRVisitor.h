#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "ast.h"
#include <unordered_map>
#include "util.h"
using namespace std;

class IRVisitor : public ifccBaseVisitor {
public:
    IRVisitor() {}

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *ctx) override;
    // virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
    // virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;
    // virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
    // virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
    // virtual antlrcpp::Any visitVar_ass(ifccParser::Var_assContext *ctx) override;
    // virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
    // virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
    // virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;
        

protected:
};