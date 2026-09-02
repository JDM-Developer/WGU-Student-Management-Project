#include "roster.h"

int main()
{

	cout << "C867" << endl; //couts course number
	cout << "C++" << endl; //couts language used
	cout << "Student ID: 010571765" << endl; //couts my student ID
	cout << "Jesse McClure\n" << endl; //couts my name


	const string studentData[] = //allocates string below into studentData array
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack, Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jesse,McClure,jmc1252@wgu.edu,42,30,45,50,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;
	//Sets numStudents (number of students) variable to a constanst integer at 5.    

	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]); //For loop to parse each students data

	}

	cout << "Displaying all students:" << endl;
	classRoster.printAll(); //Displays all students
	cout << endl;

	cout << "Displaying students with invalid emails:" << endl;
	classRoster.printInvalidEmails(); //Displays invalid emails
	cout << endl;

	cout << "Displaying average days in course for all students:" << endl;
	for (int i = 0; i <= classRoster.lastIndex; i++) { //Iterates over each student
		string studentID = classRoster.studentRosterArray[i]->getStudentID(); //Accesses unique student ID
		classRoster.printAverageDaysInCourse(studentID); //Displays average days in course.
	}
	cout << endl;

	cout << "Displaying students with a software degree program:" << endl;
	classRoster.printByDegreeProgram (SOFTWARE); //identify those who are enrolled in SOFTWARE degree program.
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster.removeByStudentID("A3"); //Removes A3 from student roster
	cout << "Displaying all students after removing A3 the first time:" << endl;
	classRoster.printAll(); //Prints remaining students
	cout << endl;

	// Attempt to remove A3 a second time
	cout << "Attempting to remove A3 again:" << endl;
	classRoster.removeByStudentID("A3"); /*Attempts to find A3 to remove, cannot remove A3 therefore will result
	in displaying "Student ID A3 not found." */
	cout << endl;

	return 0;
}
	
	
	

