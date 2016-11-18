import numpy as np
import Node
import MinHeap

def main():
    array = np.array([[1, 3, 5, 7], [2, 4, 6, 12], [0, 9, 10, 11]]);
    k, n = np.shape(array); 
    #node_dt = np.dtype([('value' , np.int,1),('arr_num', np.int,1)]); 
    #nodes = np.empty((k, n), dtype=node_dt);
    nodes = [];
    node_num = 0;
    for i in range(k):
        nodes_row = [Node.Node(array[i][j] , i) for j in range(n)];
        nodes.append(nodes_row);
        #for j in range(n):
            #nodes[i][j] = Node.Node(array[i][j], i);

    #Set up the initial heap elements
    min_heap = MinHeap.MinHeap();
    for i in range(k):
        min_heap.AddElements(nodes[i][0]);

    #min_heap.PrintElements();

    array_indices = np.ones(k, dtype=np.int);
    n_elements = n*k;
    for i in range(n_elements):
        val = min_heap.pop();
        array_num = val.GetArrayNum();
        array_index = array_indices[array_num];
        if array_index < n:
            #print '\n';
            #print array_num, ' ', array_index;
            min_heap.AddElements(nodes[array_num][array_index]);
            array_indices[array_num] = array_index + 1;
            #min_heap.PrintElements();
         
        print val.GetValue();

if __name__ == "__main__": main()
