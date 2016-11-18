#include<iostream>
using namespace std;
#include <map>

int main() {
   string input("aabcbcdbca");
   int start_index = 0;
   int end_index = 0;
   int max_length = 1;
   int current_length = 1;
   int longest_seq_start = 0;
   int longest_seq_end = 0;
   int i;
   map<char, int> char_index_map;
   map<char, int>::iterator it;
   for (i = 0 ; i < input.length() ; i++) {
       char ch = input[i];
       it = char_index_map.find(ch);
       if((it != char_index_map.end()) && (it->second >= start_index)) {
           current_length = i - start_index;
           if(current_length > max_length) {
               max_length = current_length;
               longest_seq_start = start_index;
               longest_seq_end = i - 1;
           }
           start_index = it->second + 1;
       }      
       char_index_map[ch] = i;
   }
   current_length = i - start_index;
   if (current_length > max_length) {
       max_length = current_length;
       longest_seq_start = start_index;
       longest_seq_end = i - 1;
   }
   cout << "start : " << longest_seq_start << " , end : " << longest_seq_end << " , length : " << max_length << "\n";
   cout << "sequence : " << input.substr(longest_seq_start , max_length) << "\n";
}
