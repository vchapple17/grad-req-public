/****************************************************************************************
 ** Program Filename: school.cpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 ** Description:     Class School Implementation File
 ** Input:           Constructor with parameters, set/get functions
 ** Output:          Returns member variables and calculated values. No console display.
 ***************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "constants.hpp"
#include "student.hpp"
#include "school.hpp"

/****************************************************************************************
 ** Function:         School()
 ** Description:      Default Constructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  Sets pointers to NULL and integers to zero
 ***************************************************************************************/
School::School() {
    numStudents = 0;
    numTeachers = 0;
}


/****************************************************************************************
 ** Function:         ~School()
 ** Description:      Destructor
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  GradCategory Destroyed
 ***************************************************************************************/
School::~School(){

}

School::School(const School &obj) {
    // Copy constructor
}

/****************************************************************************************
 ** Function:         getStudentsFromFile()
 ** Description:      Creates array of Student objects from comma-separated file.
 **                   File Columns:
 **                     Name, Grade, Department, Required, YTD, IP, Required
 **                     Complete/IP, Class, Status, Credit, Grade TM, Grade Sem
 **
 ** Parameters:       None
 ** Pre-Conditions:   File Requirements
 **                     File is a comma-separated text file
 **                     13 Columns:
 **                         Name, Grade, Department, Required, YTD, IP, Required,
 **                         Complete/IP, Class, Status, Credit, Grade TM, Grade Sem
 **                     Name and Grade Must be unique.
 **                     All columns required, except Complete/IP, Class, Status, Credit,
 **                         Grade TM, Grade Sem
 **                     File sorted by Name, such that student information comes in seq-
 **                         uential rows.
 **
 ** Post-Conditions:    Compiles a particular's student's rows into a single student obj.
 ***************************************************************************************/

// Help from: http://www.cplusplus.com/forum/general/17771/
void School::loadStudentsFromFile(std::string filename) {
    std::ifstream inputFile;
    std::cout << filename << std::endl;
    inputFile.open(filename);
    if (inputFile.fail()) {
        // Error
        std::cout << "Error opening student input file." << std::endl;
        inputFile.close();
        exit(2);
    }
    
    // Read lines
    while (inputFile) {
        std::string line;
        if (!std::getline(inputFile, line, '\r')) break;
        std::istringstream ss(line);
        int col = 0;
        std::string name;
        int grade = 0;
        std::string category;
        double creditsEarned = 0;
        double creditsInProgress = 0;
        double creditsRemaining = 0;
        std::string courseName;
        std::string courseStatus;
        double courseCredits = 0;
        std::string gradeTerm;
        std::string gradeSem;

        while (ss) {
            col++;
            std::string item;
            
            if (!std::getline(ss, item, '\t')) break;
            if (col == 1) {
                name = item;
                if (name[0] == '\"') {
                    const char * cname = name.c_str();
                    char *temp = new char[name.length() + 1];
                    int i = 0;
                    int j = 0;
                    for (i = 0; i <= name.length(); i++) {
                        if ((cname[i] != '\"') && (cname[i] != '\"')) {
                            if (cname[i] == ',') {
                                temp[j] = ';';
                                j++;
                            }
                            else {
                                temp[j] = cname[i];
                                j++;
                            }
                        }
                    }
                    name = temp;
                }
            }
            else if ((col == 2) && (item != "")) {
                grade = std::stoi(item);
            }
            else if (col == 3) {
                category = item;
            }
            else if ((col == 4) && (item != "")) {
                creditsEarned = std::stod(item);
            }
            else if ((col == 5) && (item != "")) {
                creditsInProgress = std::stod(item);
            }
            else if ((col == 6) && (item != "")) {
                creditsRemaining = std::stod(item);
            }
            else if (col == 7) {
                courseName = item;
            }
            else if (col == 8) {
                courseStatus = item;
            }
            else if ((col == 9) && (item != "")) {
                courseCredits = std::stod(item);
            }
            else if (col == 10) {
                gradeTerm = item;
            }
            else if (col == 11) {
                gradeSem = item;
            }
        }
        // Check if student exists
        Student * student = this->getStudent(name, grade);
        
        if (student == NULL) {
            if (category == "Total") {
                student = new Student(name, grade, creditsEarned+creditsInProgress);
                this->students.push_back(student);
                this->numStudents++;
            }
            else {
                // Error
                std::cout << "Error: No Total for first row of student: " << name << std::endl;
            }
        }
        else {
            // Student exists, Add course
            if (courseName != "") {
                student->addCourse(courseName, courseCredits, category, courseStatus, gradeTerm, gradeSem);
            }
        }
        
    }
}

Student * School::getStudent(std::string name, int grade) {
    // returns student if student with name matches.
    for (std::vector<Student*>::iterator i = this->students.begin(); i != this->students.end(); i++) {
        Student * current = *i;
        if ((current->getName() == name)) {
            if (current->getGrade() == grade) return current;
            else {
                std::cout << "Error: Grade level doesn't match for " << name << std::endl;
                return current;
            }
        }
    }
//    std::cout << "No Student with name: " << name << std::endl;
    return NULL;
}

void School::printStudents() {
    int count = 0;
    for (std::vector<Student*>::iterator i = this->students.begin(); i != this->students.end(); i++) {
        Student * current = *i;
        std::cout << "*********************************************************" << std::endl;
        std::cout  << std::endl;
        std::cout << current->getName() << "\tGrade: " << current->getGrade() << std::endl;
        current->printCoursesByCompletedCategory();
        std::cout << "\tTotal Credits: " << current->getTotalCredits() << std::endl ;
        std::cout << std::endl;
        count++;
    }
    std::cout << "Number of students: " << this->numStudents << "\tcount :" << count << std::endl;
    
}

void School::saveStudentsToCSV(std::string filename) {
    std::ofstream outFile;
    outFile.open(filename);
    if (outFile) {
        for (std::vector<Student*>::iterator i = this->students.begin(); i != this->students.end(); i++) {
            if (i != this->students.begin()) outFile << "NEW_PAGE,";
            
            Student * current = *i;
            outFile << "Name: " << current->getName() << ",Grade Level: " << current->getGrade() << "\t";
            outFile << "Credits Earned: " << current->getTotalCredits() << ",";
            current->saveCoursesByCompletedCategory(outFile);
            
            outFile << std::endl;
        }
    }
    outFile.close();
}

// Fixing file four column name
void School::loadTeachersFromFile(std::string filename) {
    std::ifstream inputFile;
    inputFile.open(filename);
    if (inputFile.fail()) {
        // Error
        std::cout << "Error opening teacher input file." << std::endl;
        inputFile.close();
        exit(2);
    }
    
    // Read lines
    while (inputFile) {
        std::string line;
        if (!std::getline(inputFile, line, '\r')) break;
        std::istringstream ss(line);
        //        std::cout << line;
        int col = 0;
        std::string name;
        int grade = 0;
        
        std::string teachers[8];
        for (int i = 0; i < 8; i++) teachers[i] = "";
        
        int hour = 0;
        
        while (ss) {
            col++;
            std::string item;
            
            if (!std::getline(ss, item, '\t')) break;
            if ((col == 1) && (item != "")) {
                name = item;            // Last Name
                // First Name
                col++;      // col = 2
                if (!std::getline(ss, item, '\t')) break;
                name += "; " + item;
                
                // Middle Initial (optional, need to add period)
                col++;      // col = 3
                if (!std::getline(ss, item, '\t')) break;
                if (item != "") name+= " " + item + ".";
                
                // Suffix (optional, no period)
                col++;      // col = 4
                if (!std::getline(ss, item, '\t')) break;
                if (item != "") name+= " " + item;
                std::cout << "NAME ACQUIRED: " << name << std::endl;
            }
            else if ((col == 5) && (item != "")) {
                grade = std::stoi(item);
            }
            else if ((col % 2 == 0) && (item != "")) {        // Determine Hour listed,if any and valid.
                hour = std::stoi(item);
                if ((hour <= 8) && (hour >= 1)) {
                    hour--;     // Adjust hour to appropriate index of array
                    col++;      // col =  next odd
                    if (!std::getline(ss, item, '\t')) break;
                    if (item != "") {
                        teachers[hour] = item;
                    }
                }
            }
        }
        // Check if student exists
        Student * student = this->getStudent(name, grade);
        
        
        if (student == NULL) {
            // Error
            std::cout << "Error: Student not in Grad Requirements File: " << name << std::endl;
        }
        else {
            // Add student to teacher's lists.
            this->addStudentToTeachers(student, teachers);
        }
    }
}


Teacher * School::addOrGetTeacher(std::string name) {
    if (name != "") {
        Teacher * teacher = this->getTeacher(name);
        if ( teacher == NULL) {
            // Push new teacher to school
            teacher = new Teacher(name);
            this->teachers.push_back(teacher);
            this->numTeachers++;
        }
        return teacher;
    }
    else {
        return NULL;
    }
}

Teacher * School::getTeacher(std::string name) {
    for (std::vector<Teacher*>::iterator i = this->teachers.begin(); i != this->teachers.end(); i++) {
        Teacher * current = *i;
        if (current->getName() == name) {
            return current;
        }
    }
    return NULL;
}

void School::printTeachers() {
    int count = 0;
    for (std::vector<Teacher*>::iterator i = this->teachers.begin(); i != this->teachers.end(); i++) {
        Teacher * current = *i;
        std::cout << current->getName() << std::endl;
        count++;
    }
    std::cout << "Number of teachers: " << this->numTeachers << "\tcount :" << count << std::endl;
}


void School::addStudentToTeachers(Student * student, std::string teachers[8]) {
    std::string teacherName;
    int hour = 1;
    Teacher * teacher;
    
    // First Hour
    for (int i = 0; i < 8; i++) {
        hour = i + 1;
        teacher = this->addOrGetTeacher(teachers[i]);
        if (teacher != NULL) teacher->addStudent(student, hour);
    }
}



void School::printStudentsByTeacher() {
    for (std::vector<Teacher*>::iterator i = this->teachers.begin(); i != this->teachers.end(); i++) {
        Teacher * current = *i;
        std::cout << "*********************************************************" << std::endl;
        std::cout  << std::endl;
        std::cout << current->getName() << std::endl;
        current->printStudentsByHour();
        std::cout << std::endl;
    }
}

void School::saveStudentsByTeacherToCSV(std::string filenameBase){
    // For each teacher in vector, create file for each hour.
    
        // For each teacher
        for (std::vector<Teacher*>::iterator i = this->teachers.begin(); i != this->teachers.end(); i++) {
            Teacher * current = *i;
//            current->saveStudentGradReqsByHourFile(filenameBase);
            current->saveStudentGradReqsByHour(filenameBase);
        }
}

