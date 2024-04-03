#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <string>
#include <unordered_map>
#include "util.h"

using namespace std;

class VarCheckVisitor : public ifccBaseVisitor
{
public:
        VarCheckVisitor() : cur_pointer(0), number_errors(0), number_warnings(0) {}
        VarCheckVisitor(unordered_map<string, VariableInfo> adrTable) : adrTable(adrTable), cur_pointer(0), number_errors(0), number_warnings(0) {}
        unordered_map<string, VariableInfo> getAdrTable() { return this->adrTable; }
        int getCurPointer() { return this->cur_pointer; }
        int getNumber_errors() { return this->number_errors; }
        int getNumber_warnings() { return this->number_warnings; }
        void insertParam(string name, string type);
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        virtual antlrcpp::Any visitFunc_decl(ifccParser::Func_declContext *ctx) override;
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
        virtual antlrcpp::Any visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx) override;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitVar(ifccParser::VarContext *ctx) override;

        virtual antlrcpp::Any visitUnaireExpr(ifccParser::UnaireExprContext *ctx) override;
        virtual antlrcpp::Any visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx) override;
        virtual antlrcpp::Any visitAddSubExpr(ifccParser::AddSubExprContext *ctx) override;
        virtual antlrcpp::Any visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx) override;
        virtual antlrcpp::Any visitEqualExpr(ifccParser::EqualExprContext *ctx) override;
        virtual antlrcpp::Any visitAndExpr(ifccParser::AndExprContext *ctx) override;
        virtual antlrcpp::Any visitXorExpr(ifccParser::XorExprContext *ctx) override;
        virtual antlrcpp::Any visitOrExpr(ifccParser::OrExprContext *ctx) override;

        virtual antlrcpp::Any visitPutchar(ifccParser::PutcharContext *ctx) override;
        virtual antlrcpp::Any visitGetchar(ifccParser::GetcharContext *ctx) override;
        virtual antlrcpp::Any visitParExpr(ifccParser::ParExprContext *ctx) override;
        virtual antlrcpp::Any visitFunctionCall(ifccParser::FunctionCallContext *ctx) override;

        virtual antlrcpp::Any visitVarPostIncrement(ifccParser::VarPostIncrementContext *ctx) override;
        virtual antlrcpp::Any visitVarPostDecrement(ifccParser::VarPostDecrementContext *ctx) override;
        virtual antlrcpp::Any visitVarParPostIncrement(ifccParser::VarParPostIncrementContext *ctx) override;
        virtual antlrcpp::Any visitVarParPostDecrement(ifccParser::VarParPostDecrementContext *ctx) override;
        virtual antlrcpp::Any visitVarPreIncrement(ifccParser::VarPreIncrementContext *ctx) override;
        virtual antlrcpp::Any visitVarPreDecrement(ifccParser::VarPreDecrementContext *ctx) override;
        virtual antlrcpp::Any visitVarParPreIncrement(ifccParser::VarParPreIncrementContext *ctx) override;
        virtual antlrcpp::Any visitVarParPreDecrement(ifccParser::VarParPreDecrementContext *ctx) override;

        virtual antlrcpp::Any visitVarAdditionAssignment(ifccParser::VarAdditionAssignmentContext *ctx) override;
        virtual antlrcpp::Any visitVarSubstractionAssignment(ifccParser::VarSubstractionAssignmentContext *ctx) override;

        virtual antlrcpp::Any visitIntConst(ifccParser::IntConstContext *ctx) override;
        virtual antlrcpp::Any visitCharConst(ifccParser::CharConstContext *ctx) override;

protected:
        unordered_map<string, VariableInfo> adrTable;
        unordered_map<string, Function_info> func_table;
        int cur_pointer;
        int number_errors;
        int number_warnings;

        string INT_Type = "int";
        string VOID_Type = "void";
};