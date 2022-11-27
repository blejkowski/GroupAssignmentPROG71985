#define _CRT_SECURE_NO_WARNINGS
/*PROG1985 F22 Section2 - Group Project - operations.c
*Author: Salah Salame
*Main Contributor: Salah Salame
*Contributed to by: Salah Salame
*
* This module contains the file handling excerpt of this program.
*
*/

#include "File.h"

FILE* fileHandling(char* argv) {
	FILE* data;
	if ((data = fopen(argv, "r")) == NULL) {
		puts("File does not exist. Creating new file...");
		data = fopen(argv, "w");
		return data;
	}
	
	puts("File loaded.");
	return data;
	
}