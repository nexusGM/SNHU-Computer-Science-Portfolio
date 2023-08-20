#ifndef ALGORITHMSANDDATASTRUCTURES_COURSEVECTOR_H
#define ALGORITHMSANDDATASTRUCTURES_COURSEVECTOR_H

#include <string>
#include <vector>
#include "Course.h"

/**
 * @class CourseVector
 * @brief Represents a collection of Course objects using a vector.
 *
 * This class uses a standard vector to store and manage Course objects.
 * It provides functionalities to load courses from a file, print a sample
 * course schedule, retrieve specific course details, and check if the vector is empty.
 */
class CourseVector {
private:

    /// Vector storing the collection of courses.
    std::vector<Course> courses;

public:

    /**
     * @brief Loads courses from a given file and appends them to the vector.
     * @param filename The path to the file containing course details.
     */
    void loadCoursesIntoVector(const std::string& filename);

    /// Prints a sample schedule of the courses.
    void printSampleSchedule() const;

    /**
    * @brief Prints information of a specific course given its course number.
    * @param courseNumber The unique identifier of the course to print.
    */
    void printCourseInformation(const std::string& courseNumber) const;

    /// @return True if the vector is empty, otherwise false.
    bool isEmpty() const { return courses.empty();}
};

#endif //ALGORITHMSANDDATASTRUCTURES_COURSEVECTOR_H
