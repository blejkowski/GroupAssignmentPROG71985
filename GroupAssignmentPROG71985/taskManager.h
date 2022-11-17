#pragma once
#include "node.h"
#include "stdbool.h"
/*PROG1985 F22 Section2 - Group Project - taskManager.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains all of the taskManager declaritions and function definitions/prototypes to be utilized.
*/

typedef struct taskManager {
	pLISTNODE list;
}LIST, *pLIST;
/*
* Function: createList()
* ------------------------
* This function creates a pLIST data type which will be an array of structure pointers.
*
* Params: void
*
* Return: pLIST
*/
pLIST createList();

/*
* Function: addTask()
* ------------------------
* This function attempts to add a task to the taskManager
* 
* Params: pLIST taskManager TASK taskToAdd
*
* Return: bool return true if successful addition to the list, return false if unsuccessful
*/
bool addTask(pLIST, TASK);

/*
* Function: deleteTaskByNumber()
* ------------------------
* This function attempts to find a task with the given taskNumber and delete it
*
* Params: pLIST taskManager int numberOfTaskToDelete
*
* Return: bool return true if successful deletion from the list, return false if unsuccessful
*/
bool deleteTaskByNumber(pLIST, int);


void removeTask(pLIST, TASK);

void Display(LIST);

void disposeList(pLIST);

int getNumberOfTasks(pLIST);
pLISTNODE findTaskByNumber(pLIST thisList, int taskNumber);