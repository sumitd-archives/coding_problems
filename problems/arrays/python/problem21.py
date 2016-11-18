#Min inssertions to form a palindrom
def main():
    input = "bcd";
    length = len(input);
    dp = [[0 for i in range(length)]for j in range(length)]; 
    for i in range(2, length + 1):
        for start in range(length + 1 - i):
            end = start + i - 1;
            if (input[start] == input[end]):
                if (i == 2):
                    dp[start][end] = 0;
                else:
                    dp[start][end] = dp[start + 1][end - 1];
            else:
                dp[start][end] = 1 + min(dp[start + 1][end],
                                         dp[start][end - 1]);

    print (dp[0][length - 1]) ;

if __name__ == "__main__" : main()
