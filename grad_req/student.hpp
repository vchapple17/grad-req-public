/****************************************************************************************
 ** Program Filename: student.hpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class Student header File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <vector>
#include <fstream>

#include "course.hpp"
#include "constants.hpp"
#include "gradReqs.hpp"

class Student {
private:
    std::string name;
    int grade;
    double totalCredits;
    std::vector<Course*> courses;
    GradReqs gradReqs;
    
public:
    Student();
    Student(std::string name, int grade, double totalCredits);
    Student(const Student &obj);
    ~Student();
    
    std::string getName();
    int getGrade();
    double getTotalCredits();
    
    void addCourse(std::string name, double numCredits, std::string category, std::string status, std::string termGrade, std::string semGrade);
    
    void printCourses();
    void printCourses(std::string categoryName);
    void printCategories();
    void printCoursesByCategory();
    void printCoursesByCompletedCategory();
    
    void saveCourses(std::string categoryName, std::ofstream & fileAddr);
    void saveCoursesByCompletedCategory(std::ofstream & fileAddr);
    
    
};
#endif
