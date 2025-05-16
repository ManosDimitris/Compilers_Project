#ifndef QUAD_HPP
#define QUAD_HPP

#include <string>
#include <vector>
#include "../SymTable/SymTable.hpp" 

using namespace std;

//O opcode ton quads
typedef enum iopcode {
    assign, add, sub, mul, div_i, mod, uminus,
    and_i, or_i, not_i,
    if_eq, if_noteq, if_lesseq, if_greatereq, if_less, if_greater,
    jump,
    call, param, ret, getretval,
    funcstart, funcend,
    tablecreate, tablegetelem, tablesetelem
};

//Ta types ton expressions poy einai apodekta
typedef enum expr_t {
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
typedef struct expr{
    expr_t type;
    SymbolEntry* sym;
    expr* index;

    double numConst;
    std::string strConst;
    bool boolConst;
};

/*  Ta quad toy ka8e kodika exoyn to akolou8w typo:
*    Εντολή: αποτέλεσμα, τελεστής1, τελεστής2;
*/
 typedef struct quad {
    iopcode op;
    expr* arg1;
    expr* arg2;
    expr* result;
    unsigned int label;
    unsigned int line;
};


//Lista me ola ta quads tou prgrammatos  
extern vector<quad> quads;


/*-------------------------------------------*/
/*---------- Function Declarations ----------*/
/*-------------------------------------------*/


expr* NewExpr(expr_t t);
//...
#endif