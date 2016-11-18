#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int arr[] = {-2, -1, 0, 1, 1};
    //int arr[] = {-1, -1, -1, -1, 0, 1, 1, 1, 1};
    //int arr[] = {-1, -1, -1, -1, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = len - 1;
    int current = -1;
    int n_distinct = 0;

    while (end >= start) {
        if (abs(arr[end]) == abs(arr[start])) {
            if (current != abs(arr[end])) {
                n_distinct++;
                current = abs(arr[end]);
            }
            end--;
            start++;
            continue;
        }
        else if(abs(arr[end]) > abs(arr[start])) {
            if (current != abs(arr[end])) {
                n_distinct++;
                current = abs(arr[end]);
            }
            end--;
        }
        else {
            if (current != abs(arr[start])) {
                n_distinct++;
                current = abs(arr[start]);
            }
            start++;
        }
    }
    cout << "n_distinct = " << n_distinct << "\n";
}
