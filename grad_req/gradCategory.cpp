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
#include <fstream>

#include "gradCategory.hpp"

/****************************************************************************************
 ** Function:         GradReq()
 ** Description:      Default Constructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:
 ***************************************************************************************/
GradCategory::GradCategory():creditsReq(0) {
    this->name = "";
    
    this->creditsComp = 0;
    this->creditsInProgress = 0;
    this->creditsAtmpt = 0;
}

GradCategory::GradCategory(std::string name, const double creditsReq):creditsReq(creditsReq) {
    this->name = name;
    this->creditsComp = 0;
    this->creditsInProgress = 0;
    this->creditsAtmpt = 0;
}

GradCategory::~GradCategory() {
    
}

std::string GradCategory::getName() {
    return this->name;
}

double GradCategory::getCreditsReq() const {
    return this->creditsReq;
}
double GradCategory::getCreditsComp() {
    return this->creditsComp;
}
double GradCategory::getCreditsInProgress() {
    return this->creditsInProgress;
}
double GradCategory::getCreditsAtmpt() {
    return this->creditsAtmpt;
}

double GradCategory::getCreditsEarned() {
    return (this->creditsComp + this->creditsInProgress);
}

void GradCategory::addCreditToCategory(std::string status, double credits) {
    if (status == "Comp") this->creditsComp += credits;
    else if (status == "IP") this->creditsInProgress += credits;
    else if (status == "Atmpt") this->creditsAtmpt += credits;
}

bool GradCategory::isComplete() {
    return (this->getCreditsEarned() >= this->creditsReq);
}

void GradCategory::printCreditsAndCategory() {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << this->getCreditsEarned() << " of " << this->getCreditsReq();
    std::cout << "\t" << this->name << std::endl;
}

void GradCategory::saveCreditsAndCategory(std::ofstream & outFile) {
    outFile << std::setprecision(1) << std::fixed;
    outFile << this->getCreditsEarned() << " of " << this->getCreditsReq() << " - ";
    if (this->name == "US History") outFile << "Am History (Junior Year),";
    else if (this->name == "US Government") outFile << "Am Gov (Senior Year),";
    else if (this->name == "Biology") outFile << "Biology (Sophomore Year),";
    else outFile << this->name << ",";
}
