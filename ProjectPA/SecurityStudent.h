#pragma once
#include <string>
#include "Degree.h"
#include "Student.h"

class SecurityStudent : public Student
{
public:

	//empty constructor
	SecurityStudent();

	//full constructor
	SecurityStudent(
		string studentID, 
		string firstname,
		string lastname, 
		string emailaddress,
		string age, 
		int* DIC,
		DegreeProgram Degree);



	DegreeProgram getDegreeProgram();
	void print();

	//deconstructor
	~SecurityStudent();
	
};