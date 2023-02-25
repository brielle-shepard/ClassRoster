#include <iostream>
#include <string>
#include <sstream>
#include <vector>
// #include "student.h"
#include "roster.h"
using namespace std;


// Roster::Roster() {}


void Roster::parse(const string& text) {
	// Parse each set of data identified in studentData Table and populate classRosterArray
	//	//parse strings

	string studentID, firstName, lastName, email;
	
	std::istringstream inSS(text);
	getline(inSS, studentID, ',');
	getline(inSS, firstName, ',');
	getline(inSS, lastName, ',');
	getline(inSS, email, ',');

	//	//parse integers
	string column;
	getline(inSS, column, ',');//age?
	int age = stoi(column);

	int daysToComplete[3] = {0,0,0};
	getline(inSS, column, ',');
	daysToComplete[0] = stoi(column);

	getline(inSS, column, ',');
	daysToComplete[1] = stoi(column);

	getline(inSS, column, ',');
	daysToComplete[2] = stoi(column);

	DegreeProgram degreeProgram = DEFAULT;
		getline(inSS, column);
		if (column == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (column == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (column == "SOFTWARE"){
			degreeProgram = SOFTWARE;
		}

			
	this->add(studentID, firstName, lastName, email, age, 
			 daysToComplete[0], daysToComplete[1], daysToComplete[2], 
			 degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, 
	int age, int daysInCourse1,int daysInCourse2, int daysInCourse3, 
	DegreeProgram degreeProgram)
{
	if(m_size < CAPACITY) {
		Student * student = new Student(studentID, firstName, lastName, email, age, daysInCourse1,
			daysInCourse2, daysInCourse3, degreeProgram);
		classRosterArray[m_size++] = student;
	}
		
}

void Roster::printAll() {
	for (int i = 0; i < m_size; i++) {
		// *(classRosterArray[i]).print();
		classRosterArray[i]->print();
	}
}
