#include "compiler.hpp"

int main()
{
    lexical_analyze("C:\\Users\\miker\\OneDrive\\Desktop\\ASUENG\\Junior\\semster 6\\CSE439 - Design of Compilers\\C-Lexical-and-Syntax-Analyzer\\Tests\\test.c");
    parse();

    cout << "Tokens:" << endl;
    for (const auto &token : token_stream)
    {
        cout << "(" << token.first << ", " << token.second << ")" << endl;
    }
    cout << "Lexemes:" << endl;
    for (const auto &token : token_stream)
    {
        cout << token.first;
    }
    cout << endl;
    cout << "Symbol Table:" << endl;
    cout << symbol_table;
}