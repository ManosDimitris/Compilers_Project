#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

#define CAPACITY 509
#define HASH_MUL 65599

/* Scope Spaces */
enum scopespace_t{
    programvar,
    functionlocal,
    formalarg
};

extern unsigned int scopeSpaceCounter;

struct SymbolEntry {
    string name;
    string type;
    int scope;
    int line;
    bool isActive; //Ebala active
    scopespace_t scopespace;
    SymbolEntry *next;
    
    SymbolEntry(string n, string t, int s, int l, bool b) : name(n), type(t), scope(s), line(l), isActive(b) ,next(NULL){}
};

struct ScopeList
{
    vector<SymbolEntry *> data_in_scope;
    int isActive; //EBALA KAI EDW ENA ACTIVE GIA NA APENERGOPOIEI OLO TO SCOPE AN EXEI KLEISEI 
    ScopeList* next;
    ScopeList(SymbolEntry* s, bool b) :  next(nullptr), isActive(b) { data_in_scope.push_back(s); }
    ScopeList() : next(nullptr){}
};



class SymbolTable {
private:
    SymbolEntry* table[CAPACITY];
    ScopeList* scopes;
    int SymTable_hash(string name);
    
    unsigned int programVarOffset = 0;
    unsigned int funcVarOffset = 0;
    unsigned int formalArgOffset = 0;
    scopespace_t currscopespace();
public:

    SymbolTable();
    
    void insert(string name, string type, int scope, int line);
    
    void display();

    bool lookup(string name , int scope);

    bool lookup(string name);

    void ScopeHide(int scope);
    
    bool isFunction(string name, int scope);

    SymbolEntry* returnSymbol(string name);
};

#endif