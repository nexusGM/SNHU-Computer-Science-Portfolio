#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "ItemTracker.h"

using namespace std;

void ItemTracker::loadData() {
    ifstream file(inputFile);
    if (file.is_open()) {
        string item;
        while (file >> item) {
            frequencyMap[item]++;
        }
        file.close();
    }
}

void ItemTracker::displayItemFrequency(string item) {
    cout << endl << "Frequency of " << item << ": " << frequencyMap[item] << endl << endl;
}

 
void ItemTracker::displayAllFrequency() {
    cout << endl;
    for (auto const& x : frequencyMap) {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}

void ItemTracker::displayHistogram() {
    cout << endl;
    for (auto const& x : frequencyMap) {
        cout << x.first << " ";
        for (int i = 0; i < x.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}


void ItemTracker::saveData() {
    ofstream file(outputFile);
    if (file.is_open()) {
        for (auto const& x : frequencyMap) {
            file << x.first << " " << x.second << endl;
        }
        file.close();
    }
}
