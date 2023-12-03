#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

map<int, bool> visited;
vector<string> lines;

int64_t get_number(int x, int y) {
    
    int i =x;
    int j =y;
    // iteate over the line from the given index until we found a non digit character then we get the position of the number from start
    while(isalnum(lines[i][--j])) {
    } j++;

    int num = 0;


    int position = i*10 +j;
    
    // check if the position is already visited or not if yes then do noting and return 0 else mark it as visited and continue
    if (visited[position]) {
        return 0;
    } else {
        visited[position] = true;
    }

    while(isalnum(lines[i][j])) {
        num = num*10 + (lines[i][j] - '0');
        j++;
    }

    // cout << "i: " << i << " j: " << j << " -> " << num << endl;


    return num;
    

}

int64_t get_nebours(int x, int y) {
   
    int64_t sum = 1;

    vector< int64_t> numbers;

    if (isalnum(lines[x][y+1])){
        // cout << "i: " << x << " j: " << y+1 << " -> " << lines[x][y+1] << endl;
        // sum *= get_number(x, y+1);
        numbers.push_back (get_number(x, y+1));
    } 
    if (isalnum(lines[x+1][y+1]) ) {
        // cout << "i: " << x+1 << " j: " << y+1 << " -> " << lines[x+1][y+1] << endl;
        // sum *= get_number(x+1, y+1);
        numbers.push_back (get_number(x+1, y+1));
    }
    if (isalnum(lines[x+1][y]) ) {
        // cout << "i: " << x+1 << " j: " << y << " -> " << lines[x+1][y] << endl;
        // sum *= get_number(x+1, y);
        numbers.push_back (get_number(x+1, y));
    }
    if (isalnum(lines[x+1][y-1]) ) {
        // cout << "i: " << x+1 << " j: " << y-1 << " -> " << lines[x+1][y-1] << endl;
        // sum *= get_number(x+1, y-1);
        numbers.push_back (get_number(x+1, y-1));
    }
    if (isalnum(lines[x][y-1]) ) {
        // cout << "i: " << x << " j: " << y-1 << " -> " << lines[x][y-1] << endl;
        // sum *= get_number(x, y-1);
        numbers.push_back (get_number(x, y-1));
    }
    if (isalnum(lines[x-1][y-1]) ) {
        // cout << "i: " << x-1 << " j: " << y-1 << " -> " << lines[x-1][y-1] << endl;
        // sum *= get_number(x-1, y-1);
        numbers.push_back (get_number(x-1, y-1));
    }
    if (isalnum(lines[x-1][y]) ) {
        // cout << "i: " << x-1 << " j: " << y << " -> " << lines[x-1][y] << endl;
        // sum *= get_number(x-1, y);
        numbers.push_back (get_number(x-1, y));
    }
    if (isalnum(lines[x-1][y+1]) ) {
        // cout << "i: " << x-1 << " j: " << y+1 << " -> " << lines[x-1][y+1] << endl;
        // sum *= get_number(x-1, y+1);
        numbers.push_back (get_number(x-1, y+1));
    }

    for (auto i: numbers) {
        if (i > 0) {
            sum *= i;
        }
    }

    cout << sum << endl;
    // cout << sum ;
    return sum;
}


int main (int argc, char *argv[]) {
    ifstream input_file ("./sample.txt");
    // ifstream input_file ("./input.txt");
    string line;   

    int64_t sum = 0;

    while (getline(input_file, line)) {
        lines.push_back(line);
    }


    for (int i=0;i< lines.size();i++) {

        for (int j=0;j<lines[i].size();j++){

            if (lines[i][j] != '.' &&  !isalnum(lines[i][j])) {
                // cout << "i: " << i << " j: " << j << " " << lines[i][j] << endl;
                sum += get_nebours(i, j);
                // cout <<endl;
            }

        }
    }

    // cout << sum;

    return 0;
}
