//
//  line.cpp
//  grad_req
//
//  Created by Val Chapple on 1/14/17.
//  Copyright © 2017 Val Chapple. All rights reserved.
//

#include <string>

// http://stackoverflow.com/questions/40337177/c-how-to-use-fstream-to-read-tab-delimited-file-with-spaces


struct Line
{
    std::string name;
    int         grade;
    std::string category;
    std::string required;
    
    std::string  col;
    std::string  uid;
    
    void swap(Line& other) noexcept {
        using std::swap;
        swap(grade, other.grade);
        swap(col, other.col);
        swap(uid, other.uid);
    }
    friend std::istream& operator>>(std::istream& in, Line& data);
};
