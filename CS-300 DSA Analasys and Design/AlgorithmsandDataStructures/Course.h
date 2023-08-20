#ifndef ALGORITHMSANDDATASTRUCTURES_COURSE_H
#define ALGORITHMSANDDATASTRUCTURES_COURSE_H

#include <string>
#include <vector>

/**
 * @class Course
 * @brief Represents a single course with its details.
 *
 * This class provides functionality to store and retrieve details of a course
 * including its number, title, and prerequisites.
 */
class Course {

private:
    std::string number;
    std::vector<std::string> prerequisites;
    std::string title;

public:

    /// Default constructor, initializes an empty course.
    Course();

    /**
     * @brief Parametrized constructor to initialize a course with given details.
     * @param number The unique course identifier.
     * @param title The descriptive course title.
     */
    Course(std::string  number, std::string  title);

    /// @return Returns the course number.
    std::string getNumber() const;

    /**
     * @brief Sets the course number.
     * @param num The course number to set.
     */
    void setNumber(const std::string& num);

    /// @return Returns the course title.
    std::string getTitle() const;

    /**
    * @brief Sets the course title.
    * @param t The course title to set.
    */
    void setTitle(const std::string& t);

    /// @return Returns a list of prerequisites for the course.
    std::vector<std::string> getPrerequisites() const;

    /**
     * @brief Adds a prerequisite course to the current course.
     * @param prereq The course number of the prerequisite to add.
     */
    void addPrerequisite(const std::string& prereq);
};

#endif //ALGORITHMSANDDATASTRUCTURES_COURSE_H