#include <stdio.h>
#include <String.h>
#include "StringUtils.h"

/*PROG1985 F22 Section2 - Group Project - switch.c
*Author: Salah Salame
*Main Contributor: Salah Salame
*Contributed to by:
*
* This module removes the new line char from a string.
*
*
*/


void CleanNewLineFromString(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '\n')
			string[i] = '\0';
	}
}