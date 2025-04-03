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
    int scope;
    int line;
    SymbolEntry *next;
    
    SymbolEntry(string n, int s, int l) : name(n), scope(s), line(l) ,next(NULL){}
};

struct ScopeList
{
    SymbolEntry *data;
    ScopeList* next;
    ScopeList(int s) :  data(nullptr), next(nullptr) {}
};



class SymbolTable {
private:
    SymbolEntry* table[CAPACITY];
    ScopeList* scopes;
    //vector<list<SymbolEntry>> table;
    int SymTable_hash(string name);

public:

    SymbolTable();
    
    void insert(string name, int scope, int line);
    
    void display();
};

#endif