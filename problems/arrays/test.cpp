#include<iostream>
#include<vector>
using namespace std;

int sum(vector < int > numbers) {
        int n = numbers[0];
            int sum = 0;
                cout  << n <<"\n";
                    for (int i = 0; i < n; i++) {
                                sum = sum + numbers[i+1];
                                    }
                            return sum;
}


int main()
{
    vector <int> a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    cout << sum(a) <<"\n";
}
