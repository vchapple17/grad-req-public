/****************************************************************************************
 ** Program Filename: course.cpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 **
 ** Description:     Class Course Implementation File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#include <cstdlib>
#include <iostream>
#include "course.hpp"
#include "constants.hpp"


#include <iomanip> // setprecision
#include <sstream> // stringstream



/****************************************************************************************
 ** Function:         course()
 ** Description:      Default Constructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Sets pointers to NULL and integers to zero
 ***************************************************************************************/
Course::Course() {
    
}

// No data validation
Course::Course(std::string name, double numCredits, std::string category, std::string status, std::string termGrade, std::string semGrade) {
    if (numCredits > .5) {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(1) << numCredits;
        std::string s = stream.str();
        
        std::string numCreditStr = std::to_string(numCredits);
        this->name = name + " (" + s + "credit)";
    }
    else {
        this->name = name;
    }
    this->numCredits = numCredits;
    this->category = category;
    if (status == "Comp") {
        this->status = 1;
    }
    else if (status == "IP") {
        this->status = 2;
    }
    else if (status == "Atmpt") {
        this->status = 0;
    }
    
    this->termGrade = termGrade;
    this->semGrade = semGrade;
}

/****************************************************************************************
 ** Function:         ~course()
 ** Description:      Destructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  course Destroyed
 ***************************************************************************************/
Course::~Course(){

}

std::string Course::getName() const {
    return this->name;
}

double Course::getNumCredits() {
    return this->numCredits;
}

std::string Course::getCategory() {
    return this->category;
}

std::string Course::getStatus() {
    if (this->status == 0) return "Atmpt";
    else if (this->status == 1) return "Comp";
    else if (this->status == 2) return "IP";
    else return "Error";
}


std::string Course::getGradeTerm(){
    return this->termGrade;
}
std::string Course::getGradeSem() {
    return this->semGrade;
}
