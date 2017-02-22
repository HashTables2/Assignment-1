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

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "constants.h"
#include "header.h"
#include "doctor.h"
#include "patient.h"
#include "doctorOperations.h"
#include "patientOperation.h"
using namespace std;

int main()
{
        //load the doctors
        Doctor doctorArray[NUM_OF_DOCTOR];
        loadDoctor( doctorArray );

        //load the patients
        Patient patientArray[NUM_OF_PATIENT][NUM_OF_DOCTOR];
        loadPatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors);

        int choice;

        //print menu and get choices
        do{
            choice = menu();
            switch ( choice )
            {
                case ADD:
                    addPatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors);
                    break;
                case REMOVE:
                    removePatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors);
                    break;
                case SEARCH:
                    //searches for a patient
                    searchPatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors);
                    break;
                    //Update a patients name
                case UPDATE:
                {
                    string id;
                    cout << "Enter ID (xxx-xx-xxxx): ";
                    cin.ignore();
                    getline(cin, id);
                    if( id == "")
                        break;
                    updatePatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors, id);
                    break;
                }
                case EXIT:
                    break;
                default:
                    cout << "No such Choice: Error. ";
                    break;
            }

        }while ( choice != EXIT );

        //store any new or deleted doctors or patients
        storePatient(patientArray, doctorArray, Doctor::totalNumberOfDoctors);
        storeDoctor(doctorArray, Doctor::totalNumberOfDoctors);


    return 0;
}
