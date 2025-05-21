#include "quad.hpp"
#include <iomanip>
#include <string>
#include <sstream>

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

string exprtToString(expr* expr){
    ostringstream oss;
    switch (expr->type){
        case var_e: return expr->sym->name;
        case tableitem_e: return "tableitem_e"; 
        case programfunc_e: return "programfunc_e";
        case libraryfunc_e: return "libraryfunc_e";
        case arithexpr_e: return "arithexpr_e";
        case boolexpr_e: return "boolexpr_e"; 
        case assignexpr_e: return "assignexpr_e";
        case newtable_e: return "newtable_e";
        case constnum_e: oss << fixed << setprecision(1) << expr->numConst; return oss.str(); 
        case constbool_e: return (expr->boolConst) ? "True" : "false"; 
        case conststring_e: return expr->strConst;
        case nil_e: return "nil_e";
        default: return "invalid expression";
    };
}
string iopcodeToString(iopcode op) {
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
    string result = "", arg1 = "", arg2 = "", label = "";

    cout<< "quad#\t" << "op\t " << "result\t" <<  "arg1\t" << "arg2\t" << "label"<< endl;
    cout << "----------------------------------------------" << endl;
    for(int i = 0; i < quads.size(); i++){
        if(quads[i]->result != nullptr) result = exprtToString(quads[i]->result);
        if(quads[i]->arg1 != nullptr) arg1 = exprtToString(quads[i]->arg1);
        if(quads[i]->arg2 != nullptr) arg2 = exprtToString(quads[i]->arg2);
        if(quads[i]->label != 0) label = to_string(quads[i]->label);

        cout << i+1 << "\t" << iopcodeToString(quads[i]->op) << "\t" << result << "\t" << arg1 << "\t" << arg2 << "\t" << label << endl;

        result = "", arg1 = "", arg2 = "", label = "";
    }
}
