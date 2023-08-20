#ifndef ALGORITHMSANDDATASTRUCTURES_COURSEHASHTABLE_H
#define ALGORITHMSANDDATASTRUCTURES_COURSEHASHTABLE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Course.h"

/**
 * @class CourseHashtable
 * @brief Represents a hashtable for storing and managing Course objects.
 *
 * This class uses an unordered_map to maintain a hashtable with course numbers as keys
 * and the corresponding Course objects as values. It provides functionalities to
 * load courses from a file, print course schedules, retrieve specific course details,
 * and check if the hashtable is empty.
 */
class CourseHashtable {
private:

    /// Hashtable storing courses with the course number as key and the Course object as value.
    std::unordered_map<std::string, Course> courses;

public:

    /**
     * @brief Loads courses from a given file and inserts them into the hashtable.
     * @param filename The path to the file containing course details.
     */
    void loadCoursesIntoHashtable(const std::string& filename);

    /// Prints a sample schedule of courses.
    void printSampleSchedule();

    /**
     * @brief Prints information of a specific course given its course number.
     * @param courseNumber The unique identifier of the course to print.
     */
    void printCourseInformation(const std::string& courseNumber);

    /// @return True if the hashtable is empty, otherwise false.
    bool isEmpty() const {return courses.empty();}
};

#endif //ALGORITHMSANDDATASTRUCTURES_COURSEHASHTABLE_H