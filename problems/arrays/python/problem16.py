def bitionic(array):
    length = len(array);
    increasing = [1 for i in range(length)];
    decreasing = [1 for i in range(length)];
    increasing[0] = 1;
    decreasing[0] = 1;

    max_seq = 0;
    for i in range(1, length):
        max_incr = 0;
        max_decr = 0;
        for j in range(0 , i):
            if array[j] == array[i]:
                continue;

            if array[j] < array[i]:
                incr = increasing[j] + 1;
                if incr > max_incr:
                    max_incr = incr;
            else:
                decr = max(increasing[j], decreasing[j]) + 1;
                if decr > max_decr:
                    max_decr = decr;
        increasing[i] = max_incr;
        decreasing[i] = max_decr;
        max_seq = max(max_incr, max_decr, max_seq);

    print max_seq;

def main():
    #array = [1, 11, 2, 10, 4, 5, 2, 1];
    #array = [12, 11, 40, 5, 3, 1];
    array = [80, 60, 30, 40, 20, 10];
    bitionic(array);

if __name__ == "__main__": main()
