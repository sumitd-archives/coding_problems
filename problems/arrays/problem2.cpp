#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    string sentence("   gee k s    f o r g e  k  ks   ");//   ks  for  geek s  ");
    int i = 0  , j = 0;
    while (j < sentence.length()) {
        while(sentence[j] == ' ' && (j < sentence.length())){
            j++; 
        }
        if (j != sentence.length()) {
            sentence[i++] = sentence[j++];
        }
    }
    sentence[i] = '\0';
    //cout << sentence -> wont work
    cout << sentence.c_str() << "\n";
}

//In C++ , string does not treat '\0' as end of character . cout << str will fail . cout<<str.c_str() will work
