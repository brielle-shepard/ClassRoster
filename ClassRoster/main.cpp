/****************************************************
*	Brielle Shepard									*
*	Student ID: 000613239							*
*	Scripting and Programming - Applications - C867	*
*	JYM1 TASK 1: CLASS ROSTER						*
*	Western Governors University					*
****************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

const int numStudents = 5;
const string studentData[] =
{
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@mailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Brielle,Shepard,bshep12@wgu.edu,32,40,35,40,SOFTWARE",
};


int main()
{
	/********************************* Print My Information ***************************************/
	string courseTitle = "C867 -  SCRIPTING AND PROGRAMMING - APPLICATIONS";
	string language = "C++";
	string WGUID = "000613239";
	string myName = "Brielle Shepard";

	string returnString = "";

	cout << "Course Title: " << courseTitle << "\n" << "Programming Language: " << language
		<< "\n" << "WGU Student ID: " << WGUID << "\n" << "Name: " << myName << endl << endl;
	/**********************************************************************************************/

	Roster classRoster;
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	//classRoster.printAll();
	cout << "Printing Roster" << endl;
	cout << "---------------" << endl;
	classRoster.printAll();
	cout << endl << endl << endl;

	// ClassRoster.printInvalidEmails();
	cout << "Checking for invalid email entries" << endl;
	cout << "----------------------------------" << endl;
	classRoster.printInvalidEmails();
	cout << endl << endl;
	
	cout << "Printing By Degree Program (SOFTWARE)" << endl;
	cout << "-------------------------------------" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl << endl;
	
	cout << "Printing Average days in course per student" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID()); // Print average days in course for each student
	}
	cout << endl << endl;


	cout << "Removing student A3" << endl;
	cout << "-------------------" << endl;
	classRoster.remove("A3");
	cout << endl << endl;
	
	
	cout << "Printing Roster" << endl;
	cout << "---------------" << endl;
	classRoster.printAll(); // prints everything again after A3 is removed to show chaa
	cout << endl << endl;


	cout << "Removing student A3" << endl;
	cout << "-------------------" << endl;
	classRoster.remove("A3");//--- this should return an error message since A3 has already been deleted
	cout << endl << endl;

	return 0;

}

