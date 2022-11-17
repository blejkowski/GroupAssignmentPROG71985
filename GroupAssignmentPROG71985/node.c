#include "task.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
pLISTNODE createNode(TASK task) {
	pLISTNODE newNode = (pLISTNODE)malloc(sizeof(LISTNODE));

	if (!newNode) {
		fprintf(stderr, "error allocating memory");
		exit(1);
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