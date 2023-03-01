#pragma once
#include "student.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Roster
{
private:
	const int CAPACITY = 5;
	int m_size = 0;
public:
	//constructor
	Roster() = default;

	//create an array of pointers classRosterArray to hold data in "studentData" Table
	Student* classRosterArray[5] = { nullptr,nullptr,nullptr,nullptr,nullptr };

	/************************* void add() function *********************************
	*	Add each student object to classRosterArray
	*********************************************************************************/
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);


	/************************* void remove() function *********************************
	*	remove function - removes students from the roster by student ID.
	*	If the student ID does not exist, the function prints an error message
	*	indicating that the student was not found.
	*	if student does not exist, print error mesage: "Student ID not found"
	************************************************************************************/
	void remove(string StudentID);



	/************************* voidprintAll() function *********************************
	*	prints a complete tab - separated ist of student data in the provided format :
	*	A1 [tab] First Name: John [tab] Last Name: Smith [tab]
	*	Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
	************************************************************************************/
	void printAll();


	/************************* printAverageDaysInCourse Function ************************
	*	correctly prints a student’s average number of days in the three courses.
	*	The student is identified by the studentID parameter.
	************************************************************************************/
	void printAverageDaysInCourse(string studentID);

	/************************* printInvalidEmails Function *********************************
	*	verifies student email addresses and displays all invalid email addresses to the user
	************************************************************************************/
	void printInvalidEmails();

	/****************************************************************************/
	void parse(const string&);

	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};

