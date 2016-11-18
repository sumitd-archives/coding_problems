import LinkedList as lp
import numpy as np

def main():
    array = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
    #array = np.array([1, 2, 3]);
    linked_list = lp.LinkedList();
    for i in range(len(array)):
        linked_list.AddElements(array[i]);
    linked_list.FirstLastPattern();
    #linked_list.PrintElements();

if __name__ == "__main__": main()
