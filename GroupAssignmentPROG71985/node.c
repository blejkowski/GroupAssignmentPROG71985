#include "task.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*PROG1985 F22 Section2 - Group Project - node.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains all of the implementations of the listnode functions
*/

pLISTNODE createNode(TASK task) {
	pLISTNODE newNode = (pLISTNODE)malloc(sizeof(LISTNODE));

	if (!newNode) {
		fprintf(stderr, "error allocating memory");
		exit(EXIT_FAILURE);
	}
	else {
		newNode->task = copyTask(task);
		newNode->next = NULL;
		return newNode;
	}

}

pLISTNODE getNextNode(pLISTNODE node) {
	return node->next;
}
void setNextNode(pLISTNODE source, pLISTNODE next) {
	source->next = next;
}

void disposeNode(pLISTNODE node) {
	free(node);
}
