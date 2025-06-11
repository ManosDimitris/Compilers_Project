#ifndef AVM_MEMCELL_HPP
#define AVM_MEMCELL_HPP
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

enum avm_memcell_t {
    number_m =0,
    string_m =1,
    bool_m =2,
    table_m =3,
    userfunc_m =4,
    libfunc_m =5,
    nil_m =6,
    undef_m =7
};

struct avm_table; 

struct avm_memcell {
    avm_memcell_t type;

    union {
        double          numVal;
        string*         strVal;
        bool            boolVal;
        avm_table*      tableVal;
        unsigned        funcVal;       
        string*         libfuncVal;
    } data;
};

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))


avm_memcell stack[AVM_STACKSIZE];
void avm_initstack();

#endif
