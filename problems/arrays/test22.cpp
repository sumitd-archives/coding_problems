#include<iostream>
#include<vector>
using namespace std;
int max_val(int coins) {
    int i = 1;
   while (coins > 0) {
       coins = coins - i;
       i = i + 1;
   }   
   if (coins == 0) 
   return (i-1);
   else 
   return (i-2);

}

void arrangeCoins(vector < long > coins) {
int n_rows = coins[0];
    for (int i = 0 ; i <  n_rows ; i++) {
        cout << max_val(coins[i + 1]) << "\n";
    }

}

int main() {
    vector<long> input;
    input.push_back(4);
    input.push_back(2);
    input.push_back(5);
    input.push_back(8);
    input.push_back(3);
    arrangeCoins(input);
}
