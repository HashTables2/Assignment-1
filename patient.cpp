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

#include "patient.h"
#include <iostream>
using namespace std;

//default contructor
Patient::Patient()
{
    mPatient.mId = "";
    mPatient.mName = "";
    mPhoneNumber = "";
    mDoctorId = "";
    mAddress = "";

}

//deconstructor
Patient::~Patient()
{

}

//constructor
Patient::Patient( string doctorId, string name, string id, string address, string phoneNumber)
{
    mPatient.mId = id;
    mPatient.mName = name;
    mPhoneNumber = phoneNumber;
    mDoctorId = doctorId;
    mAddress = address;
}


//overloaded == operagtor
 Patient& Patient::operator== (const Patient &cPatient)
 {
    mPatient.mId == cPatient.mPatient.mId;

    return *this;
 }

//use overlaod operator to set a new name
 istream& operator>>(istream &input, Patient& cPatient)
 {
    cout << "Enter new name: ";
    string name;
    getline(cin, name);

    cPatient.setName(name);

    return input;
 }

 ostream& operator<<(ostream &out, Patient& cPatient)
 {
    out << cPatient.getName() << endl << cPatient.getId()
    << endl << cPatient.getAddress() << endl << cPatient.getPhoneNumber() << endl;

    return out;

 }
