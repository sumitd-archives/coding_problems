#include <iostream>
using namespace std;
int arr[] = {5 , 6 , 7};

int main()
{
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum1 = 0, sum2 =0 , max_sum2 = 0;
    for (int i = 0 ; i < len ; i++) {
        sum1 = sum1 + arr[i];
        sum2 = sum2 + (i+1)*arr[i];
    }
    max_sum2 = sum2;
    for (int i = 1 ; i < len ; i++) {
        sum2 = sum2 - sum1 + len*arr[i-1];
        if (sum2 > max_sum2) {
            max_sum2 = sum2;
        }
    }
    cout << "max sum = " << max_sum2 << "\n";
} 
          
