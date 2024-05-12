#include "lexical_analyzer.hpp"

// Insert identifier to the symbol table to store its name and offset in the file
void SymbolTable::insert(string name, int offset)
{
    symbol_table_hashmap[name].push_back(offset);
}

void SymbolTable::display(ostream &out)
{
    for (auto &identifier : symbol_table_hashmap)
    {
        cout << '<' << identifier.first << ", {";
        bool first = true; 
        for (auto &offset : identifier.second) {
            if (!first) 
                cout << ", ";
            cout << offset;
            first = false; 
        }
        cout << "}>\n";
    }
}

ostream &operator<<(ostream &out, SymbolTable symbol_table)
{
    symbol_table.display(out);
    return out;
}