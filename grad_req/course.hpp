/****************************************************************************************
 ** Program Filename: course.hpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 **
 ** Description:     Class course header File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
#include "constants.hpp"

class Course {
private:
    std::string category;
    double numCredits;
    std::string name;
    int status;     // 0 atmpt, 1 complete 2, in progress
    std::string termGrade;
    std::string semGrade;
    
public:
    Course();
    Course(std::string name, double numCredits, std::string category, std::string status, std::string termGrade, std::string semGrade);
    ~Course();
    
    std::string getName() const;
    double getNumCredits();
    std::string getCategory();
    std::string getStatus();
    std::string getGradeTerm();
    std::string getGradeSem();
    
};
#endif
