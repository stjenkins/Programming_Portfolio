/**************************************************************************************************
*
*	Function: GetLab.c
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

void GetLab(COURSE* record)
{
	int i;                                                    //Declare Variables
	char buff[255];
	BOOLEAN error;

	do                                                       //Repeat if Error
	{
		printf("Is there a lab? (Y/N): ");                    //Prompt
		fgets(buff, 255, stdin);
		error = FALSE;

		buff[0] = tolower(buff[0]);                            //lowercase input
	
		if((buff[0] == 'y' || buff[0] == 'n') && buff[1] == '\n')        //Sanity Check
			if(buff[0] == 'y')                                   //find lab value
				record -> lab = 1;
			else
				record -> lab = 0;
		else
		{
			printf("\nError\nPlease enter a valid response.\n");           //Error response
			error = TRUE;
		}
	}while(error);

	return;
}
