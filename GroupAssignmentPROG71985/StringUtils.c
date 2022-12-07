#include <stdio.h>
#include <String.h>
#include "StringUtils.h"



void CleanNewLineFromString(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '\n')
			string[i] = '\0';
	}
}