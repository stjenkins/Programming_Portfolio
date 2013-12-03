/**************************************************************************************************
*
*	Function: GetCredit.c
*
*	Author:	Samuel Horst
*
*	Date:	November 6, 2012
*
*	Purpose:	Get course number.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void GetCredit(COURSE* record)
{
	int i;                                                   //Declare variables
	char buff[255];
	BOOLEAN error;

	do                                                       //Loop if Error
	{
		error = FALSE;
		printf("Please enter the number of credits: ");
		fgets(buff, 255, stdin);
	
		sscanf(buff, "%d", &(record -> credit));

		if(record -> credit > 9 || record -> credit < 0)       //Sanity Check
		{
			printf("\nError\nPlease enter a valid response.\n");
			error = TRUE;
		}
	}while(error);
	return;
}
