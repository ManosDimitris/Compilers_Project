#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define CAPACITY 509
#define HASH_MUL 65599



struct SymbolEntry {
    string name;
    string type;
    int scope;
    int line;
    SymbolEntry *next;
    
    SymbolEntry(string n, string t, int s, int l) : name(n), type(t), scope(s), line(l) ,next(NULL){}
};

struct ScopeList
{
    vector<SymbolEntry *> data_in_scope;
    ScopeList* next;
    ScopeList(SymbolEntry* s) : next(nullptr) { data_in_scope.push_back(s); }
    ScopeList() : next(nullptr){}
};



class SymbolTable {
private:
    SymbolEntry* table[CAPACITY];
    ScopeList* scopes;
    int SymTable_hash(string name);

public:

    SymbolTable();
    
    void insert(string name, string type, int scope, int line);
    
    void display();

    //bool lookup();
};

#endif