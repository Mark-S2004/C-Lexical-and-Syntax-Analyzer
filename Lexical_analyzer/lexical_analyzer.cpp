#include "lexical_analyzer.hpp"

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
    case U_ARITHMETIC_OP:
        out << "U_ARITHMETIC_OP";
        break;
    case POINTER_OP:
        out << "POINTER_OP";
        break;
    case MEMBER_OP:
        out << "MEMBER_OP";
        break;
    case TERNARY_OP:
        out << "TERNARY_OP";
        break;
    case B_LOGICAL_OP:
        out << "B_LOGICAL_OP";
        break;
    case B_BITWISE_OP:
        out << "B_BITWISE_OP";
        break;
    case B_RELATIONAL_OP:
        out << "B_RELATIONAL_OP";
        break;
    case B_ASSIGNMENT_OP:
        out << "B_ASSIGNMENT_OP";
        break;
    case B_ARITHMETIC_OP:
        out << "B_ARITHMETIC_OP";
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

// Take file path as input and add each line to the lines_of_code vector
vector<string> read_c_file(string file_path)
{
    ifstream file(file_path);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
    }

    vector<string> lines_of_code;
    string line;
    while (getline(file, line))
    {
        lines_of_code.push_back(line);
    }
    file.close();

    return lines_of_code;
}

// Extract and store tokens in symbol table and hashmap
void extract_store_tokens(vector<string> lines_of_code)
{
    vector<pair<string, TOKEN_TYPE>> tokens;
    SymbolTable symbol_table;
    // Generate token extractor regex from TOKENS_REGEX map
    string token_regex_str = "";
    for (auto &entry : TOKEN_REGEX)
    {
        token_regex_str += entry.second + "|";
    }
    // For each line extract tokens
    for (const auto &line : lines_of_code)
    {
        regex token_regex(token_regex_str);
        auto tokens_begin = sregex_iterator(line.begin(), line.end(), token_regex);
        auto tokens_end = sregex_iterator();
        // For each token identify its type
        for (auto it = tokens_begin; it != tokens_end; ++it)
        {
            string lexeme = it->str();
            if (!lexeme.empty())
            { // Ensure non-empty lexemes
                TOKEN_TYPE token_type = identifyToken(lexeme);
                // Insert identifiers in symbol table
                if (token_type == IDENTIFIER)
                    symbol_table.insert(lexeme, tokens.size());
                // [B_ARITHMETIC_OP|B_BITWISE_OP]B_ASSIGNMENT_OP = B_ASSIGNMENT_OP
                if (token_type == B_ASSIGNMENT_OP && (tokens.back().second == B_ARITHMETIC_OP || tokens.back().second == B_BITWISE_OP))
                {
                    lexeme = tokens.back().first + lexeme;
                    tokens.pop_back();
                }
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
    cout << symbol_table;
}