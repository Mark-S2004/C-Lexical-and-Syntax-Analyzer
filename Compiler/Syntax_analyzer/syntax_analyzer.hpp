#pragma once

#include "../tokens_enum.hpp"
using namespace std;

// Parse tree node data structure
class parse_tree_node
{
public:
    bool is_terminal;
    string label;
    deque<parse_tree_node *> children;
    parse_tree_node(string l, bool t) : label(l), is_terminal(t) {}
};

// A function to uniquely identify the node in graphviz dot style
ostream &operator<<(std::ostream &out, parse_tree_node *node);

// Parse Tree visualizer, and as usual with recursive tree visualizers we need an auxiliary function
void visualize_parse_tree(parse_tree_node *root);
void visualize_parse_tree_aux(parse_tree_node *node, std::ostream &out);

// Parser functions
inline string buf;
inline TOKEN_TYPE tok;

inline unordered_map<string, unordered_map<string, vector<string>>> parsing_table;
void init_parsing_table();
int get_next_token();
parse_tree_node *generate_parse_tree(vector<pair<string, TOKEN_TYPE>>);

// final parse function
void parse();