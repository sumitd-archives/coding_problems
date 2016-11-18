def minEdits(string1, string2):
    len1 = len(string1);
    len2 = len(string2);

    dp = [[0 for i in range(len2 + 1)]for j in range(len1 + 1)]; 

    for i in range(len1 + 1):
        dp[i][0] = i;

    for i in range(len2 + 1):
        dp[0][i] = i;

    for i in range(len1):
        for j in range(len2):
            if string1[i] == string2[j]:
                dp[i + 1][j + 1] = dp[i][j];
            else:
                val1 = dp[i][j + 1];
                val2 = dp[i + 1][j];
                val3 = dp[i][j];
                dp[i + 1][j + 1] = 1 + min(val1, val2, val3);

    return dp[len1][len2];

def main():
    string1 = "sunday";
    string2 = "saturday";
    print minEdits(string1, string2);

if __name__ == "__main__" : main()
