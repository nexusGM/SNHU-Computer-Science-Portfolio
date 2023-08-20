#include "Course.h"

#include <utility>

Course::Course() = default;

Course::Course(std::string  number, std::string  title) : number(std::move(number)), title(std::move(title)) {}

std::string Course::getNumber() const {
    return number;
}

void Course::setNumber(const std::string& num) {
    number = num;
}

std::string Course::getTitle() const {
    return title;
}

void Course::setTitle(const std::string& t) {
    title = t;
}

std::vector<std::string> Course::getPrerequisites() const {
    return prerequisites;
}

void Course::addPrerequisite(const std::string& prereq) {
    prerequisites.push_back(prereq);
}


