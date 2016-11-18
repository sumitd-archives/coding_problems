#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    map<char , int> charCount;
    for (int i = 0 ; i < 25 ; i++) {
        charCount[97+i] = 0;
    }
        
    //cout << "Enter String : ";
    cin >> input;
    for (int i = 0 ; i < input.length() ; i++) {
        charCount[input[i]]++;         
    }
    
    map<char , int>::iterator itr;
    for (itr = charCount.begin() ; itr!= charCount.end() ; itr++) {
        itr->second /= 2;
    }
        
    string current , alternative;
    for (int index = 0 ; index < input.length() ; index++) {
        char c = input[index];
        if (charCount[c] == 0) {
            alternative = current;
            for (int o_index = current.length() - 1 ; o_index>= 0 ; o_index--) {
                //get the fist occurence from the end
                if (current[o_index] == c) {
                    //remove from here and put at the end
                    //cout << "alternative = " << alternative;
                    alternative.erase(o_index , 1);
                    alternative += c;
                    //cout << "index = " << o_index;
                    //cout << "alternative = " << alternative;
                    reverse(alternative.begin() , alternative.end());
                    reverse(current.begin() , current.end());
                    if(current.compare(alternative) < 0) {
                        //current is smaller . dont do any thing . proceed
                        reverse(current.begin() , current.end());
                        alternative = current;
                        continue;
                    }
                    else {
                        reverse(alternative.begin() , alternative.end());
                        current = alternative;
                        break;
                    }
                    
                }
                
            }
        }
        else {
            current += c;
            charCount[c] --;
        }
    }
    reverse(current.begin() , current.end());
    cout << current;
    return 0;
    
}

