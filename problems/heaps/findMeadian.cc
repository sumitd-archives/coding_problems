#include<iostream>
#include "heap.hpp"
using namespace std;
class heap;
class maxHeap;
class minHeap;

int main() {
    heap * max_heap = new maxHeap(5);
    //heap * min_heap = new minHeap(5);
    int input = 0; 
    while (input >= 0) {
        cin >> input;
        max_heap->addToHeap(input);
    }

    max_heap->printElements();
    return 0;
}    


