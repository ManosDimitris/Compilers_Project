#ifndef __INSTR_HPP__
#define __INSTR_HPP__
#include <string>
#include <vector>
#include "../SymTable/SymTable.hpp"
#include "../quad/quad.hpp"
#include <stack>
#include <iomanip> 

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
    vmarg_t type = nil_a;
    unsigned int val = 0;
    string name;// Gia prints.
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

struct FuncInfo {
    SymbolEntry* sym;
    string id;
    std::vector<int> returnList; 
};
struct incomplete_jump{
    unsigned int instrNo;
    unsigned int iaddress;
};

/*-------------GENERATORS-------------*/

void generate_ADD(quad* q);
void generate_SUB(quad* q);
void generate_MUL(quad* q);
void generate_DIV(quad* q);
void generate_MOD(quad* q);
void generate_UMINUS(quad* q);
void generate_AND(quad* q);
void generate_NEWTABLE(quad* q);
void generate_TABLEGETELEM(quad* q);
void generate_TABLESETELEM(quad* q);
void generate_ASSIGN(quad* q);
void generate_NOP(quad* q);
void generate_JUMP(quad* q);
void generate_IF_EQ(quad* q);
void generate_IF_NOTEQ(quad* q);
void generate_IF_GREATER(quad* q);
void generate_IF_GREATEREQ(quad* q);
void generate_IF_LESS(quad* q);
void generate_IF_LESSEQ(quad* q);
void generate_NOT(quad* q);
void generate_OR(quad* q);
void generate_PARAM(quad* q);
void generate_CALL(quad* q);
void generate_GETRETVAL(quad* q);
void generate_FUNCSTART(quad* q);
void generate_RETURN(quad* q);
void generate_FUNCEND(quad* q);

typedef void (*generator_func_t)(quad*);

extern generator_func_t generators[];


/*------------------------------------*/
extern vector<double> numConsts;
extern vector<string> stringConsts;
extern vector<string> namedLibfuncs;
extern vector<userfunc> userFuncs;

extern vector<instruction> instructions;
extern stack<FuncInfo> funcStack;

void add_incomplete_jump(unsigned int instrNo, unsigned int iaddress);
void patch_incomplete_jumps();

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
void print_instructions();
void print_Args(vmarg*); 
#endif