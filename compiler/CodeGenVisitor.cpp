#include "CodeGenVisitor.h"

using namespace std;

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx)
{   

    cout << ".global _main\n";
    cout << "_main:\n";
    cout << "sub sp, sp, #16\n";
    cout << "str	wzr, [sp, #12]\n";

    for (auto line : ctx->line())
    {
        visit(line);
    }
    this->visit(ctx->return_stmt());
    cout << "add sp, sp, #16\n";
    cout << "ret\n"; // Restore frame pointer and return
    
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitVar_decl(ifccParser::Var_declContext *ctx)
{

    string typeName = ctx->type()->getText();
    string name = ctx->ID()->getText();
    Type *type = new Type(typeName);
    if (ctx->expr())
    {
        int adr = any_cast<int>(visit(ctx->expr()));
        // Load the value from the stack to a register (e.g., w0)
        cout << "    ldr w0, [fp, #" << adr << "]" << endl; 
        // Store the value from the register to the variable's location
        cout << "    str w0, [fp, #" << this->adrTable[name].index << "]" << endl;
    }

    return 0;
    // return new VarDecl(id, type, nullptr);
}

antlrcpp::Any CodeGenVisitor::visitVar_ass(ifccParser::Var_assContext *ctx)
{
    // auto expr = visitChildren(ctx);
    string name = ctx->ID()->getText();
    int adr = any_cast<int>(visit(ctx->expr()));
    // Load the expression value into a register (e.g., w0)
    cout << "    ldr w0, [fp, #" << adr << "]" << endl; 
    // Store the value from the register into the variable's location
    cout << "    str w0, [fp, #" << this->adrTable[name].index << "]" << endl;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_stmt(ifccParser::Return_stmtContext *ctx)
{
    if (ctx->expr())
    {
        int value = any_cast<int>(visit(ctx->expr()));
        cout << "    ldr w0, [fp, #" << value << "]" << endl;
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitIntConst(ifccParser::IntConstContext *ctx)
{
    int value = stoi(ctx->INT_CONST()->getText());

    // Assign the IntConst to a tmp value in the memory
    this->cur_pointer -= 4;
    int tmpAdr = this->cur_pointer;
    cout << "    mov w0, #" << value << endl;  // Move the constant value into w0
    cout << "    str w0, [fp, #" << tmpAdr << "]" << endl;  // Store w0 at the stack location

    return tmpAdr;
}

antlrcpp::Any CodeGenVisitor::visitCharConst(ifccParser::CharConstContext *ctx)
{
    char value = ctx->CHAR_CONST()->getText()[1];

    // Assign the CharConst to a tmp value in the memory
    this->cur_pointer -= 4;
    int tmpAdr = this->cur_pointer;
    cout << "    mov w0, #" << value << endl;  // Move the constant value into w0
    cout << "    str w0, [fp, #" << tmpAdr << "]" << endl;  // Store w0 at the stack location

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

    // Visit left and right expressions and get their address in memory
    int lvalue = std::any_cast<int>(visit(left));
    int rvalue = std::any_cast<int>(visit(right));

    // Load the left and right values into registers
    cout << "    ldr r1, [fp, #" << lvalue << "]" << endl;
    cout << "    ldr r2, [fp, #" << rvalue << "]" << endl;

    // Perform addition or subtraction
    if (op == "+")
    {
        cout << "    add w0, r1, r2" << endl;
    }
    else if (op == "-")
    {
        cout << "    sub w0, r1, r2" << endl;
    }

    // Allocate space for result and store it
    this->cur_pointer -= 4; // Assuming 4 bytes for an int
    int tmpAdr = this->cur_pointer;
    cout << "    str w0, [fp, #" << tmpAdr << "]" << endl;

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

    // Visit left and right expressions and get their address in memory
    int lvalue = std::any_cast<int>(visit(left));
    int rvalue = std::any_cast<int>(visit(right));
    int tmpAdr;

    // Load left value into a register
    cout << "    ldr w0, [fp, #" << lvalue << "]" << endl;

    if (op == "*")
    {
        // Load right value into another register
        cout << "    ldr r1, [fp, #" << rvalue << "]" << endl;
        // Perform multiplication
        cout << "    mul w0, w0, r1" << endl;

        // Allocate space for result and store it
        this->cur_pointer -= 4; // Assuming 4 bytes for an int
        tmpAdr = this->cur_pointer;
        cout << "    str w0, [fp, #" << tmpAdr << "]" << endl;

        return tmpAdr;
    }
    else
    {
        // Handle division and modulus
        // This may involve subroutine calls or a series of instructions
        // specific to ARM architecture
    }

    return tmpAdr;
}





