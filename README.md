# Class-Algorithm
# Program Description
This program provides a practical experience with basic array operations, file input/output processes, and simple object creation using the C++ programming language. Below are the key details of the assignment.

Program Overview
Reading from girdi.csv File
Data will be read from the girdi.csv file, and an object class will be created. The file contains the following fields separated by commas, with their corresponding data types:

Name → string[]
Student ID → string[]
Midterm Exam → float[]
Second Exam → float[]
Homework → float[]
Final Exam → float[]
Attendance Count → int[]
Class Details

The class will be named Student.
As data is read from the file, the corresponding fields in the class will be populated with these values.
Required Methods in the Student Class
The Student class must include the following methods:

Constructor: To initialize variables and create dynamic arrays.
Destructor: To delete dynamic arrays and free memory.
readFromCSV(): To load values from the CSV file into class variables.
average(): To calculate the average score based on the following weight distribution:
Midterm Exam: 20%
Second Exam: 20%
Homework: 20%
Final Exam: 40%
print(): To print the student list in a formatted way.
When called with no parameters, it should display the entire list.
When called with 0 as an argument, it should display the list of failing students.
When called with 1 as an argument, it should display the list of passing students (passing threshold: 50).
If a string argument is passed, it should consider the string as a file name and write the results to the specified file.
