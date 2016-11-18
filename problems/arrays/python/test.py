import numpy as np
def main():
    sum = 0;
    arr = [1 , 2 , 3, 4 , 5, 6 ,7 , 8, 9];
    length = len(arr);
    sum = sum + np.sum(arr[6:]);
    #print length
    print sum;

if __name__ == "__main__": main()

