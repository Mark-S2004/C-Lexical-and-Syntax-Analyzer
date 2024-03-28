#include "lexical_analyzer.hpp"

pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_analyze(string file_path)
{
    vector<string> lines_of_code = read_c_file(file_path);
    return extract_store_tokens(lines_of_code);
}