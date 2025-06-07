#include "avm_memcell.hpp"

void avm_initstack (){
    for (int i = 0; i < AVM_STACKSIZE; ++i)
    {
        AVM_WIPEOUT(stack[i]);
        stack[i].type = avm_memcell_t(undef_m);
    }
    
}