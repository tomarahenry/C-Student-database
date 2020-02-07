#include <iostream>
#include "NetworkStudent.h"
using std::cout;
using std::endl;

NetworkStudent::NetworkStudent() :Student()
{
	Degree = NETWORK;
}
//full constructor
NetworkStudent::NetworkStudent(
	string studentID, 
	string firstname, 
	string lastname,
	string emailaddress, 
	string age,
	int* DIC, 
	DegreeProgram Degree)
	:Student(studentID, firstname, lastname, emailaddress, age, DIC, Degree)
{
	Degree = NETWORK;
}
DegreeProgram NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	Student::print();
	cout << "NETWORK" << endl << endl;

}
NetworkStudent::~NetworkStudent()
{
Student::~Student();
}
