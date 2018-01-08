/****************************************************************************************
 ** Program Filename: school.hpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class School header File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#ifndef SCHOOL_HPP
#define SCHOOL_HPP
#include <string>
#include "student.hpp"
#include "teacher.hpp"
#include <vector>
#include "constants.hpp"

class School {
private:
    std::vector<Student*> students;
    std::vector<Teacher*> teachers;
    int numStudents;
    int numTeachers;
    
public:
    School();
    ~School();
    School(const School &obj);
    
    void loadStudentsFromFile(std::string filename);
    Student * getStudent(std::string name, int grade);
    void printStudents();
    void saveStudentsToCSV(std::string filename);
    
    void loadTeachersFromFile(std::string filename);
    Teacher * getTeacher(std::string name);
    void printTeachers();
    Teacher * addOrGetTeacher(std::string name);
    void addStudentToTeachers(Student * student, std::string teachers[8]); // array of 8 in order... 1st hour to 8th hour
    
    void printStudentsByTeacher();
    void saveStudentsByTeacherToCSV(std::string filename);
};
#endif
