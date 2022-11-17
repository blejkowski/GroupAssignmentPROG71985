#pragma once
#include "node.h"
#include "stdbool.h"

typedef struct taskManager {
	pLISTNODE list;
}LIST, *pLIST;

pLIST createList();
bool addTask(pLIST, TASK);
void removeTask(pLIST, TASK);

void Display(LIST);

void disposeList(pLIST);