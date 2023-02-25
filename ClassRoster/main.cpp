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
"000613239,Brielle,Shepard,bshep12@wgu.edu,32,40,35,40,SOFTWARE",
};


int main()
{
	
	Roster roster;
	for(int i = 0; i < numStudents; i++) {
		roster.parse(studentData[i]); 
	}
	roster.printAll();
	// roster.printInvalidEmails();//TODO
	// roster.printAverageDaysInCourse();//TODO
	//Print average days in course for each student
	//Remove student

	return 0;

 }

