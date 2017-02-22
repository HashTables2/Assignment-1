/*Author: Irime
Class: CS_281-05
Assignment: Assignment 4
Date Assigned: 2/1/2015
Due Date: 9/7/2015 2PM

Description:
This is a patient managment system for a small medical center.

Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the
    definition and consequences of plagiarism and acknowledge that the assessor
    of this assignment may, for the purpose of assessing this assignment:
        - Reproduce this assignment and provide a copy to another member of
        academic staff; and/or
        - Communicate a copy of this assignment to a plagiarism checking
        service (which may then retain a copy of this assignment on its
        database for the purpose of future plagiarism checking)
*/

#include "doctor.h"
#include <iostream>
using namespace std;



//default constructor
Doctor::Doctor()
{
    mDoctor.mId = "";
    mDoctor.mName = "";
    mIndex = 0;
    mNumberOfPatient = 0;

}

//deconstructor
Doctor::~Doctor()
{
    //stub
}

//constructor
Doctor::Doctor(const Doctor& cDoctor)
{
     mDoctor.mId = cDoctor.mDoctor.mId;
    mDoctor.mName = cDoctor.mDoctor.mName;
    mIndex = cDoctor.mIndex;
    mNumberOfPatient = cDoctor.mNumberOfPatient;
    totalNumberOfDoctors++;
}

//=overloaded
Doctor& Doctor::operator= (const Doctor &cDoctor)
{
    mDoctor.mId = cDoctor.mDoctor.mId;
    mDoctor.mName = cDoctor.mDoctor.mName;
    mIndex = cDoctor.mIndex;
    mNumberOfPatient = cDoctor.mNumberOfPatient;
    totalNumberOfDoctors++;

    return *this;
}

//init coutner of doctors
int Doctor::totalNumberOfDoctors = 0;

//overloaded ==
bool operator==(Doctor rhs, Doctor lhs)
{
    return rhs.getName() == lhs.getName();
}

//overloaded >> operator
istream& operator>>(istream &input, Doctor& cDoctor)
{
    cout << "Enter a new number of patients: ";
    int newNum;
    cin >> newNum;

    cDoctor.setNumberOfPatient(newNum);
    return input;
}

//overlaod << operator
ostream& operator<<(ostream &out, Doctor& cDoctor)
{
    out << cDoctor.getName();
    return out;
}

