#ifndef ALGORITHMSANDDATASTRUCTURES_COURSETREE_H
#define ALGORITHMSANDDATASTRUCTURES_COURSETREE_H

#include <string>
#include "Course.h"

/**
 * @class CourseTree
 * @brief Represents a Binary Search Tree (BST) for storing and managing Course objects.
 *
 * This class provides an interface to load courses from a file, print courses in
 * sorted order, retrieve specific course details, and check if the tree is empty.
 */
class CourseTree {
private:

    // Nested template class representing a node in the BST.
    template <class T>
    class Node {
    public:
        T course;
        Node* left;
        Node* right;

        /// Parametrized constructor that initializes node with given course data.
        explicit Node(const T& courseData) : course(courseData), left(nullptr), right(nullptr) {}
    };

    Node<Course>* root; ///< Root node of the BST.

    /**
     * @brief Recursive function for in-order traversal of BST.
     * @param node Starting node for traversal.
     * @param courses Vector to store the courses during traversal.
     */
    void inOrderTraversal(Node<Course>* node, std::vector<Course>& courses) const;

    /**
     * @brief Inserts a course into the BST.
     * @param node Current node during recursive insertion.
     * @param course The course to insert.
     * @return Node pointer after insertion.
     */
    Node<Course>* insert(Node<Course>* node, const Course& course);

    /**
     * @brief Searches for a course by its course number in the BST.
     * @param node Current node during recursive search.
     * @param courseNumber The unique identifier of the course to search for.
     * @return Course object if found, otherwise a default Course object.
     */
    Course searchBST(Node<Course>* node, const std::string& courseNumber) const;

public:

    /// Default constructor that initializes an empty BST.
    CourseTree() : root(nullptr) {}

    /**
     * @brief Loads courses from a given file and inserts them into the BST.
     * @param filename The path to the file containing course details.
     */
    void loadCoursesIntoTree(const std::string& filename);

    /// Prints a sample schedule of courses in sorted order.
    void printSampleSchedule() const;

    /**
     * @brief Prints information of a specific course given its course number.
     * @param courseNumber The unique identifier of the course to print.
     */
    void printCourseInformation(const std::string& courseNumber) const;

    /// @return True if the tree is empty, otherwise false.
    bool isEmpty() const { return root == nullptr; }

};

#endif //ALGORITHMSANDDATASTRUCTURES_COURSETREE_H
