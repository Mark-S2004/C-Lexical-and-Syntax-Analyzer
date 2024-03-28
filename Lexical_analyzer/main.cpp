#include "lexical_analyzer.hpp"

int main()
{
    vector<pair<string, TOKEN_TYPE>> tokens;
    SymbolTable symbol_table;
    pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_output;

    lexical_output = lexical_analyze("C:\\Users\\miker\\OneDrive\\Desktop\\ASUENG\\Junior\\semster 6\\CSE439 - Design of Compilers\\C-Lexical-and-Syntax-Analyzer\\Tests\\test3.c");
    tokens = lexical_output.first;
    symbol_table = lexical_output.second;

    cout << "Tokens:" << endl;
    for (const auto &token : tokens)
    {
        cout << "(" << token.first << ", " << token.second << ")" << endl;
    }
    for (const auto &token : tokens)
    {
        cout << token.first;
    }
    cout << symbol_table;
}