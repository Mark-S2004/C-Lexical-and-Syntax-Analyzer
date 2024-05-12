#pragma once

#include "../tokens_enum.hpp"
using namespace std;

// Lexical Analyzer functions
ostream &operator<<(std::ostream &out, const TOKEN_TYPE token_type);
vector<string> read_c_file(string file_path);
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> extract_store_tokens(vector<string> lines_of_code);

// Final lexical analyzer
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_analyze(string file_path);