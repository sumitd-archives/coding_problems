import java.util.*;
public class dynamic23{
    public static  boolean wordbreak(String input) {
        HashMap<String, Boolean> dictionary = new HashMap<String, Boolean>();
        dictionary.put("i" , true);
        dictionary.put("like", true);
        dictionary.put("sam" , true);
        dictionary.put("sung" , true);
        dictionary.put("samsung" , true);
        dictionary.put("mobile" , true);
        dictionary.put("ice" , true);
        dictionary.put("icecream" , true);
        dictionary.put("cream" , true);
        dictionary.put("mango" , true);
        dictionary.put("man" , true);
        dictionary.put("go" , true);
        dictionary.put("and" , true);
        int len = input.length();
        if (len == 0) {
            return true;
        }
        boolean [][] dp = new boolean[len][len];
        int start = 0;
        for (int sub_l = 1; sub_l <= len; sub_l++) {
            for (start = 0; start <= (len - sub_l); start++) {
                int end = start + sub_l - 1;
                String sub_str = input.substring(start, end + 1);
                if (dictionary.containsKey(sub_str)) {
                    dp[start][end] = true;
                }
                else if(sub_l == 1) {
                    dp[start][end] = false;
                }
                else {
                    for (int k = start; k <= end; k++) {
                        if (dp[start][k] && dp[k+1][end]) {
                            dp[start][end] = true;
                            break;
                        }
                    }
                } 
            }
        }
        return dp[0][len - 1];
    }

    public static void main(String[] args) {
        String input = "samsungandmangok";
        if (wordbreak(input)) {
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }
    }
}
                



