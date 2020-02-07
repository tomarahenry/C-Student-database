#include <iostream>
#include "SecurityStudent.h"
using std::cout;
using std::endl;

SecurityStudent::SecurityStudent() :Student()
{
	Degree = SECURITY;
}

//full constructor
SecurityStudent::SecurityStudent(string studentID, string firstname, string lastname, string emailaddress, string age, int* DIC, DegreeProgram Degree)
	: Student(studentID, firstname, lastname, emailaddress, age, DIC, Degree)
{
	Degree = SECURITY;

}

void SecurityStudent::print()
{
	Student::print();
	cout << "SECURITY" << endl << endl;
}


DegreeProgram SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

SecurityStudent::~SecurityStudent()
{
Student::~Student();
}