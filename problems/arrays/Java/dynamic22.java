// Dice Throwing
public class dynamic22 {
    public static void main(String[] args) {
        int n_dice = 4;
        int n_values = 6;
        int sum = 10;
        int[][] dp = new int[n_dice][sum + 1];
        for (int j = 1; j < sum; j++) {
            if(j > n_values) {
                break;
            }
            dp[0][j] = 1;
        }
        for (int i = 1; i < n_dice; i++) {
            for (int j = i; j <= sum; j++) {
                int cnt = 0;
                for (int k = 1; k <= n_values; k++) {
                    int prev_val = j - k;
                    if (prev_val <= 0) {
                        break;
                    }
                    cnt = cnt + dp[i - 1][prev_val];
                }
                dp[i][j] = cnt;
            }
        }
        int val = dp[n_dice - 1][sum];
        System.out.println(val);
    }
}

            
        

