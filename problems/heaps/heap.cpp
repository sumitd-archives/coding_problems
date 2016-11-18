#include <iostream>
#include <cstdlib>
#include "heap.hpp"
using namespace std;
    void heap::allocateSpace() {
        max_size *= 2;
        arr = (int*)realloc(arr , max_size*sizeof(int)); 
    }

    heap::heap(int size) {
       max_size = size;
       heap_size = 0;
       arr = (int*)malloc(sizeof(int)*size);   
    }

    int heap::getTop() {
        return arr[0];
    }
    int heap::extractTop() {
        int top = getTop();
        arr[0] = arr[heap_size - 1];
        --heap_size;
        topDownHeapify();
        return top;
    }
    void heap::addToHeap(int element) {
        if (heap_size == max_size) {
            allocateSpace();
        } 
        arr[heap_size++] = element;
        bottomUpHeapify();
    }
    void heap::swap(int left , int right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    void heap::printElements() {
        int index = 0;
        while (index < heap_size) {
            cout << arr[index] << "  ";
            ++index;
        }
    }

    maxHeap::maxHeap(int size):heap(size) {}
    
    void maxHeap::topDownHeapify() {
        int current = 0;
        int left_index , right_index, greater, greater_index , lesser_index;
        while(current < heap_size) {
		left_index = current*2 + 1;
		right_index = current*2 + 2;
		if (arr[left_index] > arr[right_index]) {
		    greater_index = left_index;
		    lesser_index = right_index;
		}
		else {
		    greater_index = right_index;
		    lesser_index = left_index;
		}
		if (arr[current] < arr[greater_index]) {
		    //swap
                    swap(current , greater_index); 
		    current = greater_index;
		}
	        else {
                    return;
                }
        }   
        return;
    }        
          
    void maxHeap::bottomUpHeapify() {
        int current = heap_size - 1;
        int parent;
        while (current >= 0) {
           parent = (current - 1) / 2;
           if (arr[current] > arr[parent]) {
               swap(current , parent); 
               current = parent;
           }
           else {
              return;
           }
        } 
    }       
   
    minHeap::minHeap(int size):heap(size) {}
    
    void minHeap::topDownHeapify() {
        int current = 0;
        int left_index , right_index, greater, greater_index , lesser_index;
        while(current < heap_size) {
		left_index = current*2 + 1;
		right_index = current*2 + 2;
		if (arr[left_index] > arr[right_index]) {
		    greater_index = left_index;
		    lesser_index = right_index;
		}
		else {
		    greater_index = right_index;
		    lesser_index = left_index;
		}
		if (arr[current] > arr[lesser_index]) {
		    //swap
                    swap(current , lesser_index); 
		    current = lesser_index;
		}
	        else {
                    return;
                }
        }   
        return;
    }        
          
    void minHeap::bottomUpHeapify() {
        int current = heap_size - 1;
        int parent;
        while (current >= 0) {
           parent = (current - 1) / 2;
           if (arr[current] < arr[parent]) {
               swap(current , parent); 
               current = parent;
           }
           else {
              return;
           }
        } 
    } 
