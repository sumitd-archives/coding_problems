public class MinHeap {
    private int length;
    Node[] elements;

    public MinHeap(int size) {
        this.length = 0;  
        this.elements = new Node[size+1];
    }

    public MinHeap(Node[] elements) {
        this.length = elements.length; 
        this.elements = new Node[length + 1];   
	System.arraycopy(elements, 0, this.elements, 1, length);
        BuildMinHeap();
    }

    public void BuildMinHeap() {
	int i;
        for (i = length/2; i > 0; i--) {
	    TopDownHeapify(i);
        }
    }	  

    private void TopDownHeapify(int index) {
        int left_child_index = 2*index;
        int right_child_index = 2*index + 1;
        if (left_child_index > length) {
	    return;
        }
//        System.out.println("length = " + length + " , index = " + left_parent_index);
 	int child = elements[left_child_index].GetValue();
        int child_index = left_child_index;
        if (right_child_index <= length) {
            int  right_child_val = elements[right_child_index].GetValue();
	    if (right_child_val < child) {
		child = elements[right_child_index].GetValue();
 		child_index = right_child_index;
	    }
	}
        
        if (elements[index].GetValue() > child) {
            swap(index, child_index);
            TopDownHeapify(child_index);
       	}
    }

    private void BottomTopHeapify(int index) {
        if (index == 1) {
            return;
        }
        int parent_index = index/2;
        int parent_val = elements[parent_index].GetValue();
        if (elements[index].GetValue() < parent_val) {
            swap(index, parent_index);
            BottomTopHeapify(parent_index);
        }
    } 

    private void swap(int index1, int index2) {
	Node temp = elements[index1];
        elements[index1] = elements[index2];
	elements[index2] = temp; 	
    }
   
    public Node pop() {
        Node head = elements[1];
        elements[1] = elements[length--];
        TopDownHeapify(1);
        return head;
    } 

    public void AddElement(Node node) {
        elements[++length] = node;
        BottomTopHeapify(length);        
    }

    public void PrintElements() {
        for (int i = 1; i <= length; i++) {
            System.out.println(elements[i].GetValue());
        }
    }
}
