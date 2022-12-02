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
#include "node.h"

void checkFile(char* argv) {
	FILE* data;
	if ((data = fopen(argv, "r")) == NULL)
	{
		puts("File does not exist. Creating new file...");
		data = fopen(argv, "w");
	}
	puts("File created.");
}

void saveToFile(pLIST list, char* argv)
{
	FILE* dataFile = fopen(argv, "w");
	pLISTNODE currentNode = list->list;
	while (currentNode != NULL)
	{
		fprintf(dataFile, "%d\n", currentNode->task.isComplete);
		fprintf(dataFile, "%d\n", currentNode->task.priority);
		fprintf(dataFile, "%s", currentNode->task.taskInfo);
		fprintf(dataFile, "%d\n", currentNode->task.taskNumber);

		currentNode = getNextNode(currentNode);
	}

	fclose(dataFile);
}