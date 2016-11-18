#include<iostream>
using namespace std;
int main() {
//string str("DDIDDIID");
string str("IIDDD");
int index = 0;
int largest = 1;
int cnt =1;
while(index < str.length()-1) {

    if(str[index + 1] == 'D') {
        largest++;
        cnt++;
    }
    else if(str[index] == 'I') {
        cout << ++largest ;
    }
    else {
        int digit = ++largest;
        cnt++;
        while(cnt != 0) {
           cout << digit--; 
           cnt--;
        }
        cnt = 1;
    }
    index++;
}
if (str[index] == 'D') {
    if (cnt > 0) {
        int digit = ++largest;
        cnt++;
        while(cnt != 0) {
           cout << digit--; 
           cnt--;
        }
    }
    else {
        cout << largest + 1 ;
        cout << largest;
    }
}
else if((index == 0) || str[index - 1] == 'I') {
    cout << largest << largest + 1;
}
else {
    cout << largest + 1;
}  
cout << "\n";
return 0;
}
