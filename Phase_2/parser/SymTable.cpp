#include"SymTable.hpp"



/*SymbolTable::SymbolTable() : table(CAPACITY) {}

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
}*/

void SymbolTable::display() {
    for (int i = 0; i < CAPACITY; i++) {
        if (table[i] != nullptr) {  // Check if the linked list at index i is not empty
            cout << "Index " << i << ": ";
            SymbolEntry* current = table[i]; // Start at the head of the linked list
            while (current != nullptr) {
                cout << "[" << current->name << ", Scope: " << current->scope << ", Line: " << current->line << "] ";
                current = current->next; // Move to the next node
            }
            cout << endl;
        }
    }
}

void SymbolTable::insert(string name , int scope , int line){
    int index = hashFunction(name);
    if (table[index]==nullptr){
        table[index]=&SymbolEntry(name,scope,line);
    }
    else{
        SymbolEntry* temp_list=table[index];
        while(temp_list->next!=NULL){
            table[index]=&SymbolEntry(name,scope,line);
        }
    }
    //table[index].push_back(SymbolEntry(name, scope, line));
}


int SymbolTable::hashFunction(string name){
    int hash = 0;
    for (char c : name) {
        hash = (hash * 31 + c) % CAPACITY-1;
    }
    return hash+1;
}
