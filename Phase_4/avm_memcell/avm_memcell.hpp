#ifndef AVM_MEMCELL_HPP
#define AVM_MEMCELL_HPP
#include <cstring>
#include <iostream>

enum avm_memcell_t {
    number_m,
    string_m,
    bool_m,
    table_m,
    userfunc_m,
    libfunc_m,
    nil_m,
    undef_m
};

struct avm_table; 

struct avm_memcell {
    avm_memcell_t type;

    union {
        double          numVal;
        std::string*    strVal;
        bool            boolVal;
        avm_table*          tableVal;
        unsigned        funcVal;       
        std::string*    libfuncVal;
    } data;
};

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))


avm_memcell stack[AVM_STACKSIZE];
void avm_initstack();

#endif
