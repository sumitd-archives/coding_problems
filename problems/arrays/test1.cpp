#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> SplitString(string input , string tokens) 
{
    int start = 0 , end = 0;
    vector<string> split_strings;
    //dont consider leading tokens
    start = input.find_first_not_of(tokens , start);
    while (1) {
	size_t index1 = input.find_first_of(tokens , start);
	if (index1 != string::npos) {
	    end = index1 - 1;
	    split_strings.push_back(input.substr(start, end - start + 1));  
	}
	else {
	    end = input.length() - 1;
	    split_strings.push_back(input.substr(start,end - start + 1));
	    break;
	} 
	size_t index2 = input.find_first_not_of(tokens , index1);
	if (index2 != string::npos) {
	    start = index2;
	}
	else {
	    break;
        } 
    }
    return split_strings;
}

int main() {
    string input("10 20");
    string tokens(" ");
    vector<string>output = SplitString(input , tokens);
    int row = stoi(output[0]);
    int col = stoi(output[1]);
    cout << row + col << "\n";
    //for (int i = 0 ; i < output.size() ; i++) {
    //    cout<<output[i] << "\n";
    //}
}
