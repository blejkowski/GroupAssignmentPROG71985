#pragma once
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 128
typedef struct task {
	int taskNumber; // a unique identifier for the task
	char taskInfo[MAX_LENGTH]; // a string explaining details of the task
	int isComplete; // 1 = true, 0 = false
	int priority; // 1 = low, 2 = medium, = 3 high
}TASK;
//this is what must be done here
// 
// create new task
TASK createTask(int, char*, int, int);
// 
//get task
TASK getTask(TASK);
//set/update task

//copy task
TASK copyTask(TASK);
//compare task
bool compareTasks(TASK, TASK);

void printTask(TASK task);