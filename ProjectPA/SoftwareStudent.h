#pragma once
#include <string>
#include <string>
#include "Degree.h"
#include "Student.h"

class SoftwareStudent :public Student
{
public:
	
	//empty constructor
	SoftwareStudent();

	//full constructor
	SoftwareStudent(
		string studentID,
		string firstname,
		string lastname,
		string emailaddress,
		string age,
		int* DIC,
		DegreeProgram Degree);

	void print();
	DegreeProgram getDegreeProgram();
	
	//deconstructor
	~SoftwareStudent();

};