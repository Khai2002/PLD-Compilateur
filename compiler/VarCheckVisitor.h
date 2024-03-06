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
        VarCheckVisitor() : cur_pointer(0) {}
        VarCheckVisitor(unordered_map<string, VariableInfo> adrTable) : adrTable(adrTable), cur_pointer(0) {}
        unordered_map<string, VariableInfo> getAdrTable() { return this->adrTable; }
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
        //virtual antlrcpp::Any visitVarAss(ifccParser::VarAssContext *ctx) override;
        //virtual antlrcpp::Any visitExprAss(ifccParser::ExprAssContext *ctx) override;
        //virtual antlrcpp::Any visitReturnVar(ifccParser::ReturnVarContext *ctx) override ;

protected:
        unordered_map<string, VariableInfo> adrTable;
        int cur_pointer;
};