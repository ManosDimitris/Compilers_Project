#include "./instructions.hpp"
#include <vector>

using namespace std;

vector<instruction> instructions;

vector<double> numConsts;
vector<string> stringConsts;
vector<string> namedLibfuncs;
vector<userfunc> userFuncs;

unsigned int consts_newNumber(double n){
    for(unsigned int i = 0; i < numConsts.size(); i++){
        if(n == numConsts[i])
            return i;
    }

    numConsts.push_back(n);

    return numConsts.size() - 1;
}

unsigned int consts_newString(string s){
    for(unsigned int i = 0; i < stringConsts.size(); i++){
        if(s == stringConsts[i])
            return i;
    }
    stringConsts.push_back(s);
    return stringConsts.size() - 1;
}

unsigned int libfuncs_newUsed(string s){
    for(unsigned int i = 0; i < namedLibfuncs.size(); i++){
        if(s == namedLibfuncs[i])
            return i;
    }
    
    namedLibfuncs.push_back(s);
    return namedLibfuncs.size() - 1;
}

unsigned int userfuncs_newFunc(SymbolEntry* s){
    for(unsigned int i = 0; i < userFuncs.size(); i++){
        if(s->name == userFuncs[i].id)
            return i;
    }

    userfunc newFunc;
    newFunc.id = s->name;
    userFuncs.push_back(newFunc);
    return userFuncs.size() - 1;
}
