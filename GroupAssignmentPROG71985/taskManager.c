#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "taskManager.h"

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
			if (thisList->list->task.taskNumber, taskNumber) {
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
		return 0;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		while (currentNode != NULL){
			if (thisList->list->task.taskNumber == taskNumber) {
				pLISTNODE taskNodeToDelete = findTaskByNumber(thisList, taskNumber);
			/*	TASK taskToRemove = findTaskByNumber(taskNumber);
				removeTask(thisList, taskToRemove);*/
				removeTask(thisList, taskNodeToDelete->task);
				return true;
			}
			currentNode = getNextNode(currentNode);
		}

		return false;
	}
}
