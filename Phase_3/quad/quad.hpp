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
    assign, add, sub, mul, div_i, mod, uminus,
    and_i, or_i, not_i,
    if_eq, if_noteq, if_lesseq, if_greatereq, if_less, if_greater,
    jump,
    call, param, ret, getretval,
    funcstart, funcend,
    tablecreate, tablegetelem, tablesetelem
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

string newtempname();
expr* newtemp();
void ressettemp();
expr* member_item (expr* lv, string name);


void patchLabel(unsigned int quadNo, unsigned int label);

#endif