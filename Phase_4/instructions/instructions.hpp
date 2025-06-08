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
    tablegetelem_v, tableselem_v, nop_v
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

/*-------------GENERATORS-------------*/

extern void generate_ADD(quad*);
extern void generate_SUB(quad*);
extern void generate_MUL(quad*);
extern void generate_DIV(quad*);
extern void generate_MOD(quad*);
extern void generate_UMINUS(quad*);
extern void generate_AND(quad*);
extern void generate_NEWTABLE(quad*);
extern void generate_TABLEGETELEM(quad*);
extern void generate_TABLESETELEM(quad*);
extern void generate_ASSIGN(quad*);
extern void generate_NOP(quad*);
extern void generate_JUMP(quad*);
extern void generate_IF_EQ(quad*);
extern void generate_IF_NOTEQ(quad*);
extern void generate_IF_GREATER(quad*);
extern void generate_IF_GREATEREQ(quad*);
extern void generate_IF_LESS(quad*);
extern void generate_IF_LESSEQ(quad*);
extern void generate_NOT(quad*);
extern void generate_OR(quad*);
extern void generate_PARAM(quad*);
extern void generate_CALL(quad*);
extern void generate_GETRETVAL(quad*);
extern void generate_FUNCSTART(quad*);
extern void generate_RETURN(quad*);
extern void generate_FUNCEND(quad*);

typedef void (*generator_func_t)(quad*);

extern generator_func_t generators[];


/*------------------------------------*/
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

/* Helper funcs */
void make_numberoperant(vmarg* arg, double val);
void make_booloperant(vmarg* arg, bool val);
void make_retval(vmarg* arg);
void reset_operant(vmarg* arg);

unsigned int nextinstructionlabel();
void emit(instruction instr);

void generate(vmopcode op,quad* quad);
void generate_Default();

#endif