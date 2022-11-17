#pragma once
#include "task.h"
typedef struct listnode {
	TASK task;
	struct listnode* next;
}LISTNODE, * pLISTNODE;

pLISTNODE createNode(ITEM);

pLISTNODE getNextNode(pLISTNODE);
void setNextNode(pLISTNODE, pLISTNODE);

void disposeNode(pLISTNODE);