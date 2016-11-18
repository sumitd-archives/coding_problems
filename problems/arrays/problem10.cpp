#include<iostream>
using namespace std;

bool match(const string& input) {
    int len = input.size();
    char stack[len];
    int top = -1;
    for (int i = 0 ; i < len ; i++) {
        char element = input[i];
        if (element == '(') {
            stack[++top] = element;
        }
        else if (element == ')') {
            if (top < 0) {
                return false;
            }
            if (stack[top--] != '('){
                return false;
            }
        }
    }
    if (top != -1) {
        return false;
    }
    return true;
}

int main()
{
    string input = "abc(d))";
    if (match(input)) {
        cout<<"true";
    }
    else {
        cout<<"false";
    }
}
