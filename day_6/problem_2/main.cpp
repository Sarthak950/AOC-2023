#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main (int argc, char *argv[]) {
    ifstream input_file ("./test.txt");

    string line;
    int time = 0;
    int64_t distance = 0;

    getline(input_file, line );

    int i = 0;
    while (line[i-1] != ':') i++;

    for ( ; i< line.length() +1; i++) {
        if (isalnum(line[i])) {
            time = time * 10 + (line[i] - '0');
        }
   } 

    getline(input_file, line);

    i = 0;
    while (line[i-1] != ':') i++;

    for ( ; i< line.length() +1; i++) {
        if (isalnum(line[i])) 
            distance = distance * 10 + (line[i] - '0');
    }  

    cout << "Time: " << time << " Distance: " << distance << endl;

    int64_t ans = 0;
    
    // distance = 212206012011044;
    for (int64_t hold=1; hold < time; hold ++) {
        
        int64_t velocity = hold;

        int64_t distance_covered = ( time - hold) * velocity;    

        if (distance_covered > distance) {
            // cout << "Time: " << hold << " Distance: " << distance_covered << endl;
            ans++;
        }

    }

    cout << ans << endl;

    return 0;
}
