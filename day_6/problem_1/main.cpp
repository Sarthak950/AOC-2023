#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    ifstream input_file ("./test.txt");

    string line;
    vector<int> time;
    vector<int> distance;

    getline(input_file, line );

    int i = 0;
    while (line[i-1] != ':') i++;
    // now get all the all the number and push them into the vector 
    int num = 0;

    for ( ; i< line.length() +1; i++) {
        if (isalnum(line[i])) {
            num = num * 10 + (line[i] - '0');
        }
        else {
            if (num)time.push_back(num);
            num = 0;
        }
    } 

    getline(input_file, line);

    i = 0;
    while (line[i-1] != ':') i++;
    // now get all the all the number and push them into the vector 
    num = 0;

    for ( ; i< line.length() +1; i++) {
        if (isalnum(line[i])) {
            num = num * 10 + (line[i] - '0');
        }
        else {
            if (num) distance.push_back(num);
            num = 0;
        }
    }  

    vector<int> win_count;

    for (int i= 0;i< time.size();i++) {
        
        int curr_win = 0;
        for (int hold=1; hold < time[i]; hold ++) {
            
            int velocity = hold;

            int distance_covered = ( time[i] - hold) * velocity;    

            if (distance_covered > distance[i]) {
                cout << "Time: " << hold << " Distance: " << distance_covered << endl;
                curr_win++;
            }


        }
        win_count.push_back(curr_win);

        cout << endl;
    }

    int ans = 1;
    for (int i=0; i< win_count.size(); i++) {
        cout << win_count[i] << " ";
        ans *= win_count[i];
    }

    cout << endl;
    cout << ans << endl;
    return 0;
}
