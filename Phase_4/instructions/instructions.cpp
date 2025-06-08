#include "./instructions.hpp"
#include "../quad/quad.hpp"
#include <vector>
#include <cassert>

using namespace std;

vector<instruction> instructions;

vector<double> numConsts;
vector<string> stringConsts;
vector<string> namedLibfuncs;
vector<userfunc> userFuncs;

 void generate_ADD(quad*);
void generate_SUB(quad*);
 void generate_MUL(quad*);
 void generate_DIV(quad*);
 void generate_MOD(quad*);
 void generate_UMINUS(quad*);
 void generate_AND(quad*);
 void generate_NEWTABLE(quad*);
 void generate_TABLEGETELEM(quad*);
 void generate_TABLESETELEM(quad*);
 void generate_ASSIGN(quad*);
 void generate_NOP(quad*);
 void generate_JUMP(quad*);
 void generate_IF_EQ(quad*);
 void generate_IF_NOTEQ(quad*);
 void generate_IF_GREATER(quad*);
 void generate_IF_GREATEREQ(quad*);
 void generate_IF_LESS(quad*);
 void generate_IF_LESSEQ(quad*);
 void generate_NOT(quad*);
 void generate_OR(quad*);
void generate_PARAM(quad*);
void generate_CALL(quad*);
void generate_GETRETVAL(quad*);
void generate_FUNCSTART(quad*);
void generate_RETURN(quad*);
void generate_FUNCEND(quad*);

generator_func_t generators[] = {
    //OLA BASISMENA ME TO enum iopcode STO QUAD.HPP
    //!! MHN ALLAXTEI KATI
    generate_ASSIGN,
    generate_ADD,
    generate_MUL,
    generate_SUB,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,
    generate_AND,
    generate_OR,
    generate_NOT,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,
    generate_JUMP,
    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
    generate_NOP
};

unsigned int consts_newNumber(double n){
    for(unsigned int i = 0; i < numConsts.size(); i++){
        if(n == numConsts[i])
            return i;
    }

    numConsts.push_back(n);

    return numConsts.size() - 1;
}

unsigned int consts_newString(string s){
    for(unsigned int i = 0; i < stringConsts.size(); i++){
        if(s == stringConsts[i])
            return i;
    }
    stringConsts.push_back(s);
    return stringConsts.size() - 1;
}

unsigned int libfuncs_newUsed(string s){
    for(unsigned int i = 0; i < namedLibfuncs.size(); i++){
        if(s == namedLibfuncs[i])
            return i;
    }
    
    namedLibfuncs.push_back(s);
    return namedLibfuncs.size() - 1;
}

unsigned int userfuncs_newFunc(SymbolEntry* s){
    for(unsigned int i = 0; i < userFuncs.size(); i++){
        if(s->name == userFuncs[i].id)
            return i;
    }

    userfunc newFunc;
    newFunc.id = s->name;
    userFuncs.push_back(newFunc);
    return userFuncs.size() - 1;
}

void variableOP(expr *e, vmarg* arg){
    assert(e->sym);
    arg->val = e->sym->offset;

    switch(e->sym->scopespace){
        case programvar:
            arg->type = global_a;
            break;
        case functionlocal:
            arg->type = local_a;
        case formalarg:
            arg->type = formal_a;
        default:
            assert(0);
    }
}

void make_operant(expr* e, vmarg* arg){
    switch (e->type){
        case var_e:
            variableOP(e, arg);
            break;
        case tableitem_e:
            variableOP(e, arg);
            break;
        case arithexpr_e:
            variableOP(e, arg);
            break;
        case boolexpr_e:
            variableOP(e, arg);
            break;
        case newtable_e:
            variableOP(e, arg);
            break;
        case constbool_e:
            arg->val = e->boolConst;
            arg->type = bool_a;
            break;
        case conststring_e:
            arg->val = consts_newString(e->strConst);
            arg->type = string_a;
            break;
        case constnum_e:
            arg->val = consts_newNumber(e->numConst);
            arg->type = number_a;
            break;
        case nil_e:
            arg->type = nil_a;
            break;
        case programfunc_e:
            arg->type = userfunc_a;
            arg->val = userfuncs_newFunc(e->sym);
            break;
        case libraryfunc_e:
            arg->type = libfunc_a;
            arg->val = libfuncs_newUsed(e->sym->name);
            break;
        default: assert(0);
    }
}

/* Helper funcs */
void make_numberoperant(vmarg* arg, double val){
    arg->val = val;
    arg->type = number_a;
}

void make_booloperant(vmarg* arg, bool val){
    arg->val = val;
    arg->type = bool_a;
}

void make_retval(vmarg* arg){
    arg->type = retval_a;
}

unsigned int nextinstructionlabel(){
    return instructions.size();
}

void emit(instruction instr){
    instructions.push_back(instr);
}

void generate(vmopcode op, quad* quad){
    instruction t;
    t.opcode = op;

    make_operant(quad->arg1,&t.arg1);
    make_operant(quad->arg2,&t.arg2);
    make_operant(quad->result,&t.result);
    quad->taddress = nextinstructionlabel();
    t.srcLine = quad->line;
    emit(t);
}


//Extra
void generate_Default(){
    for (int i = 0; i < quads.size(); i++)
    {   
       generators[quads[i]->op](quads[i]); 
    }
}

/*Generate*/
void generate_ADD(quad* q){generate(vmopcode(add_v), q);}
void generate_SUB(quad* q){generate(vmopcode(add_v), q);}
void generate_MUL(quad* q) {generate(vmopcode(mul_v), q);}
void generate_DIV(quad* q){generate(vmopcode(div_v), q);}
void generate_MOD(quad* q){generate(vmopcode(mod_v), q);}
void generate_UMINUS(quad* q){generate(vmopcode(uminus_v), q);}
void generate_AND(quad* q){generate(vmopcode(and_v), q);}
void generate_NEWTABLE(quad* q){generate(vmopcode(newtable_v), q);}
void generate_TABLEGETELEM(quad* q){generate(vmopcode(tablegetelem_v), q);}
void generate_TABLESETELEM(quad* q){generate(vmopcode(tableselem_v), q);}
void generate_ASSIGN(quad* q){generate(vmopcode(assign_v), q);}

void generate_NOP(quad* q){
    instruction t;
    t.opcode = vmopcode(nop_v);
    emit(t);
}

/*Generate relation*/
void generate_JUMP(quad*){}
void generate_IF_EQ(quad*){}
void generate_IF_NOTEQ(quad*){}
void generate_IF_GREATER(quad*){}
void generate_IF_GREATEREQ(quad*){}
void generate_IF_LESS(quad*){}
void generate_IF_LESSEQ(quad*){}

void generate_NOT(quad*){}
void generate_OR(quad*){}

void generate_PARAM(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = pusharg_v;
    make_operant(q->arg1,&t.arg1);
    emit(t);
}

void generate_CALL(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = call_v;
    make_operant(q->arg1, &t.arg1);
    emit(t);
}

void generate_GETRETVAL(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = assign_v;
    make_operant(q->result, &t.result);
    make_retval(&t.arg1);

    emit(t);
}
void generate_FUNCSTART(quad*){}
void generate_RETURN(quad*){}
void generate_FUNCEND(quad*){}