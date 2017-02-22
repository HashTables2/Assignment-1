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
#include "patientOperation.h"
#include "doctorOperations.h"
#include <fstream>
#include "generalOperations.h"

using namespace std;

//add a patient
void addPatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors)
{
    string tName, tId, tPhone, tAddress, tDoctorName, tDoctorId;
    int doctorsIndex, numOfPatients;

    //CLEAR ANY JUNK
    cin.ignore();

    //Ask user for info
    cout << "Enter name of patient: ";
    getline(cin, tName);

    cout << "Enter ID (SSN): ";
    getline(cin, tId);

    cout << "Enter phone: ";
    getline(cin, tPhone);


    cout << "Enter Address: ";
    getline(cin, tAddress);

    cout << "Enter Doctors name: ";
    getline(cin, tDoctorName);


    //check to make sure this patient doesnt exist
    for(int row=0; row < NUM_OF_PATIENT; row++)
        for(int col = 0; col < numberOfDoctors; col++)
        {
            //check to make sure that there is not another patient with the ID
            if (patients[row][col].getId() == tId ) /*could use the overloaded OP here*/
            {
                cout << "ERROR: There is a patient with the same ID" << endl;
                pause();
                return;
            }
            else
            {
               continue;
            }
        }


    //find what doctor
    doctorsIndex = getDoctorIndex(doctors, numberOfDoctors, tDoctorName);

    //error check to make sure index is correct
    if( doctorsIndex >= 0 )
    {
        //if index is correct, make sure doctor doesnt have too many patients
        if( doctors[doctorsIndex].getNumberOfPatient() > NUM_OF_PATIENT)
        {
            cout << "Error, this doctor already has the max number of patients" << endl;
            pause();
            return;
        }
        else
        {
            //get how many patients the doctor has. Add one to them. That is also new index.
            numOfPatients = doctors[doctorsIndex].getNumberOfPatient();
            tDoctorId = doctors[doctorsIndex].getId();

            //create a new Patient
            patients[numOfPatients][doctorsIndex] = Patient( tDoctorId, tName, tId, tAddress, tPhone );
            doctors[doctorsIndex].setNumberOfPatient(numOfPatients + 1);
        }

    }
    else
    {
       cout << "Error doctor does not seem to exist." << endl;
       cin.ignore();
       cin.clear();
       return;
    }
}

//find a patients index
void getPatientIndex( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors,
string patientId, int &patientIndex, int &doctorIndex)
{
//loop through all patients
for(int row=0; row < NUM_OF_PATIENT; row++)
    for(int col = 0; col < numberOfDoctors; col++)
    {
        //find one which matches the wanted ID
        if (patients[row][col].getId() == patientId)
        {
            //return the indexs
            doctorIndex = col;
            patientIndex = row;
        }
        else
        {
            continue;
        }
    }

}

//find if a patient exsists
bool isPatientExist(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors, string id)
{
//loop through patients
for(int row=0; row < NUM_OF_PATIENT; row++)
    for(int col = 0; col < numberOfDoctors; col++)
    {
        //check to see if passes in ID matches any of the patients SSNs
        if ( patients[row][col].getId() == id)
            return true;
        else
            continue;
    }
    return false;
}



//load patients in from a file
void loadPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors)
{
    string fileName;
    for( int i = 0; i < numberOfDoctors; i++)
    {
        //get file name from doctors ID
        fileName = doctors[i].getId() + FILE_EXT;

        //ensure doctor has some patients to load
        if( doctors[i].getNumberOfPatient() > 0 )
        {
            //open file
            fstream inFile(fileName.c_str());

            if( inFile.good() )
            {
                //read in info from the ssn.txt file
                readPatientInfo(inFile, patients, doctors, doctors[i].getNumberOfPatient() );
            }
            else
            {
                cout << "Error opening file: " << fileName;
            }
        }

    }
}


//extended function of loadPatient
void readPatientInfo(fstream& inFile, Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numOfPatients)
{
    //create a pointer to Patient object
    Patient * objPointer;
    objPointer = new Patient;

    string line;
    int doctorIndex;
    int counter = 0;

        //read file line by line for all patients
         while( getline( inFile, line) && counter < numOfPatients )
        {
            objPointer->setName( line );

            getline( inFile, line);
            objPointer->setId( line );

            getline( inFile, line);
            objPointer->setAddress(line);

            getline( inFile, line);
            objPointer->setPhoneNumber(line);

            getline( inFile, line);
            objPointer->setDoctorId(line);

            //get index of the doctor
            doctorIndex = getDoctorIndexById(doctors, Doctor::totalNumberOfDoctors, objPointer->getDoctorId() );

            //use index of the doctor and position of the patient to store in 2d array
            patients[counter][doctorIndex] = *objPointer;
            counter++;
        }
}



//remove patient from 2d array
void removePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors)
{
    string id;
    int pIndex = 0, dIndex = 0, tempNumPatients;

    //get patient ID to remove
    cout << "Please enter the ID of the patient (xxx-xx-xxxx): ";
    cin >> id;

    //check to see if ID exsits
    if ( isPatientExist(patients, doctors, numberOfDoctors, id) )
    {
        //find the exsisting patientes index so we can NULL out the correct patient
        getPatientIndex(patients, doctors,numberOfDoctors, id, pIndex, dIndex);

        //subtract 1 from the number of Patients assigned to the doctor
        tempNumPatients = doctors[dIndex].getNumberOfPatient();
        doctors[dIndex].setNumberOfPatient(tempNumPatients - 1);

        //NULL all the things
        patients[pIndex][dIndex].setAddress("");
        patients[pIndex][dIndex].setDoctorId("");
        patients[pIndex][dIndex].setId("");
        patients[pIndex][dIndex].setName("");
        patients[pIndex][dIndex].setPhoneNumber("");

        cout << "Patient has been removed" << endl;

    }
    else
    {
        cout << "Error, this user does not seem to exsist" << endl;
    }

}


void searchPatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors)
{

    string id;
    int pIndex = 0, dIndex = 0;
    cout << "Please enter the ID of the patient (xxx-xx-xxxx): ";
    cin >> id;
    cout << endl;

    //check to see if patient exsists
     if ( isPatientExist(patients, doctors, numberOfDoctors, id) )
    {
        clearScreen();
        //display info if patient does exist
        cout << "INFORMATION:" << endl << endl;
        getPatientIndex(patients, doctors,numberOfDoctors, id, pIndex, dIndex);

        //use overloaded << operator
        cout << patients[pIndex][dIndex];
        cout << "Doctor: " << doctors[dIndex] << endl;
        pause();
    }
    else
    {
        cout << "This patient does not seem to exist" << endl;
        pause();
    }

}

//store patients into appropriate doctor files
void storePatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors)
{

    string filename;
    //search through how many doctors there are
    for( int doctorColomn = 0; doctorColomn < numberOfDoctors; doctorColomn++)
    {
        //create a file name for the doctor
        filename = doctors[doctorColomn].getId() + FILE_EXT;

        //check to make sure that the doctor has at least one patient
        if( doctors[doctorColomn].getNumberOfPatient() > 0 )
        {
            //open file
            ofstream outFile(filename.c_str());

            //output data
            for(int row=0; row < doctors[doctorColomn].getNumberOfPatient(); row++)
            {
                outFile << patients[row][doctorColomn].getName() << endl << patients[row][doctorColomn].getId() << endl
                << patients[row][doctorColomn].getAddress() << endl << patients[row][doctorColomn].getPhoneNumber() << endl
                << patients[row][doctorColomn].getDoctorId() << endl;
            }
        }
        else
        {
            continue;
        }

    }


}

//update a patients name
void updatePatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors, string id)
{

    //check for existence
     if ( isPatientExist(patients, doctors, numberOfDoctors, id) )
     {
        int pIndex = 0, dIndex = 0;
        string input;
        getPatientIndex(patients, doctors,numberOfDoctors, id, pIndex, dIndex);

        cin >> patients[pIndex][dIndex];
     }
     else
     {
        cout << "No Patient exsists by that criteria" << endl;
        return;
     }

}
