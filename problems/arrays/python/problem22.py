# Generate Interleaved Strings

def shiftright(output, dest, src):
    c = output[src];
    str = output[dest : src];
    output = output[ : dest] + c + str + output[(src + 1) : ];
    return output;

def shiftleft(output, dest, src):
    c = output[src];
    str = output[(src + 1) : (dest + 1)];
    output = output[ : src] + str + c + output[(dest + 1) : ];
    return output
    
def interleave(output, index1, index2, length):
    print output;
    if (index2 >= length):
        return;
    for i in range(index1, index2):
        output = shiftright(output, i, index2);
        interleave(output, i + 1, index2 + 1, length);
        output = shiftleft(output, index2, i);

def main():
    input1 = "ab";
    input2 = "cd";
    output = input1 + input2;
    interleave(output, 0, len(input1), len(output));

if __name__ == "__main__" : main()
