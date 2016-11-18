def partition(arr):
    length = len(arr);
    total = sum(arr);
    if total%2 != 0:
        return false;
    sub_sum = total/2;

    dp = [[False for i in range(length + 1)] for j in range(sub_sum + 1)];
    dp[0] = [True for i in range(length + 1)];
    print dp

    for i in range(sub_sum):
        for j in range(length):
            cur_sum = i + 1;
            prev_sub_val = cur_sum - arr[j];
            if prev_sub_val >= 0:
                val = dp[prev_sub_val][j];
                if val == True:
                    for k in range(j + 1 , length + 1):
                        print cur_sum , k;
                        dp[cur_sum][k] = True;

    return dp[sub_sum][length];

def main():
    arr = [1, 9, 4, 6];
    print partition(arr);

if __name__ == "__main__" : main()


