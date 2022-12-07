#pragma once
#include <stdbool.h>
#include "taskManager.h"
#include "StringUtils.h"
/*PROG1985 F22 Section2 - Group Project - operations.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains the declarations/prototypes of the operations functions to be called by the switch in switch.c
*/

/*
* Function: addTaskOperation()
* ------------------------
* This function takes in a pointer to the list/task manager and adds a new task to it.
*
* Params: pLIST taskManager
* Return: bool Successful addition returns true, unsuccessful addition returns false
*/
bool addTaskOperation(pLIST);

/*
* Function: deleteTaskOperation()
* ------------------------
* This function takes in a pointer to the list/task manager and removes the task from it.
*
* Params: pLIST taskManager
* Return: bool Successful addition returns true, unsuccessful addition returns false
*/
bool deleteTaskOperation(pLIST);

/*
* Function: updateTaskOperation()
* ------------------------
* This function takes in a pointer to the list/task manager updates a task in it.
*
* Params: pLIST taskManager
* Return: bool Successful addition returns true, unsuccessful addition returns false
*/
bool updateTaskOperation(pLIST);

/*
* Function: displaySingleTaskOperation()
* ------------------------
* This function takes in a pointer to the list/task manager prints a task found by ID.
*
* Params: pLIST taskManager
* Return: bool Successful addition returns true, unsuccessful addition returns false
*/
bool displaySingleTaskOperation(pLIST);

/*
* Function: SortTasksByPriorityOperation()
* ------------------------
* This function takes in a pointer to the list/task manager and then sorts and re-numbers the task according to the highest priority.
*
* Params: pLIST taskManager
* Return: bool Successful addition returns true, unsuccessful addition returns false
*/
bool SortTasksByPriorityOperation(pLIST taskManager);