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
* This module runs/loops through the main program
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
	printf("\n4) Display a task.");
	printf("\n5) Display all tasks.");
	printf("\n6) Quit \n");
}

void selectionFunction(pLIST taskManager) {
	int option;
	scanf(" %d", &option);

	switch (option) {
	case 1: 
		if (addTaskOperation(taskManager))
			printf("Task has been added.\n");
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
		//update task
		break;
	case 4:
		//display single task
		break;
	case 5: 
		Display(*taskManager);
		break;
	default:
		exit(1);
		break;
	}
}