import numpy as np

def func(arr):
    arr1 = [];
    arr1[1:] = arr[:];
    #for i in range(1 , 10):
        #  print(arr1[i]);
    
def main():
    #arr = range(10);
    array = np.matrix('1 2 5; 3 4 6');
    nrows , ncols = np.shape(array);
    print nrows;
    print ncols;
    #print(arr);
    #func(arr);

if __name__ == "__main__": main()
