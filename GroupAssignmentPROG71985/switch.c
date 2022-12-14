#define _CRT_SECURE_NO_WARNINGS
#define NUM_SIZE_BYTES                  4
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "taskManager.h"
#include "task.h"
#include "File.h"
#include "operations.h"
/*PROG1985 F22 Section2 - Group Project - switch.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by: Salah Salame, Aidan Nickerson
* 
* This module contains the functions that print the menus to the screen as well as handles user inputs
* 
* Updated scanf to scanf_s
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
	printf("\n7) Display range of tasks.");
	printf("\n8) Display incomplete Tasks.");
	printf("\n9) Display completed tasks.");
	printf("\n10) Exit the program.\n");
	
}

bool selectionFunction(pLIST taskManager, bool* runPtr) {
	
	int option;
	char buf[NUM_SIZE_BYTES];
	
	// As using scanf to parse input leaves a new line character, it was decided to use fgets and 
	// convert the input to an integer. The program keeps asking for input until a number is entered.
	printf("enter a number: ");
	do {
		
		if (!fgets(buf, NUM_SIZE_BYTES, stdin)) {
			return 1;
		}
		option = atoi(buf);
	} while (option == 0);

	CleanNewLineFromString(buf);
	switch (option) {
	case 1:
		
		if (addTaskOperation(taskManager))
			printf("Task has been added.");
		else
			fprintf(stderr, "There has been a problem adding that task.\n");
		break;
	case 2:
		if (deleteTaskOperation(taskManager))
			printf("Task has been deleted.\n");
		else
			fprintf(stderr, "There has been a problem deleting that task.\n");
		break;
	case 3:
		if (updateTaskOperation(taskManager))
			printf("Task has been updated.\n");
		else
			fprintf(stderr, "Could not update the task");
		break;
	case 4:
		if (!displaySingleTaskOperation(taskManager))
			fprintf(stderr, "Task cannot be printed\n");	
		break;
	case 5:
		Display(*taskManager);
		break;
	case 6:
		SortTasksByPriorityOperation(taskManager);
		printf("DisplayList: ");
		Display(*taskManager);
		break;
	case 7:
		if (!DisplayRangeOperation(taskManager))
			fprintf(stderr, "Range could not be displayed\n");
		break;
	case 8:
		DisplayIncompleteTasks(taskManager);
		break;
	case 9:
		DisplayCompleteTasks(taskManager);
		break;
	default:

		saveToFile(taskManager);
		*runPtr = false;
		//exit(1);
		break;
	}

	return *runPtr;
 }