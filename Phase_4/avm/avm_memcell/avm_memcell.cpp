#include "avm_memcell.hpp"
#include <cstring>
using namespace std;

void avm_initstack (){
    for (int i = 0; i < AVM_STACKSIZE; ++i)
    {
        AVM_WIPEOUT(stack[i]);
        stack[i].type = avm_memcell_t(undef_m);
    }
    
}