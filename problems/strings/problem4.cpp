#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool  IsCircularChain(vector<string>& arr) {
    int n = arr.size();
    int start[26]; int end[26]; int startendsame[26];
    int i;
    for (i = 0 ; i < 26 ; i++) {
        start[i] = 0;
        end[i] = 0;
        startendsame[i] = 0;
    }
    for (i = 0; i < n; i++) {
        string current = arr[i];
        int length = current.length();
        char begin = current[0];
        char last = current[length - 1];
        start[begin - 'a']++;
        end[last - 'a']++;
        if (begin == last) {
            startendsame[begin - 'a']++;
        }
    }

    for (i = 0 ; i < 26; i++) {
        int val = startendsame[i];
        if ((val % 2) == 1) {
            if ((start[i] <= val) || (end[i] <= val)) {
                if (arr.size() == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        if (start[i] != end[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string arr[] = {"aaa"};
    vector<string> input;
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        input.push_back(arr[i]);
    }
    cout << IsCircularChain(input) << "\n";
}

        
