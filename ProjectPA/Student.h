#pragma once
#include <string>
#include "Degree.h"

using std::string;
class Student
{
public: 
	const static int coursearraysize = 3;

protected:
	
	string studentID;
	string firstname;
	string lastname;
	string emailaddress;
	string age;
	int DIC[coursearraysize];
	DegreeProgram Degree;
public:
	Student(); //empty constructor

	 //full constructor
	Student(string studentID, string firstname, string lastname, string emailaddress, string age, int DIC[], DegreeProgram Degree);

	//getters
	string getstudentID();
	string getfirstname();
	string getlastname();
	string getemailaddress();
	string getage();
	int* getDIC();

	//virtual get Degree
	virtual DegreeProgram getDegreeProgram() = 0;

	//setters 
	void setstudentID(string studentID);
	void setfirstname(string firstname);
	void setlastname(string lastname);
	void setemailaddress(string emailaddress);
	void setage(string age);
	void setDIC(int DIC[]);
	void setDegreeProgram(DegreeProgram Degree);

	//virtual print
	virtual void print() = 0;

	//destructor
	~Student();

};