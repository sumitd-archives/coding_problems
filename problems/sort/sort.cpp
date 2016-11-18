#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int foo[] = {3 , 2, 1, 5 , 4};
    int size = sizeof(foo)/sizeof(foo[0]);
    sort(foo , foo + size);
    for (int i = 0 ; i < size ; i++) {
        cout << foo[i] << " ";
    }
}

