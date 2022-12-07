#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <stdbool.h>
#include "switch.h"
#include "task.h"
#include "taskManager.h"
#include "File.h"

/*PROG1985 F22 Section2 - Group Project - Source.c
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by: Salah Salame
* 
* This module runs/loops through the main program
* Added partial File I/O support. Needs refactoring.
* 
*/
int main() {
	checkFile();
	printWelcome();
	bool run = true;
	pLIST taskManager = createList(); //create a heap allocated list structure that acts as a "task manager"
	readFromFile(&taskManager);
	do {
		printMenu();
		run = selectionFunction(&taskManager, &run);
	} while (run == true);

	return 0;
}