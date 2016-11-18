import math
import numpy as np

def main():
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9];
    length = len(arr);
    new_arr = np.empty(length , dtype=np.int);
    new_arr[length - 1] = 0;
    for index in range(length - 2, -1, -1):
        current_min = float("inf");
        for i in range(1, arr[index] + 1, 1):
            if (index + i) == length:
                break;
            val = new_arr[index + i];
            if val < current_min:
                current_min = val;
        if current_min == float("inf"):
            new_arr[index] = current_min;
        else:
            new_arr[index] = current_min + 1;
    print new_arr[0];
    print new_arr;

if __name__ == "__main__": main()
