#include "SymTable.hpp"

int main() {
    SymbolTable symTable;
    
    // Insert some symbols
    symTable.insert("x", 0, 10);
    symTable.insert("y", 0, 12);
    symTable.insert("z", 1, 15);
    symTable.insert("x", 1, 20); // Same name, different scope

    // Display the symbol table
    symTable.display();

    return 0;
}
