#include "CheckVisitor.h"

using namespace std;

void CheckVisitor::insertParam(string name, string type)
{
    auto it = this->adrTable.find(name);
    if (it != this->adrTable.end())
    {
        cerr << "#Error:  the variable '" << name << "' has already been declared." << endl;
        exit(1);
    }

    this->adrTable[name] = VariableInfo();
}

void CheckVisitor::checkVariableName(string name)
{
    auto it = this->adrTable.find(name);
    if (it == this->adrTable.end())
    {
        cerr << "#Error:  the variable '" << name << "' has not been declared." << endl;
        exit(1);
    }
    it->second.callCount++;
}

antlrcpp::Any CheckVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout << "# visiting Prog" << endl;

    for (auto func : ctx->func_decl())
    {
        visit(func);
    }

    return 0;
}

antlrcpp::Any CheckVisitor::visitFunc_decl(ifccParser::Func_declContext *ctx)
{
    cout << "# visitFunc_decl ..." << endl;
    Function_info F_info;
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
        cerr << "# No type matches " << ctx->type(0)->getText();
        exit(1);
    }
    int i = 1;

    this->adrTable.clear();

    while (ctx->type(i) != nullptr)
    {

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
            exit(1);
        }
        insertParam(ctx->ID(i)->getText(), ctx->type(i)->getText());
        i++;
    }

    if (F_info.get_number_params() > 6)
    {
        cerr << " Sorry we don't support functions with more than 6 parameters" << endl;
        exit(1);
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
        else if (line->block() != nullptr)
        {
            auto block = line->block();
            visit(block);
        }
    }

    for (const auto &entry : adrTable)
    {
        const VariableInfo &variable = entry.second;
        if (variable.callCount == 0)
        {
            cerr << "# Variable '" << entry.first << "' declared but not used " << endl;
            this->number_warnings++;
        }
    }

    return 0;
}

antlrcpp::Any CheckVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{
    cout << "# visitVar_decl" << endl;

    for (auto Dec : ctx->declareAssign())
    {
        visit(Dec);
    }
    return 0;
}

antlrcpp::Any CheckVisitor::visitDeclareAssign(ifccParser::DeclareAssignContext *ctx)
{
    cout << "# visit Declaration assignement" << endl;
    if (ctx->expr() != nullptr)
    {
        auto expr = visit(ctx->expr());
        if ((string)expr == VOID_Type)
        {
            cerr << "wrong Type for the expression assignment " << endl;
            exit(1);
        }
    }

    insertParam(ctx->ID()->getText(), "int");
    return 0;
}

antlrcpp::Any CheckVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    cout << "# visiting return statement" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the return statement " << endl;
        exit(1);
    }
    return 0;
}

antlrcpp::Any CheckVisitor::visitVar(ifccParser::VarContext *ctx)
{
    cout << "# visitVar" << endl;
    checkVariableName(ctx->ID()->getText());
    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitVar_Assignment(ifccParser::Var_AssignmentContext *ctx)
{
    cout << "# visitVar_Assignment" << endl;
    checkVariableName(ctx->ID()->getText());

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expression assignment" << endl;
        exit(1);
    }

    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitUnaireExpr(ifccParser::UnaireExprContext *ctx)
{
    cout << "# visitUnaireExpr" << endl;
    auto expr = visit(ctx->expr());
    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the unary expression" << endl;
        exit(1);
    }
    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx)
{
    cout << "# visitMultDivModExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the expressions of Multiplication/Division/ Modulo." << endl;
        exit(1);
    }

    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    cout << "# visitAddSubExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the expressions of addition/substraction" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitMoreLessExpr(ifccParser::MoreLessExprContext *ctx)
{
    cout << "# visitMoreLessExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the expressions " << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitEqualExpr(ifccParser::EqualExprContext *ctx)
{
    cout << "# visitEqualExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the  Equal/notEqual expression " << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitAndExpr(ifccParser::AndExprContext *ctx)
{
    cout << "# visitAndExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the And expression" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitXorExpr(ifccParser::XorExprContext *ctx)
{
    cout << "# visitXorExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the Xor expression" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitOrExpr(ifccParser::OrExprContext *ctx)
{
    cout << "# visitOrExpr" << endl;

    auto expr1 = visit(ctx->expr(0));
    auto expr2 = visit(ctx->expr(1));
    if ((string)expr1 == VOID_Type || (string)expr2 == VOID_Type)
    {
        cerr << "wrong Type for at least one of the Or expression" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitPutchar(ifccParser::PutcharContext *ctx)
{
    // cout << "#visitPutchar" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expression in putchar" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitGetchar(ifccParser::GetcharContext *ctx)
{
    cout << "# visitGetChar" << endl;
    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitParExpr(ifccParser::ParExprContext *ctx)
{
    cout << "#visiting ParExpr" << endl;

    auto expr = visit(ctx->expr());

    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expression in parenthesis" << endl;
        exit(1);
    }

    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    cout << "# visiting IntConst" << endl;
    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    cout << "# visiting charConst" << endl;
    return (INT_Type);
}

antlrcpp::Any CheckVisitor::visitFunctionCall(ifccParser::FunctionCallContext *ctx)
{
    cout << "# visiting function call " << endl;
    string name1 = ctx->ID()->getText();

    auto it1 = this->func_table.find(name1);
    if (it1 == this->func_table.end())
    {
        cerr << "# Error  : the function  '" << name1 << "' has not been declared." << endl;
        exit(1);
    }
    auto it2 = this->adrTable.find(name1);
    if (it2 != this->adrTable.end())
    {
        cerr << "#Error : the variable '" << name1 << "' has already been declared as a variable." << endl;
        exit(1);
    }

    int i = 0;
    while (ctx->expr(i) != nullptr)
    {
        auto expr = visit(ctx->expr(i));
        if ((string)expr == VOID_Type)
        {
            cerr << "wrong Type for the at least one argument passed in parameter  " << endl;
            exit(1);
        }
        i++;
    }
    if (i != it1->second.get_number_params())
    {
        cerr << "The number of arguments passed in parameter is incorrect." << endl;
        exit(1);
    }

    return this->func_table[name1].Get_Return_type();
}

antlrcpp::Any CheckVisitor::visitVarPostIncrement(ifccParser::VarPostIncrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarPostDecrement(ifccParser::VarPostDecrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarParPostIncrement(ifccParser::VarParPostIncrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarParPostDecrement(ifccParser::VarParPostDecrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarPreIncrement(ifccParser::VarPreIncrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarPreDecrement(ifccParser::VarPreDecrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarParPreIncrement(ifccParser::VarParPreIncrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarParPreDecrement(ifccParser::VarParPreDecrementContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarAdditionAssignment(ifccParser::VarAdditionAssignmentContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    auto expr = visit(ctx->expr());
    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expression " << endl;

        exit(1);
    }
    return INT_Type;
}

antlrcpp::Any CheckVisitor::visitVarSubstractionAssignment(ifccParser::VarSubstractionAssignmentContext *ctx)
{
    checkVariableName(ctx->ID()->getText());
    auto expr = visit(ctx->expr());
    if ((string)expr == VOID_Type)
    {
        cerr << "wrong Type for the expression" << endl;
        exit(1);
    }
    return INT_Type;
}
