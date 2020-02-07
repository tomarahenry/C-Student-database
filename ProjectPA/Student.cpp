#pragma once
#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstname = "";
	this->lastname = "";
	this->emailaddress = "";
	this->age = "";
	for (int i = 0; i < coursearraysize; i++) this->DIC[i] = 0;

}

//full constructor
Student::Student(string studentID, string firstname, string lastname, string emailaddress, string age, int DIC[], DegreeProgram Degree)
{
	this->studentID = studentID;
	this->firstname = firstname;
	this->lastname = lastname;
	this->emailaddress = emailaddress;
	this->age = age;
	for (int i = 0; i < coursearraysize; i++)  this->DIC[i] = DIC[i];

}

//getters
string Student::getstudentID()
{
	return studentID;
}

string Student::getfirstname()
{
	return firstname;
}

string Student::getlastname()
{
	return lastname;
}

string Student::getemailaddress()
{
	return emailaddress;
}

string Student::getage()
{
	return age;
}

int* Student::getDIC()
{
	return DIC;
}

//setters
void Student::setstudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setfirstname(string firstname)
{
	this->firstname = firstname;
}

void Student::setlastname(string lastname)
{
	this->lastname = lastname;
}

void Student::setemailaddress(string emailaddress)
{
	this->emailaddress = emailaddress;
}

void Student::setage(string age)
{
	this->age = age;
}

void Student::setDIC(int DIC[])
{
	for (int i = 0; i < 3; i++)
		this->DIC[i] = DIC[i];
}



void Student::print()
{
	cout << "StudentID: " << getstudentID() << endl;
	cout << "First Name: " << getfirstname() << endl;
	cout << "Last Name: " << getlastname() << endl;
	cout << "Email Address: " << getemailaddress() << endl;
	cout << "Age: " << getage() << endl;
	cout << "Days in Course: {" << getDIC()[0] << "," << getDIC()[1] << "," << getDIC()[2] << "}" << endl;
}

//destructor
Student::~Student()
{

}
