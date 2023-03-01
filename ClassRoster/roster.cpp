#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
using namespace std;

void Roster::parse(const string& text) {
	// Parse each set of data identified in studentData Table and populate classRosterArray
	//	//parse strings

	string studentID, firstName, lastName, email;

	std::istringstream inSS(text);
	getline(inSS, studentID, ',');
	getline(inSS, firstName, ',');
	getline(inSS, lastName, ',');
	getline(inSS, email, ',');

	//parse integers
	string column;
	getline(inSS, column, ',');
	int age = stoi(column);

	int daysToComplete[3] = { 0,0,0 };
	getline(inSS, column, ',');
	daysToComplete[0] = stoi(column);

	getline(inSS, column, ',');
	daysToComplete[1] = stoi(column);

	getline(inSS, column, ',');
	daysToComplete[2] = stoi(column);

	DegreeProgram degreeProgram = DEFAULT;
	getline(inSS, column);
	if (column == "SECURITY")
	{
		degreeProgram = SECURITY;
	}
	else if (column == "NETWORK")
	{
		degreeProgram = NETWORK;
	}
	else if (column == "SOFTWARE")
	{
		degreeProgram = SOFTWARE;
	}

	this->add(studentID, firstName, lastName, email, age,
		daysToComplete[0], daysToComplete[1], daysToComplete[2],
		degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeProgram)
{
	if (m_size < CAPACITY) {
		Student* student = new Student(studentID, firstName, lastName, email, age, daysInCourse1,
			daysInCourse2, daysInCourse3, degreeProgram);
		classRosterArray[m_size++] = student;
	}

}

void Roster::printAll()
{
	for (int i = 0; i < m_size; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails()
{	
	for (int i = 0; i < m_size; i++)
	{
		string email = classRosterArray[i]->getEmail();
		if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
			cout << "Invalid Email Address: " << email << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < m_size; i++)
	{
		if (this->classRosterArray[i]->getDegreeProg() == degreeProgram) this->classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{

	bool found = false;
	for (int i = 0; i < m_size; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* ptr = classRosterArray[i]->getDaysToComplete();
			cout << "Student ID: " << studentID << " -- Average days in course: " << (ptr[0] + ptr[1] + ptr[2]) / 3 << endl;
		}
	}
	if (!found) cout << "Student entry not found!" << endl;
}

void Roster::remove(string studentID)
{
	int index = -1;

	for (int i = 0; i < m_size && index == -1; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			index = i;
		}
	}
	if (index == -1) {
		cout << "Student ID not found" << endl;
	}
	else {
		delete this->classRosterArray[index];
		this->classRosterArray[index] = nullptr;
		for (int i = index; i < m_size - 1; i++)
		{
			this->classRosterArray[i] = this->classRosterArray[i + 1];
		}
		m_size--;

		this->classRosterArray[m_size] = nullptr;
	}
	cout << "Done." << endl;
}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete this->classRosterArray[i];
	}
}