#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "taskManager.h"
/*PROG1985 F22 Section2 - Group Project - taskManager.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains the definitions and implementations of the functions related to the taskManager/list
*
*/

pLIST createList() {
	pLIST newlist = { 0 };
	return newlist;
}
bool addTask(pLIST thisList, TASK task) {
	pLISTNODE newNode = createNode(task);

	if (thisList->list == NULL) {
		setNextNode(newNode, thisList->list);
		thisList->list = newNode;
	}
	else {
		pLISTNODE currentNode = thisList->list;

		while (getNextNode(currentNode) != NULL)
			currentNode = getNextNode(currentNode);

		setNextNode(currentNode, newNode);
	}
	return true;
}

//this function i need to add pushing back the task numbers
void removeTask(pLIST thisList, TASK task) {
	pLISTNODE currentNode = thisList->list;
	if (compareTasks(currentNode->task, task)) {
		if (getNextNode(currentNode) != NULL)
			thisList->list = getNextNode(currentNode);
		else
			thisList->list = NULL;

		disposeNode(currentNode);
		return;
	}
	pLISTNODE previousNode = NULL;
	while (currentNode != NULL && !compareTasks(currentNode->task, task)) {
		previousNode = currentNode;
		currentNode = getNextNode(currentNode);
	}
	if (currentNode == NULL)
		return;

	setNextNode(previousNode, getNextNode(currentNode));
	disposeNode(currentNode);
	return;
}

void Display(LIST thisList) {
	if (thisList.list == NULL)
		return;
	else {
		pLISTNODE currentNode = thisList.list;
		do {
			printTask(currentNode->task);
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);
	}
}

int getNumberOfTasks(pLIST thisList) {
	int count = 0;
	if (thisList->list == NULL) {
		return 0;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		do {
			count++;
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);
		return count;
	}
}

void disposeList(pLIST thisList) {

	pLISTNODE tmp;

	pLISTNODE current = thisList->list;
	while (current != NULL)
	{
		tmp = current;
		current = getNextNode(current);
		disposeNode(tmp);
	}
}

pLISTNODE findTaskByNumber(pLIST thisList, int taskNumber) {
	if (thisList->list == NULL) {
		return 0;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		do {
			if (thisList->list->task.taskNumber == taskNumber) {
				pLISTNODE taskNode = thisList->list;
				return taskNode;
			}
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);
	}
}

//delete task by id
bool deleteTaskByNumber(pLIST thisList, int taskNumber) {
	if (thisList->list == NULL) {
		return false;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		do{
			printf("\ntask in list: %d tasknumber given: %d\n", currentNode->task.taskNumber, taskNumber);
			if (currentNode->task.taskNumber == taskNumber) {
				removeTask(thisList, currentNode->task);
				return true;
			}
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);

		return false;
	}
}
