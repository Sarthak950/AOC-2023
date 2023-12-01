#include <bits/stdc++.h>
#include <cstddef>
#include <iostream>

using namespace std;


int main (int argc, char *argv[]) {
    

    // open the file problem1.input 
    // FILE *fp = fopen("./day_1/test.txt", "r");
    FILE *fp = fopen("./day_1/problem1.input", "r");
    if (fp == NULL) {
        cout << "Could not open file problem1.input" << endl;
        return 1;
    }

    // read the file line by line
    char *line = NULL;
    size_t len = 0;
    long long int sum = 0;
    while (getline(&line, &len, fp) != -1) {
        // iterate over the string and then check if it is a number or not then make a current number from it and print it 
        int i = 0;
        long long int current_number = 0;

        while (line[i] != '\0') {
            if (line[i] >= '0' && line[i] <= '9') {
                current_number = current_number * 10 + (line[i] - '0');
            }
            i++;
        }

        // for single digits numbers 
        if (current_number < 10) {
            current_number =  (current_number * 10) + current_number;
        }

        // takeing only first and last number if the number is greater than 2 digits
        if (current_number > 99) {
            int last_digit = current_number % 10;
            // chect the first digit 
            while (current_number > 9) {
                current_number /= 10;
            }
            current_number = current_number * 10 + last_digit;
        }
        

        sum += current_number;
        cout << current_number << endl;
        if (sum<0) {
            cout << "sum is negative" << endl;
        }
    }
    cout << sum << endl;


    return 0;
}
