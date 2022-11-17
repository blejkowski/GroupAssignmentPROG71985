#pragma once
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 128

/*PROG1985 F22 Section2 - Group Project - task.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains all of the task declaritions and function definitions/prototypes to be utilized
*/

typedef struct task {
	int taskNumber; // a unique identifier for the task
	char taskInfo[MAX_LENGTH]; // a string explaining details of the task
	int isComplete; // 1 = true, 0 = false
	int priority; // 1 = low, 2 = medium, = 3 high
}TASK;

/*
* Function: createTask()
* ------------------------
* This function takes the neccessary information requreid to create a task and returns a task.
*
* Params: int taskNumber, char* taskInfo, int isComplete, int priority
*		
* Return: TASK
*/
TASK createTask(int, char*, int, int);

/* TO BE REFACTORED POSSIBLY MAKE IT TAKE INT TASKNUMBER AS A PARAMETER
* Function: getTask()
* ------------------------
* This function takes a task and returns a task.
*
* Params: TASK
*
* Return: TASK
*/
TASK getTask(TASK);
//set/update task

/*
* Function: copyTask()
* ------------------------
* This function take a TASK as a parameter and returns a copy of it.
*
* Params: TASK
*
* Return: TASK
*/
TASK copyTask(TASK);

/*
* Function: compareTasks()
* ------------------------
* This function takes two TASKs as parameters and compares them by taskNumber.
*
* Params: TASK
*
* Return: bool return true if both taskNUmbers are equal, return false if not
*/
bool compareTasks(TASK, TASK);

/*
* Function: printTask()
* ------------------------
* This function takes a task as a parameter, parses the values of isComplete and priority, and prints it.
*
* Params: TASK
*
* Return: void
*/
void printTask(TASK task);