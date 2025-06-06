#include "quad.hpp"
#include "../SymTable/SymTable.hpp"
#include <iomanip>
#include <string>
#include <sstream>
extern SymbolTable symTable;
extern int scope;
extern int yylineno;
unsigned int temp_counter = 0;
unsigned int curr_quad = 1;

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

/**
 * @param iopcode 
 * @param arg1
 * @param arg2
 * @param result
 * @param label
 * @param line
 * 
 */
void emit(iopcode op, 
    expr* arg1, 
    expr* arg2, 
    expr* result, 
    unsigned int label, 
    unsigned int line){

        quad *p = new quad(op, arg1, arg2, result, label, line);

        quads.push_back(p);
        curr_quad++;
}

expr* member_item (expr* lv, string name){
    lv = emit_iftableitem(lv); // Emit code if r-value use of table item
    expr* ti = NewExpr(tableitem_e); // Make a new expression
    ti->sym = lv->sym;
    ti->index = newexpr_conststring(name); // Const string index
    return ti;
}

expr* emit_iftableitem(expr *e){
    if(e->type != tableitem_e) return e;
    
    expr* result = NewExpr(var_e);
    result = newtemp();
    emit(tablegetelem,e,e->index,result,0,yylineno);
    return result;
    
}

expr* newexpr_conststring(string name){
    expr* e = NewExpr(conststring_e);
    e->strConst = name;
    return e;
}

string exprtToString(expr* expr){
    ostringstream oss;
    switch (expr->type){
        case var_e: return expr->sym->name;
        case tableitem_e: return expr->sym->name; 
        case programfunc_e: return expr->sym->name;
        case libraryfunc_e: return "libraryfunc_e";
        case arithexpr_e: return expr->sym->name;
        case boolexpr_e: return expr->sym->name; 
        case assignexpr_e: return expr->sym->name;
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


void printQuads() {
    const int col1 = 8;   
    const int col2 = 15; 
    const int col3 = 12;  
    const int col4 = 12;  
    const int col5 = 12;  
    const int col6 = 12;  
    const int col7 = 12;

    cout << left
         << setw(col1) << "quad#"
         << setw(col2) << "op"
         << setw(col3) << "result"
         << setw(col4) << "arg1"
         << setw(col5) << "arg2"
         << setw(col6) << "label"
         << setw(col7) << "line"
         << endl;

    cout << string(col1 + col2 + col3 + col4 + col5 + col6, '-') << endl;

    for (size_t i = 0; i < quads.size(); ++i) {
        string result = "", arg1 = "", arg2 = "", label = "", line ="";

        if (quads[i]->result) result = exprtToString(quads[i]->result);
        if (quads[i]->arg1)   arg1 = exprtToString(quads[i]->arg1);
        if (quads[i]->arg2)   arg2 = exprtToString(quads[i]->arg2);
        if (quads[i]->label)  label = to_string(quads[i]->label);
        if (quads[i]->line)  line = to_string(quads[i]->line);
        line = "["+ line + "]";

        cout << left
             << setw(col1) << i + 1
             << setw(col2) << iopcodeToString(quads[i]->op)
             << setw(col3) << result
             << setw(col4) << arg1
             << setw(col5) << arg2
             << setw(col6) << label
             << setw(col7) << line
             << endl;
    }
}

string newtempname(){
    return "_t" + to_string(temp_counter++);
}

expr* newtemp(){
    string name = newtempname();
    SymbolEntry* newTemp;

    if(symTable.lookup(name,scope)){
        newTemp =symTable.returnSymbol(name);
    }else{
        symTable.insert(name,"temp_variable",scope,yylineno);
        newTemp =symTable.returnSymbol(name); //<- Ayto einai xazw alla den allasw tin insert na epistrefei SymbolEntry*
    }
    
    expr* e = NewExpr(var_e);
    e->sym = newTemp;
    return e;
}

void ressettemp(){
    temp_counter = 0;
}

/* IF STUFF */
void patchLabel(unsigned int quadNo, unsigned int label){
    if(quadNo < curr_quad && quads[quadNo - 2] == nullptr){
        cout << "Quad does not exist";
        exit(1);
    }
    quads[quadNo - 2]->label = label;
}
