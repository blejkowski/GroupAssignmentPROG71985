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
			//if the current node equals one of the task numbers the new value will be task that matches that number is the current nodes new value
			if (currentNode->task.taskNumber == taskNumber) {
				return currentNode;
			}
			currentNode = getNextNode(currentNode);
			//this while loop only works if the current node does not equal null
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
	//finds the task number the the user has inputted and then gets the user to replace that task with another one
	else {
		pLISTNODE nodeToUpdate = findTaskByNumber(thisList, newTask.taskNumber);
		nodeToUpdate->task = newTask;
		return true;
	}
}


bool SortTasksByPriority(pLIST thisList) {
	bool sorted = false;
	//if there are no tasks the return value is fale
	if (thisList->list == NULL) {
		return false;
	}
	else {
		pLISTNODE currentNode = thisList->list;
		pLISTNODE nextNode;
		TASK temp;
		//creating a while loop for finding where the current node should be
		while (currentNode != NULL) {
			//the next node is equal to the current node
			nextNode = currentNode->next;
			//main loop that sorts the priority levels of the tasks 
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

//boolean
bool DisplayRangeOfTasks(pLIST thisList, int mintask, int maxtask)
{
	//get min task node
	

	//if list is empty return false
	if (thisList->list == NULL) {
		return false;


	}

	//otherwise find the range od the two tasks inputed
	else {
		//creates a linked list called node which is used as the function for findTaskByNumber
		pLISTNODE node = findTaskByNumber(thisList, mintask);
		do {
			//
			printTask(node->task);
			//keeps going until it reaches NULL and then the code breaks
			if (getNextNode(node) == NULL)
				break;
			node = getNextNode(node);
			//the while loop constantly loops the code until
		} while (node->task.taskNumber >= maxtask);

		//returns whatever the working value was
		return true;
	}
	

}