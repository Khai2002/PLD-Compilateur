#include "VarCheckVisitor.h"

using namespace std;

antlrcpp::Any VarCheckVisitor::visitProg(ifccParser::ProgContext *ctx)
{

    for (auto func : ctx->func_decl())
    {
        visit(func);
    }


    // cout << "#visitProg" << endl;
    //   To be completed

    /*for (auto func : ctx->func_decl())
    {
        func_table.add(ctx->func_decl().ID()->getText());
        adrTable.clear();
        for (auto line : func->line())
        {
            if (line->stmt() != nullptr)
            {
                auto stmt = line->stmt();
                visit(stmt);
            }
            if (line->expr() != nullptr)
            {
                auto expr = line->expr();
                visit(expr);
            }
            else if (line->if_block() != nullptr)
            {
                auto if_block = line->if_block();
                visit(if_block);
            }
            else if (line->while_block() != nullptr)
            {
                auto while_block = line->while_block();
                visit(while_block);
            }
        }
        this->visit(func->return_stmt());
        for (const auto &entry : adrTable)
        {
            const VariableInfo &variable = entry.second;
            if (variable.callCount == 0)
            {
                cerr << "# Variable '" << entry.first << "' déclarée mais non utilisée" << endl;
                this->number_warnings++;
            }
        }
    }*/

    return 0;
}

antlrcpp::Any VarCheckVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    Function_info F_info;
    this->func_table[ctx->ID()->getText()] = F_info;

    this->adrTable.clear();
    for (auto line : ctx->line())
    {
        if (line->stmt() != nullptr)
        {
            auto stmt = line->stmt();
            visit(stmt);
        }
        if (line->expr() != nullptr)
        {
            auto expr = line->expr();
            visit(expr);
        }
        else if (line->if_block() != nullptr)
        {
            auto if_block = line->if_block();
            visit(if_block);
        }
        else if (line->while_block() != nullptr)
        {
            auto while_block = line->while_block();
            visit(while_block);
        }
    }
    this->visit(ctx->return_stmt());
    for (const auto &entry : adrTable)
    {
        const VariableInfo &variable = entry.second;
        if (variable.callCount == 0)
        {
            cerr << "# Variable '" << entry.first << "' déclarée mais non utilisée" << endl;
            this->number_warnings++;
        }
    }

    return 0;
}

antlrcpp::Any VarCheckVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    // cout << "#visitVar_decl" << endl;
    int int_size = 8;
    int char_size = 8;

    for (auto id : ctx->ID())
    {
        string name = id->getText();
        auto it = this->adrTable.find(name);
        if (it != this->adrTable.end())
        {
            cerr << "#Erreur : Variable '" << name << "' déjà déclarée." << endl;
            this->number_errors++;
            return 0;
        }

        string type = ctx->type()->getText();
        if (type == "int")
        {
            this->cur_pointer -= int_size;
        }
        else
        {
            this->cur_pointer -= char_size;
        }
        this->adrTable[name] = VariableInfo(this->cur_pointer);
    }

    // cout << "Name :" << name << " index : " << this->adrTable[name].index << endl;
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx)
{
    // cout << "visitVar_Assignment" << endl;
    string name1 = ctx->ID()->getText();

    auto it1 = this->adrTable.find(name1);
    if (it1 == this->adrTable.end())
    {
        cout << "# Erreur : Variable '" << name1 << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return 0;
    }
    auto expr = visitChildren(ctx);
    it1->second.callCount++;
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitVar(ifccParser::VarContext *ctx)
{
    // cout << "visitVar" << endl;
    string name = ctx->ID()->getText();
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cerr << "#Erreur : Variable '" << name << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return 0;
    }
    auto expr = visitChildren(ctx);
    it->second.callCount++;
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    auto expr = visitChildren(ctx);
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx)
{
    string name1 = ctx->ID()->getText();

    auto it1 = this->func_table.find(name1);
    if (it1 == this->func_table.end())
    {
        cout << "# Erreur : la fonction '" << name1 << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return 0;
    }
    return 0;
}