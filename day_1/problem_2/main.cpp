#include <bits/stdc++.h>
#include <iostream>

using namespace std;


typedef struct {
    string str;
    int num;
} lookup_t;

lookup_t lookup[] = {
    {"one",     1}, 
    {"two",     2}, 
    {"three",   3},
    {"four",    4}, 
    {"five",    5}, 
    {"six",     6},
    {"seven",   7}, 
    {"eight",   8}, 
    {"nine",    9}
};


int match (string &slice) {
    for (int i = 0; i < 9; i++) {
        if (slice == lookup[i].str) {
            return lookup[i].num;
        }
    }
    return -1;
}



int main (int argc, char *argv[]) {
    
    ifstream input_file;
    input_file.open("test.txt");

    string line;
    int sum = 0;
    
    // read the file line by line
    while (getline(input_file, line)) {
        
        int leftDigit = 0;
        int rightDigit = 0;

        int left_int = 0;
        int right_int = 0;

        int posCharLeft = -1;
        int posCharRight = -1;

        int posIntLeft = -1;
        int posIntRight = -1;
        
        // print all the sub string that matches the lookup table 
        for (int i = 0; i < line.length(); i++) {
            for (int j = 1; j <= line.length() - i; j++) {
                string slice = line.substr(i, j);
                int num = match(slice);
                if (num != -1) {
                    if (leftDigit == 0) {

                        if (posCharLeft == 0) {
                            posCharLeft = i;
                        }
                        leftDigit = num;
                    } else {
                        if (posCharRight == 0) {
                            posCharRight = i;
                        }
                        rightDigit = num;
                    }
                }
            }
        }


        // now check if the string contains a number in both sides 
        
        for ( int i=0;i<line.length() ;i++) {
            if (isdigit(line[i])) {
                if (posIntLeft == 0) {
                    posIntLeft = i;
                }
                left_int = line[i] - '0';
            }
        }
            
        for ( int i=0;i<line.length() ;i++) {
            if (isdigit(line[i])) {
                if (posIntRight == 0) {
                    posIntRight = i;
                }
                right_int = line[i] - '0';
            }
        }

        
        int finalLeft = 0;
        int finalRight = 0;

        // calculate the final left and right values if any position is negetive then chose the other one char, int then if both are positive then for left check which is snaller and then set it to final and opposite for the right 

        if (posCharLeft == -1) {
            finalLeft = left_int;
        } else if (posIntLeft == -1) {
            finalLeft = leftDigit;
        } else {
            if (posCharLeft < posIntLeft) {
                finalLeft = leftDigit;
            } else {
                finalLeft = left_int;
            }
        }

        if (posCharRight == -1) {
            finalRight = right_int;
        } else if (posIntRight == -1) {
            finalRight = rightDigit;
        } else {
            if (posCharRight < posIntRight) {
                finalRight = rightDigit;
            } else {
                finalRight = right_int;
            }
        }

        sum += finalLeft * 10 + finalRight;

    }

    cout << sum << endl;



    return 0;
}
