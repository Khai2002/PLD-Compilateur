#include "IR.h" // Assuming the header file is named IR.h
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

using namespace std;

// Assuming the other headers are included in the IR.h file

// ======= IRInstr ================================================================================================

// Method implementation for gen_asm

void IRInstr::gen_asm_arm64(ostream &o)
{
    cout << "Using arm64..." << endl;
}

void IRInstr::print_IRInstr()
{

    cout << operationToString(this->op) << " < params = ";
    for (auto it = params.begin(); it != params.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << " >" << endl;
}

string IRInstr::operationToString(Operation op)
{
    switch (op)
    {
    case ldconst:
        return "ldconst";
    case copy:
        return "copy";
    case add:
        return "add";
    case sub:
        return "sub";
    case mul:
        return "mul";
    case div:
        return "div";
    case bit_or:
        return "bit_or";
    case bit_and:
        return "bit_and";
    case bit_xor:
        return "bit_xor";
    case eq:
        return "eq";
    case neq:
        return "neq";
    case lt:
        return "lt";
    case gt:
        return "gt";
    case neg:
        return "neg";
    case unary_not:
        return "unary_not";
    case ret:
        return "ret";
    case rmem:
        return "rmem";
    case wmem:
        return "wmem";
    case call:
        return "call";
    case putchar:
        return "putchar";
    case getchar:
        return "getchar";
    case InsertParam:
        return "InsertParam";
    case CallParam:
        return "CallParam";
    default:
        return "Unknown Operation";
    }
}

// ==============================================================================================================

// ============ Subclasses of IRInstr ============================================================================

void IRInstrConst::gen_asm(ostream &o)
{
    int indexDest = this->bb->cfg->get_var_index(params[0]);
    o << "movq  $" << params[1] << "," << indexDest << "(%rbp)" << endl;
}

void IRInstrCopy::gen_asm(ostream &o)
{

    int indexLvalue = bb->cfg->get_var_index(params[0]);
    int indexRValue = bb->cfg->get_var_index(params[1]);
    o << "movq " << indexRValue << "(%rbp), %rax" << endl;
    o << "movq %rax, " << indexLvalue << "(%rbp)" << endl;
}

void IRInstrAdd::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "addq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrSub::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);
    o << "movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "subq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrMul::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);
    o << "movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "imulq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrDiv::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cltd" << endl;
    o << "idivl " << indexParam2 << "(%rbp)" << endl;
    o << "movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrMod::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cltd" << endl;
    o << "idivl " << indexParam2 << "(%rbp)" << endl;
    o << "movq %rdx, " << indexDest << "(%rbp)" << endl;
}

void IRInstrOr::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    orq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrAnd::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    andq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrXor::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    xorq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrEq::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cmpq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    sete %al" << endl;
    o << "    movzbq %al, %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrNeq::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cmpq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    setne %al" << endl;
    o << "    movzbq %al, %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrLt::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cmpq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    setl %al" << endl;
    o << "    movzbq %al, %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrGt::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "    movq " << indexParam1 << "(%rbp), %rax" << endl;
    o << "    cmpq " << indexParam2 << "(%rbp), %rax" << endl;
    o << "    setg %al" << endl;
    o << "    movzbq %al, %rax" << endl;
    o << "    movq %rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrNeg::gen_asm(ostream &o)
{
    int indexParam = bb->cfg->get_var_index(params[0]);
    int indexDest = bb->cfg->get_var_index(params[1]);

    o << "    negq " << indexParam << "(%rbp)" << endl;
    o << "    movq " << indexParam << "(%rbp), %rax" << endl;
    o << "    movq "
      << "%rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrNot::gen_asm(ostream &o)
{
    int indexParam = bb->cfg->get_var_index(params[0]);
    int indexDest = bb->cfg->get_var_index(params[1]);

    o << "    cmpl $0, " << indexParam << "(%rbp)" << endl;
    o << "    sete %al" << endl;
    o << "    movzbq %al, %rax" << endl;
    o << "    movq "
      << "%rax, " << indexDest << "(%rbp)" << endl;
}

void IRInstrRet::gen_asm(ostream &o)
{
    int indexDest = bb->cfg->get_var_index(params[0]);
    o << "movq " << indexDest << "(%rbp), %rax" << endl;
    o << "leave" << endl;
    o << "ret" << endl;
}

void IRInstrJumpCond::gen_asm(ostream &o)
{
    // cmpl	$0, -4(%rbp)
    // je	.L2
    // movl	$4, -4(%rbp)
    // jmp	.L3
    int indexCond = bb->cfg->get_var_index(params[0]);
    string trueBBLabel = params[1];
    string falseBBLabel = params[2];

    o << "cmpq $0, " << indexCond << "(%rbp)" << endl;
    o << "je ." << falseBBLabel << endl;
    o << "jmp ." << trueBBLabel << endl;
}

void IRInstrPutChar::gen_asm(ostream &o)
{
    // movl	%eax, %edi
    // call	putchar@PLT
    // movl	$0, %eax
    // leave
    int param = bb->cfg->get_var_index(params[0]);
    o << "movq " << param << "(%rbp), %rax" << endl;
    o << "movq %rax, %rdi" << endl;
    o << "call putchar@PLT" << endl;
}

void IRInstrGetchar::gen_asm(ostream &o)
{
    // call	getchar@PLT
    // movb	%al, -9(%rbp)
    // movsbl	-9(%rbp), %eax

    int param = bb->cfg->get_var_index(params[0]);

    o << "call getchar@PLT" << endl;
    o << "movb %al," << param << "(%rbp)" << endl;
    o << "movsbq " << param << "(%rbp),"
      << "%rax" << endl;
    o << "movq %rax , " << param << "(%rbp)" << endl;
}

void IRInstrCallFunc::gen_asm(ostream &o)
{
    string func_name = params[0];
    int param = bb->cfg->get_var_index(params[1]);
    string return_type = params[2];
    o << "call " << func_name << endl;
    if (return_type == "int" || return_type == "char")
    {
        o << "movq %rax, " << param << "(%rbp)" << endl;
    }
}

void IRInstrInsertParam::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int param_num = stoi(params[1]);

    o << "movq " << this->registers_name[param_num - 1] << " , " << indexParam1 << "(%rbp)" << endl;
}
void IRInstrCallParam::gen_asm(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int param_num = stoi(params[1]);

    o << "movq " << indexParam1 << "(%rbp) , " << this->registers_name[param_num] << endl;
}

void IRInstrConst::gen_asm_arm64(ostream &o)
{
    int indexDest = this->bb->cfg->get_var_index(params[0]);
    o << "mov w8, #" << params[1] << endl; // Use a temporary register, e.g., w8
    o << "str w8, [sp, #" << -indexDest << "]" << endl;
}

void IRInstrCopy::gen_asm_arm64(ostream &o)
{
    int indexLvalue = bb->cfg->get_var_index(params[0]);
    int indexRValue = bb->cfg->get_var_index(params[1]);
    o << "ldr w8, [sp, #" << -indexRValue << "]" << endl; // Load from stack to w8
    o << "str w8, [sp, #" << -indexLvalue << "]" << endl; // Store in stack
}

void IRInstrAdd::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "add w8, w8, w9" << endl;                      // Add w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrSub::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "sub w8, w8, w9" << endl;                      // Sub w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrMul::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "mul w8, w8, w9" << endl;                      // Multiply w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrDiv::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "sdiv w8, w8, w9" << endl;                     // Divide w8 by w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrMod::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    // Load the first parameter
    o << "ldr w8, [sp," << -indexParam1 << "]" << endl;

    // Load the second parameter
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl;

    // Perform signed division, quotient in w10
    o << "sdiv w10, w8, w9" << endl;

    // Multiply quotient with divisor, result in w11
    o << "mul w11, w10, w9" << endl;

    // Subtract to get the remainder, result in w8
    o << "sub w8, w8, w11" << endl;

    // Store the result
    o << "str w8, [sp," << -indexDest << "]" << endl;
}

void IRInstrOr::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "orr w8, w8, w9" << endl;                      // Bitwise or w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrAnd::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "and w8, w8, w9" << endl;                      // Bitwise and w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrXor::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "eor w8, w8, w9" << endl;                      // Bitwise xor w8 and w9, store result in w8
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrEq::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "cmp w8, w9" << endl;                          // Compare w8 and w9
    o << "cset w8, eq" << endl;                         // Set w8 to 1 if equal, 0 otherwise
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrNeq::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "cmp w8, w9" << endl;                          // Compare w8 and w9
    o << "cset w8, ne" << endl;                         // Set w8 to 1 if not equal, 0 otherwise
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrLt::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "cmp w8, w9" << endl;                          // Compare w8 and w9
    o << "cset w8, lt" << endl;                         // Set w8 to 1 if less than, 0 otherwise
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrGt::gen_asm_arm64(ostream &o)
{
    int indexParam1 = bb->cfg->get_var_index(params[0]);
    int indexParam2 = bb->cfg->get_var_index(params[1]);
    int indexDest = bb->cfg->get_var_index(params[2]);

    o << "ldr w8, [sp," << -indexParam1 << "]" << endl; // Load first param
    o << "ldr w9, [sp," << -indexParam2 << "]" << endl; // Load second param
    o << "cmp w8, w9" << endl;                          // Compare w8 and w9
    o << "cset w8, gt" << endl;                         // Set w8 to 1 if greater than, 0 otherwise
    o << "str w8, [sp," << -indexDest << "]" << endl;   // Store result
}

void IRInstrNeg::gen_asm_arm64(ostream &o)
{
    int indexParam = bb->cfg->get_var_index(params[0]);
    int indexDest = bb->cfg->get_var_index(params[1]);

    // Load the parameter value into a register
    o << "    ldr w8, [sp, #" << -indexParam << "]" << endl;

    // Negate the value in the register
    o << "    neg w8, w8" << endl;

    // Store the result back to the destination on the stack
    o << "    str w8, [sp, #" << -indexDest << "]" << endl;
}

void IRInstrNot::gen_asm_arm64(ostream &o)
{
    int indexParam = bb->cfg->get_var_index(params[0]);
    int indexDest = bb->cfg->get_var_index(params[1]);

    o << "ldr w8, [sp, #" << -indexParam << "]" << endl;
    o << "cmp w8, #0" << endl;
    o << "cset w8, eq" << endl;
    o << "str w8, [sp, #" << -indexDest << "]" << endl;
}

void IRInstrRet::gen_asm_arm64(ostream &o)
{

    int indexDest = bb->cfg->get_var_index(params[0]);
    o << "ldr w0, [sp, #" << -indexDest << "]" << endl;
}


void IRInstrJumpCond::gen_asm_arm64(ostream &o) {

    int indexCond = bb->cfg->get_var_index(params[0]);
    string trueBBLabel = params[1];
    string falseBBLabel = params[2];

    o << "ldr w8, [sp, #" << - indexCond << "]" << endl;
    o << "cmp w8, #0" << endl;
    o << "beq " << falseBBLabel << endl;
    o << "b " << trueBBLabel << endl;
}

void IRInstrPutChar::gen_asm_arm64(ostream &o)
{

    int param = bb->cfg->get_var_index(params[0]);
    o << "ldr w0, [sp, #" << -param << "]" << endl;
    o << "bl putchar" << endl;
    o << "ldr w0, #0" << endl;
}




// ======== BasicBlock ==========================================================================================

// Constructor
BasicBlock::BasicBlock(CFG *cfg, string entry_label) : cfg(cfg), label(entry_label) {}

// Method implementation for gen_asm
void BasicBlock::gen_asm(ostream &o)
{
    // Very simple assembly code generation for this basic block
    // This is a placeholder implementation. Actual implementation will depend on your specific requirements.
    if (label == cfg->getFuncName())
    {
        cfg->gen_asm_prologue(o);
    }
    else
    {
        o << "\n." << label << ":\n\n";
    }
    for (IRInstr *instr : instrs)
    {
        instr->gen_asm(o);
    }

    if (this->exit_true && !this->exit_false)
    {
        o << "jmp ." << this->exit_true->label << endl;
    }

    if (!(this->exit_true || this->exit_false))
    {
        cfg->gen_asm_epilogue(o);
    }
}

void BasicBlock::gen_asm_arm64(ostream &o)
{
    // Check if the label is for the main function
    if (label == "main")
    {
        // For the main function, prepend with an underscore
        o << "_main:\n";
    }
    else
    {
        // For other functions or blocks, use the label as is
        o << label << ":\n";
    }

    // Generate the prologue for the main function only
    if (label == cfg->getFuncName() && label == "main")
    {
        cfg->gen_asm_prologue_arm64(o); // Generate ARM64 specific prologue for main
    }

    // Generate ARM64 assembly for each instruction in the basic block
    for (IRInstr *instr : instrs)
    {
        instr->gen_asm_arm64(o); // Each instruction generates ARM64 code
    }

    // Generate the epilogue if there are no exit branches
    if (!(this->exit_true && this->exit_false))
    {
        cfg->gen_asm_epilogue_arm64(o); // Generate ARM64 specific epilogue
    }
}

// Method implementation for add_IRInstr
void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params)
{
    // Create a new IRInstr and add it to the instrs vector
    IRInstr *newInstr;
    switch (op)
    {

    case IRInstr::Operation::ldconst:
        newInstr = new IRInstrConst(this, op, t, params);
        break;
    case IRInstr::Operation::copy:
        newInstr = new IRInstrCopy(this, op, t, params);
        break;
    case IRInstr::Operation::add:
        newInstr = new IRInstrAdd(this, op, t, params);
        break;
    case IRInstr::Operation::sub:
        newInstr = new IRInstrSub(this, op, t, params);
        break;
    case IRInstr::Operation::mul:
        newInstr = new IRInstrMul(this, op, t, params);
        break;
    case IRInstr::Operation::div:
        newInstr = new IRInstrDiv(this, op, t, params);
        break;
    case IRInstr::Operation::mod:
        newInstr = new IRInstrMod(this, op, t, params);
        break;
    case IRInstr::Operation::bit_or:
        newInstr = new IRInstrOr(this, op, t, params);
        break;
    case IRInstr::Operation::bit_and:
        newInstr = new IRInstrAnd(this, op, t, params);
        break;
    case IRInstr::Operation::bit_xor:
        newInstr = new IRInstrXor(this, op, t, params);
        break;
    case IRInstr::Operation::eq:
        newInstr = new IRInstrEq(this, op, t, params);
        break;
    case IRInstr::Operation::neq:
        newInstr = new IRInstrNeq(this, op, t, params);
        break;
    case IRInstr::Operation::lt:
        newInstr = new IRInstrLt(this, op, t, params);
        break;
    case IRInstr::Operation::gt:
        newInstr = new IRInstrGt(this, op, t, params);
        break;
    case IRInstr::Operation::neg:
        newInstr = new IRInstrNeg(this, op, t, params);
        break;
    case IRInstr::Operation::unary_not:
        newInstr = new IRInstrNot(this, op, t, params);
        break;
    case IRInstr::Operation::ret:
        newInstr = new IRInstrRet(this, op, t, params);
        break;
    case IRInstr::Operation::jmp_cond:
        newInstr = new IRInstrJumpCond(this, op, t, params);
        break;
    case IRInstr::Operation::putchar:
        newInstr = new IRInstrPutChar(this, op, t, params);
        break;
    case IRInstr::Operation::getchar:
        newInstr = new IRInstrGetchar(this, op, t, params);
        break;
    case IRInstr::Operation::call:
        newInstr = new IRInstrCallFunc(this, op, t, params);
        break;
    case IRInstr::Operation::InsertParam:
        newInstr = new IRInstrInsertParam(this, op, t, params);
        break;
    case IRInstr::Operation::CallParam:
        newInstr = new IRInstrCallParam(this, op, t, params);
        break;
    }

    // newInstr = new IRInstr(this, op, t, params); // Assuming IRInstr constructor takes BasicBlock* as first argument

    instrs.push_back(newInstr);
}

void BasicBlock::printBB()
{
    // Create a new IRInstr and add it to the instrs vector
    cout << "BB Name: " << label << endl;
    for (IRInstr *instr : instrs)
    {
        if (instr != nullptr)
        {
            cout << "   ";
            instr->print_IRInstr();
        }
    }
}

// ==============================================================================================================

// ========= CFG ================================================================================================

// Cosntructor

CFG::CFG(string funcName) : funcName(funcName), nextFreeSymbolIndex(-8), nextBBnumber(0)
{
    auto firstBB = new BasicBlock(this, funcName);
    add_bb(firstBB);

    auto lastBB = new BasicBlock(this, new_BB_name());
    add_bb(lastBB);

    firstBB->exit_false = nullptr;
    firstBB->exit_true = lastBB;

    lastBB->exit_false = nullptr;
    lastBB->exit_true = nullptr;

    current_bb = firstBB;
}

// Method implementation for add_bb
void CFG::add_bb(BasicBlock *bb)
{
    bbs.push_back(bb);
    // Optionally, set the current_bb to the newly added bb if needed
    current_bb = bb;
}

// Method implementation for gen_asm
void CFG::gen_asm(ostream &o, string name)
{
    // Placeholder for x86 code generation
    // This method should generate assembly code for the entire CFG
    // Actual implementation will depend on your specific requirements
    if (name == "main")
    {
        o << ".globl main\n";
    }

    for (auto bb : bbs)
    {
        bb->gen_asm(o);
    }
}

void CFG::gen_asm_arm64(ostream &o)
{
    // Placeholder for ARM64 code generation
    // This method should generate ARM64 assembly code for the entire CFG
    // Actual implementation will depend on your specific requirements
    o << ".globl _main\n";

    for (auto bb : bbs)
    {
        bb->gen_asm_arm64(o);
    }
}

// Method implementation for IR_reg_to_asm
string CFG::IR_reg_to_asm(string reg)
{
    // Placeholder for converting IR register to assembly register
    // Actual implementation will depend on your specific requirements
    return "-24(%rbp)"; // Example return value
}

// Method implementation for gen_asm_prologue
void CFG::gen_asm_prologue(ostream &o)
{
    // Placeholder for generating assembly code prologue
    // Actual implementation will depend on your specific requirements
    int alloc_size = nextFreeSymbolIndex;
    /*for (auto var : this->SymbolType)
    {
        alloc_size += get_type_size(var.second);
    }*/

    if (nextFreeSymbolIndex % 16 != 0)
    {
        alloc_size = nextFreeSymbolIndex + 8;
    }
    // alloc_size += 16 - (alloc_size % 16);
    o << this->funcName << ":" << endl
      << endl;

    o << "pushq  %rbp" << endl;
    o << "movq  %rsp, %rbp" << endl;
    o << "subq  $" << -alloc_size << ", %rsp" << endl;
    // o << endl;
}

// Method implementation for gen_asm_epilogue
void CFG::gen_asm_epilogue(ostream &o)
{
    // Placeholder for generating assembly code epilogue
    // Actual implementation will depend on your specific requirements
    // o << endl;
    o << "leave" << endl;
    o << "ret" << endl;
}

void CFG::gen_asm_prologue_arm64(ostream &o)
{
    // Placeholder for generating ARM64 specific prologue
    // Actual implementation will depend on your specific requirements
    // o << "nextFreeSymbolIndex" << nextFreeSymbolIndex << endl;
    int alloc_size;
    if (nextFreeSymbolIndex % 16 == 0)
    {
        alloc_size = -nextFreeSymbolIndex;
    }
    else
    {
        alloc_size = -nextFreeSymbolIndex + 8;
    }
    o << "sub sp, sp, #" << alloc_size << endl;
    o << "str wzr, [sp, #" << alloc_size - 4 << "]" << endl;
    o << endl;
}

void CFG::gen_asm_epilogue_arm64(ostream &o)
{

    int alloc_size;
    if (nextFreeSymbolIndex % 16 == 0)
    {
        alloc_size = -nextFreeSymbolIndex;
    }
    else
    {
        alloc_size = -nextFreeSymbolIndex + 8;
    }

    o << endl;
    o << "";
    o << "add sp, sp, #" << alloc_size << endl;
    o << "ret" << endl;
}

// Method implementation for add_to_symbol_table
void CFG::add_to_symbol_table(string name, Type t)
{
    SymbolType[name] = t;
    SymbolIndex[name] = nextFreeSymbolIndex;
    nextFreeSymbolIndex -= get_type_size(t);
}

// Method implementation for create_new_tempvar
string CFG::create_new_tempvar(Type t)
{
    string tempName = "temp" + to_string(-nextFreeSymbolIndex);
    add_to_symbol_table(tempName, t);
    return tempName;
}

// Method implementation for get_var_index
int CFG::get_var_index(string name)
{
    if (SymbolIndex.find(name) != SymbolIndex.end())
    {
        return SymbolIndex[name];
    }
    return -1; // Return -1 if the variable is not found
}

// Method implementation for get_var_type
Type CFG::get_var_type(string name)
{
    if (SymbolType.find(name) != SymbolType.end())
    {
        return SymbolType[name];
    }
    return Type(); // Return default Type if the variable is not found
}

int CFG::get_type_size(Type type)
{
    switch (type.getType())
    {
    case Type::TypeEnum::INT:
        return 8;
    case Type::TypeEnum::CHAR:
        return 8;
    case Type::TypeEnum::VOID:
        return 0;
    }
    return 8;
}

void CFG::printCFG()
{
    cout << "Print of every Basic Block : " << endl;
    for (BasicBlock *BB : bbs)
    {
        if (BB != nullptr)
        {
            BB->printBB();
        }
    }
}

// Method implementation for new_BB_name
string CFG::new_BB_name()
{
    return getFuncName() + to_string(nextBBnumber++);
}

// ==============================================================================================================