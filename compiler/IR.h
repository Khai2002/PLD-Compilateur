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
	IRInstr(BasicBlock *bb, Operation op, Type t, vector<string> params) : bb(bb), op(op), t(t), params(params){};

	/** Actual code generation */

	// virtual void gen_asm(ostream &o); /**< x86 assembly code generation for this IR instruction */
	virtual void gen_asm_arm64(ostream &o); /**< ARM64 assembly code generation for this IR instruction */

	virtual void gen_asm(ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */

	void print_IRInstr();

protected:
	BasicBlock *bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	Operation op;
	Type t;
	vector<string> params; /**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
						   // if you subclass IRInstr, each IRInstr subclass has its parameters and the previous (very important) comment becomes useless: it would be a better design.
};

class IRInstrConst : public IRInstr
{
public:
	IRInstrConst(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrCopy : public IRInstr
{
public:
	IRInstrCopy(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrAdd : public IRInstr
{
public:
	IRInstrAdd(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrSub : public IRInstr
{
public:
	IRInstrSub(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrMul : public IRInstr
{
public:
	IRInstrMul(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrDiv : public IRInstr
{
public:
	IRInstrDiv(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrMod : public IRInstr
{
public:
	IRInstrMod(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrOr : public IRInstr
{
public:
	IRInstrOr(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrAnd : public IRInstr
{
public:
	IRInstrAnd(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrXor : public IRInstr
{
public:
	IRInstrXor(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrEq : public IRInstr
{
public:
	IRInstrEq(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrNeq : public IRInstr
{
public:
	IRInstrNeq(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrLt : public IRInstr
{
public:
	IRInstrLt(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrGt : public IRInstr
{
public:
	IRInstrGt(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrNeg : public IRInstr
{
public:
	IRInstrNeg(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrNot : public IRInstr
{
public:
	IRInstrNot(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrRet : public IRInstr
{
public:
	IRInstrRet(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrJumpCond : public IRInstr
{
public:
	IRInstrJumpCond(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	void gen_asm_arm64(ostream &o) override;
};

class IRInstrPutChar : public IRInstr
{
public:
	IRInstrPutChar(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
};

class IRInstrGetchar : public IRInstr
{
public:
	IRInstrGetchar(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
};

class IRInstrCallFunc : public IRInstr
{
public:
	IRInstrCallFunc(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
};

class IRInstrPostIncr : public IRInstr
{
public:
	IRInstrPostIncr(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
};

class IRInstrPostDecr : public IRInstr
{
public:
	IRInstrPostDecr(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
};

class IRInstrInsertParam : public IRInstr
{
public:
	IRInstrInsertParam(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	vector<string> registers_name = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
};

class IRInstrCallParam : public IRInstr
{
public:
	IRInstrCallParam(BasicBlock *bb, Operation op, Type t, vector<string> params) : IRInstr(bb, op, t, params){};
	void gen_asm(ostream &o) override;
	vector<string> registers_name = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
};
/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions.
	 cmp_* instructions behaves as an arithmetic two-operand instruction (add or mult),
	  returning a boolean value (as an int)

	 Assembly jumps are generated as follows:
	 BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then
			if  exit_true  is a  nullptr,
			the epilogue is generated
		else if exit_false is a nullptr,
		  an unconditional jmp to the exit_true branch is generated
				else (we have two successors, hence a branch)
		  an instruction comparing the value of test_var_name to true is generated,
					followed by a conditional branch to the exit_false branch,
					followed by an unconditional branch to the exit_true branch
	 The attribute test_var_name itself is defined when converting
  the if, while, etc of the AST  to IR.

Possible optimization:
	 a cmp_* comparison instructions, if it is the last instruction of its block,
	   generates an actual assembly comparison
	   followed by a conditional jump to the exit_false branch
*/

class BasicBlock
{
public:
	BasicBlock(CFG *cfg, string entry_label);
	void gen_asm(ostream &o);		/**< x86 assembly code generation for this basic block (very simple) */
	void gen_asm_arm64(ostream &o); /**< ARM64 assembly code generation for this basic block (very simple) */
	void add_IRInstr(IRInstr::Operation op, Type t, vector<string> params);
	void printBB();
	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock *exit_true;	  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
	BasicBlock *exit_false;	  /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
	string label;			  /**< label of the BB, also will be the label in the generated code */
	CFG *cfg;				  /** < the CFG where this block belongs */
	vector<IRInstr *> instrs; /** < the instructions themselves. */
	string test_var_name;	  /** < when generating IR code for an if(expr) or while(expr) etc,
														store here the name of the variable that holds the value of expr */
protected:
};

/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
	 (again it could be identified in a more explicit way)

 */
class CFG
{
public:
	CFG(string funcName);

	void add_bb(BasicBlock *bb);

	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler

	void gen_asm(ostream &o);
	void gen_asm_arm64(ostream &o);

	void gen_asm(ostream &o, string name);

	string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
	void gen_asm_prologue(ostream &o);
	void gen_asm_epilogue(ostream &o);

	void gen_asm_prologue_arm64(ostream &o);
	void gen_asm_epilogue_arm64(ostream &o);

	// symbol table methods
	void add_to_symbol_table(string name, Type t);
	string create_new_tempvar(Type t);
	int get_var_index(string name);
	Type get_var_type(string name);
	int get_type_size(Type type);

	map<string, Type> getSymbolType() { return SymbolType; }
	map<string, int> getSymbolIndex() { return SymbolIndex; }
	int getNextFreeSymbolIndex() { return nextFreeSymbolIndex; }
	int getBBNumber() { return nextBBnumber; }
	string getFuncName() { return funcName; }
	void printCFG(); // function for debugging

	// basic block management
	string new_BB_name();
	BasicBlock *current_bb;

protected:
	map<string, Type> SymbolType; /**< part of the symbol table  */
	map<string, int> SymbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex;	  /**< to allocate new symbols in the symbol table */
	int nextBBnumber;			  /**< just for naming */
	string funcName;

	vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
};

#endif