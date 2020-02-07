#include <iostream>
#include "SoftwareStudent.h"

using std::cout;
using std::endl;

SoftwareStudent::SoftwareStudent() :Student()
{
	Degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
	string studentID,
	string firstname,
	string lastname,
	string emailaddress,
	string age,
	int* DIC,
	DegreeProgram Degree)
	: Student(studentID, firstname, lastname, emailaddress, age, DIC, Degree)
{
	Degree = SOFTWARE;
}
DegreeProgram SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	Student::print();
	cout << "SOFTWARE" << endl << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
