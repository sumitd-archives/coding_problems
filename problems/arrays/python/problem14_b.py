def mintrials(n_floors):
    dp = [0 for i in range(n_floors)];
    dp[0] = 1;
    dp[1] = 2;

    for i in range(2, n_floors):
        current_min = float('INF');
        for j in range(0, i):
            val = max(j + 1, 1 + dp[i - j - 1]);
            if val < current_min:
                current_min = val;
        dp[i] = current_min;

    return dp[n_floors - 1];

def main():
    for n_floors in range(2 , 101):
        print n_floors , " : " , mintrials(n_floors) , "\n";

if __name__ == "__main__" : main()
