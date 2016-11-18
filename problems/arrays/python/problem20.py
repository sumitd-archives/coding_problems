def word_wrap(arr, width):
    n_words = len(arr);
    n_lines = n_words;

    #line 0
    dp = [[float('inf') for i in range(n_lines)]for j in range(n_words)];
    space = 0;
    occup = 0;
    for word_i in range(n_words):
        occup = occup + len(arr[word_i]) + space;
        rem = width - occup;
        if rem >= 0:
            dp[0][word_i] = rem**2;
        else:
            break;
        space = 1;

    for line_i in range(1, n_lines):
        word_start = line_i;
        for word_i in range(word_start, n_words):
            space = 0;
            curr_min = float('inf');
            occup = 0;
            for curr_word in range(word_i, word_start - 1, -1):
                occup = occup + len(arr[curr_word]) + space;
                space = 1;
                rem = width - occup;
                val = dp[line_i - 1][curr_word - 1];
                print "rem : " , rem , "  val : " , val;
                if rem < 0:
                    dp[line_i][word_i] = curr_min;
                    break;
                if val == float('inf'):
                    continue;
                cost = val + rem**2;
                print "cost : " , cost;
                if cost < curr_min:
                    print "updating"
                    curr_min = cost;
                    dp[line_i][word_i] = curr_min;
        if dp[line_i][n_words - 1] < float('inf'):
            print dp;
            print("returning from point1\n");
            return dp[line_i][n_words - 1];

    print("returning from point2\n");
    return dp[n_lines - 1][n_words - 1];

def main():
    #arr = ["aaa" , "bb" , "cc" , "ddddd"];
    arr = ["geeks" , "for" , "geeks" , "presents", "word", "wrap", "problem"];
    print word_wrap(arr, 15);

if __name__ == "__main__" : main()


                





            



    
