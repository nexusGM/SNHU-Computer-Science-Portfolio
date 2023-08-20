/**
 * @file main.cpp
 * @author Matthew Tyson
 * @date 8/11/2023
 * @brief Main entry point for the Algorithms and Data Structures program.
 *
 * This program demonstrates the usage of various algorithms and data structures.
 * It was developed as a part of Project Two for CS300: Algorithms and Data Structures at SNHU.
 * This program reads the contents of a text file, allowing the user to assign those contents to a chosen data structure.
 * Then the User can print out the list in alphanumeric order.
 * The User can also find a class by id and have it print the course and its prerequisite courses.
 */

#include <iostream>
#include "Course.h"
#include "CourseVector.h"
#include "CourseHashtable.h"
#include "CourseTree.h"

std::string getFilename() {
    std::cout << "What's the filename? (Press Enter for default of ../filename.txt)" << std::endl;
    std::string filename;
    std::cin.ignore();
    std::getline(std::cin, filename);
    if(filename.empty()) {
        // If User presses Enter, it will default to ../filename.txt
        filename = "../filename.txt";
    }
    return filename;
}

int main() {
    CourseTree treeCourses;
    CourseVector vectorCourses;
    CourseHashtable hashtableCourses;


    std::string currentDataStructure = "none";

    while (true) {
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Load Data into Data Structure" << std::endl;
        std::cout << "2. Print Course List" << std::endl;
        std::cout << "3. Print Course" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Select the data structure to load into:" << std::endl;
                std::cout << "a. Vector" << std::endl;
                std::cout << "b. Hashtable" << std::endl;
                std::cout << "c. Tree" << std::endl;

                char dsChoice;
                std::cin >> dsChoice;
                std::string filename = getFilename();

                switch (dsChoice) {
                    case 'a':
                        vectorCourses.loadCoursesIntoVector(filename);
                        if (!vectorCourses.isEmpty()) {
                            currentDataStructure = "vector";
                        } else {
                            std::cout << "Failed to load courses into Vector." << std::endl;
                        }
                        break;

                    case 'b':
                        hashtableCourses.loadCoursesIntoHashtable(filename);
                        if (!hashtableCourses.isEmpty()) {
                            currentDataStructure = "hashtable";
                        } else {
                            std::cout << "Failed to load courses into Hashtable." << std::endl;
                        }
                        break;

                    case 'c':
                        treeCourses.loadCoursesIntoTree(filename);
                        if (!treeCourses.isEmpty()) {
                            currentDataStructure = "tree";
                        } else {
                            std::cout << "Failed to load courses into Tree." << std::endl;
                        }
                        break;

                    default:
                        std::cout << "Invalid data structure choice." << std::endl;
                }
                break;
            }
            case 2: {
                if (currentDataStructure == "vector") {
                    vectorCourses.printSampleSchedule();
                } else if (currentDataStructure == "hashtable") {
                    hashtableCourses.printSampleSchedule();
                } else if (currentDataStructure == "tree") {
                    treeCourses.printSampleSchedule();
                } else {
                    std::cout << "No data structure loaded. Load data first." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter course number:" << std::endl;
                std::string courseNumber;
                std::cin >> courseNumber;

                if (currentDataStructure == "vector") {
                    std::cout << "Printing course info from Vector..." << std::endl;
                    vectorCourses.printCourseInformation(courseNumber);
                } else if (currentDataStructure == "hashtable") {
                    std::cout << "Printing course info from Hashtable..." << std::endl;
                    hashtableCourses.printCourseInformation(courseNumber);
                } else if (currentDataStructure == "tree") {
                    std::cout << "Printing course info from Tree..." << std::endl;
                    treeCourses.printCourseInformation(courseNumber);
                } else {
                    std::cout << "No data structure loaded. Load data first." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Thank you for using the course planner!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select again." <<std::endl;
        }
        std::cout << std::endl;
    }
}
