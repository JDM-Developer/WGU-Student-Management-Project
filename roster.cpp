#include "roster.h"
#include <iomanip>

void Roster::parse(string studentData) // Parses a string to extract student data and add a student to the roster one row at a time
{ 
    int rhs = studentData.find(","); //Splits the data at the comma
    string sID = studentData.substr(0, rhs);//Stores data before the comma as student ID.  

    int lhs = rhs + 1; //Moves past previous comma
    rhs = studentData.find(",", lhs);
    string fName = studentData.substr(lhs, rhs - lhs); //First Name

    lhs = rhs + 1; //Moves to next comma
    rhs = studentData.find(",", lhs);
    string lName = studentData.substr(lhs, rhs - lhs);//Last Name

    lhs = rhs + 1; //Moves to the next comma
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);//Email address

    lhs = rhs + 1;//Moves to the next comma
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs)); //stoi converts substring to an integer, that integer being age

    lhs = rhs + 1;//Moves to the next comma
    rhs = studentData.find(",", lhs);
    double days1 = stod(studentData.substr(lhs, rhs - lhs));/*stod converts substring to a double, that double being
    the first set of days to complete the first course*/

    lhs = rhs + 1;//Moves to the next comma
    rhs = studentData.find(",", lhs);
    double days2 = stod(studentData.substr(lhs, rhs - lhs));//same thing but for second set of days to complete course

    lhs = rhs + 1;//Moves to the next comma
    rhs = studentData.find(",", lhs);
    double days3 = stod(studentData.substr(lhs, rhs - lhs));//same thing but for third set of days to complete course

    lhs = rhs + 1;
    string degreeStr = studentData.substr(lhs); // Extracting and storing the Degree type 

    DegreeType degreeType = SECURITY; // Degree classification is set as a default to "SECURITY"

    if (degreeStr == "NETWORK") { // If Degree is NETWORK then it's classification is "NETWORK"
        degreeType = NETWORK;
    }
    else if (degreeStr == "SOFTWARE") {// Else if Degree is SOFTWARE then it's classification is "SOFTWARE"
        degreeType = SOFTWARE;
    }

    add(sID, fName, lName, email, age, days1, days2, days3, degreeType); //adds a new student to the roster with the provided information.
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeType degreeProgram)
{// Defines add to be in the roster class without returning a value
    double daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };// Puts into array for constructor

    studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
    // Adds a new student objects and assigns to the array in the last position.

}

void Roster::printAll() //Displays all students
{
    Student::printheader(); //Prints header for the columns.

    for (int i = 0; i <= Roster::lastIndex; i++) //Goes through each student until last row.  
    {
        studentRosterArray[i]->print();
    }

   


}

void Roster::printByDegreeProgram(DegreeType degreeProgram)
{
    Student::printheader();

    for (int i = 0; i <= lastIndex; i++) {
        if (studentRosterArray[i]->getDegreeType() == degreeProgram) {
            studentRosterArray[i]->print();
        }
    }
    cout << std::endl;
}
void Roster::printInvalidEmails()  //Displays students with invalid email
{
    bool brokenEmail = false; //Declaring boolean brokenEmail, initialized at false.
    for (int i = 0; i <= Roster::lastIndex; i++) //For loop to scan each row
    {

        string email = (studentRosterArray[i])->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
        //Finds if email doesn't have an @,., or has a space.
            cout << "Invalid Email: " << email << endl;
            brokenEmail = true;
        }


    }
    if (!brokenEmail) cout << "NONE" << std::endl; //Couts none if no invalid emails are found.
}

void Roster::printAverageDaysInCourse(string studentID) {  //Displays each students average days to complete course
    for (int i = 0; i <= lastIndex; ++i) {
        if (studentRosterArray[i]->getStudentID() == studentID) {
            double* days = studentRosterArray[i]->getDaysUntilCourseComplete();
            cout << left << setw(12) << studentID;
            cout << "Average days: " << fixed << setprecision(2)
                << (days[0] + days[1] + days[2]) / 3 << defaultfloat << std::endl; //Gives the average
        }
    }
}

bool Roster::removeByStudentID(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (studentRosterArray[i]->getStudentID() == studentID) {
            delete studentRosterArray[i]; // Delete the student object

            /* If the student to be removed isn't the last student in the array,
             shift the last student into the current position. */
            if (i < lastIndex) {
                studentRosterArray[i] = studentRosterArray[lastIndex];
            }
            studentRosterArray[lastIndex] = nullptr; // Set the now-unused pointer to nullptr
            lastIndex--; // Decrement lastIndex since the array size has effectively decreased by one

            cout << studentID << " removed from the roster." << endl;
            return true; // End function here after student is removed
        }
    }
    cout << "Student ID " << studentID << " not found." << endl;
    return false; // Student ID was not found
}
Roster::~Roster() // Destructs student roster objects
{
    for (int i = 0; i < numStudents; i++)
    {
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
    }
}
