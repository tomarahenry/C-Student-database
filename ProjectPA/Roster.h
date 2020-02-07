#pragma once
#include <string>
#include "Student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"

class Roster
{

protected:
    int Index;
    int cap;
    Student** classRosterArray;


public:
    // empty constructor
    Roster();

    Roster(int cap);
    Student* getCM(int index);

    void parseThenAdd(string row);
    void add(
        string studentID,
        string firstname,
        string lastname,
        string emailaddress,
        string age,
        int DaysInCourse1,
        int DaysInCourse2,
        int DaysInCourse3,
        DegreeProgram Degree);
    void remove(string studentID);
    void printAll();
    void printAverageDIC(string studentid);
    void printByDegreeProgram(int Degree);
    void printInvalidEmails();

    //deconstructor
    ~Roster();

}; 