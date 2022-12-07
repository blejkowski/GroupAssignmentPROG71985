/*PROG1985 F22 Section2 - Group Project - node.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains the declarations/prototypes of the operations functions to be called by the switch in switch.c
*/
#pragma once
#include "task.h"
#include "StringUtils.h"
typedef struct listnode {
	TASK task;
	struct listnode* next;
}LISTNODE, * pLISTNODE;

pLISTNODE createNode(ITEM);

pLISTNODE getNextNode(pLISTNODE);
void setNextNode(pLISTNODE, pLISTNODE);

void disposeNode(pLISTNODE);