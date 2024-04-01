#include "VarCheckVisitor.h"

using namespace std;

void VarCheckVisitor::insertParam(string name, string type)
{
    int int_size = 8;
    int char_size = 8;

    auto it = this->adrTable.find(name);
    if (it != this->adrTable.end())
    {
        cerr << "#Erreur : Variable '" << name << "' déjà déclarée." << endl;
        this->number_errors++;
        return;
    }

    if (type == INT_Type)
    {
        this->cur_pointer -= int_size;
    }
    else
    {
        this->cur_pointer -= char_size;
    }
    this->adrTable[name] = VariableInfo(this->cur_pointer);
}

antlrcpp::Any VarCheckVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout << "# visiting Prog" << endl;

    for (auto func : ctx->func_decl())
    {
        visit(func);
    }

    return 0;
}

antlrcpp::Any VarCheckVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    cout << "# visitFunc_decl ..." << endl;
    Function_info F_info;
    // cout << ctx->type(0)->getText() << endl;
    if (ctx->type(0)->getText() == INT_Type)
    {

        F_info.addReturnType(INT_Type);
    }
    else if (ctx->type(0)->getText() == "char")
    {
        F_info.addReturnType(INT_Type);
    }
    else if (ctx->type(0)->getText() == VOID_Type)
    {
        F_info.addReturnType(VOID_Type);
    }
    else
    {
        // cout << "acdvd" << endl;
        cerr << "# No type matches " << ctx->type(0)->getText();
        this->number_errors++;
    }
    int i = 1;
    int int_size = 8;
    int char_size = 8;
    this->adrTable.clear();

    while (ctx->type(i) != nullptr)
    {
        // cout << ctx->type(i)->getText() << endl;

        if (ctx->type(i)->getText() == INT_Type)
        {
            F_info.addType(Type::INT);
        }
        else if (ctx->type(i)->getText() == "char")
        {
            F_info.addType(Type::CHAR);
        }
        else
        {
            cerr << "# No type matches " << ctx->type(i)->getText() << endl;
            this->number_errors++;
        }
        insertParam(ctx->ID(i)->getText(), ctx->type(i)->getText());
        i++;
    }

    this->func_table[ctx->ID(0)->getText()] = F_info;

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
    cout << "# visitVar_decl" << endl;
    int int_size = 8;
    int char_size = 8;

    for (auto id : ctx->ID())
    {
        insertParam(id->getText(), ctx->type()->getText());
    }

    // cout << "Name :" << name << " index : " << this->adrTable[name].index << endl;
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx)
{
    cout << "# visitVar_Assignment" << endl;
    string name1 = ctx->ID()->getText();
    auto it1 = this->adrTable.find(name1);
    if (it1 == this->adrTable.end())
    {
        cout << "# Erreur : Variable '" << name1 << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return INT_Type;
    }

    string expr = visit(ctx->expr());
    // cout << expr << endl;

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    it1->second.callCount++;
    return INT_Type;
}

antlrcpp::Any VarCheckVisitor::visitVar(ifccParser::VarContext *ctx)
{
    cout << "# visitVar" << endl;
    string name = ctx->ID()->getText();
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cerr << "#Erreur : Variable '" << name << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return 0;
    }
    // auto expr = visitChildren(ctx);
    it->second.callCount++;
    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitUnaireExpr(ifccParser::UnaireExprContext *ctx)
{
    cout << "# visitUnaireExpr" << endl;
    auto expr = visit(ctx->expr());
    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }
    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx)
{
    cout << "# visitMultDivModExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return INT_Type;
}

antlrcpp::Any VarCheckVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    cout << "# visitAddSubExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx)
{
    cout << "# visitMoreLessExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitEqualExpr(ifccParser::EqualExprContext *ctx)
{
    cout << "# visitEqualExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitAndExpr(ifccParser::AndExprContext *ctx)
{
    cout << "# visitAndExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitXorExpr(ifccParser::XorExprContext *ctx)
{
    cout << "# visitXorExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitOrExpr(ifccParser::OrExprContext *ctx)
{
    cout << "# visitOrExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitPutchar(ifccParser::PutcharContext *ctx)
{
    // cout << "visitVar" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitGetchar(ifccParser::GetcharContext *ctx)
{
    cout << "# visitGetChar" << endl;
    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitParExpr(ifccParser::ParExprContext *ctx)
{
    cout << "#visiting ParExpr" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }

    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    cout << "# visiting IntConst" << endl;
    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    cout << "# visiting charConst" << endl;
    return (INT_Type);
}

antlrcpp::Any VarCheckVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    cout << "# visiting return statement" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expresion" << endl;
        this->number_errors++;
        return INT_Type;
    }
    return 0;
}

antlrcpp::Any VarCheckVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx)
{
    cout << "# visiting function call " << endl;
    string name1 = ctx->ID()->getText();

    auto it1 = this->func_table.find(name1);
    if (it1 == this->func_table.end())
    {
        cout << "# Erreur : la fonction '" << name1 << "' n'a pas été déclarée." << endl;
        this->number_errors++;
        return INT_Type;
    }
    int i = 0;
    while (ctx->expr(i) != nullptr)
    {
        i++;
    }
    if (i != it1->second.get_number_params())
    {
        cerr << "Le nombre d'arguments passé en paramètre est incorrect" << endl;
        this->number_errors++;
        return 0;
    }

    return this->func_table[name1].Get_Return_type();
}
