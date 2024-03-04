#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <string>
#include <unordered_map>

using namespace std;

class VarCheckVisitor : public ifccBaseVisitor {
public:
        VarCheckVisitor() : cur_pointer(0) {}
        VarCheckVisitor(unordered_map<string, int> adrTable) : adrTable(adrTable), cur_pointer(0) {}
        unordered_map<string, int> getAdrTable() { return this->adrTable; }
        virtual antlrcpp::Any visitVar_decl(ifccParser::Var_declContext *ctx) override;
protected:
        unordered_map<string, int> adrTable;
        int cur_pointer;
};