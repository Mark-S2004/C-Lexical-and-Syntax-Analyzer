#include <bits/stdc++.h>
using namespace std;

enum TOKEN_TYPE
{
    RESERVED_KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOATING_LITERAL,
    CHARACTER_LITERAL,
    STRING_LITERAL,
    COMMENT,
    OPERATOR,
    SPECIAL_SYMBOL,
    WHITESPACE,
    UNKNOWN
};

ostream &operator<<(std::ostream &out, const TOKEN_TYPE token_type)
{
    switch (token_type)
    {
    case RESERVED_KEYWORD:
        out << "RESERVED_KEYWORD";
        break;
    case IDENTIFIER:
        out << "IDENTIFIER";
        break;
    case INTEGER_LITERAL:
        out << "INTEGER_LITERAL";
        break;
    case FLOATING_LITERAL:
        out << "FLOATING_LITERAL";
        break;
    case CHARACTER_LITERAL:
        out << "CHARACTER_LITERAL";
        break;
    case STRING_LITERAL:
        out << "STRING_LITERAL";
        break;
    case OPERATOR:
        out << "OPERATOR";
        break;
    case SPECIAL_SYMBOL:
        out << "SPECIAL_SYMBOL";
        break;
    case WHITESPACE:
        out << "WHITESPACE";
        break;
    case COMMENT:
        out << "COMMENT";
        break;
    case UNKNOWN:
        out << "UNKNOWN";
        break;

    default:
        break;
    }

    return out;
}

map<TOKEN_TYPE, string> TOKEN_REGEX = {
    {RESERVED_KEYWORD, "\\b(alignas|alignof|auto|bool|break|case|char|const|constexpr|continue|default|do|double|else|enum|extern|false|float|for|goto|if|inline|int|long|nullptr|register|restrict|return|short|signed|sizeof|static|static_assert|struct|switch|thread_local|true|typedef|typeof|typeof_unqual|union|unsigned|void|volatile|while|_Alignas|_Alignof|_Atomic|_BitInt|_Bool|_Complex|_Decimal128|_Decimal32|_Decimal64|_Generic|_Imaginary|_Noreturn|_Static_assert|_Thread_local)\\b"},
    {IDENTIFIER, "[a-zA-Z_][a-zA-Z0-9_]*"},
    {INTEGER_LITERAL, "\\b[0-9]+\\b"},
    {FLOATING_LITERAL, "\\b[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?\\b"},
    {CHARACTER_LITERAL, "'[^']'"},
    {STRING_LITERAL, "\"[^\"]*\""},
    {OPERATOR, "\\+\\+|--|->|<<|>>|<=|>|>=|==|!=|&&|\\|\\||!|\\||\\^|~|\\?|:|\\+=|-=|\\*=|\\/=|%=|<<=|>>=|&=|\\|\\^=|->\\*|\\.\\*|=|<|>|&|\\+|-|\\*|\\/|%"},
    {SPECIAL_SYMBOL, "\\(|\\)|\\[|\\]|\\{|\\}|,|;|\\."},
    {WHITESPACE, "[ \\t]+"},
    {COMMENT, "//.*"}};

// Function to identify token type
TOKEN_TYPE identifyToken(const string &lexeme)
{
    for (auto &entry : TOKEN_REGEX)
    {
        if (regex_match(lexeme, regex(entry.second)))
        {
            return entry.first;
        }
    }
    return UNKNOWN;
}

int main()
{
    // Step 1: Take file path as input and add each line to the lines_of_code vector
    string file_path;
    cout << "Enter file path: ";
    getline(cin, file_path); // Allowing spaces and special characters in file path

    ifstream file(file_path);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    vector<string> lines_of_code;
    string line;
    while (getline(file, line))
    {
        lines_of_code.push_back(line);
    }
    file.close();

    // Step 2: Extract tokens
    vector<pair<string, TOKEN_TYPE>> tokens;
    string token_regex_str = "";
    for (auto &entry : TOKEN_REGEX)
    {
        token_regex_str += entry.second + "|";
    }
    for (const auto &line : lines_of_code)
    {
        // regex token_regex("\\b\\w+\\b|'[^']'|\"[^\"]*\"|//.*|[(){};]|[+\\-*/%][+\\-=]?|[!=]?=||[&\\|][&\\|]?|[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?|[ \\t]+|,|\\.");
        regex token_regex(token_regex_str);
        auto tokens_begin = sregex_iterator(line.begin(), line.end(), token_regex);
        auto tokens_end = sregex_iterator();

        for (auto it = tokens_begin; it != tokens_end; ++it)
        {
            string lexeme = it->str();
            if (!lexeme.empty())
            { // Ensure non-empty lexemes
                TOKEN_TYPE token_type = identifyToken(lexeme);
                tokens.push_back({lexeme, token_type});
            }
        }
    }

    // Print tokens
    cout << "Tokens:" << endl;
    for (const auto &token : tokens)
    {
        cout << "(" << token.first << ", " << token.second << ")" << endl;
    }
    for (const auto &token : tokens)
    {
        cout << token.first;
    }

    return 0;
}