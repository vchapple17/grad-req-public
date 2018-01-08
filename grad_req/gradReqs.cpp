//
//  gradReqs.cpp
//  grad_req
//  Updated: Jan 8, 2018
//  Created by Val Chapple on 1/17/17.
//  Copyright © 2017 Val Chapple. All rights reserved.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "gradReqs.hpp"
#include "gradCategory.hpp"

GradReqs::GradReqs() {
    this->engl = new GradCategory("English Language Arts", REQ_ENGL);
    this->geom = new GradCategory("Geometry", REQ_GEOM);
    this->mathElect = new GradCategory("Mathematics Electives", REQ_MATH_ELECT);
    this->biol = new GradCategory("Biology", REQ_BIOL);
    this->sciElect = new GradCategory("Science Electives", REQ_SCI_ELECT);
    this->socElect = new GradCategory("Social Studies Electives", REQ_SOC_ELECT);
    this->gov = new GradCategory("US Government", REQ_GOV);
    this->usHist = new GradCategory("US History", REQ_USHIST);
    this->computerSci = new GradCategory("Computer Science", REQ_COMPSCI);
    this->genElect = new GradCategory("General Electives", REQ_GEN_ELECT);
    this->fineArts = new GradCategory("Fine Arts", REQ_FINEARTS);
    this->oralCom = new GradCategory("Oral Communications", REQ_ORAL_COM);
    this->peHealth = new GradCategory("PE/ Health", REQ_PE_HEALTH);
}


GradReqs::~GradReqs() {
    delete this->engl;
    delete this->geom;
    delete this->mathElect;
    delete this->biol;
    delete this->sciElect;
    delete this->socElect;
    delete this->gov;
    delete this->usHist;
    delete this->computerSci;
    delete this->genElect;
    delete this->fineArts;
    delete this->oralCom;
    delete this->peHealth;
}


void GradReqs::addCredit(std::string category, std::string status, double creditsToAdd) {
    if (category == this->engl->getName()) this->engl->addCreditToCategory(status, creditsToAdd);
    else if (category == this->geom->getName()) this->geom->addCreditToCategory(status, creditsToAdd);
    else if (category == this->mathElect->getName()) this->mathElect->addCreditToCategory(status, creditsToAdd);
    else if (category == this->biol->getName()) this->biol->addCreditToCategory(status, creditsToAdd);
    else if (category == this->sciElect->getName()) this->sciElect->addCreditToCategory(status, creditsToAdd);
    else if (category == this->socElect->getName()) this->socElect->addCreditToCategory(status, creditsToAdd);
    else if (category == this->gov->getName())this->gov->addCreditToCategory(status, creditsToAdd);
    else if (category == this->usHist->getName()) this->usHist->addCreditToCategory(status, creditsToAdd);
    else if (category == this->computerSci->getName()) this->computerSci->addCreditToCategory(status, creditsToAdd);
    else if (category == this->fineArts->getName()) this->fineArts->addCreditToCategory(status, creditsToAdd);
    else if (category == this->genElect->getName()) this->genElect->addCreditToCategory(status, creditsToAdd);
    else if (category == this->oralCom->getName()) this->oralCom->addCreditToCategory(status, creditsToAdd);
    else if (category == this->peHealth->getName()) this->peHealth->addCreditToCategory(status, creditsToAdd);
    else {
        std::cout << "Error: category [" << category << "] did not match" << std::endl;
    }
}

void GradReqs::printCreditsAndCategory() {
    this->engl->printCreditsAndCategory();
    this->geom->printCreditsAndCategory();
    this->mathElect->printCreditsAndCategory();
    this->biol->printCreditsAndCategory();
    this->sciElect->printCreditsAndCategory();
    this->socElect->printCreditsAndCategory();
    this->gov->printCreditsAndCategory();
    this->usHist->printCreditsAndCategory();
    this->computerSci->printCreditsAndCategory();
    this->fineArts->printCreditsAndCategory();
    this->genElect->printCreditsAndCategory();
    this->oralCom->printCreditsAndCategory();
    this->peHealth->printCreditsAndCategory();
}

std::vector<GradCategory*> GradReqs::getGradCategoryVector() {
    std::vector<GradCategory *> gradCategories;
    gradCategories.push_back(this->engl);
    gradCategories.push_back(this->geom);
    gradCategories.push_back(this->mathElect);
    gradCategories.push_back(this->biol);
    gradCategories.push_back(this->sciElect);
    gradCategories.push_back(this->socElect);
    gradCategories.push_back(this->gov);
    gradCategories.push_back(this->usHist);
    gradCategories.push_back(this->computerSci);
    gradCategories.push_back(this->fineArts);
    gradCategories.push_back(this->genElect);
    gradCategories.push_back(this->oralCom);
    gradCategories.push_back(this->peHealth);
    return gradCategories;
}


std::vector<GradCategory*> GradReqs::getGradCategoryVectorComplete() {
    std::vector<GradCategory *> gradCategories;
    if (this->engl->isComplete()) gradCategories.push_back(this->engl);
    if (this->geom->isComplete()) gradCategories.push_back(this->geom);
    if (this->mathElect->isComplete()) gradCategories.push_back(this->mathElect);
    if (this->biol->isComplete()) gradCategories.push_back(this->biol);
    if (this->sciElect->isComplete()) gradCategories.push_back(this->sciElect);
    if (this->socElect->isComplete()) gradCategories.push_back(this->socElect);
    if (this->gov->isComplete()) gradCategories.push_back(this->gov);
    if (this->usHist->isComplete()) gradCategories.push_back(this->usHist);
    if (this->computerSci->isComplete()) gradCategories.push_back(this->computerSci);
    if (this->fineArts->isComplete()) gradCategories.push_back(this->fineArts);
    if (this->genElect->isComplete()) gradCategories.push_back(this->genElect);
    if (this->oralCom->isComplete()) gradCategories.push_back(this->oralCom);
    if (this->peHealth->isComplete()) gradCategories.push_back(this->peHealth);
    return gradCategories;
}

std::vector<GradCategory*> GradReqs::getGradCategoryVectorIncomplete() {
    std::vector<GradCategory *> gradCategories;
    if (!this->engl->isComplete()) gradCategories.push_back(this->engl);
    if (!this->geom->isComplete()) gradCategories.push_back(this->geom);
    if (!this->mathElect->isComplete()) gradCategories.push_back(this->mathElect);
    if (!this->biol->isComplete()) gradCategories.push_back(this->biol);
    if (!this->sciElect->isComplete()) gradCategories.push_back(this->sciElect);
    if (!this->socElect->isComplete()) gradCategories.push_back(this->socElect);
    if (!this->gov->isComplete()) gradCategories.push_back(this->gov);
    if (!this->usHist->isComplete()) gradCategories.push_back(this->usHist);
    if (!this->computerSci->isComplete()) gradCategories.push_back(this->computerSci);
    if (!this->fineArts->isComplete()) gradCategories.push_back(this->fineArts);
    if (!this->genElect->isComplete()) gradCategories.push_back(this->genElect);
    if (!this->oralCom->isComplete()) gradCategories.push_back(this->oralCom);
    if (!this->peHealth->isComplete()) gradCategories.push_back(this->peHealth);
    return gradCategories;
}

