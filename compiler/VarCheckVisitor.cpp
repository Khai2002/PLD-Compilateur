#include "VarCheckVisitor.h"

using namespace std;


antlrcpp::Any VarCheckVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    int int_size = 4;
    int char_size = 1;
    string name = ctx->ID()->getText();
    string type = ctx->type()->getText();

    if (isVarDeclared(name)) {
        cerr << "Variable '" << name << "' has already been declared" << endl;
    }


    
    if(type == "int") {
        this->cur_pointer -= 4;
    } else {
        this->cur_pointer -= 1;
    }

    this->adrTable[name] = this->cur_pointer;

    cout << "Name:" << name << "  " << this->adrTable[name]  << endl;
    return 0;
}

// check if the variable is already declared
bool VarCheckVisitor::isVarDeclared(const string& name) {
    return this->adrTable.find(name) != this->adrTable.end();
}

