/****************************************************************************************
 ** Program Filename: teacher.hpp
 ** Author: Valerie Chapple
 ** Date: January 18, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class Teacher header File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#ifndef TEACHER_HPP
#define TEACHER_HPP
#include <string>
#include <vector>
#include "student.hpp"

class Teacher {
private:
    std::string name;
    std::vector<Student*> hour1;
    std::vector<Student*> hour2;
    std::vector<Student*> hour3;
    std::vector<Student*> hour4;
    std::vector<Student*> hour5;
    std::vector<Student*> hour6;
    std::vector<Student*> hour7;
    std::vector<Student*> hour8;
public:
    Teacher();
    Teacher(std::string name);
    Teacher(const Teacher &obj);
    ~Teacher();
    
    std::string getName();
    bool isEmpty(int hour);
    void addStudent(Student * student, int hour);
    std::vector<Student*> getStudentsByHour(int hour);
    void printStudentsByHour();
    void saveStudentGradReqsByHour(std::ofstream & outFile);
    void saveStudentGradReqsByHour(std::string filenameBase);
    void saveStudentGradReqsByHourFile(std::string filenameBase);
};
#endif
