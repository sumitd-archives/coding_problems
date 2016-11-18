#include<iostream>
#include<string>
using namespace std;

void BreakIntoBrackets(string input, string output, int index) {
    if (index == input.length()) {
        cout << output << "\n";
        return;
    }

    output.push_back('(');
    for (int i = index; i < input.length(); i++) {
        output.push_back(input[i]);
        output.push_back(')');
        BreakIntoBrackets(input, output, i + 1);
        output.pop_back();
    }
}

int main() {
    string input = "abcd";
    string output;
    BreakIntoBrackets(input, output, 0);
}
