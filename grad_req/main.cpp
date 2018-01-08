/****************************************************************************************
 ** Program Filename: main.cpp
 ** Author: Valerie Chapple
 ** Date: January 14, 2017
 ** Updated: Jan 8, 2018
 **
 ** Description:
 ** Takes student course history (course, category, and if passed or not) and rearranges
 ** to sort the classes by COMPLETED and INCOMPLETE graduation categories
 **
 ** Input: grad_req.txt: Tab Separated
 ** Name, Grade, Department, Required, YTD, IP, Required, Complete/IP, Class, Status, Credit, Grade TM, Grade Sem
 ** Example:
 ** "Lastname, Firstname M."    11    English Language Arts    2.5    0.5    1.5    English 9    Comp    0.5    TM2:[B-]    S2:[B-]
 
 ** Output:
 ** One row contains information for one student, and markers for Macros
 **     * ^b for column break
 **     * NEW_PAGE for page break
 **     * , for new line
 ** Copy paste raw text into Word Document Template and run grad_req Macro
 **
 ***************************************************************************************/


#include <iostream>
#include <cassert>
#include <string>
#include <iostream>

#include "school.hpp"
#include "constants.hpp"

int main() {
    School lansing;
    
    lansing.loadStudentsFromFile(FILENAME);
//    lansing.printStudents();
//    assert(lansing.contains("\"Zule, Mary K.\"", 9) == true);
    lansing.saveStudentsToCSV(FILENAME_OUT);
    lansing.loadTeachersFromFile(FILENAME_TEACHER);
//    std::cout << lansing.getTeacher("Chapple_Valerie")->getName() << std::endl;
//    lansing.printTeachers();
    lansing.printStudentsByTeacher();
    lansing.saveStudentsByTeacherToCSV(FILENAME_OUT_TEACHER);
    return 0;
}
