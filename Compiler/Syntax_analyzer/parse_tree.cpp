#include "syntax_analyzer.hpp"

std::ostream &operator<<(std::ostream &out, parse_tree_node *node)
{
    out << "\"" << (void *)node << "\" [label=\"" << node->label << "\"]";
    return out;
}

void visualize_parse_tree(parse_tree_node *root)
{

    std::ofstream dot_file_out("parse_tree.dot", std::ios::trunc);

    // TODO: Would be nice if you decorated your parse tree, lookup how to do so in graphviz dot notation
    dot_file_out << "digraph G {\n";
    visualize_parse_tree_aux(root, dot_file_out);
    dot_file_out << "}";
    dot_file_out.close();

    // Convert the dot file into a SVG vector image
    system("dot -Tsvg ./parse_tree.dot -oparse_tree.svg");

    // Open the vector file
    // TODO: Integrate this with your GUI...
    // You'll need to lookup how to open an .svg file inside Qt or whatever GUI framework you are using
    system("parse_tree.svg");
}

void visualize_parse_tree_aux(parse_tree_node *node, std::ostream &out)
{

    // Need to uniquely identify each node in graphviz
    out << "  " << node << (node->is_terminal ? "[fontcolor=\"red\"][color=\"red\"];\n" : ";\n");

    for (auto child : node->children)
    {

        bool child_has_children = child->children.size() > 0;
        if (child->is_terminal || (!child->is_terminal && child_has_children))
        {

            // Need to uniquely identify each child node too
            out << "  " << child << ";\n";

            // Create edge between node and child unique addresses
            out << "  \"" << (void *)node << "\" -> \"" << (void *)child << "\";\n";

            // Recursively build rest of tree
            visualize_parse_tree_aux(child, out);
        }
    }
}
