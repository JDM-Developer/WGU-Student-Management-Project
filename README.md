# WGU-Student-Management-Project

## Project Description

Developed a C++ application to manage student data for an imaginary university, demonstrating proficiency in various programming concepts and techniques. The project involved creating and manipulating student records, implementing control structures, arrays, pointers, and utilizing object-oriented programming principles.

**Course**: SCRIPTING AND PROGRAMMING - APPLICATIONS — C867  
**Tools & Environment**: Visual Studio, C++

## Project Demo

![Student management project console output](docs/project-screenshot.png)

## Key Responsibilities

- **Data Management**: Designed and implemented classes to handle student data, including student ID, name, email, age, course completion days, and degree programs.
- **Classes & Objects**: Created two main classes, `Student` and `Roster`, to encapsulate and manage student information.
- **Enumerated Types**: Defined an enumerated data type `DegreeProgram` for different degree programs.
- **Data Parsing & Initialization**: Parsed student data from a predefined dataset and initialized student objects, storing them in an array of pointers.
- **Control Structures**: Implemented decision and loop constructs to manage the flow of the application.
- **Arrays & Pointers**: Utilized arrays to store and manipulate student data and applied pointers for dynamic memory management.
- **Functions**: Developed accessor (getter) and mutator (setter) functions for encapsulated data access and modification, along with other essential functions such as `add`, `remove`, `printAll`, `printAverageDaysInCourse`, `printInvalidEmails`, and `printByDegreeProgram`.
- **Input Validation**: Implemented email validation to check for invalid email formats.
- **Memory Management**: Ensured proper memory management by implementing a destructor to release dynamically allocated memory.
- **Testing & Debugging**: Verified the program's functionality with comprehensive testing and debugging, ensuring accurate output and performance.

## Key Achievements

- Successfully migrated an existing student management system to a new platform using C++.
- Demonstrated effective use of object-oriented programming to manage complex data structures.
- Enhanced skills in C++ programming, including memory management, data structures, and control structures.
- Gained experience in developing and maintaining a real-world application, preparing for technical interviews and future employment opportunities in software development.

## Course Instructions

You are hired as a contractor to help a university migrate an existing student system to a new platform using the C++ language. You are responsible for implementing the part of the system based on these requirements:

### Student Data Table
- **Student ID**: A unique identifier for each student.
- **First Name**: The first name of the student.
- **Last Name**: The last name of the student.
- **Email**: The email address of the student.
- **Age**: The age of the student.
- **Days in Course**: An array of the number of days to complete each course.
- **Degree Program**: The degree program the student is enrolled in (SECURITY, NETWORK, SOFTWARE).

### Example Data
```cpp
const string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,[firstname],[lastname],[emailaddress],[age],[numberofdaystocomplete3courses],SOFTWARE"
};


