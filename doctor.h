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

#ifndef DOCTO_H
#define DOCTO_H

#include "person.h"

class Doctor
{
    Person mDoctor;
    int mIndex;
    int mNumberOfPatient;

public:
    Doctor();
    Doctor(string name, string id);
    ~Doctor();

    //accessor
    string getId() const { return mDoctor.mId; }
    int getIndex() const { return mIndex; }
    string getName() const { return mDoctor.mName; }
    int getNumberOfPatient() const { return mNumberOfPatient; }

    //mutators
    void setId( string newId ) { mDoctor.mId = newId; }
    void setIndex ( int newIndex ) { mIndex = newIndex; }
    void setName( string newName ) { mDoctor.mName = newName;}
    void setNumberOfPatient( int newNumberOfPatient ) { mNumberOfPatient = newNumberOfPatient; }

    //copy constructor
    Doctor(const Doctor&);
    Doctor& operator= (const Doctor &cDoctor);

    friend bool operator==(Doctor, Doctor);

    friend istream& operator>>(istream &input, Doctor& );
    friend ostream& operator<<( ostream &out, Doctor& ) ;

    //coutner
    static int totalNumberOfDoctors;

};



#endif // DOCTO_h
