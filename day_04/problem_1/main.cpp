#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <strings.h>

using namespace std;

int main (int argc, char *argv[]) {
    ifstream file ("./test.txt");
    // ifstream file ("./sample.txt");

    string line;

    int64_t result = 0;



    while (getline(file, line)) {

        int i=0;
        while (line[i++] != ':'){
            // to skip the : symbol  
        }

        // create a table line like structure that can sote int value and can tell me if a value is present in it or not
        vector<int> input;
        vector <int> wining;
        int winCount = 0;

        while (line[i] != '|') {
            int num = 0;
            while (line[i] != ' ' && isalnum(line[i] )) {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            input.push_back(num);
            i++;
        }i++;

        // remove all the zeros form the input 
        for (int i=0; i<input.size(); i++) {
            if (input[i] == 0) {
                input.erase(input.begin() + i);
                i--;
            }
        }

        // fill the wining vector line from the remaining string 
        while (line[i] != '\0') {
            int num = 0;
            while (line[i] != ' ' && isalnum(line[i] )) {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            wining.push_back(num);
            i++;
        }

        // remove all the zeros form the input
        for (int i=0; i<wining.size(); i++) {
            if (wining[i] == 0) {
                wining.erase(wining.begin() + i);
                i--;
            }
        }

        // find the numbr of common items in the two vectors 
        for (int i=0; i<input.size(); i++) {
            for (int j=0; j<wining.size(); j++) {
                if (input[i] == wining[j]) {
                    winCount++;
                    break;
                }
            }
        }


        result += pow(2, winCount -1);

    }

    cout << result << endl;

    return 0;
}
