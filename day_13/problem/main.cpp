#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    ifstream file ("./sample.txt");
    // log the error why the file is not opening 
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
        return 1;
    }

    vector<vector<string>> data;


    string line;

    while (getline(file, line)) {
            
        vector<string> temp;
        temp.push_back(line);

        while(getline(file,line)) {
            if (line.empty()) {
                break;   
            }
            temp.push_back(line);
        }
        data.push_back(temp);

   }


    file.close();

    int64_t ans = 0;

    for (vector<string> pattern: data) {
        
        int temp = 0;
        
        // Vertical symmetry check
        // iterate over the pattern and check if the string is == the string in the next pattern
        for (int i = 0; i < pattern.size()-1; i++) {
            string line1 = "";
            for (int j = 0; j < pattern.size(); j++) {
                line1 += pattern[j][i];
            }
            string line2 = "";
            for (int j = 0; j < pattern.size(); j++) {
                line2 += pattern[j][i+1];
            }
            if (line1 == line2) {
                cout<< "Vertical Symetry "<< i+1 <<" "<< i+2 << endl;
            }

        }
        // horizontal symetry 
        // iterate over the patter and check if there i string is == i+1 string
        for (int i = 0; i < pattern.size()-1; i++) {
            if (pattern[i] == pattern[i+1]) {
                cout << "Horizontal Symetry "<< i+1 <<" "<< i+2 << endl;
                // print the symetric line
                // cout << pattern[i] << endl;

            }
        }

        cout << "\n";
    }

    file.close();

    return 0;
}
