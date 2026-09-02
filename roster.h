#pragma once
#include "student.h"

class Roster //Creating Roster class and object 
{
public:
	int lastIndex = -1; // Tracks the last index in the student roster array
	const static int numStudents = 5; // We know from input data that the total number of students is 5.  
	Student* studentRosterArray[numStudents]; // Array of pointers to student objects

public:

	void parse(string row); // Parses the string and adds the student to the roster
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeType degreeProgram); /* Adds a student 
	with these provided details to the roster class */

	void printAll(); // Prints all student data in the roster
	void printByDegreeProgram(DegreeType degreeProgram);// Prints student data based on their degree program


	void printInvalidEmails(); //Prints invalid emails
	void printAverageDaysInCourse(string studentID); //Prints individual students average days to complete a course
	bool removeByStudentID(string studentID);// Removes a student from the roster by the student ID

	~Roster(); // Destructor to deallocate memory used by the roster

};