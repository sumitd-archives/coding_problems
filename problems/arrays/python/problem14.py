def findminfloors(highest_floor, curr_floor, tries, floors_to_try):
    if curr_floor == highest_floor:
        return (tries + floors_to_try + 1);

    val1 = findminfloors(highest_floor, curr_floor + 1, tries, floors_to_try + 1);
    val2 = findminfloors(highest_floor, curr_floor + 1, tries + 1, 0);
    val3 = tries + floors_to_try + 1;
    print val1 , ' , ' , val2, ' , ' , val3 , '\n';
    return max(val3, min(val1, val2));

def main():
    highest_floor = 16;
    min_tries = findminfloors(highest_floor, 1, 0, 0);
    print min_tries;

if __name__ == "__main__" : main()
    
