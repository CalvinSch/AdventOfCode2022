#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FILE "input.txt"

using namespace std;

int main(int argc, char *argv[]) {
    //Part 1: Determine Largest Calorie Count
    ifstream file(INPUT_FILE);

    int MAX_CALORIES = 0;
    int currentSum = 0;
    int current;
    vector<int> calorieTotals;

    string line;
    while(getline(file, line)) {
        if(line.empty()) {
            calorieTotals.push_back(currentSum);
            if(currentSum > MAX_CALORIES) MAX_CALORIES = currentSum;
            currentSum = 0;
        }
        else {
            currentSum += stoi(line);
        }
    }

    file.close();

    cout << MAX_CALORIES << "\n";
    
    //Part 2: Determine Top 3 Largest Calorie Counts and sum them

    sort(calorieTotals.begin(), calorieTotals.end(), greater<int>()); //Sort in descending order
    int TOP_3_TOTALS = calorieTotals[0] + calorieTotals[1] + calorieTotals[2];

    cout << TOP_3_TOTALS << "\n";

}