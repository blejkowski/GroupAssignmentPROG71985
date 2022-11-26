#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "taskManager.h"
#include "task.h"
#include "operations.h"
/*PROG1985 F22 Section2 - Group Project - switch.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by: 
* 
* This module contains the functions that print the menus to the screen as well as handles user inputs
*
*/


void printWelcome(void) {
	printf("\n");
	printf(" **********************\n");
	printf("**      Welcome to    **\n");
	printf("**     Task Manager   **\n");
	printf(" **********************\n");
}

void printMenu(void) {
	printf("To choose a function, enter its letter label:");
	printf("\n1) Add a new task.");
	printf("\n2) Delete a task.");
	printf("\n3) Update a task.");
	printf("\n4) Display a single task.");
	printf("\n5) Display all tasks.");
	printf("\n6) Sort tasks by priority.");
	printf("\nAny other input to quit.\n");
}

bool selectionFunction(pLIST taskManager, bool* runPtr) {
	
	int option;
	scanf(" %d", &option);
	switch (option) {
	case 1:
		if (addTaskOperation(taskManager))
			printf("Task has been added.");
		else
			fprintf(stderr, "There has been a problem adding that task.");
		break;
	case 2:
		if (deleteTaskOperation(taskManager))
			printf("Task has been deleted.\n");
		else
			fprintf(stderr, "There has been a problem deleting that task.\n");
		break;
	case 3:
		if (updateTaskOperation(taskManager))
			printf("Task has been updated.");
		else
			fprintf(stderr, "Could not update the task");
		break;
	case 4:
		if (!displaySingleTaskOperation(taskManager))
			fprintf(stderr, "Task cannot be printed");	
		break;
	case 5:
		Display(*taskManager);
		break;
	case '6':
		SortTasksByPriorityOperation(taskManager);
		printf("DisplayList: ");
		Display(*taskManager);
		break;
	default:
		*runPtr = false;
		//exit(1);
		break;
	}

	return *runPtr;
 }