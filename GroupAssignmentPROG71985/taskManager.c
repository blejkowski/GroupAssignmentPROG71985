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
void removeTask(pLIST thisList, TASK task) {
	pLISTNODE currentNode = thisList->list;
	if (compareTasks(currentNode->task, task)) {
		if (getNextNode(currentNode != NULL))
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