/**************************************************************************************************
*
*	Function: QuitProgram.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Quit.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

BOOLEAN QuitProgram(void)
{
	BOOLEAN return_value;                                    //Declare return value variable
	BOOLEAN error;
	char buff[255];

	if(!filename[0])                                         //If database closed quit
	{
		printf("\nGood-bye\n");
		return_value = TRUE;
	}
	else                                                     //If database open ask to close
	{
		do
		{
			error = FALSE;
			printf("\nA database is open.\nDo you want to save before quitting? (Y/N): ");
			fgets(buff, 255, stdin);
			buff[0] = tolower(buff[0]);

			if((buff[0] != 'y' && buff[0] != 'n') || buff[1] != '\n')
			{
				printf("\nError\nPlease enter a valid response\n");
				error = TRUE;
			}
			else
			{
				if(buff[0] == 'y')
				{
					CloseData();
					return_value = QuitProgram();
				}
				else
				{
					filename[0] = '\0';
					return_value = QuitProgram();
				}
			}
		}while(error);
	}

	return(return_value);
}
