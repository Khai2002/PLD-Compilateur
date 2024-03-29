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
        virtual antlrcpp::Any visitFunctionCall(ifccParser::FunctionCallContext *ctx) override;

protected:
        unordered_map<string, VariableInfo> adrTable;
        unordered_map<string, Function_info> func_table;
        int cur_pointer;
        int number_errors;
        int number_warnings;
};