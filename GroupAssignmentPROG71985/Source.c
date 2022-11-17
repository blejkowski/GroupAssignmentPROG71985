#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "switch.h"
#include "task.h"
#include "taskManager.h"

int main(void) {
	printWelcome();
	bool run = true;
	pLIST taskManager = createList();
	while (run) {
		printMenu();
		selectionFunction(&taskManager);
	}
}