def leftswap(start, end, string):
    temp = string[end];
    for i in range(end - 1, start - 1, -1):
        string[i + 1] = string[i];
    string[start] = temp;

def rightswap(start, end, string):
    temp = string[start];
    for i in range(start, end):
        string[i] = string[i + 1];
    string[end] = temp;

def lexico_anagrams(pos, string):
    if pos == len(string) - 1:
        print ''.join(string);

    for i in range(pos , len(string)):
        leftswap(pos, i, string);
        lexico_anagrams(pos + 1, string);
        rightswap(pos, i, string);

def main():
    string = list("abcd");
    lexico_anagrams(0, string);

if __name__ == "__main__" : main()
    
