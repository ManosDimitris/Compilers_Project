#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define CAPACITY 510



struct SymbolEntry {
    string name;
    int scope;
    int line;
    SymbolEntry *nextSc;
    SymbolEntry *next;
    
    SymbolEntry(string n, int s, int l) : name(n), scope(s), line(l) ,nextSc(NULL) ,next(NULL){}
};


class SymbolTable {
private:
    SymbolEntry* table[CAPACITY];
    //vector<list<SymbolEntry>> table;
    int hashFunction(string name);

public:

    SymbolTable();
    
    void insert(string name, int scope, int line);
    
    void display();
};

#endif