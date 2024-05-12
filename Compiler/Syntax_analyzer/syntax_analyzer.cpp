#include "syntax_analyzer.hpp"

int get_next_token()
{
    static int counter = 0;
    if (counter == token_stream.size())
    {
        tok = EndOfFile;
        return 0;
    }

    pair<string, TOKEN_TYPE> token_pair = token_stream[counter++];
    buf = token_pair.first;
    tok = token_pair.second;
    return counter;
}

void init_parsing_table()
{
    parsing_table["Assignment"][type_to_str(DATATYPE)] = {type_to_str(DATATYPE), type_to_str(IDENTIFIER), "list1"};
    parsing_table["Assignment"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "list1"};

    parsing_table["assignment-data-type_declaration"][type_to_str(DATATYPE)] = {type_to_str(DATATYPE), type_to_str(IDENTIFIER), "list1"};

    parsing_table["assignment-without-data-type"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "list1"};

    parsing_table["list1"][type_to_str(B_ASSIGNMENT_OP)] = {type_to_str(B_ASSIGNMENT_OP), "exp", "list"};
    parsing_table["list1"][type_to_str(COMMA)] = {type_to_str(COMMA), "assignment-without-data-type"};
    parsing_table["list1"][type_to_str(SEMICOLON)] = {type_to_str(SEMICOLON)};
    parsing_table["list1"][type_to_str(U_ARITHMETIC_OP)] = {type_to_str(U_ARITHMETIC_OP), type_to_str(SEMICOLON)};

    parsing_table["rb"][type_to_str(RIGHT_BRACKET)] = {type_to_str(RIGHT_BRACKET)};
    parsing_table["rb"][type_to_str(IDENTIFIER)] = {};
    parsing_table["rb"][type_to_str(INTEGER_LITERAL)] = {};
    parsing_table["rb"][type_to_str(FLOATING_LITERAL)] = {};
    parsing_table["rb"][type_to_str(CHARACTER_LITERAL)] = {};
    parsing_table["rb"][type_to_str(STRING_LITERAL)] = {};
    parsing_table["rb"][type_to_str(BOOL_LITERAL)] = {};
    parsing_table["rb"]["!"] = {};
    parsing_table["rb"][type_to_str(U_ARITHMETIC_OP)] = {};

    parsing_table["lb"][type_to_str(LEFT_BRACKET)] = {type_to_str(LEFT_BRACKET)};
    parsing_table["lb"][type_to_str(COMMA)] = {};
    parsing_table["lb"][type_to_str(SEMICOLON)] = {};
    parsing_table["lb"][type_to_str(B_LOGICAL_OP)] = {};
    parsing_table["lb"][type_to_str(B_ARITHMETIC_OP)] = {};
    parsing_table["lb"][type_to_str(B_RELATIONAL_OP)] = {};
    parsing_table["lb"][type_to_str(B_BITWISE_OP)] = {};

    parsing_table["exp_bracket"][type_to_str(RIGHT_BRACKET)] = {type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(U_ARITHMETIC_OP)] = {type_to_str(U_ARITHMETIC_OP), type_to_str(IDENTIFIER), "u_operator", "exp_list"};
    parsing_table["exp_bracket"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "u_operator", "exp_list"};
    parsing_table["exp_bracket"]["!"] = {"!", type_to_str(IDENTIFIER), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(INTEGER_LITERAL)] = {type_to_str(INTEGER_LITERAL), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(FLOATING_LITERAL)] = {type_to_str(FLOATING_LITERAL), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(CHARACTER_LITERAL)] = {type_to_str(CHARACTER_LITERAL), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(STRING_LITERAL)] = {type_to_str(STRING_LITERAL), "exp_list"};
    parsing_table["exp_bracket"][type_to_str(BOOL_LITERAL)] = {type_to_str(BOOL_LITERAL), "exp_list"};

    parsing_table["exp_list"][type_to_str(B_ARITHMETIC_OP)] = {type_to_str(B_ARITHMETIC_OP), "exp_bracket"};
    parsing_table["exp_list"][type_to_str(B_LOGICAL_OP)] = {type_to_str(B_LOGICAL_OP), "exp_bracket"};
    parsing_table["exp_list"][type_to_str(B_RELATIONAL_OP)] = {type_to_str(B_RELATIONAL_OP), "exp_bracket"};
    parsing_table["exp_list"][type_to_str(B_BITWISE_OP)] = {type_to_str(B_BITWISE_OP), "exp_bracket"};
    parsing_table["exp_list"][type_to_str(COMMA)] = {};
    parsing_table["exp_list"][type_to_str(SEMICOLON)] = {};
    parsing_table["exp_list"][type_to_str(LEFT_BRACKET)] = {};

    parsing_table["exp"][type_to_str(U_ARITHMETIC_OP)] = {type_to_str(U_ARITHMETIC_OP), type_to_str(IDENTIFIER), "u_operator", "operation"};
    parsing_table["exp"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "u_operator", "operation"};
    parsing_table["exp"]["!"] = {"!", "rb", type_to_str(IDENTIFIER), "lb", "operation"};
    parsing_table["exp"][type_to_str(INTEGER_LITERAL)] = {type_to_str(INTEGER_LITERAL), "operation"};
    parsing_table["exp"][type_to_str(FLOATING_LITERAL)] = {type_to_str(FLOATING_LITERAL), "operation"};
    parsing_table["exp"][type_to_str(CHARACTER_LITERAL)] = {type_to_str(CHARACTER_LITERAL), "operation"};
    parsing_table["exp"][type_to_str(STRING_LITERAL)] = {type_to_str(STRING_LITERAL), "operation"};

    parsing_table["term"][type_to_str(U_ARITHMETIC_OP)] = {type_to_str(U_ARITHMETIC_OP), type_to_str(IDENTIFIER), "u_operator"};
    parsing_table["term"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "u_operator"};
    parsing_table["term"]["!"] = {"!", "rb", type_to_str(IDENTIFIER), "lb"};
    parsing_table["term"][type_to_str(INTEGER_LITERAL)] = {type_to_str(INTEGER_LITERAL)};
    parsing_table["term"][type_to_str(FLOATING_LITERAL)] = {type_to_str(FLOATING_LITERAL)};
    parsing_table["term"][type_to_str(CHARACTER_LITERAL)] = {type_to_str(CHARACTER_LITERAL)};
    parsing_table["term"][type_to_str(STRING_LITERAL)] = {type_to_str(STRING_LITERAL)};

    parsing_table["u_operator"][type_to_str(U_ARITHMETIC_OP)] = {type_to_str(U_ARITHMETIC_OP)};
    parsing_table["u_operator"][type_to_str(IDENTIFIER)] = {};
    parsing_table["u_operator"][type_to_str(LEFT_BRACKET)] = {};
    parsing_table["u_operator"][type_to_str(B_ARITHMETIC_OP)] = {};
    parsing_table["u_operator"][type_to_str(B_LOGICAL_OP)] = {};
    parsing_table["u_operator"][type_to_str(B_RELATIONAL_OP)] = {};
    parsing_table["u_operator"][type_to_str(B_BITWISE_OP)] = {};
    parsing_table["u_operator"][type_to_str(COMMA)] = {};
    parsing_table["u_operator"][type_to_str(SEMICOLON)] = {};

    parsing_table["operation"][type_to_str(B_ARITHMETIC_OP)] = {type_to_str(B_ARITHMETIC_OP), "exp_bracket"};
    parsing_table["operation"][type_to_str(B_LOGICAL_OP)] = {type_to_str(B_LOGICAL_OP), "exp_bracket"};
    parsing_table["operation"][type_to_str(B_RELATIONAL_OP)] = {type_to_str(B_RELATIONAL_OP), "exp_bracket"};
    parsing_table["operation"][type_to_str(B_BITWISE_OP)] = {type_to_str(B_BITWISE_OP), "exp_bracket"};
    parsing_table["operation"][type_to_str(COMMA)] = {};
    parsing_table["operation"][type_to_str(SEMICOLON)] = {};
    parsing_table["operation"][type_to_str(LEFT_BRACKET)] = {};

    parsing_table["b_operator"][type_to_str(B_ARITHMETIC_OP)] = {type_to_str(B_ARITHMETIC_OP)};
    parsing_table["b_operator"][type_to_str(B_LOGICAL_OP)] = {type_to_str(B_LOGICAL_OP)};
    parsing_table["b_operator"][type_to_str(B_RELATIONAL_OP)] = {type_to_str(B_RELATIONAL_OP)};
    parsing_table["b_operator"][type_to_str(B_BITWISE_OP)] = {type_to_str(B_BITWISE_OP)};

    parsing_table["list"][type_to_str(COMMA)] = {type_to_str(COMMA), "assignment-without-data-type"};
    parsing_table["list"][type_to_str(SEMICOLON)] = {type_to_str(SEMICOLON)};

    parsing_table["while_loop"][type_to_str(WHILE)] = {type_to_str(WHILE), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement"};

    parsing_table["if_stmt"][type_to_str(IF)] = {type_to_str(IF), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement", "else"};

    parsing_table["else"][type_to_str(ELSE)] = {type_to_str(ELSE), "loop_statement"};
    parsing_table["else"][type_to_str(EndOfFile)] = {};
    parsing_table["else"][type_to_str(DATATYPE)] = {};
    parsing_table["else"][type_to_str(IDENTIFIER)] = {};
    parsing_table["else"][type_to_str(WHILE)] = {};
    parsing_table["else"][type_to_str(IF)] = {};
    parsing_table["else"][type_to_str(ELSE)] = {};

    parsing_table["loop_statement"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "list1"};
    parsing_table["loop_statement"][type_to_str(DATATYPE)] = {type_to_str(DATATYPE), type_to_str(IDENTIFIER), "list1"};
    parsing_table["loop_statement"][type_to_str(IF)] = {type_to_str(IF), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement", "else"};
    parsing_table["loop_statement"][type_to_str(WHILE)] = {type_to_str(WHILE), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement"};
    parsing_table["loop_statement"][type_to_str(RIGHT_BRACE)] = {type_to_str(RIGHT_BRACE), "statements", type_to_str(LEFT_BRACE)};

    parsing_table["statement"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "list1"};
    parsing_table["statement"][type_to_str(DATATYPE)] = {type_to_str(DATATYPE), type_to_str(IDENTIFIER), "list1"};
    parsing_table["statement"][type_to_str(IF)] = {type_to_str(IF), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement", "else"};
    parsing_table["statement"][type_to_str(WHILE)] = {type_to_str(WHILE), type_to_str(RIGHT_BRACKET), "", type_to_str(LEFT_BRACKET), "loop_statement"};

    parsing_table["statements"][type_to_str(IDENTIFIER)] = {type_to_str(IDENTIFIER), "list1", "statements"};
    parsing_table["statements"][type_to_str(DATATYPE)] = {type_to_str(DATATYPE), type_to_str(IDENTIFIER), "list1", "statements"};
    parsing_table["statements"][type_to_str(IF)] = {type_to_str(IF), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement", "else", "statements"};
    parsing_table["statements"][type_to_str(WHILE)] = {type_to_str(WHILE), type_to_str(RIGHT_BRACKET), "exp", type_to_str(LEFT_BRACKET), "loop_statement", "statements"};
    parsing_table["statements"][type_to_str(LEFT_BRACE)] = {};
    parsing_table["statements"][type_to_str(EndOfFile)] = {};
}

parse_tree_node *generate_parse_tree()
{
    stack<parse_tree_node *> parsing_stack;
    parsing_stack.push(new parse_tree_node("EndOfFile", true));   // We always place $ at the bottom of the stack
    parsing_stack.push(new parse_tree_node("statements", false)); // Followed by the top non-terminal of our CFG
    parse_tree_node *root = parsing_stack.top();                  // Let's keep track of this top node so we can return it later

    // Prepare the first token to parse
    int buffer_offset = get_next_token();

    // And now let the LL(1) cooking begin
    // While the stack hasn't reached the bottom entry yet, and the buffer still has content
    while (parsing_stack.top()->label != "EndOfFile" && buffer_offset != 0)
    {
        // We will be working with the top of stack every iteration, see what to do with it
        parse_tree_node *top_of_stack = parsing_stack.top();

        // cout << "[LOG] | Current top of stack: \"" << top_of_stack->label;
        // cout << "\" and current token in buffer: \"" << buf;
        // cout << "\", " << type_to_str(tok) << '\n';

        // If it is a terminal,
        if (top_of_stack->is_terminal)
        {
            // Check if it matches the current token
            if (top_of_stack->label == type_to_str(tok))
            {
                // If it does, pop the stack, get the next token, and move on to the next iteration
                // But before you do, augment the node with the value of the variable (if it is a variable, like type_to_str(identifier) or number)
                parsing_stack.top()->label = buf;
                parsing_stack.pop();
                buffer_offset = get_next_token();
                continue;
            }
            else
                return nullptr;
        }
        else
        {
            if (parsing_table[top_of_stack->label].count(type_to_str(tok)) != 0)
            {
                parsing_stack.pop();
                for (int i = parsing_table[top_of_stack->label][type_to_str(tok)].size() - 1; i >= 0; i--)
                {
                    string production_item = parsing_table[top_of_stack->label][type_to_str(tok)][i];
                    bool is_terminal = parsing_table.find(production_item) == parsing_table.end();
                    parse_tree_node *node = new parse_tree_node(production_item, is_terminal);
                    top_of_stack->children.push_front(node);
                    parsing_stack.push(node);
                }
            }
            else
                return nullptr;
        }
    }

    // If the loop finishes with no errors, and the top of the stack is $, with an empty buffer, then all is well
    if (buffer_offset == 0)
        return root;
    // Otherwise, either the stack or the buffer finished prematurely, so, parse failure
    else
        return nullptr;
}

void parse()
{
    init_parsing_table();
    parse_tree_node *parse_tree_root_node;

    parse_tree_root_node = generate_parse_tree();

    cout << parse_tree_root_node;

    cout << (parse_tree_root_node ? "Parsing successful.\n" : "Parsing failed.\n") << endl;
    if (parse_tree_root_node)
        visualize_parse_tree(parse_tree_root_node);
}