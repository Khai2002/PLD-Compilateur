#include "IR.h" // Assuming the header file is named IR.h
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

using namespace std;

// Assuming the other headers are included in the IR.h file

// ======= IRInstr ================================================================================================

// Method implementation for gen_asm

void IRInstr::gen_asm(ostream &o) {
    // Since we're returning 0, we don't need to do anything
    int indDest;
    int indParam1;
    int indParam2;

    
    switch(this->op) {
        case ldconst:
        /*
            movq	 $8, -4(%rbp)
        */
            


            cout << "Loading constant.\n";
            break;
        case copy:
        /*
            movq	-8(%rbp), %rax
	        movq	%rax, -4(%rbp)
        */
            cout << "Copying value.\n";
            break;
        case add:
        /*
            movq	[param1], %rdx
            movq	[param2], %rax
            addq	%rdx, %rax
            movq	%rax, [dest]
        */
            cout << "Adding values.\n";
            break;
        case sub:
        /*
            movq	-16(%rbp), %rax
            subq	-12(%rbp), %rax
            movq	%rax, -8(%rbp)
        */
            cout << "Subtracting values.\n";
            break;
        case mul:
        /*
            movq	-16(%rbp), %rax
            imulq	-12(%rbp), %rax
            movq	%rax, -4(%rbp)
        */
            cout << "Multiplying values.\n";
            break;
        case rmem:
            cout << "Reading from memory.\n";
            break;
        case wmem:
            cout << "Writing to memory.\n";
            break;
        case call:
            cout << "Calling a function.\n";
            break;
        case cmp_eq:
            cout << "Comparing for equality.\n";
            break;
        case cmp_lt:
            cout << "Comparing for less than.\n";
            break;
        case cmp_le:
            cout << "Comparing for less than or equal to.\n";
            break;
        default:
            cout << "Unknown operation.\n";
            break;
    }
}


void IRInstr::print_IRInstr(){
    
    cout<<operationToString(this->op) << "params = "<<endl ; 
    for (auto it = params.begin(); it != params.end(); ++it) {
        cout << *it <<  endl;
    }
}

string IRInstr::operationToString(Operation op) {
    switch (op) {
        case ldconst: return "ldconst";
        case copy: return "copy";
        case add: return "add";
        case sub: return "sub";
        case mul: return "mul";
        case rmem: return "rmem";
        case wmem: return "wmem";
        case call: return "call";
        case cmp_eq: return "cmp_eq";
        case cmp_lt: return "cmp_lt";
        case cmp_le: return "cmp_le";
        default: return "Unknown Operation";
    }
}



// ==============================================================================================================


// ======== BasicBlock ==========================================================================================

// Method implementation for gen_asm
void BasicBlock::gen_asm(ostream &o) {
    // Very simple assembly code generation for this basic block
    // This is a placeholder implementation. Actual implementation will depend on your specific requirements.
    o << "BasicBlock " << label << ":\n";
    if (label == cfg->getFuncName()) {
        cfg->gen_asm_prologue(o);
    }
    for (IRInstr* instr : instrs) {
        instr->gen_asm(o); 
    }

    if(this->exit_true) {
        o << "jmp " << this->exit_true->label << endl;
    }

    if(!(this->exit_true && this->exit_false)){
        cfg->gen_asm_epilogue(o);
    }

}

// Method implementation for add_IRInstr
void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params) {
    // Create a new IRInstr and add it to the instrs vector
    IRInstr* newInstr;
    switch(op) {
        case IRInstr::Operation::add:
            newInstr = new IRInstrAdd(this, op, t, params);

    }
    newInstr = new IRInstr(this, op, t, params); // Assuming IRInstr constructor takes BasicBlock* as first argument


    instrs.push_back(newInstr);
}

void BasicBlock::printBB() {
    // Create a new IRInstr and add it to the instrs vector
    for (IRInstr* instr : instrs) {
        if (instr != nullptr){
            instr->print_IRInstr() ;
        }
    }
}

// ==============================================================================================================


// ========= CFG ================================================================================================

// Method implementation for add_bb
void CFG::add_bb(BasicBlock* bb) {
    bbs.push_back(bb);
    // Optionally, set the current_bb to the newly added bb if needed
    current_bb = bb;
}

// Method implementation for gen_asm
void CFG::gen_asm(ostream& o) {
    // Placeholder for x86 code generation
    // This method should generate assembly code for the entire CFG
    // Actual implementation will depend on your specific requirements
    for(auto bb : bbs) {
        bb->gen_asm(o);
    }
}

// Method implementation for IR_reg_to_asm
string CFG::IR_reg_to_asm(string reg) {
    // Placeholder for converting IR register to assembly register
    // Actual implementation will depend on your specific requirements
    return "-24(%rbp)"; // Example return value
}

// Method implementation for gen_asm_prologue
void CFG::gen_asm_prologue(ostream& o) {
    // Placeholder for generating assembly code prologue
    // Actual implementation will depend on your specific requirements
    int alloc_size = 0;
    for (auto var : this->SymbolType) {
        alloc_size += get_type_size(var.second);
    }
    
    alloc_size += 16 - (alloc_size % 16);

    o << "pushq  %rbp" << endl;
    o << "movq  %rsp, %rbp" << endl;
    o << "subq  $" << alloc_size << ", %rsp" << endl;
    o << endl;
}

// Method implementation for gen_asm_epilogue
void CFG::gen_asm_epilogue(ostream& o) {
    // Placeholder for generating assembly code epilogue
    // Actual implementation will depend on your specific requirements
    o << endl;
    o << "leave" << endl;
    o << "ret" << endl;

}

// Method implementation for add_to_symbol_table
void CFG::add_to_symbol_table(string name, Type t) {
    nextFreeSymbolIndex -= get_type_size(t);
    SymbolType[name] = t;
    SymbolIndex[name] = nextFreeSymbolIndex ;
}

// Method implementation for create_new_tempvar
string CFG::create_new_tempvar(Type t) {
    string tempName = "temp" + to_string(nextFreeSymbolIndex);
    add_to_symbol_table(tempName, t);
    return tempName;
}

// Method implementation for get_var_index
int CFG::get_var_index(string name) {
    if (SymbolIndex.find(name) != SymbolIndex.end()) {
        return SymbolIndex[name];
    }
    return -1; // Return -1 if the variable is not found
}

// Method implementation for get_var_type
Type CFG::get_var_type(string name) {
    if (SymbolType.find(name) != SymbolType.end()) {
        return SymbolType[name];
    }
    return Type(); // Return default Type if the variable is not found
}

int CFG::get_type_size(Type type) {
    switch(type.getType()) {
        case Type::TypeEnum::INT:
            return 8;
        case Type::TypeEnum::CHAR:
            return 8;
        case Type::TypeEnum::VOID:
            return 0;
    }
    return 8;
}




// Method implementation for new_BB_name
string CFG::new_BB_name() {
    return "BB" + to_string(nextBBnumber++);
}

// ==============================================================================================================