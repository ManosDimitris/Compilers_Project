#include "quad.hpp"

expr* NewExpr(expr_t t){
    expr *new_expr = new expr;
    new_expr->type = t;
    new_expr->next = NULL;
    new_expr->index = NULL;
    new_expr->sym = NULL;
    new_expr->numConst = 0.0;
    new_expr->strConst = "";
    new_expr->boolConst = false;

    return new_expr;
}


void emit(iopcode op, 
    expr* arg1, 
    expr* arg2, 
    expr* result, 
    unsigned int label, 
    unsigned int line){

        quad *p = new quad(op, arg1, arg2, result, label, line);

        quads.push_back(p);
}


string iopcodeToString(enum iopcode op) {
    switch(op) {
        case assign:        return "assign";
        case add:           return "add";
        case sub:           return "sub";
        case mul:           return "mul";
        case div_i:         return "div_i";
        case mod:           return "mod";
        case uminus:        return "uminus";
        case and_i:         return "and_i";
        case or_i:          return "or_i";
        case not_i:         return "not_i";
        case if_eq:         return "if_eq";
        case if_noteq:      return "if_noteq";
        case if_lesseq:     return "if_lesseq";
        case if_greatereq:  return "if_greatereq";
        case if_less:       return "if_less";
        case if_greater:    return "if_greater";
        case jump:          return "jump";
        case call:          return "call";
        case param:         return "param";
        case ret:           return "ret";
        case getretval:     return "getretval";
        case funcstart:     return "funcstart";
        case funcend:       return "funcend";
        case tablecreate:   return "tablecreate";
        case tablegetelem:  return "tablegetelem";
        case tablesetelem:  return "tablesetelem";
        default:            return "UNKNOWN_OPCODE";
    };
}


void printQuads(){
    cout<< "Line" << "\t" << "op\t " << "result\t" <<  "arg1\t" << "arg2\t" << "Label"<< endl;
    for(int i = 0; i < quads.size(); i++){
        cout << quads[i]->line << "\t" << iopcodeToString(quads[i]->op) << "\t "  << quads[i]->result->type << "\t" << quads[i]->arg1->type << "\t\t\t " << endl;
    }
}
