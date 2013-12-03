/**************************************************************************************************
*
*	Function: DisplayRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: To display a record
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void DisplayRec(COURSE* record)
{
	printf("\n\nNumber: %s", record -> number);
	printf("\nTitle: %s", record -> title);
	printf("\nCredit: %d", record -> credit);
	printf("\nLab: %d", record -> lab);

	return;
}
