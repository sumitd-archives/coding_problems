#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, char> row_vals;

void FindCombinations(vector<vector<char> >table, int index, int* input, int input_len, string& output) {
    if (index == input_len) {
        cout << output << "\n";
        return;
    }
    if (row_vals.find(input[index]) != row_vals.end()) {
        output.push_back(row_vals[input[index]]);
        FindCombinations(table, index + 1, input, input_len, output);
        output.pop_back();
        return;
    }

    for (int i = 0 ; i < table[index].size(); i++) {
        output.push_back(table[index][i]);
        row_vals[input[index]] = table[index][i];
        FindCombinations(table, index + 1, input, input_len, output);
        output.pop_back();
        row_vals.erase(input[index]);
    }
}

int main() {
    vector<vector<char> > table;
    vector<char> row;
    int input[] = {1, 2, 1};
    int input_len = sizeof(input)/sizeof(input[0]);
    int cnt = 0;
    for (int i = 65; i <= 90; i++) {
        row.push_back(i);
        cnt++;
        if (cnt % 3 == 0) {
            table.push_back(row);
            cnt = 0;
            row.clear();
        }
    }
    table.push_back(row);
    string output;
    FindCombinations(table, 0, input, input_len, output);
} 
