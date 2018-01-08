//
//  gradReqs.hpp
//  grad_req
//  Updated: Jan 8, 2018
//  Created by Val Chapple on 1/17/17.
//  Copyright © 2017 Val Chapple. All rights reserved.
//

#ifndef GRAD_REQS_HPP
#define GRAD_REQS_HPP
#include <string>
#include <vector>

#include "gradCategory.hpp"
#include "constants.hpp"

class GradReqs {
private:
    GradCategory * engl;
    GradCategory * geom;
    GradCategory * mathElect;
    GradCategory * biol;
    GradCategory * sciElect;
    GradCategory * socElect;
    GradCategory * gov;
    GradCategory * usHist;
    GradCategory * computerSci;
    GradCategory * fineArts;
    GradCategory * genElect;
    GradCategory * oralCom;
    GradCategory * peHealth;
    
public:
    GradReqs();
    ~GradReqs();
    
    void addCredit(std::string category, std::string status, double credit);
    void printCreditsAndCategory();
    std::vector<GradCategory*> getGradCategoryVector();
    std::vector<GradCategory*> getGradCategoryVectorComplete();
    std::vector<GradCategory*> getGradCategoryVectorIncomplete();
};

#endif
