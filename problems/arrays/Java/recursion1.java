// String Interleave
public class recursion1 {
    public static void main(String args[]) {
        String input1 = "ab";
        String input2 = "cd";
        StringBuilder output = new StringBuilder(input1).append(input2);
        interleave(output, 0, input1.length(), output.length());
    }

    private static void interleave(StringBuilder output, int index1, int index2, int len) {
        System.out.println(output.toString());
        if (index2 >= len) {
            return;
        }
        for (int i = index1; i < index2; i++) {
            shiftright(output, i, index2);
            interleave(output, i + 1, index2 + 1, len);
            shiftleft(output, index2, i);
        }
    }

    private static void shiftright(StringBuilder output, int to, int from) {
        char c = output.toString().charAt(from);
        String str = output.substring(to, from);
        output.replace(to + 1, from + 1, str);
        output.setCharAt(to, c);
    }

    private static void shiftleft(StringBuilder output, int to, int from) {
        char c = output.toString().charAt(from);
        String str = output.substring(from + 1, to + 1);
        output.replace(from, to, str);
        output.setCharAt(to, c);
    }
}
        

