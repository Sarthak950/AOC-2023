#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
public:
    string parent;
    string left;
    string right;
}; 
vector<Node> nodes;


int indexOf(string word) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].parent == word) {
            return i;
        }
    }
    return -1;
}



int main (int argc, char *argv[]) {
    // ifstream input_file ("./sample2.txt");
    ifstream input_file ("./test.txt");

    string line ;


    string direction;
    getline(input_file, direction);
    getline(input_file, line);

    while (getline(input_file, line)) {
        string word = line.substr(0, 3);
        string left_word = line.substr(7,3);
        string right_word = line.substr(12, 3);

        Node node;
        node.parent = word;
        node.left = left_word;
        node.right = right_word;

        nodes.push_back(node);
    }


    int64_t ans = 0;
    string word;

    int index = 0;
    
    int address = 0;

    while (word != "ZZZ") {
            
        cout << word << endl;


        if (direction[index] == 'R') {
            address = indexOf(nodes[address].right);
        } else if (direction[index] == 'L') {
            address = indexOf(nodes[address].left);
        }
        
        

        word = nodes[address].parent;
        ans ++;

        if (index == direction.size())    index = 0;
        else                                index ++ ;
    }

    cout << "Answer: " << ans  << endl;

    return 0;
}
