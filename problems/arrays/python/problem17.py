def matrixchain(array):
    n_matrices = len(array) - 1;
    dp = [[0 for i in range(n_matrices)]for j in range(n_matrices)];
    
    for i in range(n_matrices - 1):
        val = (array[i]*array[i+1])*array[i+2];
        dp[i][i+1] = val;

    for length in range(2, n_matrices):
        for start in range(n_matrices - length):
            end = start + length;
            current_min = float('INF');
            for k in range(start + 1, end + 1):
                mat_mul_prod = dp[start][k-1] + dp[k][end] + (array[start]*array[k]*array[end + 1]);
                current_min = min(current_min, mat_mul_prod);
            dp[start][end] = current_min;

    for i in range(n_matrices):
        for j in range(n_matrices):
            print dp[i][j] , ' , ' ,;
        print '\n';

#    print dp[0][n_matrices - 1];

def main():
    array = [40, 20, 30, 10, 30];
#   array = [10, 20, 30, 40, 30];
    #array = [10, 20, 30];
    matrixchain(array);

if __name__ == "__main__" : main()



