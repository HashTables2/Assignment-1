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

#include "header.h"
#include <fstream>
#include "constants.h"
#include "generalOperations.h"
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;


//get choice and make sure it is a valid choice
int menu()
{
    clearScreen(); //clear the screen
    cout << setw(15) << "Menu" << endl;
    cout << "1. Add new patient" << endl;
    cout << "2. Remove exsisting patient " << endl;
    cout << "3. Search for a patient using an ID" << endl;
    cout << "4. Update a patients name " << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Choice: ";

    int option;

    while(!(cin >> option))
    {
		cin.clear();
		cin.ignore();
		cout << "Invalid input.  Try again: ";
	}


    return option;
}
