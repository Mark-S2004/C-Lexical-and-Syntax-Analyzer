#include "lexical_analyzer.hpp"

int main()
{
    vector<pair<string, TOKEN_TYPE>> tokens;
    SymbolTable symbol_table;
    pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_output;

    lexical_output = lexical_analyze("C:/Users/DELL/Desktop/Compiler moni/C-Lexical-and-Syntax-Analyzer\\Tests\\test3.c");
    tokens = lexical_output.first;
    symbol_table = lexical_output.second;

    cout << "Tokens:" << endl;
    for (const auto &token : tokens)
    {
        cout << "(" << token.first << ", " << token.second << ")" << endl;
    }
    cout << "Lexemes:" << endl;
    for (const auto &token : tokens)
    {
        cout << token.first<<endl;
    }
    cout << "Symbol Table:" << endl;
    cout << symbol_table;
}