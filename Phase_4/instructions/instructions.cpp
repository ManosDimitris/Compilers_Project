#include "./instructions.hpp"
#include "../quad/quad.hpp"
#include <vector>
#include <list>
#include <cassert>
#include <stack>

using namespace std;

vector<instruction> instructions;

list<incomplete_jump> ij_head;

vector<double> numConsts;
vector<string> stringConsts;
vector<string> namedLibfuncs;
vector<userfunc> userFuncs;
stack<FuncInfo> funcStack;

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

void add_incomplete_jump(unsigned int instrNo, unsigned int iaddress){
    incomplete_jump newIncompleteJump;
    newIncompleteJump.instrNo = instrNo;
    newIncompleteJump.iaddress = iaddress;
    ij_head.push_back(newIncompleteJump);
};

void patch_incomplete_jumps(){
    for(incomplete_jump& ij_element : ij_head){
        if(ij_element.iaddress == quads.size())
            instructions[ij_element.instrNo].result.val = nextinstructionlabel();
        else
            instructions[ij_element.instrNo].result.val = quads[ij_element.iaddress]->taddress;
    }
}

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
    arg->name = e->sym->name;

    switch(e->sym->scopespace){
        case programvar:
            arg->type = global_a;
            break;
        case functionlocal:
            arg->type = local_a;
            break;
        case formalarg:
            arg->type = formal_a;
            break;
        default:
            assert(0);
    }
}

void make_operant(expr* e, vmarg* arg){
    if(e == nullptr) {arg->val = 0; return;}
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

void reset_operand(vmarg* arg){
    arg=nullptr;
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

//Relational
void generate_relational(vmopcode op,quad* q){
    instruction t;
    t.opcode=op;
    make_operant(q->arg1,&t.arg1);
    make_operant(q->arg2,&t.arg2);
    t.result.type=label_a;
    if(q->label<curr_quad){
        t.result.val = quads[q->label]->taddress;
    }
    else{
        add_incomplete_jump(nextinstructionlabel(),q->label);
    }
    q->taddress=nextinstructionlabel();
    emit(t);

}

//Extra
void generate_Default(){
    
    for (int i = 0; i < quads.size(); ++i)
    {   
       (*generators[quads[i]->op])(quads[i]); 
    }
}

/*Generate*/
void generate_ADD(quad* q){generate(vmopcode(add_v), q);}
void generate_SUB(quad* q){generate(vmopcode(add_v), q);}
void generate_MUL(quad* q) {generate(vmopcode(mul_v), q);}
void generate_DIV(quad* q){generate(vmopcode(div_v), q);}
void generate_MOD(quad* q){generate(vmopcode(mod_v), q);}
void generate_UMINUS(quad* q){generate(vmopcode(uminus_v), q);}

void generate_AND(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode=jeq_v;
    make_operant(q->arg1,&t.arg1);
    make_booloperant(&t.arg2,false);
    t.result.type=label_a;
    t.result.val = nextinstructionlabel()+4;
    emit(t);

    make_operant(q->arg2,&t.arg1);
    t.result.val=nextinstructionlabel()+3;
    emit(t);

    t.opcode = assign_v;
    make_booloperant(&t.arg1,true);
    reset_operand(&t.arg2);
    make_operant(q->result,&t.result);
    emit(t);

    t.opcode = jmp_v;
    reset_operand(&t.arg2);
    reset_operand(&t.arg2);
    t.result.type=label_a;
    t.result.val = nextinstructionlabel()+2;
    emit(t);

    t.opcode= assign_v;
    make_booloperant(&t.arg1,false);
    reset_operand(&t.arg2);
    make_operant(q->result,&t.result);
    emit(t);
}

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
void generate_JUMP(quad* q){
    generate_relational(jmp_v, q);
}
void generate_IF_EQ(quad* q){
    generate_relational(jeq_v, q);
}
void generate_IF_NOTEQ(quad* q){
    generate_relational(jne_v, q);
}
void generate_IF_GREATER(quad* q){
    generate_relational(jgt_v, q);
}
void generate_IF_GREATEREQ(quad* q){
    generate_relational(jge_v, q);
}
void generate_IF_LESS(quad* q){
    generate_relational(jlt_v, q);
}
void generate_IF_LESSEQ(quad* q){
    generate_relational(jle_v, q);
}

void generate_NOT(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;

    t.opcode = jeq_v;
    make_operant(q->arg1, &t.arg1);
    make_booloperant(&t.arg2, false);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 3;
    emit(t);

    t.opcode = assign_v;
    make_booloperant(&t.arg1, false);
    reset_operand(&t.arg2);
    make_operant(q->result, &t.result);
    emit(t);

    t.opcode = jmp_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel() + 2;
    emit(t);

    t.opcode = assign_v;
    make_booloperant(&t.arg1, true);
    reset_operand(&t.arg2);
    make_operant(q->result, &t.result);
    emit(t);
}

void generate_OR(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode=jeq_v;
    make_operant(q->arg1,&t.arg1);
    make_booloperant(&t.arg2,true);
    t.result.type=label_a;
    t.result.val = nextinstructionlabel()+4;
    emit(t);

    make_operant(q->arg2,&t.arg1);
    t.result.val=nextinstructionlabel()+3;
    emit(t);

    t.opcode = assign_v;
    make_booloperant(&t.arg1,false);
    reset_operand(&t.arg2);
    make_operant(q->result,&t.result);
    emit(t);

    t.opcode = jmp_v;
    reset_operand(&t.arg2);
    reset_operand(&t.arg2);
    t.result.type=label_a;
    t.result.val = nextinstructionlabel()+2;
    emit(t);

    t.opcode= assign_v;
    make_booloperant(&t.arg1,true);
    reset_operand(&t.arg2);
    make_operant(q->result,&t.result);
    emit(t);
}

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

void generate_FUNCSTART(quad* q) {
    instruction t;
    t.opcode = jmp_v;
    t.result.val = nextinstructionlabel();
    t.result.type = label_a;
    emit(t);

    FuncInfo f;
    f.sym = q->result->sym;
    f.sym->taddress = nextinstructionlabel();
    q->taddress = nextinstructionlabel();
    userfunc tmp;
    tmp.address = f.sym->taddress;
    tmp.id = f.sym->name;
    tmp.localSize = f.sym->totallocal;

    userFuncs.push_back(tmp);
    funcStack.push(f);
    t.opcode = funcenter_v;
    make_operant(q->result, &t.result);
    emit(t);

}

void generate_RETURN(quad* q){
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = assign_v;
    t.arg1.type = nil_a;
    make_retval(&t.result);
    make_operant(q->arg1,&t.arg1);
    emit(t);
    
    
    FuncInfo *f = &funcStack.top();
    f->returnList.push_back(nextinstructionlabel());

    t.opcode = jmp_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    emit(t);

}

void generate_FUNCEND(quad* q){
    FuncInfo *f = &funcStack.top();
    for (int i = 0; i < f->returnList.size(); i++)
    {
        instructions[f->returnList[i]].result.val = nextinstructionlabel();
    }
    
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = funcexit_v;
    make_operant(q->result,&t.result);
    emit(t);
    
    instructions[f->sym->taddress - 1].result.val = nextinstructionlabel();
    funcStack.pop();

}


void print_instructions() {
    cout << "\n===== AVM INSTRUCTIONS =====\n\n";

    for (unsigned int i = 0; i < instructions.size(); ++i) {
        cout << i << ":";
        cout << setw(5);

        switch (instructions[i].opcode) {
            case assign_v:       cout << "assign\t"; break;
            case add_v:          cout << "add\t"; break;
            case sub_v:          cout << "sub\t"; break;
            case mul_v:          cout << "mul\t"; break;
            case div_v:          cout << "div\t"; break;
            case mod_v:          cout << "mod\t"; break;
            case uminus_v:       cout << "uminus\t"; break;
            case and_v:          cout << "and\t"; break;
            case or_v:           cout << "or\t"; break;
            case not_v:          cout << "not\t"; break;
            case jmp_v:          cout << "jump\t"; break;
            case jeq_v:          cout << "jeq\t"; break;
            case jne_v:          cout << "jne\t"; break;
            case jle_v:          cout << "jle\t"; break;
            case jge_v:          cout << "jge\t"; break;
            case jlt_v:          cout << "jlt\t"; break;
            case jgt_v:          cout << "jgt\t"; break;
            case call_v:         cout << "call\t"; break;
            case pusharg_v:      cout << "pusharg\t"; break;
            case funcenter_v:    cout << "enterfunc\t"; break;
            case funcexit_v:     cout << "exitfunc\t"; break;
            case newtable_v:     cout << "newtable\t"; break;
            case tablegetelem_v: cout << "tablegetelem\t"; break;
            case tableselem_v:   cout << "tablesetelem\t"; break;
            case nop_v:          cout << "nop\t"; break;
            default:              break;
        }
       
        // Operands
        print_Args(&instructions[i].result);
        print_Args(&instructions[i].arg1);
        print_Args(&instructions[i].arg2);

        cout << "\n";
    }

    cout << "\n=============================\n";
}


void print_Args(vmarg* arg) {
    if (!arg || arg->type == nil_a || arg->type > retval_a) {
        cout << "\t";
        return;
    }


    cout  << arg->type << "(";
    switch (arg->type) {
        case label_a:
            cout << "label), " << arg->val;
            break;
        case global_a:
            cout << "global), " << arg->val << ":" << arg->name;
            break;
        case formal_a:
            cout << "formal), " << arg->val << ":" << arg->name;
            break;
        case local_a:
            cout << "local), " << arg->val << ":" << arg->name;
            break;
        case number_a:
            cout << "num), " << arg->val << ":" << numConsts[arg->val];
            break;
        case string_a:
            cout << "string), " << arg->val << ":\"" << stringConsts[arg->val] << "\"";
            break;
        case bool_a:
            cout << "boolean), " << arg->val << ":" << (arg->val ? "true" : "false");
            break;
        case nil_a:
            cout << "nil), " << arg->val << ":nil";
            break;
        case userfunc_a:
            cout << "userfunc), " << arg->val << ":" << userFuncs[arg->val].id;
            break;
        case libfunc_a:
            cout << "libfunc), " << arg->val << ":" << namedLibfuncs[arg->val];
            break;
        case retval_a:
            cout << "retval), " << arg->val;
            break;
        default:
            cout << "nop" << arg->val;
            break;
    }
    cout << setw(5);
    cout << "\t";
}
