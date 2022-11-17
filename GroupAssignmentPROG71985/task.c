#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "task.h"

TASK createTask(int taskNumber, char* taskInfo, int isComplete, int priority) {
	TASK newTask;

	newTask.taskNumber = taskNumber;
	strncpy(newTask.taskInfo, taskInfo, sizeof(newTask.taskInfo));
	newTask.isComplete = isComplete;
	newTask.priority = priority;
	return newTask;
}
// 
//get task
TASK getTask(TASK task) {
	return task;
}

//copy task
TASK copyTask(TASK task) {
	return createTask(task.taskNumber, task.taskInfo, task.isComplete, task.priority);
}
//compare task
bool compareTasks(TASK left, TASK right) {
	if (left.taskNumber == right.taskNumber)
		return true;
	else
		return false;
}
//print task
void printTask(TASK task) {
	char* completeString;
	if (task.isComplete == 1) 
		completeString = "True";
	else 
		completeString = "False";

	char* priorityString;
	if (task.priority == 1)
		priorityString = "Low";
	else if (task.priority == 2)
		priorityString = "Medium";
	else
		priorityString = "High";
	
	printf("Task Number: %d\nTask Info: %s\nTask Complete: %s\nTask Priority: %s", task.taskNumber, task.taskInfo, completeString, priorityString);
}