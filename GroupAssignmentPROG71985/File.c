#define _CRT_SECURE_NO_WARNINGS
/*PROG1985 F22 Section2 - Group Project - operations.c
*Author: Salah Salame
*Main Contributor: Salah Salame
*Contributed to by: Salah Salame
*
* This module contains the file handling excerpt of this program.
*
*/

#include "File.h"
#include "taskManager.h"
#include <stdlib.h>
#include "node.h"
#include <stdbool.h>

void checkFile() {
	FILE* data;
	if ((data = fopen("Database.dat", "rb")) == NULL)
	{
		puts("File does not exist. Creating new file...");
		data = fopen("Database.dat", "wb");
	}
	puts("File created.");
}

void saveToFile(pLIST list)
{
	FILE* dataFile = fopen("Database.dat", "wb");
	
	pLISTNODE currentNode = list->list;

	if (currentNode == NULL)
	{
		fclose(dataFile);
		return;
	}
	while (currentNode != NULL)
	{
		fprintf(dataFile, "%d\n", currentNode->task.isComplete);
		fprintf(dataFile, "%d\n", currentNode->task.priority);
		fprintf(dataFile, "%s\n", currentNode->task.taskInfo);
		fprintf(dataFile, "%d\n", currentNode->task.taskNumber);

		currentNode = getNextNode(currentNode);
	}
	fclose(dataFile);
}

void readFromFile(pLIST list)
{

	FILE* dataFile;
	if ((dataFile = fopen("Database.dat", "w")) == NULL)
	{
		printf(stderr, "Cannot open the file.");
		exit(EXIT_FAILURE);
	}
	char tempStatus[MAX_LENGTH];
	char tempDescription[MAX_LENGTH];
	char tempNumber[MAX_LENGTH];
	char tempPriority[MAX_LENGTH];

	int convertedTmpNum = 0;
	int convertedTmpStatus = 0;
	int convertedTmpPriority = 0;

	// Variables to be replaced with file info after reading from file.

	pLISTNODE currentNode = list->list;
	while(fgets(tempStatus, MAX_LENGTH, dataFile)!=NULL)
	{
		fgets(tempStatus, MAX_LENGTH, dataFile);
		convertedTmpStatus = atoi(tempStatus);

		fgets(tempPriority, MAX_LENGTH, dataFile);
		convertedTmpPriority = atoi(tempPriority);
		fgets(tempDescription, MAX_LENGTH, dataFile);

		fgets(tempNumber, MAX_LENGTH, dataFile);
		convertedTmpNum = atoi(tempNumber);

		TASK newTask = createTask(convertedTmpNum, tempDescription, convertedTmpStatus, convertedTmpPriority);
		addTask(list, newTask);
		currentNode = getNextNode(currentNode);
	}
	fclose(dataFile);
}