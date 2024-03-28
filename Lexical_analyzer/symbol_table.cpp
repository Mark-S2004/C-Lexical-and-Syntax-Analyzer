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
        for (auto &offset : identifier.second)
            cout << offset << ", ";
        cout << "}>\n";
    }
}

ostream &operator<<(ostream &out, SymbolTable symbol_table)
{
    symbol_table.display(out);
    return out;
}