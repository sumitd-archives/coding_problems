def min_partition(string):
    length = len(string);
    dp = [[0 for i in range(length)]for j in range(length)]

    for i in range(length - 1):
        if string[i] != string[i + 1]:
            dp[i][i + 1] = 1;

    for k in range(3, length + 1):
        for start in range(length + 1 - k):
            end = start + k - 1;
            if (string[start] == string[end]) and (dp[start+1][end-1] == 0):
                continue;
            min_partitions = float('inf');
            for j in range(start, end):
                partitions = dp[start][j] + dp[j+1][end] + 1;   
                if partitions < min_partitions:
                    min_partitions = partitions;
            dp[start][end] = min_partitions;

    print dp[0][length - 1];

def main():
#    string = "ababbbabbababa";
    string = "abab";
    min_partition(string);

if __name__ == "__main__" : main()

