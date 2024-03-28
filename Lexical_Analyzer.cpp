#include <bits/stdc++.h>
using namespace std;

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
}