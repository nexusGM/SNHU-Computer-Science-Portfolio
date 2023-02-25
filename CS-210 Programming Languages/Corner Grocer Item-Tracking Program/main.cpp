#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "ItemTracker.h"

using namespace std;

int main() {
    ItemTracker tracker;

    // Load data from input file
    tracker.loadData();

    int option = 0;
    do {
        // Display menu options
        cout << "Menu Options" << endl;
        cout << "1. Search for a specific item" << endl;
        cout << "2. Display frequency of all items" << endl;
        cout << "3. Display histogram of item frequency" << endl;
        cout << "4. Exit program" << endl;
        cout << "Enter an option (1-4): ";
        cin >> option;

        switch (option) {
        case 1:
            // Prompt user for item to search for
            {string item;
            cout << "Enter an item to search for: ";
            cin >> item;

            // Display frequency of specified item
            tracker.displayItemFrequency(item);
            }
            break;

        case 2:
            // Display frequency of all items
            tracker.displayAllFrequency();
            break;

        case 3:
            // Display histogram of item frequency
            tracker.displayHistogram();
            break;

        case 4:
            // Save data to output file and exit program
            tracker.saveData();
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 4);

    return 0;
}
