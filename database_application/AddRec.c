/**************************************************************************************************
*
*	Function: AddRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Add Record.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void AddRec(void)
{
	COURSE course1;                                          //Declare Variables
	COURSE course2;
	int i = 0;
	char prompt_yn;
	char temp[10];

	if(filename[0])                                          //If database open
	{
		Header();
		printf("\nAdd Record\n");

		EditRec(&course1);                                     //Edit Record and Write record
		WriteRec(&course1);
		ReadRec(&course2);
		DisplayRec(&course2);

		while(array[i].number[0] != '\0')                      //Find opening in array
			i++;
		
		RecCpy(&array[i], &course2);                           //Put record in opening
		
		LinkRec(&array[i]);                                   //Link new record
		printf("\nNew record added sucessfully!");
	}
	else{
		printf("\nError\nNo database is open.\n");                //Error if no database is open
		while(1){						  //Ask the user if they would like to make one
			printf("\nWould you like to create a new database? [y/n] ");
			fgets(temp, 10, stdin);
			if(strlen(temp) > 2) printf("\nERROR: INVALID RESPONSE LENGTH\n");
			else prompt_yn = temp[0];
			if(prompt_yn == 'y'){NewDat(); AddRec();}
			else if(prompt_yn == 'n') break;
			else{
				printf("\nERROR: INVALID RESPONSE\n");
			}
		}
	}

	GetEnter();
	return;
}
