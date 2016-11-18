#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector < string > missingWords(string s, string t) {
vector<string>output;
    int j = 0;
    int k = 0;
    for (int i = 0 ; i < s.length(); i++) {
        if (s[i] == t[j]) {
            j++;
            cout << j << " "
            continue;
        }
        cout <<"\n"
        //find the missing word
        k = i;
        //cout << "here" <<  " " << i << "\n";
        while((s[i] != ' ') && (s[i] != '\0')) {
           // cout << i <<" " ;
            i++;    
        }
        cout << k << " " << i << "\n";
        string res = s.substr(k, (i -k));
        output.push_back(res);
        while(s[i] == ' ') {
            i++;
        }
    }
    return output;
}

int main() {
    string s1 = "Sumit Das is a good boy";
    string s2 = "Das a good";
    vector<string> result = missingWords(s1, s2);
cout << result.size() << "\n";  
for (int i = 0 ; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}
