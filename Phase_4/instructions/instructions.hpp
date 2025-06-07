#ifndef __INSTR_HPP__
#define __INSTR_HPP__
#include <string>
#include <vector>
#include "../SymTable/SymTable.hpp"
#include "../quad/quad.hpp"

using namespace std;

enum vmopcode{
    assign_v, add_v, sub_v,
    mul_v, div_v, mod_v,
    uminus_v, and_v, or_v, not_v, 
    jmp_v, jeq_v, jne_v,
    jle_v, jge_v, jlt_v, jgt_v, 
    call_v, pusharg_v,
    funcenter_v, funcexit_v, newtable_v,
    tablegetelem_v, tableelem_v, nop_v
};

enum vmarg_t{
    label_a = 0,
    global_a = 1,
    formal_a = 2,
    local_a = 3,
    number_a = 4,
    string_a = 5,
    bool_a = 6,
    nil_a = 7,
    userfunc_a = 8,
    libfunc_a = 9,
    retval_a = 10
};

struct vmarg{
    vmarg_t type;
    unsigned int val;
};

struct instruction{
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned int srcLine;
};

struct userfunc{
    unsigned int address;
    unsigned int localSize;
    string id;
};

extern vector<double> numConsts;
extern vector<string> stringConsts;
extern vector<string> namedLibfuncs;
extern vector<userfunc> userFuncs;

extern vector<instruction> instructions;

unsigned int consts_newNumber(double n);
unsigned int consts_newString(string s);
unsigned int libfuncs_newUsed(string s);
unsigned int userfuncs_newFunc(SymbolEntry* s);

void make_operant(expr* e, vmarg* arg);

#endif