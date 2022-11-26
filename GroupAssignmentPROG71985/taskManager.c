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
			if (currentNode->task.taskNumber == taskNumber) {
				return currentNode;
			}
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);
		return NULL;
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
			//debug  print printf("\ntask in list: %d tasknumber given: %d\n", currentNode->task.taskNumber, taskNumber);
			if (currentNode->task.taskNumber == taskNumber) {
				removeTask(thisList, currentNode->task);
				return true;
			}
			currentNode = getNextNode(currentNode);
		} while (currentNode != NULL);

		return false;
	}
}

bool updateTask(pLIST thisList, TASK newTask) {
	if (thisList->list == NULL) {
		return false;
	}
	else {
		pLISTNODE nodeToUpdate = findTaskByNumber(thisList, newTask.taskNumber);
		nodeToUpdate->task = newTask;
		return true;
	}
}


bool SortTasksByPriority(pLIST thisList) {
	bool sorted = false;
	if (thisList->list == NULL) {
		return false;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		pLISTNODE nextNode;
		TASK temp;
		while (currentNode != NULL) {
			nextNode = currentNode->next;
			while (nextNode != NULL) {
				if (currentNode->task.priority < nextNode->task.priority) {
					temp = currentNode->task;
					currentNode->task = nextNode->task;
					nextNode->task = temp;
				}
				nextNode = getNextNode(nextNode);
			}
			currentNode = getNextNode(currentNode);
		}
		
		//iterate through list and change task numbers
		currentNode = thisList->list;
		int index = 1;
		while (currentNode != NULL) {
			currentNode->task.taskNumber = index;
			index++;
			currentNode = getNextNode(currentNode);
		}
		return true;
	}
}