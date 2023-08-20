#include "CourseHashtable.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

void CourseHashtable::loadCoursesIntoHashtable(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "File not found." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2 || tokens.size() > 4) {
            std::cout << "Error in line format: " << line << std::endl;
            continue;
        }

        Course course;
        course.setNumber(tokens[0]);
        course.setTitle(tokens[1]);

        if (tokens.size() > 2) {
            course.addPrerequisite(tokens[2]);
        }
        if (tokens.size() > 3) {
            course.addPrerequisite(tokens[3]);
        }

        courses[course.getNumber()] = course;
    }

    file.close();
}



void CourseHashtable::printSampleSchedule() {
    std::vector<std::string> allCourseNumbers;

    allCourseNumbers.reserve(courses.size());
    for (const auto& pair : courses) {
        allCourseNumbers.push_back(pair.first);
    }

    std::sort(allCourseNumbers.begin(), allCourseNumbers.end());

    std::cout << std::endl;
    for (const auto& courseNumber : allCourseNumbers) {
        const Course& course = courses[courseNumber];
        std::cout << course.getNumber() << " - " << course.getTitle() << std::endl;
    }
}


void CourseHashtable::printCourseInformation(const std::string& courseNumber) {
    if (courses.find(courseNumber) != courses.end()) {
        const Course& course = courses[courseNumber];

        std::cout << std::endl << "Course: " << std::endl;
        std::cout << course.getNumber() << " - " << course.getTitle() << std::endl << std::endl;

        if (!course.getPrerequisites().empty()) {
            std::cout << "Prerequisites: " << std::endl;
            for (const auto& prerequisiteNumber : course.getPrerequisites()) {
                if(courses.find(prerequisiteNumber) != courses.end()) {
                    const Course& prerequisiteCourse = courses[prerequisiteNumber];
                    std::cout << prerequisiteCourse.getNumber() << " - " << prerequisiteCourse.getTitle() << std::endl;
                }
            }
        } else {
            std::cout << "No Prerequisites" << std::endl;
        }
    } else {
        std::cout << std::endl <<"Course not found" << std::endl;
    }
}