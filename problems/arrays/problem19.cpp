#include<iostream>
using namespace std;

int main() {
    int arr[] = {10, 3, 5, 6, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    int prod = 1;
    while(i < len) {
        prod = prod * arr[i];
        i++;
    }

    i = 0;
    while(i < len) {
        arr[i] = arr[i] ^ prod;
        i++;
    }

    for (i = 0; i < len; i++) {
        cout << arr[i] << " , ";
    }
    cout << "\n";
}

    

