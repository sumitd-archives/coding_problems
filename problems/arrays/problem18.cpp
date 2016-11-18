#include<iostream>
using namespace std;

int max_value(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}


int main() {
    //int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    //int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *max_arr = new int[len];
    int max = 0;
    max_arr[len - 1] = len - 1;
    int i;
    for(i =  len - 2; i >= 0 ; i--) {
        if (arr[i] > arr[max_arr[i + 1]]) {
            max_arr[i] = i;
        }
        else {
            max_arr[i] = max_arr[i + 1];
        }
    }

    i = 0;
    int j = max_arr[0];
    int prev = 0;
    int curr_diff = 0;
    while((i < j) && (j < len)) {
        if(arr[i] < arr[j]) {
            prev = j;
            if (j == (len - 1)) {
                break;
            }
            else {
                j = max_arr[j + 1];
            }
        }
        else {
            curr_diff = prev - i;
            if (curr_diff > max) {
                max = curr_diff;
            }
            i++;
        }
    }
    curr_diff = prev - i;
    cout << max_value(curr_diff , max) << "\n" ; 
}
     
