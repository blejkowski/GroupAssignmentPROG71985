#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "taskManager.h"
#include "task.h"

void printWelcome() {
	printf("\n");
	printf(" **********************\n");
	printf("**      Welcome to    **\n");
	printf("**     Task Manager   **\n");
	printf(" **********************\n");
}

void printMenu() {
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
	case 1: {
		TASK newTask = createTask(1, "test task", 1, 2);
		printTask(newTask);
		addTask(taskManager, newTask);
	}
		break;
	case 2:
		//delete task
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