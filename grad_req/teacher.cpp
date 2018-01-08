/****************************************************************************************
 ** Program Filename: teacher.cpp
 ** Author: Valerie Chapple
 ** Date: January 18, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class Teacher Implementation File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>

#include "teacher.hpp"
#include "student.hpp"

/****************************************************************************************
 ** Function:         Teacher()
 ** Description:      Default Constructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Sets pointers to NULL and integers to zero
 ***************************************************************************************/
Teacher::Teacher() {
}

Teacher::Teacher(std::string name) {
    this->name = name;
}

/****************************************************************************************
 ** Function:         ~Teacher()
 ** Description:      Destructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Teacher Destroyed
 ***************************************************************************************/
Teacher::~Teacher(){
    // delete courses memory
}


Teacher::Teacher(const Teacher &obj) {
    
}


std::string Teacher::getName() {
    return this->name;
}

bool Teacher::isEmpty(int hour) {
    // returns true if no students are in an hour.
    assert(hour >= 1);
    assert(hour <= 8);
    
    switch (hour) {
        case 1:
            return hour1.empty();
            break;
        case 2:
            return hour2.empty();
            break;
        case 3:
            return hour3.empty();
            break;
        case 4:
            return hour4.empty();
            break;
        case 5:
            return hour5.empty();
            break;
        case 6:
            return hour6.empty();
            break;
        case 7:
            return hour7.empty();
            break;
        case 8:
            return hour8.empty();
            break;
    }
    return true;
}

void Teacher::addStudent(Student * student, int hour) {
    assert(hour > 0);
    assert(hour < 9);
    assert(student != NULL);
    
    switch (hour) {
        case 1:
            this->hour1.push_back(student);
            break;
        case 2:
            this->hour2.push_back(student);
            break;
        case 3:
            this->hour3.push_back(student);
            break;
        case 4:
            this->hour4.push_back(student);
            break;
        case 5:
            this->hour5.push_back(student);
            break;
        case 6:
            this->hour6.push_back(student);
            break;
        case 7:
            this->hour7.push_back(student);
            break;
        case 8:
            this->hour8.push_back(student);
            break;
        default:
            std::cout << "No student added\n";
            break;
    }
}

std::vector<Student*> Teacher::getStudentsByHour(int hour) {
    assert(hour > 0);
    assert(hour < 9);
    
    switch (hour) {
        case 1:
            return this->hour1;
            break;
        case 2:
            return this->hour2;
            break;
        case 3:
            return this->hour3;
            break;
        case 4:
            return this->hour4;
            break;
        case 5:
            return this->hour5;
            break;
        case 6:
            return this->hour6;
            break;
        case 7:
            return this->hour7;
            break;
        case 8:
            return this->hour8;
            break;
        default:
            std::cout << "No students returned\n";
            std::vector<Student*> teacher;
            return teacher;
            break;
    }
}

void Teacher::printStudentsByHour() {
    for (int i = 1; i <=8; i++) {
        std::cout << "Hour " <<  i << std::endl;
        std::vector<Student *> students = this->getStudentsByHour(i);
        for (std::vector<Student *>::iterator j = students.begin(); j < students.end(); j++) {
            std::cout << "\t" << (*j)->getName() << std::endl;
        }
    }
}

void Teacher::saveStudentGradReqsByHour(std::ofstream & outFile) {
    for (int i = 1; i <=8; i++) {
        std::vector<Student *> students = this->getStudentsByHour(i);
        for (std::vector<Student *>::iterator j = students.begin(); j < students.end(); j++) {
            outFile << "Hour " <<  i << std::endl;
            outFile << "\t" << (*j)->getName() << std::endl;
        }
    }
}

void Teacher::saveStudentGradReqsByHour(std::string filenameBase) {
    std::string name = this->getName();
    std::string hour;
    for (int i = 1; i <=8; i++) {
        if (!(this->isEmpty(i))) {
            // Write to file for each hour
            hour = std::to_string(i);
            const char * filename = (filenameBase + name + hour + ".csv").c_str();
            std::ofstream outFile;
            outFile.open(filename);
            if (outFile) {
//                outFile << name << std::endl;
                // Go through each student in current hour
                std::vector<Student *> students = this->getStudentsByHour(i);
                
                for (std::vector<Student *>::iterator j = students.begin(); j < students.end(); j++) {
                    Student * current = *j;
                    if (j != students.begin()) outFile << "NEW_PAGE,";
                    outFile << "Teacher: " << name << ",";
                    outFile << "Name: " << current->getName() << "\t";
                    outFile << "Hour: " <<  i << ",";
                    outFile << "Grade Level: " << current->getGrade() << "\t";
                    outFile << "Credits Earned: " << current->getTotalCredits() << ",";
                    outFile << "****************************";
                    current->saveCoursesByCompletedCategory(outFile);
                    outFile << std::endl;
                }
            }
            outFile.close();
        }
    }
}


// Single File For Teacher
void Teacher::saveStudentGradReqsByHourFile(std::string filenameBase) {
    std::string name = this->getName();
    std::string hour;
    const char * filename = (filenameBase + name + ".csv").c_str();
    std::ofstream outFile;
    // Write to file with each hour
    outFile.open(filename);
    if (outFile) {
        bool firstClass = true;
        for (int i = 1; i <=8; i++) {
            if (!(this->isEmpty(i))) {
                if (!firstClass) outFile << "DOC_BREAK";
                firstClass = false;
                // Go through each student in current hour
                std::vector<Student *> students = this->getStudentsByHour(i);
                for (std::vector<Student *>::iterator j = students.begin(); j < students.end(); j++) {
                    Student * current = *j;
                    if (j != students.begin()) outFile << "NEW_PAGE,";
                    outFile << "Teacher: " << name << ",";
                    outFile << "Name: " << current->getName() << "\t";
                    outFile << "Hour: " <<  i << ",";
                    outFile << "Grade Level: " << current->getGrade() << "\t";
                    outFile << "Credits Earned: " << current->getTotalCredits() << ",";
                    outFile << "****************************";
                    current->saveCoursesByCompletedCategory(outFile);
                    outFile << std::endl;
                }
                
            }
        }
    }
    outFile.close();
}
