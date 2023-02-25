#pragma once
#include <iostream>
#include<string>
#include "degree.h"
using namespace std;

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	//2a.  an accessor (i.e., getter) for each instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int * getDaysToComplete();
	DegreeProgram getDegreeProg();

	//2b.  a mutator (i.e., setter) for each instance variable from part D1
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[3]);
	void setDegreeProg(DegreeProgram degreeProg);
	
	//2d.  constructor using all of the input parameters provided in the table
	Student();
	Student(string studentID, string firstName, string lastName, string email, 
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
			DegreeProgram degreeProgram );

	//2e.print() to print specific student data
	void print();

	
};
