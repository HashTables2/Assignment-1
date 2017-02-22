#ifndef CONST_H
#define CONST_H

#include <iostream>
#include <string>

using namespace std;

const int NUM_OF_DOCTOR = 5, NUM_OF_PATIENT = 10, NUM_OF_DAYS = 5, NUM_OF_TIME_SLOT = 28;
const string FILE_EXT = ".txt";
const string DOCTOR_FILE = "doctors.txt", SCHEDULE_FILE = "schedule.txt";
const int SPACE = 25;
const int TIME_SPACE = 15;

//enum MENU_OP { ADD = 1, REMOVE, SEARCH, UPDATE, SCHEDULER, EXIT };
enum MENU_OP { ADD = 1, REMOVE, SEARCH, UPDATE, EXIT };
enum SCHEDULER_OP { VIEW_SCHEDULE = 1, ADD_APP, REMOVE_APP, EXIT_SCHEDULE };

const string DAYS[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"};

const string TIME_SLOT[] = {"09:00 - 09:15", "09:15 - 09:30", "09:30 - 09:45", "09:45 - 10:00",
                            "10:00 - 10:15", "10:15 - 10:30", "10:30 - 10:45", "10:45 - 11:00",
                            "11:00 - 11:15", "11:15 - 11:30", "11:30 - 11:45", "11:45 - 12:00",
                            "13:00 - 13:15", "13:15 - 13:30", "13:30 - 13:45", "13:45 - 14:00",
                            "14:00 - 14:15", "14:15 - 14:30", "14:30 - 14:45", "14:45 - 15:00",
                            "15:00 - 15:15", "15:15 - 15:30", "15:30 - 15:45", "15:45 - 16:00",
                            "16:00 - 16:15", "16:15 - 16:30", "16:30 - 16:45", "16:45 - 17:00" };

#endif
