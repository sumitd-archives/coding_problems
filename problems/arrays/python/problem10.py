import numpy as np
def main():
    #arr = np.array([6, 2, 5, 4, 5, 1, 6]);
    arr = np.array([1, 3, 2, 1, 1]);
    max = 0;
    length = len(arr);
    for i in range(length):
        current = arr[i];
        sum = 0;
        for j in range(i, -1, -1):
            if arr[j] >= current:
                sum += 1;
            else:
                break;
        for j in range(i+1, length, 1):
            if arr[j] >= current:
                sum += 1;
            else:
                break;
        area = current*sum;
        if area > max:
            max = area;

    print max;

if __name__ == "__main__": main()
