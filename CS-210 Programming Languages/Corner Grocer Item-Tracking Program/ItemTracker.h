#pragma once
#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Class to represent the item-tracking program
class ItemTracker {

    public:

        // Function to load item data from input file
        void loadData();

        // Function to display frequency of a specific word
        void displayItemFrequency(string item);

        // Function to print the list with numbers that represent the frequency of all items purchased
        void displayAllFrequency();

        // Function to display frequency of all items in the form of a histogram
        void displayHistogram();

        // Function to save frequency data file to back up all accumulated data
        void saveData();

    private:

        map<string, int> frequencyMap;  // Map to store item frequency
        string inputFile = "CS210_Project_Three_Input_File.txt";  // Input file name
        string outputFile = "frequency.dat";  // Output file name

};

#endif
