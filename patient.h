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

#ifndef PATIE_H
#define PATIE_H

#include "person.h"

class Patient
{
    Person mPatient;
    string mAddress;
    string mDoctorId;
    string mPhoneNumber;

public:
    Patient();
    Patient( string doctorId, string name, string id, string address, string phoneNumber);
    ~Patient();

    //accsessor
    string getAddress() const { return mAddress; };
    string getDoctorId() const { return mDoctorId;};
    string getId() const {return mPatient.mId;} ;
    string getName() const { return mPatient.mName;};
    string getPhoneNumber() const {return mPhoneNumber;};

    //mutator
    void setAddress( string newAddress) { mAddress = newAddress; }
    void setDoctorId( string newDoctorId ) { mDoctorId = newDoctorId; }
    void setId( string newId ) { mPatient.mId = newId; }
    void setName( string newName ) { mPatient.mName = newName; }
    void setPhoneNumber( string newPhoneNumber ) { mPhoneNumber = newPhoneNumber; }

    //overload
     Patient& operator== (const Patient &cPatient);
     friend istream& operator>>(istream &input, Patient& );
     friend ostream& operator<<( ostream& out, Patient& ) ;



};

#endif
