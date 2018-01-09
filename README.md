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

The program also creates a CSV file for each teacher and one for the entire school (`grad_reqs_spring_2018.csv`).  The text in each file should be pasted without formatting into the Word Document Template. Then run the provided macro, `grad_req,` which will adjust the so that each student's information will be on its own page.  Occasionally, a student may have earned enough high school credits to make their information continue to the next page. This will have to be manually fixed to fit one page (adjust margins or font size).

### Microsoft Word macro

The `grad_req` macro is saved to the Microsoft Word template. Screen updating is halted, so you may get a frozen like state; however, screen updating is returned once the macro finishes updating the formatting.

The Macro replaces "NEW_PAGE", commas, and the ^b text in the program output files with appropriate page breaks, line breaks, and column breaks.  It then bolds the headings of each column before returning the screen updating functionality.

```
Sub grad_req()
Application.ScreenUpdating = False

Set myRange = ActiveDocument.Content
myRange.Find.Execute findText:="NEW_PAGE", ReplaceWith:="^m", _
 Replace:=wdReplaceAll

Set myRange = ActiveDocument.Content
myRange.Find.Execute findText:=",", ReplaceWith:="^p", _
 Replace:=wdReplaceAll

Set myRange = ActiveDocument.Content
myRange.Find.Execute findText:="^^b", ReplaceWith:="^n", _
 Replace:=wdReplaceAll

Set myRange = ActiveDocument.Content
myRange.Find.ClearFormatting
myRange.Find.Replacement.Font.Bold = True
myRange.Find.Execute findText:="INCOMPLETE CATEGORIES", ReplaceWith:="INCOMPLETE CATEGORIES", _
 Replace:=wdReplaceAll
myRange.Find.Execute findText:="COMPLETED CATEGORIES", ReplaceWith:="COMPLETED CATEGORIES", _
 Replace:=wdReplaceAll

Application.ScreenUpdating = True
End Sub
```

## Author

* **Valerie Chapple** - [vchapple17](https://github.com/vchapple17)

## License

This project is licensed under the MIT License.
