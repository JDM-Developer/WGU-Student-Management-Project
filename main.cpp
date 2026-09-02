#include "roster.h"

void printSection(const string& title)
{
	cout << "\n" << string(92, '-') << "\n";
	cout << title << "\n";
	cout << string(92, '-') << "\n";
}

int main()
{
	cout << string(92, '=') << "\n";
	cout << "WGU STUDENT MANAGEMENT PROJECT\n";
	cout << "Course: C867  |  Language: C++  |  Developer: Jesse McClure\n";
	cout << string(92, '=') << "\n";


	const string studentData[] = //allocates string below into studentData array
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jesse,McClure,jesse.mcclure@example.com,42,30,45,50,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;
	//Sets numStudents (number of students) variable to a constanst integer at 5.    

	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]); //For loop to parse each students data

	}

	printSection("ALL STUDENTS");
	classRoster.printAll(); //Displays all students
	printSection("EMAIL VALIDATION");
	classRoster.printInvalidEmails(); //Displays invalid emails
	printSection("AVERAGE DAYS IN COURSE");
	for (int i = 0; i <= classRoster.lastIndex; i++) { //Iterates over each student
		string studentID = classRoster.studentRosterArray[i]->getStudentID(); //Accesses unique student ID
		classRoster.printAverageDaysInCourse(studentID); //Displays average days in course.
	}
	printSection("SOFTWARE DEGREE PROGRAM");
	classRoster.printByDegreeProgram (SOFTWARE); //identify those who are enrolled in SOFTWARE degree program.
	printSection("REMOVE STUDENT A3");
	classRoster.removeByStudentID("A3"); //Removes A3 from student roster
	cout << "\nUpdated roster:\n";
	classRoster.printAll(); //Prints remaining students
	// Attempt to remove A3 a second time
	cout << "\nSecond removal attempt:\n";
	classRoster.removeByStudentID("A3"); /*Attempts to find A3 to remove, cannot remove A3 therefore will result
	in displaying "Student ID A3 not found." */
	cout << "\n" << string(92, '=') << "\n";
	cout << "PROGRAM COMPLETE\n";
	cout << string(92, '=') << "\n";

	return 0;
}
	
	
	

