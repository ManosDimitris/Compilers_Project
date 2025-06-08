#ifndef QUAD_HPP
#define QUAD_HPP

#include <string>
#include <vector>
#include "../SymTable/SymTable.hpp" 

using namespace std;

extern unsigned int temp_counter;
extern unsigned int curr_quad;

//O opcode ton quads
enum iopcode {
    assign = 0, add = 1, sub = 2, mul = 3, div_i= 4, mod = 5, uminus = 6,
    and_i = 7, or_i = 8, not_i = 9,
    if_eq = 10, if_noteq = 11, if_lesseq = 12, if_greatereq = 13, if_less = 14, if_greater = 15,
    jump = 16,
    call = 17, param = 18, ret = 19, getretval = 20,
    funcstart = 21, funcend = 22,
    tablecreate = 23, tablegetelem = 24, tablesetelem = 25, 
    nop = 26 // Phase 4
};

//Ta types ton expressions poy einai apodekta
enum expr_t {
    var_e,
    tableitem_e, 
    programfunc_e, 
    libraryfunc_e,
    arithexpr_e, 
    boolexpr_e, 
    assignexpr_e,
    newtable_e, 
    constnum_e, 
    constbool_e, 
    conststring_e,
    nil_e
};

//Anaparista ola ta expressions tis aplha
struct expr{
    expr_t type;
    SymbolEntry* sym;
    expr* index;

    double numConst;
    std::string strConst;
    bool boolConst;

    expr* next;
};

/*  Ta quad toy ka8e kodika exoyn to akolou8w typo:
*    Εντολή: αποτέλεσμα, τελεστής1, τελεστής2;
*/
struct quad {
    iopcode op;
    expr* arg1;
    expr* arg2;
    expr* result;
    unsigned int label;
    unsigned int line;
    unsigned int taddress; 
    quad();
    quad(iopcode op, expr* arg1, expr* arg2, expr* result, unsigned int label, unsigned int line) : 
    op(op), arg1(arg1), arg2(arg2), result(result), label(label), line(line){}
};


//Lista me ola ta quads tou prgrammatos  
extern vector<quad *> quads;


/*-------------------------------------------*/
/*---------- Function Declarations ----------*/
/*-------------------------------------------*/

/**
 * @param op
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
    unsigned int line);
    
expr* emit_iftableitem(expr *e);


expr* NewExpr(expr_t t);

void printQuads();

string iopcodeToString(enum iopcode op);
string to_string_or_type(expr* e) ;
expr* newexpr_conststring(string name);

void patchlabel(int index, int label);
int nextquad();

string newtempname();
expr* newtemp();
void ressettemp();
expr* member_item (expr* lv, string name);


void patchLabel(unsigned int quadNo, unsigned int label);

#endif