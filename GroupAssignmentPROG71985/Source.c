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
int main(int argc, char* argv[]) {
	checkFile(argv[1]);
	// If this function fails, or if the count is otherwise not what it should be, the program exits.
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printWelcome(); 
	bool run = true;
	pLIST taskManager = createList(); //create a heap allocated list structure that acts as a "task manager"
	do {
		printMenu();
		run = selectionFunction(&taskManager, &run, argv[1]);
	} while (run == true);

	

	return 0;
}