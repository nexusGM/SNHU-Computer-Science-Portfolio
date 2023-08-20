#include "CourseVector.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void CourseVector::loadCoursesIntoVector(const std::string &filename) {
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

        Course course(tokens[0], tokens[1]);
        if (tokens.size() > 2) {
            course.addPrerequisite(tokens[2]);
        }
        if (tokens.size() > 3) {
            course.addPrerequisite(tokens[3]);
        }

        courses.push_back(course);
    }

    file.close();
}

void CourseVector::printSampleSchedule() const {
    std::vector<Course> sortedCourses = courses;
    std::sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
        return a.getNumber() < b.getNumber();
    });
    std::cout << std::endl;
    for (const Course& course : sortedCourses) {
        std::cout << course.getNumber() << " - " << course.getTitle() << std::endl;
    }
}

void CourseVector::printCourseInformation(const std::string& courseNumber) const {
    bool found = false;
    for (const Course& course : courses) {
        if (course.getNumber() == courseNumber) {
            found = true;
            std::cout << std::endl << "Course: " << std::endl;
            std::cout << course.getNumber() << " - " << course.getTitle() << std::endl << std::endl;

            const std::vector<std::string>& prerequisites = course.getPrerequisites();
            if (!prerequisites.empty()) {
                std::cout << "Prerequisites:" << std::endl;
                for (const std::string& prerequisite : prerequisites) {
                    std::cout << prerequisite << std::endl;
                }
            }
            else {
                std::cout << "No Prerequisites" << std::endl;
            }
            break;
        }
    }
    if (!found) {
        std::cout << std::endl << "Course not found" << std::endl;
    }
}