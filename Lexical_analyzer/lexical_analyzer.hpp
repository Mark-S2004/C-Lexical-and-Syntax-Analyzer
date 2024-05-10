#pragma once

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <regex>
#include <fstream>
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

// Tokens data structure functions and constants

// Lexical Analyzer functions and constants
enum TOKEN_TYPE
{
    RESERVED_KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOATING_LITERAL,
    CHARACTER_LITERAL,
    STRING_LITERAL,
    COMMENT,
    U_ARITHMETIC_OP,
    POINTER_OP,
    MEMBER_OP,
    TERNARY_OP,
    B_LOGICAL_OP,
    B_BITWISE_OP,
    B_RELATIONAL_OP,
    B_ASSIGNMENT_OP,
    B_ARITHMETIC_OP,
    RIGHT_BRACKET, 
    LEFT_BRACKET,
    RIGHT_BRACE,
    LEFT_BRACE,
    LEFT_SQUARE_BRACKET,
    RIGHT_SQUARE_BRACKET,
    COMMA,
    SEMICOLON,
    WHITESPACE,
    UNKNOWN
};

const map<TOKEN_TYPE, string> TOKEN_REGEX = {
    {RESERVED_KEYWORD, "\\b(alignas|alignof|auto|bool|break|case|char|const|constexpr|continue|default|do|double|else|enum|extern|false|float|for|goto|if|inline|int|long|nullptr|register|restrict|return|short|signed|sizeof|static|static_assert|struct|switch|thread_local|true|typedef|typeof|typeof_unqual|union|unsigned|void|volatile|while|_Alignas|_Alignof|_Atomic|_BitInt|_Bool|_Complex|_Decimal128|_Decimal32|_Decimal64|_Generic|_Imaginary|_Noreturn|_Static_assert|_Thread_local)\\b"},
    {IDENTIFIER, "[a-zA-Z_][a-zA-Z0-9_]*"},
    {INTEGER_LITERAL, "\\b[0-9]+\\b"},
    {FLOATING_LITERAL, "\\b[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?\\b"},
    {CHARACTER_LITERAL, "'[^']'"},
    {STRING_LITERAL, "\"[^\"]*\""},
    {COMMENT, "//.*"},
    {U_ARITHMETIC_OP, "\\+\\+|--"},
    {POINTER_OP, "->"}, // TODO: Handle *, & pointer operators
    {MEMBER_OP, "\\."},
    {TERNARY_OP, "\\?|:"},
    {B_LOGICAL_OP, "&&|\\|\\||!"},
    {B_BITWISE_OP, "<<|>>|\\||\\^|~|&"},
    {B_RELATIONAL_OP, "==|!=|<=|>=|<|>"},
    {B_ASSIGNMENT_OP, "="},
    {B_ARITHMETIC_OP, "\\+|-|\\*|\\/|%"},
    {RIGHT_BRACKET, "\\("},
    {LEFT_BRACKET, "\\)"},
    {RIGHT_BRACE, "\\{"},
    {LEFT_BRACE, "\\}"},
    {LEFT_SQUARE_BRACKET, "\\["},
    {RIGHT_SQUARE_BRACKET, "\\]"},
    {SEMICOLON, ";"},
    {COMMA, ","},
    {WHITESPACE, "[ \\t]+"}};

ostream &operator<<(std::ostream &out, const TOKEN_TYPE token_type);
vector<string> read_c_file(string file_path);
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> extract_store_tokens(vector<string> lines_of_code);

// Final lexical analyzer
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> lexical_analyze(string file_path);