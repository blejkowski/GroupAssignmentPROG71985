#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "operations.h"
#include "task.h"

/*PROG1985 F22 Section2 - Group Project - operations.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains all of the operations to be called by the switch in switch.c
*/

bool addTaskOperation(pLIST taskManager) {
	//Get the input from the user and store
	printf("Enter the task: ");
	char taskString[MAX_LENGTH];
	scanf(" %s", taskString);
	
	printf("What is the priority of this task?\nHigh - 3\nMedium - 2\nLow - 1\n");
	int priority = 0;
	scanf( "%d", &priority);

	//get number of tasks
	int numberOfTasks = getNumberOfTasks(taskManager);
	// debug printf("Number of tasks debug: %d\n", numberOfTasks);

	//create task
	TASK newTask = createTask(numberOfTasks + 1, taskString, 0, priority);
	//add the task and return whether it was successful or not
	return addTask(taskManager, newTask);
}

bool deleteTaskOperation(pLIST taskManager) {
	//get the number of the task the user will like to delte
	printf("Enter the numbero of the task you wish to delete.\n");
	int taskNumber;
	scanf(" %d", &taskNumber);
	//delete the task and return whether it was successful or not
	return deleteTaskByNumber(taskManager, taskNumber);
}

bool updateTaskOperation(pLIST taskManager) {
	//Get the input from the user and store
	printf("Enter ID of task to update: \n");
	int taskIdToUpdate;
	scanf(" %d", &taskIdToUpdate);
	printf("Enter the task: \n");
	char taskString[MAX_LENGTH];
	scanf(" %s", taskString);

	printf("Enter 1 if task has been completed. Enter 0 if it has not been completed. \n");
	int completion = 0;
	scanf("%d", &completion);

	printf("What is the priority of this task?\nHigh - 3\nMedium - 2\nLow - 1\n");
	int priority = 0;
	scanf("%d", &priority);

	//create task
	TASK newTask = createTask(taskIdToUpdate, taskString, completion, priority);

	return updateTask(taskManager, newTask);
}

bool displaySingleTaskOperation(pLIST taskManager) {
	printf("Enter ID of task to display: \n");
	int taskIdToDisplay;
	scanf(" %d", &taskIdToDisplay);
	pLISTNODE taskToDisplay = findTaskByNumber(taskManager, taskIdToDisplay);
	
	if (taskToDisplay == NULL)
		return false;
	else {
		printTask(taskToDisplay->task);
		return true;
	}

}