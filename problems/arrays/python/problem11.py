import numpy as np
def main():
    arr1 = [2, 3, 7, 10, 12, 15, 30, 34];
    arr2 = [1, 5, 7, 8, 10, 15, 16, 19];

    #arr1 = [10, 12];
    #arr2 = [5, 7, 9];

    index1 = 0
    index2 = 0;
    sum1 = 0;
    sum2 = 0;
    max_sum = 0;
    len1 = len(arr1);
    len2 = len(arr2);

    while index1 < len1 and index2 < len2:
        if arr1[index1] < arr2[index2]:
            sum1 = sum1 + arr1[index1];
            index1 += 1;
        elif arr1[index1] > arr2[index2]:
            sum2 = sum2 + arr2[index2];
            index2 += 1;
        else:
            max_sum = max_sum + max(sum1, sum2) + arr1[index1];
            sum1 = 0;
            sum2 = 0;
            index1 += 1;
            index2 += 1;
    if index1 == len1:
        sum2 = sum2 + np.sum(arr2[index2 : ]);
        max_sum = max_sum + max(sum1, sum2);
    else:
        sum1 = sum1 + np.sum(arr1[index1 : ]);
        max_sum = max_sum + max(sum1, sum2);
    
    print max_sum;

if __name__ == "__main__": main()

