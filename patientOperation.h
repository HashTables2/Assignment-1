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
#include "constants.h"
#include "doctor.h"

void addPatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors);
void getPatientIndex( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors, string patientId, int &patientIndex, int &doctorIndex);
bool isPatientExist(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors, string id);
void loadPatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors);
void readPatientInfo(fstream& inFile, Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numOfPatients);
void removePatient(Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors);
void searchPatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors);
void storePatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors);
void updatePatient( Patient patients[][NUM_OF_DOCTOR], Doctor doctors[], int numberOfDoctors, string id);



