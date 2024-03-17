#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> lines_of_code;

    regex token_regex("\".*\"|([a-zA-Z_][a-zA-Z0-9_]*)|\\(|\\)|\\{|\\}|;|[0-9]+|,|=");
    for (auto line : lines_of_code)
    {
        sregex_iterator token_regex_iterator(
            line.begin(),
            line.end(),
            token_regex);

        sregex_iterator end;

        while (token_regex_iterator != end)
        {
            cout << "Token: " << token_regex_iterator->str() << '\n';
            ++token_regex_iterator;
        }
    }
}