/**************************************************************************************************
*
*	Function: CloseData.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Close and save the Database.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void CloseData(void)
{
	if(filename[0])                                          //If File open
	{
		FILE* database;                                        //Declare Variable
		int i = 0;

		Header();
		printf("\nClose the Database\n");
		database = fopen(filename, "wt");                      //Open database for writing
		for(i = 0; i < 256; i++)                               //Write file
			if(array[i].number[0] != '\0')
			{
				fprintf(database, "%s\n", array[i].number);
				fprintf(database, "%s\n", array[i].title);
				fprintf(database, "%d\n", array[i].credit);
				fprintf(database, "%d\n", array[i].lab);
			}

		fclose(database);                                      //Close file
		FIRST = NULL;                                          //Re-initialize array
		LAST = NULL;
		filename[0] = '\0';
		for(i = 0; i < 256; i++)
			InitializeRec(&array[i]);

	}
	else
		printf("\nError\nNo database is open.\n");               //Error if no is open

	GetEnter();
	return;
}
