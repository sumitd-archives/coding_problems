#include<iostream>
using namespace std;

int findHighest(int index , int val , int size , int * arr) {
    if ((index + 1) == size) { 
        return index;
    }
    int local_max_index = ++index;
    int local_max = arr[local_max_index];

    while(index < size) {
        int element = arr[index];
        if (element >= val) {
            local_max_index = index;
            break;
        }  
        if (element >= local_max) {
            local_max = element;
            local_max_index = index;
        }
        ++index;
    }
    return local_max_index;
}

int findWaterStored(int * arr , int size) {
    int index = 0 , volume = 0;
    while(index < size) { 
        int highest_index = findHighest(index , arr[index] , size , arr);
        cout << highest_index << "  ";
        int max_height = arr[highest_index];
        int current_height = arr[index];
        int max_allowed = current_height;
        if (max_height <= current_height) {
            max_allowed = max_height;
        }  
               
        index++;
        while(index < highest_index) {
	volume = volume + max_allowed - arr[index];
	++index;
	}
    }
    return volume;
} 
   
int main() {
    int arr[] = {1 , 2 , 0 , 0 , 5 , 1 , 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findWaterStored(arr , size) << "\n";
}    
