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

#include "doctorOperations.h"
#include "constants.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//find the index where the doctor resides
int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName)
{
    //loop through until the doctor name is found
    for(int i = 0; i < numberOfDoctor; i++)
    {
        if( doctorName == doctors[i].getName() )
            return doctors[i].getIndex();
        else
            continue;
    }

    return -1;
}

//Find doctors index by using their ssn instead of name
int getDoctorIndexById(Doctor doctors[], int numberOfDoctor, string ssn)
{
    for(int i = 0; i < numberOfDoctor; i++)
    {
        if( ssn == doctors[i].getId() )
            return doctors[i].getIndex();
        else
            continue;
    }

    return -1;
}

//check if a doctor exsists
bool isDoctorExsist(Doctor doctors[], int numberOfDoctor, string doctorName)
{
    for(int i = 0; i < numberOfDoctor; i++)
    {
        if( doctorName == doctors[i].getName() )
            return true;
        else
           continue;
    }

    return false;

}


//load Doctors
int loadDoctor(Doctor doctors[])
{
    //open file
    fstream inFile(DOCTOR_FILE.c_str() );


    string line;
    stringstream ss;

    if ( inFile.good() )
    {

        //create new pointer to an object
        Doctor * objPointer;
        objPointer = new Doctor;

        //temp variables
        int tempIndex, tempNumOfPatients;
        int i = 0;

        //read in each line to a variable
        while( getline( inFile, line) )
        {
             objPointer->setName(line);
             getline( inFile, line);

             objPointer->setId(line);
             getline( inFile, line);

             //read lat line into two seperate variables using string stream
             ss << line;
             ss >> tempIndex >> tempNumOfPatients;
             objPointer->setIndex(tempIndex);
             objPointer->setNumberOfPatient(tempNumOfPatients);

            //set the object point to eaul an element in array
             doctors[tempIndex] = *objPointer;


             ss.clear();
             i++;

        }

        //close file
        inFile.close();
        return 0;
    }
    else
    {
        cout << "There was an error loading the data." << endl;
        return -1;
    }

}


//store the doctors into a file
void storeDoctor(Doctor doctors[], int numberOfDoctor)
{
    //open output file
    ofstream outFile(DOCTOR_FILE.c_str());
    string doctorsName;

    if( outFile.good() )
    {
        //loop through doctors, placing each into the file and formatting correctly
        for(int i = 0; i < numberOfDoctor; i++)
        {
            outFile << doctors[i].getName() << endl << doctors[i].getId() << endl
            << doctors[i].getIndex() << " " << doctors[i].getNumberOfPatient() << endl;
        }

        outFile.close();
    }
    else
    {
        cout << "Error: file couldn't be open." << endl;
    }

}

