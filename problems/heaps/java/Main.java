import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[][] array = {{1, 3, 5, 7},
                         { 2, 4, 6, 8},
                         { 0, 9, 10, 11}};
        //System.out.println(array.length);
        int n = array[0].length;
        int k = array.length;
        Node[][] nodes = new Node[k][n]; 
        int node_num = 0; 
        int i;
        for (i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                nodes[i][j] = new Node(array[i][j], i);
            }
        }
        
        //Set up the initial heap elements
        //MinHeap min_heap = new MinHeap(k);
        Node[] first_elements = new Node[k];
        for (i = 0; i < k; i++) {
            first_elements[i] = nodes[i][0];
        }
        MinHeap min_heap = new MinHeap(first_elements);
        //min_heap.PrintElements();
        
        int[] array_indices = new int[k];
        Arrays.fill(array_indices, 1);
        int n_elements = n*k;
        for (i = 0; i < n_elements; i++) {
            Node val =  min_heap.pop();
            int array_num = val.GetArrayNum();
            int array_index = array_indices[array_num];
            if (array_index < n) {
                Node element = nodes[array_num][array_index];
                //System.out.println(element.GetValue());
                min_heap.AddElement(nodes[array_num][array_index]);
                array_indices[array_num] = array_index + 1;
            }   
            System.out.println(val.GetValue());
        } 
    }
}
