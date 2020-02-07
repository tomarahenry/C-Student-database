#pragma once
#include <string>
#include"Degree.h"
#include"Student.h"

class NetworkStudent :public Student
{
public:
	
	//empty constructor
	NetworkStudent();

	//fullconstructor
	NetworkStudent(
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
	~NetworkStudent();

};