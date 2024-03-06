#include "VarCheckVisitor.h"

using namespace std;

antlrcpp::Any VarCheckVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    int int_size = 4;
    int char_size = 1;

    string name = ctx->ID()->getText();
    auto it = this->adrTable.find(name);
    if (it != this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name << "' déjà déclarée." << endl;
        return 0;
    }

    string type = ctx->type()->getText();
    if(type == "int") {
        this->cur_pointer -= int_size;
    }else {
        this->cur_pointer -= char_size;
    }
    this->adrTable[name] = VariableInfo(this->cur_pointer);

    cout << "Name :" << name << " index : " << this->adrTable[name].index << endl;
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    for (auto stmt : ctx->stmt())
    {
        visit(stmt);
    }
    this->visit(ctx->return_stmt());
    for (const auto &entry : adrTable)
    {
        const VariableInfo &variable = entry.second;
        if (variable.callCount == 0)
        {
            cout << "Variable '" << entry.first << "' déclarée mais non utilisée" << endl;
        }
    }
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitVar_ass(ifccParser::Var_assContext *ctx){
    // cout<<"Je rentre ici "<<endl ; 
    string name1 = ctx->ID()->getText();
   
    auto it1 = this->adrTable.find(name1);
    if (it1 == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name1 << "' n'a pas été déclarée." << endl;
        return 0;
    }
    auto expr = visitChildren(ctx); 
    it1->second.callCount++;
    return 0 ; 
} 


antlrcpp::Any VarCheckVisitor::visitVar(ifccParser::VarContext *ctx) 
{
    string name = ctx->ID()->getText();
   
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name << "' n'a pas été déclarée." << endl;
        return 0;
    }
    auto expr = visitChildren(ctx); 
    it->second.callCount++;
    return 0 ; 
}


antlrcpp::Any VarCheckVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    auto expr = visitChildren(ctx);  
    return 0;
}

/*antlrcpp::Any VarCheckVisitor::visitVarAss(ifccParser::VarAssContext *ctx)
{
    string name1 = ctx->ID(0)->getText();
    string name2 = ctx->ID(1)->getText();
    auto it1 = this->adrTable.find(name1);
    if (it1 == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name1 << "' n'a pas été déclarée." << endl;
        return 0;
    }

    auto it2 = this->adrTable.find(name2);
    if (it2 == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name2 << "' n'a pas été déclarée." << endl;
        return 0;
    }

    it1->second.callCount++;
    it2->second.callCount++;

    return 0;
}
*/


/*antlrcpp::Any VarCheckVisitor::visitExprAss(ifccParser::ExprAssContext *ctx)
{
    string name = ctx->ID()->getText();
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name << "' n'a pas été déclarée." << endl;
        return 0;
    }

    VariableInfo &variable = it->second;
    variable.callCount++;

    return 0;
}
*/

/*antlrcpp::Any VarCheckVisitor::visitReturnVar(ifccParser::ReturnVarContext *ctx)
{
    string name = ctx->ID()->getText();
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cout << "Erreur : Variable '" << name << "' n'a pas été déclarée." << endl;
        return 0;
    }

    VariableInfo &variable = it->second;
    variable.callCount++;

    return 0;
}
*/

