#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    std::cout << ".globl main\n";
    std::cout << " main: \n";

    for (auto stmt : ctx->stmt())
    {
        visit(stmt);
    }
    this->visit(ctx->return_stmt());

    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{

    string typeName = ctx->type()->getText();
    string id = ctx->ID()->getText();
    Type *type = new Type(typeName);
    //auto expr = visitChildren(ctx);
    if (ctx->expr() != nullptr){
        cout<<"movl " ; 
        auto expr = visitChildren(ctx);
        
        cout << this->adrTable[id].index << "(%rbp)"<<endl ;
    }
    return 0;
    // return new VarDecl(id, type, nullptr);
}

antlrcpp::Any CodeGenVisitor::visitVar_ass(ifccParser::Var_assContext *ctx)
{
    cout<<"movl " ; 
    auto expr = visitChildren(ctx);
    string name = ctx->ID()->getText();
    cout << this->adrTable[name].index << "(%rbp) " <<endl ;
    
    return 0;
    // return new VarDecl(id, type, nullptr);
}




/*
antlrcpp::Any CodeGenVisitor::visitReturnVar(ifccParser::ReturnVarContext *ctx)
{
    string name = ctx->ID()->getText();
    cout << "    movl ";
    cout << this->adrTable[name].index << "(%rbp) ";
    cout << ", %eax\n";

    return ReturnStmt(ctx->start->getLine());
}*/


/*antlrcpp::Any CodeGenVisitor::visitReturnExp(ifccParser::ReturnExpContext *ctx)
{

    if (ctx->expr())
    {
        cout << "    movl ";
        visit(ctx->expr());
        cout << ", %eax\n";
    }

    return ReturnStmt(ctx->start->getLine());
}*/

//  movl	-12(%rbp), %edx
// 	movl	-8(%rbp), %eax
// 	addl	%edx, %eax
antlrcpp::Any CodeGenVisitor::visitAddSubExpr(ifccParser::AddSubExprContext *ctx)
{
    auto left = ctx->expr(0);
    auto right = ctx->expr(1);
    string op = ctx->ADD_SUB()->getText();

    cout << "    movl ";
    visit(left);
    cout << ", %edx\n";

    cout << "    movl ";
    visit(right);
    cout << ", %eax\n";

    if (op == "+")
    {
        cout << "    addl ";
    }
    else if (op == "-")
    {
        cout << "    subl ";
    }

    cout << "%edx, %eax" << endl;
    return 0;
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

    cout << "    movl ";
    visit(left);
    cout << ", %eax\n";

    if (op == "*")
    {
        cout << "    imull ";
        visit(right);
        cout << ", %eax\n";
    }
    else
    {
        cout << "    cltd" << endl;
        cout << "    idivl ";
        visit(right);
        cout << "\n";
        cout << "    movl ";
        if (op == "/")
        {
            cout << ", %eax, [to be filled]\n";
        }
        else
        {
            cout << ", %edx, [to be filled]\n";
        }
    }
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    int value = stoi(ctx->INT_CONST()->getText());
    cout << "$" << value << " ";
    return (Expr *)(new IntConst(value, ctx->start->getLine()));
}

// movl	-4(%rbp), %eax
antlrcpp::Any CodeGenVisitor::visitVar(ifccParser::VarContext *ctx)
{
    string name = ctx->ID()->getText();
    cout << this->adrTable[name].index << "(%rbp)";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    char value = ctx->CHAR_CONST()->getText()[1];
    // cout << "Char Const: " << value << endl;
    return (Expr *)(new CharConst(value, ctx->start->getLine()));
}

/*antlrcpp::Any CodeGenVisitor::visitVarAss(ifccParser::VarAssContext *ctx)
{
    string name1 = ctx->ID(0)->getText();
    string name2 = ctx->ID(1)->getText();
    cout << "    movl ";
    cout << this->adrTable[name2].index << "(%rbp) ";
    cout << this->adrTable[name1].index << "(%rbp) " << endl;
    return 0;
}*/


/*antlrcpp::Any CodeGenVisitor::visitExprAss(ifccParser::ExprAssContext *ctx)
{
    auto left = ctx->expr();
    auto var = ctx->ID()->getText();
    return 0 ; 
}
*/
