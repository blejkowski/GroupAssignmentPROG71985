#pragma once
#include "node.h"
#include "stdbool.h"
/*PROG1985 F22 Section2 - Group Project - taskManager.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains all of the taskManager declaritions/prototypes to be utilized.
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
* Return: pLIST createdList
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

/*
* Function: removeTask()
* ------------------------
* This function removes a task from the task manager
*
* Params: pLIST taskManager TASK taskToBeRemoved
*
* Return: void
*/
void removeTask(pLIST, TASK);

/*
* Function: Display()
* ------------------------
* This function prints the current tasks stored
*
* Params: LIST taskManager
* Return: void
*/
void Display(LIST);

/*
* Function: disposeList()
* ------------------------
* This function disposes the taskManager/list and frees the memory used by it.
*
* Params: pLIST taskManager
* Return: void
*/
void disposeList(pLIST);

/*
* Function: getNumberOfTasks()
* ------------------------
* This function returns a count of how many tasks are in the taskManager at the moment.
*
* Params: pLIST taskManager
* Return: int numberOfTasks
*/
int getNumberOfTasks(pLIST);

/*
* Function: findTaskByNumber()
* ------------------------
* This function finds and returns a task from the task manager 
*
* Params: pLIST taskManager int taskNumber
* Return: pLISTNODE foundTask
*/
pLISTNODE findTaskByNumber(pLIST, int);

/*
* Function: updateTask()
* ------------------------
* This function finds a task by ID and replaces it in the list with a new task.
*
* Params: pLIST taskManager TASK newTASK
* Return: boolean result
*/
bool updateTask(pLIST, TASK);

/*
* Function: SortTasksByPriority()
* ------------------------
* This function sorts the list of task by priority. If the list has been sorted it will return true, if the list has not been sorted/is empty it will return false;
*
* Params: pLIST taskManager 
* Return: boolean result
*/
bool SortTasksByPriority(pLIST);