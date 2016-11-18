#include<stdio.h>
#include <iostream>
using namespace std;
int arr[][4] = {  
 {0, 1, 2 ,3},    /*  initializers for row indexed by 0 */
 {4, 5, 6 ,7},    /*  initializers for row indexed by 1 */
 {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

int main()
{
    int rows = sizeof(arr)/sizeof(arr[0]);
    int columns = sizeof(arr[0])/sizeof(arr[0][0]);
    cout << "rows : " <<  rows << "   columns : " << columns << "\n";
    
    int r_index = 0 , c_index = 0 , i , j;

    while ((r_index <= (rows -1)/2) && (c_index <= (columns - 1)/2)) {
        for(i = c_index ; i < (columns - c_index) ; i++) {
            cout << arr[r_index][i] << " ";
        }
        cout << "\n";
        for(i=r_index+1 ; i<(rows - r_index) ; i++) {
            cout << arr[i][columns - c_index - 1]<<" ";
        }
        cout << "\n";
        for(i = columns - c_index -2 ; i >= c_index ; i--) {
            if (r_index == rows - r_index -1) {
                break;
            }  
            cout << arr[rows - r_index - 1][i] << " ";
        }
        cout << "\n";
        for(i = rows - r_index -2 ; i > r_index ; i--) {
            if (c_index == columns - c_index -1) {
                break;
            }
            cout << arr[i][c_index] << " ";
        }
        cout << "\n";
        r_index++;
        c_index++;
    }
    return 0;
}
