# grad-req-public

Skyward is a Student Information System that allows us to track student courses, attendance, GPA, etc.  While it is powerful, it does not always have an easy to read print out of information.

Therefore, two Skyward reports are used as inputs and a customized CSV file is the output for each class period for each teacher, as well as a .cvs for the entire school.

The custom CSV file can then be copied into a Word template with two columns.  A template is provided that includes a macro with quickly find and replace the unique markers in the .cvs file.

For instance, in the output file...

* a comma is the same as a new line
* the "NEW_PAGE" is the same as a page break
* a "^b" is the same as a column break

## Compiling & Execution

The Xcode 9.2 project is setup to compile and run the C++ 99 program, but can be compiled separately.  If you use Xcode, do not forget to add the two input files to the same file as the Product folder that holds your executable.

### Input

**grad_req.txt** is a tab-separated file that has a row for each course taken by each student. The file has been sorted by the student name, with the first line indicating the total number of credits taken followed by rows for each course, noting which graduation category.

**student_schedules.txt** is a tab-separated file that lists a student's name (4 column parts) followed by the names of teachers for each of the 8 class period schedule.

### Output

The program will output to the console errors with file reading and/or mismatching students between files.  It also prints out the teacher and the students associated with each hour.

The program also creates a CSV file for each teacher and one for the entire school (grad_reqs_spring_2018.csv).  These files can be placed in the Word Document Template and have a Macro run to format it.

## Author

* **Valerie Chapple** - [vchapple17](https://github.com/vchapple17)

## License

This project is licensed under the MIT License.
