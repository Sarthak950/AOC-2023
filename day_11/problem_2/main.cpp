#include <bits/stdc++.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace  std;

struct Point {
    int x;
    int y;
};

std::vector<Point> findHashPositions(const std::vector<std::string>& galaxy) {
    std::vector<Point> hashPositions;

    for (int i = 0; i < galaxy.size(); ++i) {
        for (int j = 0; j < galaxy[i].size(); ++j) {
            if (galaxy[i][j] == '#') {
                hashPositions.push_back({j, i});
            }
        }
    }

    return hashPositions;
}

int calculateAbsoluteDistance(const Point& p1, const Point& p2) {
    int absDistance = abs(p2.x - p1.x) + abs(p2.y - p1.y);
    return absDistance;
}

int findTotalAbsoluteDistance(const std::vector<Point>& hashPositions) {
    int totalDistance = 0;

    for (size_t i = 0; i < hashPositions.size(); ++i) {
        for (size_t j = i + 1; j < hashPositions.size(); ++j) {
            totalDistance += calculateAbsoluteDistance(hashPositions[i], hashPositions[j]);
        }
    }

    return totalDistance;
}


int main(int argc, char *argv[]) {
    ifstream file ("./test.txt");
    
    vector<string> galaxy;

    int count_1 = 0;
    int count_2 = 0;
    {
        string line;
        while(getline(file,line)) {
            galaxy.push_back(line);

            bool flag = false;

            for( int i=0;i< line.length(); i++) 
                if(line[i] == '#') flag = true;

            if(flag == false)
                for (int i=0;i<1000000;i++)
                    galaxy.push_back(line);
        }

        // rotate the galaxy 
        vector<string> rotated_galaxy;

        for (int i=0; i<galaxy[0].size();i++) {
            string temp = "";
            for (int j=0; j<galaxy.size(); j++) {
                // print 
                temp += galaxy[j][i];
            }
            rotated_galaxy.push_back(temp);
        }


        // now do the same thing as adding the empty line in the rotated_galaxy
        vector <string> temp_rotated_galaxy;
        for ( int i=0;i<rotated_galaxy.size();i++) {
            temp_rotated_galaxy.push_back(rotated_galaxy[i]);

            bool flag = false;

            for (int j=0; j<rotated_galaxy[i].length(); j++) {
                if (rotated_galaxy[i][j] == '#') flag = true;
            }

            if (flag == false)
                for (int i=0; i<1000000;i++) 
                    temp_rotated_galaxy.push_back(rotated_galaxy[i]);
        }



        vector <string> temp_galaxy;
        for (int i=0; i<temp_rotated_galaxy[0].size();i++) {
            string temp = "";
            for (int j=0; j<temp_rotated_galaxy.size(); j++) {
                // print 
                temp += temp_rotated_galaxy[j][i];
            }
            temp_galaxy.push_back(temp);
        }

        galaxy = temp_galaxy;
    }

    
    // now calculate distance of each # to the other # 
    
    
std::vector<Point> hashPositions = findHashPositions(galaxy);
    int64_t totalAbsoluteDistance = findTotalAbsoluteDistance(hashPositions);

    std::cout << totalAbsoluteDistance << std::endl;



    return 0;
}
