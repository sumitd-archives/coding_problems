#include<iostream>
using namespace std;

void swap(string& input , int i , int j) {
    char temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

void permute(string& input , int index , int length) {
    if (index == length) {
        return;
    }
    cout << input << "\n";
    for (int i = index + 1 ; index < length ; index++) {
        swap(input , index , i);
        permute(input , index + 1 , length);
        swap(input , index , i);
    }   
}

int main()
{
    string input("abcde");
    int length = input.length();
    permute(input , 0 , length);
    return 0;
}   
