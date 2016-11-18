#include<iostream>
using namespace std;
int arr[] = {1 , 0 , 0 , 0 , 0, 0, 1 , 1 , 1 , 1 , 0 , 1};
int longestStreak(int flipsAllowed) {
    int streakStart = 0;
    int flipStart = 0;
    int index;
    int flipsLeft;
    int longest = 0;
    int length = sizeof(arr)/sizeof(arr[0]);
    int streakLength = 0;
    while(1) {
    while ((flipStart < length) && (arr[flipStart] == 1)) {
        ++flipStart;  
    }
    /*if (flipStart == length) {
        streakLength = flipStart - streakStart;
        if (streakLength < longest) {
            return longest;
        }
        else {
            return streakLength;
        }
    }*/
    index = flipStart;
    flipsLeft = flipsAllowed; 
    while ((index < length) && (flipsLeft > 0)) {
        if (arr[index] == 0) {
            --flipsLeft;
        }
        ++index;
    }

    while ((index < length) && (arr[index] == 1)) {
        ++index;
    } 
    
    streakLength = index - streakStart;
    if (streakLength > longest) {
        longest = streakLength;
    }

    if (index == length) {
        return longest;
    }
    
    ++flipStart;
    streakStart = flipStart;
    }
    return longest;
}
   
int main() {
   cout << longestStreak(0) << "\n";
}
        
