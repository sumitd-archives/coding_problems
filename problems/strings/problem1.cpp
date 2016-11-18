#include <iostream>
#include <string>
using namespace std;
char kposition(string input, int k) {
    int len = input.length();
    int i = 0;
    int index = 0;
    while (i < len) {
        char c = input[i];
        int freq = 0;
        i += 1;
        while ((i < len) && ((input[i] - '0') <= 9)) {
            freq = 10*freq + (input[i] - '0');
            i += 1;
        }
        if (freq == 0) {
            freq = 1;
        }
        index = index + freq;
        cout << index << " , ";
        if (k <= index) {
            return c;
        }
    }
    return 'a';
}

int main()
{
    string input = "ab4c2ed3";
    cout << kposition(input, 9) << "\n";
}
