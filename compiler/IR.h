#ifndef IR_H
#define IR_H

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
#include <map>
#include "util.h"

using namespace std;

// Declarations from the parser -- replace with your own
// #include "symbole.h"

class BasicBlock;
class CFG;
class DefFonction;

//! The class for one 3-address instruction
class IRInstr
{

public:
	/** The instructions themselves -- feel free to subclass instead */
	typedef enum
	{
		ldconst,
		copy,
		add,
		sub,
		mul,
		div,
		mod,
		bit_or,
		bit_and,
		bit_xor,
		eq,
		neq,
		lt,
		gt,
		neg,
		unary_not,
		PostIncr,
		PostDecr,
		PreIncr,
		PreDecr,
		postIncr,
		putchar,
		getchar,
		InsertParam, // For inserting the params when defining a function
		CallParam,	 // for instanciating the params in the right register before jumping to the function
		rmem,
		wmem,
		call,
		cmp_eq,
		cmp_lt,
		cmp_le,
		ret,
		jmp_cond
	} Operation;

	string operationToString(Operation op);

	/**  constructor */
	IRInstr(BasicBlock *bb, Operation op, vector<string> params) : bb(bb), op(op), params(params){};

	/** Actual code generation */

	/**
	 * Function to generate the assembly code for the IR instruction in ARM64
	 * @param o The output stream to write the assembly code to
	 */
	virtual void gen_asm_arm64(ostream &o); /**< ARM64 assembly code generation for this IR instruction */

	/**
	 * Function to generate the assembly code for the IR instruction
	 * @param o The output stream to write the assembly code to
	 */
	virtual void gen_asm(ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */

	/**
	 * Function to print the IR instruction
	 */
	void print_IRInstr();

	/**
	 * Function to get the string value of the given parameter
	 * @param s The string to get the value of
	 * @return The value of the string
	 */
	string getValueString(string s);

	/**
	 * Function to get the string value of the given parameter in ARM64
	 * @param s The string to get the value of
	 * @return The value of the string
	 */
	string getValueString_arm64(string s);

	/**
	 * Function to get the operation object of the IR instruction
	 * @return The operation object of the IR instruction
	 */
	Operation getOperation() { return op; }

protected:
	BasicBlock *bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Operation op;
	Type t;
	vector<string> params; /**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
						   // if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design.
};

/**
 * @class IRInstrConst
 * @brief Represents a constant value instruction in the IR.
 *
 * This instruction is used to load a constant value into a register.
 */
class IRInstrConst : public IRInstr
{
public:
	IRInstrConst(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrCopy
 * @brief Represents a copy instruction in the IR.
 *
 * This instruction is used to copy the value from one register to another.
 */
class IRInstrCopy : public IRInstr
{
public:
	IRInstrCopy(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrAdd
 * @brief Represents an addition instruction in the IR.
 *
 * This instruction is used to perform addition between two operands.
 */
class IRInstrAdd : public IRInstr
{
public:
	IRInstrAdd(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrSub
 * @brief Represents a subtraction instruction in the IR.
 *
 * This instruction is used to perform subtraction between two operands.
 */
class IRInstrSub : public IRInstr
{
public:
	IRInstrSub(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrMul
 * @brief Represents a multiplication instruction in the IR.
 *
 * This instruction is used to perform multiplication between two operands.
 */
class IRInstrMul : public IRInstr
{
public:
	IRInstrMul(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrDiv
 * @brief Represents a division instruction in the IR.
 *
 * This instruction is used to perform division between two operands.
 */
class IRInstrDiv : public IRInstr
{
public:
	IRInstrDiv(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrMod
 * @brief Represents a modulus instruction in the IR.
 *
 * This instruction is used to calculate the remainder of a division operation.
 */
class IRInstrMod : public IRInstr
{
public:
	IRInstrMod(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrOr
 * @brief Represents a bitwise OR instruction in the IR.
 *
 * This instruction is used to perform a bitwise OR operation between two operands.
 */
class IRInstrOr : public IRInstr
{
public:
	IRInstrOr(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrAnd
 * @brief Represents a bitwise AND instruction in the IR.
 *
 * This instruction is used to perform a bitwise AND operation between two operands.
 */
class IRInstrAnd : public IRInstr
{
public:
	IRInstrAnd(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrXor
 * @brief Represents a bitwise XOR instruction in the IR.
 *
 * This instruction is used to perform a bitwise XOR operation between two operands.
 */
class IRInstrXor : public IRInstr
{
public:
	IRInstrXor(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrEq
 * @brief Represents an equality comparison instruction in the IR.
 *
 * This instruction is used to compare two operands for equality.
 */
class IRInstrEq : public IRInstr
{
public:
	IRInstrEq(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrNeq
 * @brief Represents a non-equality comparison instruction in the IR.
 *
 * This instruction is used to compare two operands for non-equality.
 */
class IRInstrNeq : public IRInstr
{
public:
	IRInstrNeq(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrLt
 * @brief Represents a less-than comparison instruction in the IR.
 *
 * This instruction is used to compare two operands to determine if one is less than the other.
 */
class IRInstrLt : public IRInstr
{
public:
	IRInstrLt(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrGt
 * @brief Represents a greater-than comparison instruction in the IR.
 *
 * This instruction is used to compare two operands to determine if one is greater than the other.
 */
class IRInstrGt : public IRInstr
{
public:
	IRInstrGt(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrNeg
 * @brief Represents a negation instruction in the IR.
 *
 * This instruction is used to negate the value of an operand.
 */
class IRInstrNeg : public IRInstr
{
public:
	IRInstrNeg(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrNot
 * @brief Represents a logical NOT instruction in the IR.
 *
 * This instruction is used to perform a logical NOT operation on an operand.
 */
class IRInstrNot : public IRInstr
{
public:
	IRInstrNot(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrRet
 * @brief Represents a return instruction in the IR.
 *
 * This instruction is used to return from a function.
 */
class IRInstrRet : public IRInstr
{
public:
	IRInstrRet(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrJumpCond
 * @brief Represents a conditional jump instruction in the IR.
 *
 * This instruction is used to conditionally jump to another basic block based on a condition.
 */
class IRInstrJumpCond : public IRInstr
{
public:
	IRInstrJumpCond(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrPutChar
 * @brief Represents a putchar instruction in the IR.
 *
 * This instruction is used to output a character to the standard output.
 */
class IRInstrPutChar : public IRInstr
{
public:
	IRInstrPutChar(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrGetchar
 * @brief Represents a getchar instruction in the IR.
 *
 * This instruction is used to read a character from the standard input.
 */
class IRInstrGetchar : public IRInstr
{
public:
	IRInstrGetchar(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrCallFunc
 * @brief Represents a function call instruction in the IR.
 *
 * This instruction is used to call a function with specified parameters.
 */
class IRInstrCallFunc : public IRInstr
{
public:
	IRInstrCallFunc(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrPostIncr
 * @brief Represents a post-increment instruction in the IR.
 *
 * This instruction is used to increment the value of an operand after its value has been used.
 */
class IRInstrPostIncr : public IRInstr
{
public:
	IRInstrPostIncr(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrPostDecr
 * @brief Represents a post-decrement instruction in the IR.
 *
 * This instruction is used to decrement the value of an operand after its value has been used.
 */
class IRInstrPostDecr : public IRInstr
{
public:
	IRInstrPostDecr(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

/**
 * @class IRInstrInsertParam
 * @brief Represents an instruction to insert a parameter into a function call in the IR.
 *
 * This instruction is used to prepare parameters for a function call by loading them into registers.
 */
class IRInstrInsertParam : public IRInstr
{
public:
	IRInstrInsertParam(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
	vector<string> registers_name = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
	vector<string> registers_name_arm64 = {"%x0", "%x1", "%x2", "%x3", "%x4", "%x5"};
};

/**
 * @class IRInstrCallParam
 * @brief Represents an instruction to call a function with parameters in the IR.
 *
 * This instruction is used to call a function with the parameters that have been prepared by previous instructions.
 */
class IRInstrCallParam : public IRInstr
{
public:
	IRInstrCallParam(BasicBlock *bb, Operation op, vector<string> params) : IRInstr(bb, op, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
	vector<string> registers_name = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
	vector<string> registers_name_arm64 = {"%x0", "%x1", "%x2", "%x3", "%x4", "%x5"};
};
/**
 * @class BasicBlock
 * @brief Handles the generation of assembly jumps within a basic block, without including jump instructions in IRInstr.
 *
 * @details
 *  - IRInstr lacks jump instructions.
 *  - cmp_* instructions act like arithmetic two-operand instructions (e.g., add, mult), returning an integer as a boolean value.
 *
 * Assembly Jumps Generation:
 *  - BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all instructions.
 *  - It then handles jump generation based on the exit points:
 *    1. If 'exit_true' is nullptr, it generates the epilogue.
 *    2. If 'exit_false' is nullptr, it creates an unconditional jump to 'exit_true'.
 *    3. For two successors, it compares 'test_var_name' to true, followed by a conditional jump to 'exit_false', and an unconditional jump to 'exit_true'.
 *  - The 'test_var_name' attribute is set during the conversion of if, while, etc., from AST to IR.
 *
 * Optimization:
 *  - A cmp_* instruction, if it's the last in its block, directly generates an assembly comparison and a conditional jump to 'exit_false'.
 */
class BasicBlock
{
public:
	BasicBlock(CFG *cfg, string entry_label);

	void gen_asm(ostream &o);										/**< x86 assembly code generation for this basic block (very simple) */
	void gen_asm_arm64(ostream &o);									/**< ARM64 assembly code generation for this basic block (very simple) */
	void add_IRInstr(IRInstr::Operation op, vector<string> params); // Add Intruction to BasicBlock
	void printBB();
	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock *exit_true;	  /**< pointer to the next basic blockrue branch. If nullptr, return from procedure */
	BasicBlock *exit_false;	  /**< pointer to the next basic block, false branch. If null_ptrhe basic block ends with an unconditional jump */
	string label;			  /**< label of the BB, also will be the label in the generated code */
	CFG *cfg;				  /** < the CFG where this block belongs */
	vector<IRInstr *> instrs; /** < the instructions themselves. */
	string test_var_name;	  /** < when generating IR code for an if(expr) or while(expr) etc,
														store here the name of the variable that holds the value of expr */

protected:
};
/**
 * @class ControlFlowGraph
 * @brief Represents the control flow graph of a program, incorporating the symbol table as well.
 *
 * @details
 *  - The Control Flow Graph (CFG) is a fundamental structure in the compilation process,
 *    mapping the flow of control between different blocks of code and also including symbol table management.
 *
 * Key Components:
 *  - Entry Block: Identified as the block with the same label as the AST function name. It can be the first in 'bbs'
 *    (basic blocks) or determined by a specific attribute value.
 *  - Exit Block: Recognized as the block where both exit pointers are nullptr. This can also be explicitly identified
 *    in other ways, depending on the implementation specifics.
 */
class CFG
{
public:
	CFG(string funcName);

	/**
	 * Function to add a new basic block to the CFG
	 * @param *bb The pointer to the basic block to add to the CFG
	 */
	void add_bb(BasicBlock *bb);

	/**
	 * Function to generate the x86 assembly code for the CFG
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm(ostream &o);

	/**
	 * Function to generate the ARM64 assembly code for the CFG
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm_arm64(ostream &o);

	/**
	 * Function to generate the assembly code for the CFG
	 * @param o The output stream to write the assembly code to
	 * @param name The name of the function to generate the assembly code for
	 */
	void gen_asm(ostream &o, string name);

	/**
	 * helper function that inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24
	 * @param reg The register to convert to assembly
	 */
	string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */

	/**
	 * Function to generate the prologue assembly code for the CFG in ARM64
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm_prologue(ostream &o); // Generate prologue for a CFG

	/**
	 * Function to generate the epilogue assembly code for the CFG in ARM64
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm_epilogue(ostream &o); // Generate epilogue for a CFG

	/**
	 * Function to generate the prologue assembly code for the CFG in ARM64
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm_prologue_arm64(ostream &o, bool hasCharOp); // Generate prologue for a CFG in ARM64

	/**
	 * Function to generate the epilogue assembly code for the CFG in ARM64
	 * @param o The output stream to write the assembly code to
	 */
	void gen_asm_epilogue_arm64(ostream &o, bool hasCharOp); // Generate epilogue for a CFG in ARM64

	/**
	 * Function to add a new variable to the symbol table
	 * @param name The name of the variable to add
	 * @param t The type of the variable to add
	 */
	void add_to_symbol_table(string name, Type t); // Add var <name> into SymbolType and SymbolIndex

	/**
	 * Function to create a new temporary variable for linearization
	 * @param t The type of the temporary variable to create
	 * @return The name of the temporary variable created
	 */
	string create_new_tempvar(Type t); // Create tempvar for linearization

	/**
	 * Function to get the index of a variable given its name
	 * @param name The name of the variable to get the index of
	 * @return The index of the variable
	 */
	int get_var_index(string name); // Get index given var name

	/**
	 * Function to get the type of a variable given its name
	 * @param name The name of the variable to get the type of
	 * @return The type of the variable
	 */
	Type get_var_type(string name); // Get type given var name

	/**
	 * Function to get the size of a type
	 * @param type The type to get the size of
	 * @return The size of the type
	 */
	int get_type_size(Type type); // Get type size

	/**
	 * Function to get the symbol type
	 * @return The symbol type as a map
	 */
	map<string, Type> getSymbolType() { return SymbolType; }

	/**
	 * Function to get the symbol index
	 * @return The symbol index as a map
	 */
	map<string, int> getSymbolIndex() { return SymbolIndex; }

	/**
	 * Function to get the next free symbol index
	 * @return The next free symbol index
	 */
	int getNextFreeSymbolIndex() { return nextFreeSymbolIndex; }

	/**
	 * Function to get the next basic block number
	 * @return The next basic block number
	 */
	int getBBNumber() { return nextBBnumber; }

	/**
	 * Function to get the function name
	 * @return The function name
	 */
	string getFuncName() { return funcName; }

	/**
	 * Function to get the return present
	 * @return The return present as bool
	 */
	bool getReturnPresent() { return ReturnPresent; }

	/**
	 * Function to change the return present to true
	 */
	void changeReturnPresent() { ReturnPresent = true; }

	/**
	 * Function to print the CFG for debugging
	 */
	void printCFG();

	/**
	 * Function to set the has char call operation to true
	 */
	void setHasCharCallOp() { hasCharCallOp = true; }

	/**
	 * Function to get the has char call operation
	 * @return The has char call operation as bool
	 */
	bool getHasCharCallOp() { return hasCharCallOp; }

	// basic block management
	string new_BB_name();
	BasicBlock *current_bb;

protected:
	map<string, Type> SymbolType; /**< part of the symbol table  */
	map<string, int> SymbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex;	  /**< to allocate new symbols in the symbol table */
	int nextBBnumber;			  /**< just for naming */
	string funcName;
	bool ReturnPresent = false;

	vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
	bool hasCharCallOp = false;
};

#endif