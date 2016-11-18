// Min insertions to form a palindrom
public class dynamic21 {
        public static void main(String args[]) {
            String input = "abcde";
            int len = input.length();
            int[][] dp = new int[len][len];

            
            for (int i = 2; i <= len; i++) {
                for (int start = 0; start <= (len - i); start++) { 
                    int end = start + i - 1;
                    if (input.charAt(start) == input.charAt(end)) {
                        if (i == 2) {
                            dp[start][end] = 0;
                        }
                        else {
                            dp[start][end] = dp[start + 1][end - 1];
                        }
                    }
                    else {
                        dp[start][end] = 1 + Math.min(dp[start + 1][end],
                                                      dp[start][end - 1]);
                    }
                }
            }
            System.out.println (dp[0][len - 1]);

            for (int i = 0 ; i < len ; i++) {
                for (int j = 0; j < len; j++) {
                    System.out.print(dp[i][j]);
                }
                System.out.println();
            }
        }
}
                    
            
            
