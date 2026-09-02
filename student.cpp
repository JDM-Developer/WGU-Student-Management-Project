#include "student.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;

//Default constructor
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0; //Initializing my age int to zero
	for (int i = 0; i < courseCompleteArraySize; ++i) this->daysUntilCourseComplete[i] = 0;
		this->degreeType = DegreeType::SECURITY; //Assumes SECURITY as default

}
// Constructor implementation
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysUntilCourseComplete[], DegreeType degreeType)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	for (int i = 0; i < courseCompleteArraySize; ++i) {
		this->daysUntilCourseComplete[i] = daysUntilCourseComplete[i];
	}
	this->degreeType = degreeType;

}
// Destructor implementation
Student::~Student() {}

//Implementation of getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
double* Student::getDaysUntilCourseComplete() { return this->daysUntilCourseComplete; }
DegreeType Student::getDegreeType() { return this->degreeType; }

//Implementation of setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysUntilCourseComplete(double daysUntilCourseComplete[])
{
	for (int i = 0; i < courseCompleteArraySize; ++i)
		this->daysUntilCourseComplete[i] = daysUntilCourseComplete[i];
}
void Student::setDegreeType(DegreeType degreeType) { this->degreeType = degreeType; }




void Student::printheader() // Prints the header for the student data table
{
	cout << left
		<< setw(12) << "Student ID"
		<< setw(14) << "First Name"
		<< setw(14) << "Last Name"
		<< setw(30) << "Email Address"
		<< setw(7) << "Age"
		<< setw(22) << "Course Days"
		<< "Degree Program\n";
	cout << string(113, '-') << '\n';
}

// Prints a single student's data in aligned columns.
void Student::print()
{
	double* days = getDaysUntilCourseComplete();
	string courseDays = "{" + std::to_string(static_cast<int>(days[0])) + ", "
		+ std::to_string(static_cast<int>(days[1])) + ", "
		+ std::to_string(static_cast<int>(days[2])) + "}";

	cout << left
		<< setw(12) << getStudentID()
		<< setw(14) << getFirstName()
		<< setw(14) << getLastName()
		<< setw(30) << getEmailAddress()
		<< setw(7) << getAge()
		<< setw(22) << courseDays
		<< DegreeTypeStrings[getDegreeType()] << endl;
}
