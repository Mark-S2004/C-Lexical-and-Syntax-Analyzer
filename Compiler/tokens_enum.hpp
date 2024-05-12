#pragma once
#include <bits/stdc++.h>
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

// Tokens constants
enum TOKEN_TYPE
{
    RESERVED_KEYWORD,
    DATATYPE,
    IF,
    ELSE,
    WHILE,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOATING_LITERAL,
    CHARACTER_LITERAL,
    STRING_LITERAL,
    BOOL_LITERAL,
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
    UNKNOWN,
    EndOfFile
};

inline vector<pair<string, TOKEN_TYPE>> token_stream;
inline SymbolTable symbol_table;

const map<TOKEN_TYPE, string> TOKEN_REGEX = {
    {RESERVED_KEYWORD, "\\b(alignas|alignof|auto|bool|break|case|const|constexpr|continue|default|do|enum|extern|for|goto|inline|nullptr|register|restrict|return|signed|sizeof|static|static_assert|struct|switch|thread_local|typedef|typeof|typeof_unqual|union|unsigned|void|volatile|_Alignas|_Alignof|_Atomic|_BitInt|_Bool|_Complex|_Decimal128|_Decimal32|_Decimal64|_Generic|_Imaginary|_Noreturn|_Static_assert|_Thread_local)\\b"},
    {DATATYPE, "float|int|long|short|char|double"},
    {IF, "if"},
    {ELSE, "else"},
    {WHILE, "while"},
    {IDENTIFIER, "[a-zA-Z_][a-zA-Z0-9_]*"},
    {INTEGER_LITERAL, "\\b[0-9]+\\b"},
    {FLOATING_LITERAL, "\\b[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?\\b"},
    {CHARACTER_LITERAL, "'[^']'"},
    {STRING_LITERAL, "\"[^\"]*\""},
    {BOOL_LITERAL, "true|false"},
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

inline string type_to_str(TOKEN_TYPE token_type)
{
    switch (token_type)
    {
    case RESERVED_KEYWORD:
        return "RESERVED_KEYWORD";
        break;
    case IDENTIFIER:
        return "IDENTIFIER";
        break;
    case INTEGER_LITERAL:
        return "INTEGER_LITERAL";
        break;
    case FLOATING_LITERAL:
        return "FLOATING_LITERAL";
        break;
    case CHARACTER_LITERAL:
        return "CHARACTER_LITERAL";
        break;
    case STRING_LITERAL:
        return "STRING_LITERAL";
        break;
    case U_ARITHMETIC_OP:
        return "U_ARITHMETIC_OP";
        break;
    case POINTER_OP:
        return "POINTER_OP";
        break;
    case MEMBER_OP:
        return "MEMBER_OP";
        break;
    case TERNARY_OP:
        return "TERNARY_OP";
        break;
    case B_LOGICAL_OP:
        return "B_LOGICAL_OP";
        break;
    case B_BITWISE_OP:
        return "B_BITWISE_OP";
        break;
    case B_RELATIONAL_OP:
        return "B_RELATIONAL_OP";
        break;
    case B_ASSIGNMENT_OP:
        return "B_ASSIGNMENT_OP";
        break;
    case B_ARITHMETIC_OP:
        return "B_ARITHMETIC_OP";
        break;
    case RIGHT_BRACKET:
        return "RIGHT_BRACKET";
        break;
    case LEFT_BRACKET:
        return "LEFT_BRACKET";
        break;
    case RIGHT_BRACE:
        return "RIGHT_BRACE";
        break;
    case LEFT_BRACE:
        return "LEFT_BRACE";
        break;
    case LEFT_SQUARE_BRACKET:
        return "LEFT_SQUARE_BRACKET";
        break;
    case RIGHT_SQUARE_BRACKET:
        return "RIGHT_SQUARE_BRACKET";
        break;
    case SEMICOLON:
        return "SEMICOLON";
        break;
    case COMMA:
        return "COMMA";
        break;
    case WHITESPACE:
        return "WHITESPACE";
        break;
    case COMMENT:
        return "COMMENT";
        break;
    case UNKNOWN:
        return "UNKNOWN";
        break;

    case EndOfFile:
        return "EndOfFile";
        break;

    case DATATYPE:
        return "DATATYPE";
        break;

    case IF:
        return "IF";
        break;

    case ELSE:
        return "ELSE";
        break;

    case WHILE:
        return "WHILE";
        break;

    case BOOL_LITERAL:
        return "BOOL_LITERAL";
        break;

    default:
        break;
    }

    return "None";
}
