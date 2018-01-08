//
//  gradCategory.hpp
//  grad_req
//  Updated: Jan 8, 2018
//  Created by Val Chapple on 1/17/17.
//  Copyright © 2017 Val Chapple. All rights reserved.
//

#ifndef GRAD_CATEGORY_HPP
#define GRAD_CATEGORY_HPP
#include <string>

class GradCategory {
private:
    std::string name;
    const double creditsReq;
    
    double creditsComp;
    double creditsInProgress;
    double creditsAtmpt;
    
public:
    GradCategory();
    ~GradCategory();
    GradCategory(std::string name, double creditsReq);
    
    // Getter
    std::string getName();
    double getCreditsReq() const;
    double getCreditsComp();
    double getCreditsInProgress();
    double getCreditsAtmpt();
    
    // Calculated Getter
    double getCreditsEarned();
    
    // Incremented Setter
    void addCreditToCategory(std::string status, double credits);
    
    // General Functions
    bool isComplete();
    void printCreditsAndCategory();
    void saveCreditsAndCategory(std::ofstream & fileAddr);
};

#endif
