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

void generate(){
    for (int i = 0; i < quads.size(); i++)
    {   
       generators[quads[i]->op](quads[i]); 
    }
    
}