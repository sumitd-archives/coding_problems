public class Node {
    private int array_num;
    private int val;

    public Node(int val, int array_num) {
        this.array_num = array_num;
	this.val = val;
    }

    public int GetArrayNum() {
        return array_num;
    }

    public int GetValue() {
        return val;
    }
} 
