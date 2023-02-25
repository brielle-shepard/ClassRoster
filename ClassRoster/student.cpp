#include <iostream>
#include "student.h"
using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	daysToComplete[0]=0;
	daysToComplete[1]=0;
	daysToComplete[2]=0;

	this->degreeProgram = SOFTWARE;
}

Student::Student(string studentID, string _firstName, string lastName, string email, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = _firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	daysToComplete[0] = daysInCourse1;
	daysToComplete[1] = daysInCourse2;
	daysToComplete[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;

}


string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

// int *
int * Student::getDaysToComplete() {
	// not sure what to return -- come back to this later
	return daysToComplete;
}

DegreeProgram Student::getDegreeProg() {
	return degreeProgram;
}

void Student::print() {
	// output: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab] daysInCourse: {35, 40, 55} [tab] Degree Program: Security
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}\t";

	string dp_str = "";
	if (degreeProgram == SECURITY) {
		dp_str = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		dp_str = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE){
		dp_str = "SOFTWARE";
	} else {
		dp_str = "UNKNOWN";
	}
	cout << "Degree Program: " << dp_str << endl;
}
