#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

// The Student class, creating an object that embodies all properties and behaviors of a student entity.
class Student
{
public:
	const static int courseCompleteArraySize = 3; // Number of arrays to input days to complete course.  

private:
	string studentID; // Private member variables representing student attributes
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysUntilCourseComplete[courseCompleteArraySize]; // Array storing days to complete each of the 3 courses
	DegreeType degreeType; // Degree program, using the DegreeType enumeration
	

public:
	// Student constructors and destructor
	Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysUntilCourseComplete[], DegreeType degreeType);

		~Student();

		// (Setters/Mutators)
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysUntilCourseComplete(double daysUntilCourseComplete[]);
		void setDegreeType(DegreeType degreeType);

		// (Getters/Accessors)
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		double* getDaysUntilCourseComplete();
		DegreeType getDegreeType();

		static void printheader(); //Prints the header for student data
		void print(); //Prints student data


};