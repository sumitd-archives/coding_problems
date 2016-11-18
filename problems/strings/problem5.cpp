#include<iostream>
#include<string>
using namespace std;

int main() {
    string input = "acaaabbbacdddd";
    string output = input;
    int index1 = 0, index2 = -1;
    int i = 1;
    int length = input.length();
    while (i < length) {
        while ((i < length) && (input[i] == input[index1])) {
            i++;
        }
        if((i - index1) > 1) {
            if(((index2 >= 0) && (i < length)) && (input[i] == output[index2])) {
                --index2;
            }
        }
        else {
            output[++index2] = input[index1];
        }
        index1 = i;
        i++;
        string temp = output;
        temp[index2 + 1] = '\0';
        //cout << temp <<"   ";
    }

    if (index2 >= 0) {
        cout<<"\n" << output.substr(0, (index2 + 1)) << "\n";
    }
    else {
        cout <<"\n" << "Empty String" << "\n";
    }
}
