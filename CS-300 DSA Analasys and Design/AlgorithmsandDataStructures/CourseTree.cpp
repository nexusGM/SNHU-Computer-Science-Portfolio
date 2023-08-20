#include "CourseTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

void CourseTree::inOrderTraversal(Node<Course>* node, std::vector<Course>& courses) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, courses);
        courses.push_back(node->course);
        inOrderTraversal(node->right, courses);
    }
}

CourseTree::Node<Course>* CourseTree::insert(Node<Course>* node, const Course& course) {
    if (node == nullptr) {
        return new Node<Course>(course);
    }

    if (course.getNumber() < node->course.getNumber()) {
        node->left = insert(node->left, course);
    } else if (course.getNumber() > node->course.getNumber()) {
        node->right = insert(node->right, course);
    }

    return node;
}

Course CourseTree::searchBST(Node<Course>* node, const std::string& courseNumber) const {
    if (node == nullptr || node->course.getNumber() == courseNumber)
        return node->course;

    if (courseNumber < node->course.getNumber())
        return searchBST(node->left, courseNumber);

    return searchBST(node->right, courseNumber);
}

void CourseTree::loadCoursesIntoTree(const std::string &filename) {
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

        root = insert(root, course);
    }

    file.close();
}

void CourseTree::printSampleSchedule() const {
    std::vector<Course> courses;
    inOrderTraversal(root, courses);
    std::cout << std::endl;
    for (const auto& course : courses) {
        std::cout << course.getNumber() << " - " << course.getTitle() << std::endl;
    }
}

void CourseTree::printCourseInformation(const std::string& courseNumber) const {
    Course foundCourse = searchBST(root, courseNumber);

    if (!foundCourse.getNumber().empty()) {
        std::cout << std::endl << "Course: " << std::endl;
        std::cout << foundCourse.getNumber() << " - " << foundCourse.getTitle() << std::endl << std::endl;

        if (!foundCourse.getPrerequisites().empty()) {
            std::cout << "Prerequisites: " << std::endl;
            for (const std::string& prerequisiteNumber : foundCourse.getPrerequisites()) {
                Course prerequisiteCourse = searchBST(root, prerequisiteNumber);
                std::cout << prerequisiteCourse.getNumber() << " - " << prerequisiteCourse.getTitle() << std::endl;
            }
        } else {
            std::cout << "No Prerequisites" << std::endl;
        }
    } else {
        std::cout << std::endl <<"Course not found" << std::endl;
    }
}