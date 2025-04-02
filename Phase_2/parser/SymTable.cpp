#include"SymTable.hpp"



SymbolTable::SymbolTable() : table(CAPACITY) {}

void SymbolTable::display(){
    for (int i = 0; i < CAPACITY; i++) {
        if (!table[i].empty()) {
            cout << "Index " << i << ": ";
            for (auto &entry : table[i]) {
                cout << "[" << entry.name << ", Scope: " << entry.scope << ", Line: " << entry.line << "] "<< endl;
            }
            cout << endl;
        }
    }
}

void SymbolTable::insert(string name , int scope , int line){
    int index = hashFunction(name);
    table[index].push_back(SymbolEntry(name, scope, line));
}


int SymbolTable::hashFunction(string name){
    int hash = 0;
    for (char c : name) {
        hash = (hash * 31 + c) % CAPACITY;
    }
    return hash;
}
