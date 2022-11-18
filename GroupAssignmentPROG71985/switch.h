/*PROG1985 F22 Section2 - Group Project - switch.h
*Author: Bryan Lejkowski
*Main Contributor: Bryan Lejkowski
*Contributed to by:
*
* This module contains declarations/prototypes of the switch functions to be called by the main function in main.c
*/

/*
* Function: selectionFunction()
* ------------------------
* This function prints gets the input from the user of which operation is to be performed, and then executes it.
*
* Params: pLIST taskManager
* Return: void
*/
void selectionFunction(pLIST);

/*
* Function: printMenu()
* ------------------------
* This function prints a the menu of operations to the console.
*
* Params: void
* Return: void
*/
void printMenu(void);

/*
* Function: printWelcome()
* ------------------------
* This function prints a "welcome message" to the console.
*
* Params: void
* Return: void
*/
void printWelcome(void);