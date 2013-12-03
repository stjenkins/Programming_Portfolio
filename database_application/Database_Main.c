/**************************************************************************************************
*
*	Program: Database_Main.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: This is the main file for the Database Program.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"
COURSE array[255];                                         //Declare global Variables
COURSE* FIRST;
COURSE* LAST;
char filename[255];

void main(void)
{
	char choice;                                             //Declare Variables
	int i = 0;
	BOOLEAN quit = FALSE;

	FIRST = NULL;                                            //Initialize variables                         
	LAST = NULL;
	for(i = 0; i < 256; i++)
		InitializeRec(&array[i]);
	filename[0] = '\0';

	i = 0;
	
	do                                                       //menu open until quit = TRUE
	{
	choice = DisplayMainMenu();                              //Display Main Menu and Get Main Menu Choice
	
	switch(choice)                                           //Menu swithc
		{
			case 'o': OpenData();
				break;
			case 'a': AddRec();
				break;
			case 's': SearchData();
				break;
			case 'b': BrowseData();
				break;
			case 'd': printf("\nDelete Record\n");
				break;
			case 'c': CloseData();
				break;
			case 'q': quit = QuitProgram();
				break;
			default: printf("\nError\nPlease enter a valid response.\n");
				break;
		}

	}while(!quit);

	return;                                                    //Exit the program.
}
