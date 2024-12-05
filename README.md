# Class-Algorithm

## Program Description

This program provides a practical experience with basic array operations, file input/output processes, and simple object creation using the C++ programming language. Below are the key details of the assignment.

---

### Program Overview

1. **Reading from `girdi.csv` File**  
   Data will be read from the `girdi.csv` file, and an object class will be created. The file contains the following fields, separated by commas, with their corresponding data types:  
   - **Name** → `string[]`  
   - **Student ID** → `string[]`  
   - **Midterm Exam** → `float[]`  
   - **Second Exam** → `float[]`  
   - **Homework** → `float[]`  
   - **Final Exam** → `float[]`  
   - **Attendance Count** → `int[]`  

---

### Class Details

- The class will be named **`Student`**.  
- As data is read from the file, the corresponding fields in the class will be populated with these values.

---

### Methods in the `Student` Class

The `Student` class must include the following methods:

1. **Constructor**  
   - Used to initialize variables and create dynamic arrays.  

2. **Destructor**  
   - Used to delete dynamic arrays and free memory.  

3. **`readFromCSV()`**  
   - Loads values from the CSV file into class variables.  

4. **`average()`**  
   - Calculates the average score based on the following weight distribution:  
     - **Midterm Exam:** 20%  
     - **Second Exam:** 20%  
     - **Homework:** 20%  
     - **Final Exam:** 40%  

5. **`print()`**  
   - Prints the student list in a formatted way.  
     - **Without Parameters**: Displays the entire list.  
     - **With Argument `0`**: Displays the list of failing students.  
     - **With Argument `1`**: Displays the list of passing students (passing threshold: **50**).  
     - **With a String Argument**: Treats the string as a file name and writes the results to the specified file.

---

### Additional Notes

- **Input File Format**: Ensure that the `girdi.csv` file follows the specified structure and uses commas as separators.  
- **Output File**: When using the string argument in the `print()` method, results will be saved in the provided file name.

---

