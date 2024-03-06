#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "ast.h"
#include <unordered_map>
#include "util.h"
using namespace std;

class CodeGenVisitor : public ifccBaseVisitor
{
public:
        CodeGenVisitor() {}
        CodeGenVisitor(unordered_map<string, VariableInfo> adrTable) : adrTable(adrTable), cur_pointer(0) {}
        CodeGenVisitor(unordered_map<string, VariableInfo> adrTable, int cur_pointer) : adrTable(adrTable), cur_pointer(cur_pointer) {}
        unordered_map<string, VariableInfo> getVarMap() { return this->adrTable; }
        int getCurPointer() { return this->cur_pointer; }

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        // virtual antlrcpp::Any visitReturnExp(ifccParser::ReturnExpContext *ctx) override;
        // virtual antlrcpp::Any visitReturnVar(ifccParser::ReturnVarContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
        virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
        virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;
        virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
        virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
        virtual antlrcpp::Any visitVar_ass(ifccParser::Var_assContext *ctx) override ; 
        // virtual antlrcpp::Any visitVarAss(ifccParser::VarAssContext *ctx) override;
        // virtual antlrcpp::Any visitExprAss(ifccParser::ExprAssContext *ctx) override;

protected:
        unordered_map<string, VariableInfo> adrTable;
        int cur_pointer;
};
