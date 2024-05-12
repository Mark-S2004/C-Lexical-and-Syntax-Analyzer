#pragma once

#include "../tokens_enum.hpp"
using namespace std;

// Symbol Table functions and constants
class SymbolTable
{
    unordered_map<string, list<int>> symbol_table_hashmap;

public:
    SymbolTable() {}

    void insert(string name, int offset);
    void display(ostream &out);
};
ostream &operator<<(std::ostream &out, SymbolTable symbol_table);

// Lexical Analyzer functions
ostream &operator<<(std::ostream &out, const TOKEN_TYPE token_type);
vector<string> read_c_file(string file_path);
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> extract_store_tokens(vector<string> lines_of_code);

// Final lexical analyzer
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_analyze(string file_path);