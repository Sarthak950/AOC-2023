#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Bag {
    public:

    int red;
    int green;
    int blue;

    Bag() {
        red = 0;
        green = 0;
        blue = 0;
    }

    Bag(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    bool match_possible (Bag other) {
        if (red >= other.red && green >= other.green && blue >= other.blue) {
            return true;
        }
        return false;
    }

    void print () {
        cout << "red: " << red << " green: " << green << " blue: " << blue << endl;
    }

};

int main (int argc, char *argv[]) {
    ifstream input_file;
    input_file.open("./problem_1.txt");
    // input_file.open("./sample1.txt"); 
    string line;


    Bag max = Bag(12, 13, 14);

    int game_no = 0;

    int sum =0;

    while (getline(input_file, line)) {

        game_no++;

        int i;
        for (i = 0; i < line.length(); i++) {
            if (line[i] == ':') {
                i++;
                break;
            }
        }

        Bag currentBag = Bag(0, 0, 0);

        for ( ; i<line.length(); i++) {
            
            if (line[i] == 'r'){
                int num = line[i-2] - '0';
                currentBag.red += num;
            }
            else if (line[i] == 'g'){
                int num = line[i-2] - '0';
                currentBag.green += num;
            }
            else if (line[i] == 'b'){
                int num = line[i-2] - '0';
                currentBag.blue += num;
            }

        }
        
        currentBag.print();

        if (!max.match_possible(currentBag)) {
            sum += game_no;
        }     

    }


    cout << sum << endl;




    return 0;
}
