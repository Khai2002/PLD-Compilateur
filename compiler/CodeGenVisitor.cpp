#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    cout << ".globl main\n";
    cout << " main: \n";
    cout << "    pushq %rbp \n";
    cout << "    movq %rsp, %rbp\n";

    for (auto stmt : ctx->stmt())
    {
        visit(stmt);
    }
    this->visit(ctx->return_stmt());
    cout << "    popq %rbp\n";

    cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{

    string typeName = ctx->type()->getText();
    string name = ctx->ID()->getText();
    Type *type = new Type(typeName);
    if (ctx->expr())
    {
        int adr = visit(ctx->expr());
        cout << "    movl " << adr << "(%rbp), "
             << "%eax" << endl;
        cout << "    movl "
             << "%eax, " << this->adrTable[name].index << "(%rbp)" << endl;
    }

    return 0;
    // return new VarDecl(id, type, nullptr);
}

antlrcpp::Any CodeGenVisitor::visitVar_ass(ifccParser::Var_assContext *ctx)
{
    // auto expr = visitChildren(ctx);
    string name = ctx->ID()->getText();
    int adr = visit(ctx->expr());
    cout << "    movl " << adr << "(%rbp), "
         << "%eax" << endl;
    cout << "    movl "
         << "%eax, " << this->adrTable[name].index << "(%rbp)" << endl;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    if (ctx->expr())
    {
        int value = visit(ctx->expr());
        cout << "    movl " << value << "(%rbp), "
             << " %eax" << endl;
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    int value = stoi(ctx->INT_CONST()->getText());

    // Assign the IntConst to a tmp value in the memory
    this->cur_pointer -= 4;
    int tmpAdr = this->cur_pointer;
    cout << "    movl $" << value << ", " << tmpAdr << "(%rbp)" << endl;
    return tmpAdr;
}

antlrcpp::Any CodeGenVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    char value = ctx->CHAR_CONST()->getText()[1];

    // Assign the CharConst to a tmp value in the memory
    this->cur_pointer -= 4;
    int tmpAdr = this->cur_pointer;
    cout << "    movl $" << (int)value << ", " << tmpAdr << "(%rbp)" << endl;
    return tmpAdr;
}

// movl	-4(%rbp), %eax
antlrcpp::Any CodeGenVisitor::visitVar(ifccParser::VarContext *ctx)
{
    string name = ctx->ID()->getText();
    // cout << this->adrTable[name].index << "(%rbp)";
    return this->adrTable[name].index;
}

//  movl	-12(%rbp), %edx
// 	movl	-8(%rbp), %eax
// 	addl	%edx, %eax
antlrcpp::Any CodeGenVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->ADD_SUB()->getText();

    // Visit left and right expressions and get their adress in memory
    int lvalue = visit(left);
    int rvalue = visit(right);
    int tmpAdr;

    cout << "    movl " << lvalue << "(%rbp)"
         << ", %edx\n";

    cout << "    movl " << rvalue << "(%rbp)"
         << ", %eax\n";

    if (op == "+")
    {
        cout << "    addl ";
        cout << "%edx, %eax" << endl;
        this->cur_pointer -= 4;
        tmpAdr = this->cur_pointer;
        cout << "    movl "
             << "%eax, " << tmpAdr << "(%rbp)\n";
    }
    else if (op == "-")
    {
        cout << "    subl ";
        cout << "%eax, %edx" << endl;
        this->cur_pointer -= 4;
        tmpAdr = this->cur_pointer;
        cout << "    movl "
             << "%edx, " << tmpAdr << "(%rbp)\n";
    }

    return tmpAdr;
}

// Mult
//  movl	-12(%rbp), %eax
// 	imull	-8(%rbp), %eax

// Div
//  movl	-12(%rbp), %eax
// 	cltd
// 	idivl	-8(%rbp)
// 	movl	%eax, -4(%rbp)

// Mod
//  movl	-12(%rbp), %eax
// 	cltd
// 	idivl	-8(%rbp)
// 	movl	%edx, -4(%rbp)
antlrcpp::Any CodeGenVisitor::visitMultDivModExpr(ifccParser::MultDivModExprContext *ctx)
{
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->MULT_DIV_MOD()->getText();

    // Visit left and right expressions and get their adress in memory
    int lvalue = visit(left);
    int rvalue = visit(right);
    int tmpAdr;

    cout << "    movl " << lvalue << "(%rbp)"
         << ", %eax\n";

    if (op == "*")
    {
        cout << "    imull " << rvalue << "(%rbp)"
             << ", %eax\n";
        this->cur_pointer -= 4;
        tmpAdr = this->cur_pointer;
        cout << "    movl "
             << "%eax, " << tmpAdr << "(%rbp)\n";
        return tmpAdr;
    }
    else
    {
        cout << "    cltd" << endl;
        cout << "    idivl " << rvalue << "(%rbp)\n";

        this->cur_pointer -= 4;
        tmpAdr = this->cur_pointer;

        if (op == "/")
        {
            cout << "    movl "
                 << "%eax, " << tmpAdr << "(%rbp)\n";
        }
        else
        {
            cout << "    movl "
                 << "%edx, " << tmpAdr << "(%rbp)\n";
        }
    }
    return tmpAdr;
}
