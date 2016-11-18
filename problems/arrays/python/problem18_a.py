def minEdits(string1, string2, index1, index2):
    len1 = len(string1);
    len2 = len(string2);

    if index1 == len1:
        return (len2  - index2);

    if index2 == len2:
        return (len1  - index1);

    if (string1[index1] == string2[index2]): 
        return  minEdits(string1, string2, index1 + 1, index2 + 1);

    val1 = minEdits(string1, string2, index1 + 1, index2);
    val2 = minEdits(string1, string2, index1, index2 + 1);
    val3 = minEdits(string1, string2, index1 + 1, index2 + 1);
    return (1 + min(val1, val2, val3));

def main():
    string1 = "sunday";
    string2 = "saturday";

    print minEdits(string1, string2, 0, 0);

if __name__ == "__main__" : main()
    
