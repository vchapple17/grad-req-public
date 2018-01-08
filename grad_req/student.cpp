/****************************************************************************************
 ** Program Filename: student.cpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class Student Implementation File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/


#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>

#include "student.hpp"
#include "course.hpp"
#include "constants.hpp"
#include "gradReqs.hpp"

/****************************************************************************************
 ** Function:         Student()
 ** Description:      Default Constructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Sets pointers to NULL and integers to zero
 ***************************************************************************************/
Student::Student() {
    
}

Student::Student(std::string name, int grade, double totalCredits) {
    this->name = name;
    this->grade = grade;
    this->totalCredits = totalCredits;
}

/****************************************************************************************
 ** Function:         ~Student()
 ** Description:      Destructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Student Destroyed
 ***************************************************************************************/
Student::~Student(){
    // delete courses memory
    
}


Student::Student(const Student &obj) {
    
}
/****************************************************************************************
 ** Function:         getName()
 ** Description:      Returns name of Student
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Returns name of Student
 ***************************************************************************************/
std::string Student::getName()  {
    return this->name;
}

int Student::getGrade() {
    return this->grade;
}

double Student::getTotalCredits() {
    return this->totalCredits;
}

void Student::addCourse(std::string name, double numCredits, std::string category, std::string status, std::string termGrade, std::string semGrade) {
    Course * course = new Course(name, numCredits, category, status, termGrade, semGrade);
    assert(course != NULL);
    this->courses.push_back(course);
    
    // Add course to total, assuming in progress class is passed.
    gradReqs.addCredit(course->getCategory(), course->getStatus(), course->getNumCredits());
    
    }


void Student::printCourses() {
    for (std::vector<Course*>::iterator i = this->courses.begin(); i != this->courses.end(); i++) {
        Course * current = *i;
        std::cout << current->getCategory() << ": " << current->getName() << std::endl;
    }
}


void Student::printCourses(std::string categoryName) {
    for (std::vector<Course*>::iterator i = this->courses.begin(); i != this->courses.end(); i++) {
        Course * current = *i;
        if (current->getCategory() == categoryName) {
            std::cout << "\t ";
            std::string status = current->getStatus();
            
            if (status == "IP") std::cout << "InProg";
            else  std::cout << status;
            
            std::string semGrade = current->getGradeSem();
            if (semGrade == "") std::cout << "NoGrade\t";
            else std::cout << "\t" << current->getGradeSem() << "\t";
            std::cout << current->getName() << std::endl;
        }
    }
}

void Student::saveCourses(std::string categoryName, std::ofstream & outFile) {
    for (std::vector<Course*>::iterator i = this->courses.begin(); i != this->courses.end(); i++) {
        Course * current = *i;
        if (current->getCategory() == categoryName) {
            std::string status = current->getStatus();
            outFile << "\t";
            if (status == "IP") outFile << "InProg\t";
            else  outFile << status << "\t";
            
            std::string semGrade = current->getGradeSem();
            if (semGrade == "") outFile << "NoGrade\t";
            else outFile << current->getGradeSem() << "\t";
            outFile << current->getName() << ",";
        }
    }
}

void Student::printCategories() {
    this->gradReqs.printCreditsAndCategory();
}

void Student::printCoursesByCategory() {
    std::vector<GradCategory*> gradCategories = gradReqs.getGradCategoryVector();
    for (std::vector<GradCategory*>::iterator i = gradCategories.begin(); i != gradCategories.end(); i++) {
        GradCategory * current = *i;
        current->printCreditsAndCategory();
        this->printCourses(current->getName());
        std::cout << "------------------------------" << std::endl;
    }
}

void Student::printCoursesByCompletedCategory() {
    std::vector<GradCategory*> completed = gradReqs.getGradCategoryVectorComplete();
    std::vector<GradCategory*> notCompleted = gradReqs.getGradCategoryVectorIncomplete();
    std::cout << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "\tINCOMPLETE CATEGORIES" << std::endl;
    std::cout << "***********************************" << std::endl;
    for (std::vector<GradCategory*>::iterator i = notCompleted.begin(); i != notCompleted.end(); i++) {
        GradCategory * current = *i;
        current->printCreditsAndCategory();
        this->printCourses(current->getName());
        std::cout << "------------------------------" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "\tCOMPLETED CATEGORIES" << std::endl;
    std::cout << "***********************************" << std::endl;
    for (std::vector<GradCategory*>::iterator i = completed.begin(); i != completed.end(); i++) {
        GradCategory * current = *i;
        current->printCreditsAndCategory();
        this->printCourses(current->getName());
        std::cout << "-----------------------------------" << std::endl;
    }
    std::cout << std::endl;
}


void Student::saveCoursesByCompletedCategory(std::ofstream &outFile) {
//    outFile << "^b";
    std::vector<GradCategory*> completed = gradReqs.getGradCategoryVectorComplete();
    std::vector<GradCategory*> notCompleted = gradReqs.getGradCategoryVectorIncomplete();
    
    outFile << ",INCOMPLETE CATEGORIES,";
    for (std::vector<GradCategory*>::iterator i = notCompleted.begin(); i != notCompleted.end(); i++) {
        GradCategory * current = *i;
        current->saveCreditsAndCategory(outFile);
        this->saveCourses(current->getName(), outFile);
    }
    outFile << "^b";
    outFile << "COMPLETED CATEGORIES,";
    for (std::vector<GradCategory*>::iterator i = completed.begin(); i != completed.end(); i++) {
        GradCategory * current = *i;
        current->saveCreditsAndCategory(outFile);
        this->saveCourses(current->getName(), outFile);
    }
}
