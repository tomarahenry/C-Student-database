#include "iostream"
#include <string>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include <iomanip>
using namespace std;
using std::cout;
using std::endl;
using std::cerr;

Roster::Roster()
{
    this->cap = 0;
    this->Index = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int cap)
{
    this->cap = cap;
    this->Index = -1;
    this->classRosterArray = new Student * [cap];
}

Student* Roster::getCM(int index)
{
    return classRosterArray[index];
}

void Roster::parseThenAdd(string row)
{
    if (Index < cap)
    {
        Index++;
        DegreeProgram Degree;

        //Reading StudentID

        int rhs = row.find(",");
        string studentID = row.substr(0, rhs);

        //Reading FirstName

        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string firstname = row.substr(lhs, rhs - lhs);

        //Reading LastName
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string lastname = row.substr(lhs, rhs - lhs);

        //Reading EmailAddress
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string emailaddress = row.substr(lhs, rhs - lhs);

        //Reading Age
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string age = row.substr(lhs, rhs - lhs);

        //Reading DaysInCourse1
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int DaysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

        //Reading DaysInCourse2
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int DaysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

        //Reading DaysInCourse3
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int DaysInCourse3 = stoi(row.substr(lhs, rhs - lhs));
       
          if (row.back() == 'Y')
        {
            Degree = SECURITY;
        }
        else if (row.back() == 'K')
        {
            Degree = NETWORK;
        }
        else if (row.back() == 'E')
        {
            Degree = SOFTWARE;
        }
        else
        {
            cerr << "Invalid Degree! Exiting Now!" << endl;
            exit(-1);
        }
       
          add(
              studentID,
              firstname,
              lastname,
              emailaddress,
              age,
              DaysInCourse1,
              DaysInCourse2,
              DaysInCourse3,
              Degree);

    }
}
void Roster::add(
    string studentID,
    string firstname,
    string lastname,
    string emailaddress,
    string age,
    int DaysInCourse1,
    int DaysInCourse2,
    int DaysInCourse3,
    DegreeProgram Degree)
{
    int DaysInCourse[Student::coursearraysize];
    DaysInCourse[0] = DaysInCourse1;
    DaysInCourse[1] = DaysInCourse2;
    DaysInCourse[2] = DaysInCourse3;

    switch (Degree)
    {
    case NETWORK:
        classRosterArray[Index] = new NetworkStudent(studentID, firstname, lastname, emailaddress, age, DaysInCourse, Degree);
        break;
    case SOFTWARE:
        classRosterArray[Index] = new SoftwareStudent(studentID, firstname, lastname, emailaddress, age, DaysInCourse, Degree);
        break;
    case SECURITY:
        classRosterArray[Index] = new SecurityStudent(studentID, firstname, lastname, emailaddress, age, DaysInCourse, Degree);
        break;

    default:
        cout << "Invalid Degree!" << endl;
        break;
    }
}

void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i <= this->Index && !found; i++)
    {
        if (this->classRosterArray[i]->getstudentID() == studentID)
        {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[Index];
            Index--;


        }
    }
    if (!found)
        cout << studentID << "Student ID has been removed" << endl;
}

void Roster::printAll()
{
    for (int i = 0; i <= this->Index; i++) (this->classRosterArray)[i]->print();
}
void Roster::printAverageDIC(string studentID)
{
    bool found = false;
    for (int i = 0; i <=Index && !found; i++)
    {
        if (this->classRosterArray[i]->getstudentID() == studentID)
            {
                found = true;
                int* DIC = this->classRosterArray[i]->getDIC();

                cout << "Average Days In Course: " << studentID << " = " << (DIC[0] + DIC[1] + DIC[2]) / 3.0 << endl << endl;

            }
        else if (i >= this->Index && !found)
        {
            cout << "NOT FOUND " << studentID << "." << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i < 3; i++)
    {
        string email = classRosterArray[i]->getemailaddress();
        if (email.find("@") == string::npos)
        {
            cout << "The email, " << email << " is not valid. The @ symbol is required. \n";
        }
        if (email.find(".") == string::npos)
        {
            cout << "The email, " << email << " is not valid. The . symbol is required. \n";
        }
        if (email.find(" ") == string::npos)
        {
            cout << "The email, " << email << " is not valid. Spaces are not allowed. \n" << endl;
        }
    }
        
}

void Roster::printByDegreeProgram(int Degree)
{
    for (int i = 0; i <= Index; ++i)
    {
        if (this->classRosterArray[i]->getDegreeProgram() == Degree)
        {
            (this->classRosterArray)[i]->print();
        }
    }
}

//main function

int main()
{

    cout << "Scripting and Programming Application - C867" << endl;
    cout << "Programming Lang: C++" << endl;
    cout << "My Student ID: 001079138" << endl;
    cout << "Name: Tomaranisha Henry" << endl << endl;


    int NSD = 5;
    const string studentData[5] =
        //Data for Table including my own.
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Tomaranisha,Henry,thenr54@wgu.edu,25,22,50,49,SOFTWARE"
    };

    Roster* classRoster = new Roster(NSD);
    for (int i = 0; i < NSD; i++)
    {
        classRoster->parseThenAdd(studentData[i]);
    }


    classRoster->printAll();
   
    for (int i = 0; i < NSD; i++)
    {
        classRoster->printAverageDIC(classRoster->getCM(i)->getstudentID());
    }

    cout << "Invalid emails: " << endl << endl;
    classRoster->printInvalidEmails();

    classRoster->remove("A3");
    cout << "A3 has been removed" << endl << endl;
    classRoster->remove("A3");
   
}
Roster::~Roster()
{
    
}