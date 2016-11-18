#include<iostream>
#include<cstdlib>
using namespace std;

int findLength(int number) {
    int n_digits = 0;
    while (number > 0) {
        number /= 10;
        ++n_digits;
    }
    return n_digits;     
}

void sort(int * new_arr , int * arr , int start , int n_numbers) {
    int temp;
  //  for (int i = 0 ; i < n_numbers-1 ; i++) {
    int i = n_numbers - 1;
    while ( i > 0) {  
        for (int j = 0  ; j < i ; j++) {
            if(new_arr[j] < new_arr[j+1]) {
                temp = new_arr[j];
                new_arr[j] = new_arr[j+1];
                new_arr[j+1] = temp;
                //swap the two elements in the main array as well
                temp = arr[j + start];
                arr[j + start] = arr[j + 1 + start];
                arr[j + 1 + start] = temp;  
            }
        }
    --i;
    }
}

void arrange(int * arr , int start , int end , int level) {
    if (start >= end) {
        return;
    }

    int element, index = 0 , i;
    int new_array_len = end - start + 1;
    int * new_arr = (int*)malloc(sizeof(int)*(new_array_len));
    for (i = start ; i <= end ; i++) {
        element = arr[i];
        int n_digits = findLength(element);
        while (n_digits > level) {
            element /= 10;
            n_digits = findLength(element); 
        }
        new_arr[index++] = element%10;
    }
    sort(new_arr , arr , start , index);
    index = 0;
    int offset_index = 0;
    while (index < new_array_len) {
        element = new_arr[offset_index];
        while ((index < new_array_len) && (new_arr[index] == element)) {
            index++;
        }
        arrange(arr, start + offset_index , start + index - 1 , level + 1);
        offset_index = index;
    }
} 

int main() {
    //int arr[] = {1 , 34 , 3 , 98 , 9 , 76 , 45 ,4};
    int arr[] = {1 , 34, 3 , 98 , 9 , 76 , 45 ,4};
    //int arr[] = {54 , 546, 548 , 60};
    //int arr[] = {54 , 546 ,60};
    int length = sizeof(arr)/sizeof(arr[0]);
    arrange(arr , 0 , length - 1 , 1);
    for (int i = 0 ; i < length ; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
