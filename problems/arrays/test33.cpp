#include<iostream>
#include<string>
using namespace std;

string rearrangeWord(string word) {
    bool result = false;
    int len = word.length();
    for (int j = (len - 1) ; j > 0 ; j--) {
        for (int k = (j - 1) ; k >= 0; k--) {
            int a1 = word[j] - 'a';
            int a2 = word[k] - 'a';
            if (a1 > a2) {
                cout <<j <<" "<<k;
                char temp = word[j];
                word[j] = word[k];
                word[k] = temp;
                return word;
            }
        }
    }
    return ("no answer");
}

int main() {
    string input = "hefg";
    cout << rearrangeWord(input) << "\n";
}

