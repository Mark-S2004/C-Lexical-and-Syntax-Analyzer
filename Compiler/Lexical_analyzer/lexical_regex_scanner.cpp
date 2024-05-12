#include "lexical_analyzer.hpp"

ostream &operator<<(std::ostream &out, const TOKEN_TYPE token_type)
{
    out << type_to_str(token_type);
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
pair<vector<pair<string, TOKEN_TYPE>>, SymbolTable> extract_store_tokens(vector<string> lines_of_code)
{
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
                    symbol_table.insert(lexeme, token_stream.size());
                // [B_ARITHMETIC_OP|B_BITWISE_OP]B_ASSIGNMENT_OP = B_ASSIGNMENT_OP
                if (token_type == B_ASSIGNMENT_OP && (token_stream.back().second == B_ARITHMETIC_OP || token_stream.back().second == B_BITWISE_OP))
                {
                    lexeme = token_stream.back().first + lexeme;
                    token_stream.pop_back();
                }
                if (token_type != COMMENT && token_type != WHITESPACE)
                    token_stream.push_back({lexeme, token_type});
            }
        }
    }

    return {token_stream, symbol_table};
}