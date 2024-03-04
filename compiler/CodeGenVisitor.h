#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "ast.h"
#include <unordered_map>

using namespace std;


class CodeGenVisitor : public ifccBaseVisitor {
public:
        CodeGenVisitor() {}
        CodeGenVisitor(unordered_map<string, int> adrTable) : adrTable(adrTable) {}
        unordered_map<string, int> getVarMap() {return this->adrTable;}

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override ;
        virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override ;
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override ;
        virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override ;
        virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override ;
        virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override ;
protected:
        unordered_map<string, int> adrTable;
};

