/**************************************************************************************************
*
*	Function: BrowseData.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Browse the Database.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void BrowseData(void)
{
	BOOLEAN quit = FALSE;                                    //Declare Variables
	BOOLEAN flag = FALSE;
	COURSE* current;
	char buff[255];

	if(FIRST)                                 //If database is open with atleast 1 record
	{
		Header();
		printf("\nBrowse the Database\n");
		current = FIRST;

		while(!quit)                                           //Display records until q is pressed
		{
			flag = FALSE;
			DisplayRec(current);

			if(current == FIRST && current != LAST && !flag)
			{
				printf("\nN  %8s", "Next");
				printf("\nD  %8s\tE  %8s", "Delete", "Edit");
				printf("\nQ  %8s\n", "Quit");

				fgets(buff, 255, stdin);
				buff[0] = tolower(buff[0]);
			
				if(buff[1] == '\n')
				{
					switch(buff[0])
					{
						case 'n': current = current -> next;
							break;
						case 'd': DeleteRec(current);
							quit = TRUE;
							break;
						case 'e': UnlinkRec(current);
							EditRec(current);
							LinkRec(current);
							quit = TRUE;
							break;
						case 'q': quit = TRUE;
							break;
						default: printf("\nError\nPlease enter a valid response.\n");
					}
				}
				else
					printf("\nError\nPlease enter a valid response.\n");

				flag = TRUE;
			}

			if(current == FIRST && current == LAST && !flag)
			{
				printf("\nD  %8s\tE  %8s", "Delete", "Edit");
				printf("\nQ  %8s\n", "Quit");

				fgets(buff, 255, stdin);
				buff[0] = tolower(buff[0]);
			
				if(buff[1] == '\n')
				{
					switch(buff[0])
					{
						case 'd': DeleteRec(current);
							quit = TRUE;
							break;
						case 'e': UnlinkRec(current);
							EditRec(current);
							LinkRec(current);
							quit = TRUE;
							break;
						case 'q': quit = TRUE;
							break;
						default: printf("\nError\nPlease enter a valid response.\n");
					}
				}
				else
					printf("\nError\nPlease enter a valid response.\n");

				flag = TRUE;
			}

			if(current != FIRST && current != LAST && !flag)
			{
				printf("\nP  %8s\tN  %8s", "Previous", "Next");
				printf("\nD  %8s\tE  %8s", "Delete", "Edit");
				printf("\nQ  %8s\n", "Quit");

				fgets(buff, 255, stdin);
				buff[0] = tolower(buff[0]);
			
				if(buff[1] == '\n')
				{
					switch(buff[0])
					{
						case 'p': current = current -> previous;
							break;
						case 'n': current = current -> next;
							break;
						case 'd': DeleteRec(current);
							quit = TRUE;
							break;
						case 'e': UnlinkRec(current);
							EditRec(current);
							LinkRec(current);
							quit = TRUE;
							break;
						case 'q': quit = TRUE;
							break;
						default: printf("\nError\nPlease enter a valid response.\n");
					}
				}
				else
					printf("\nError\nPlease enter a valid response.\n");

				flag = TRUE;
			}

			if(current == LAST && current != FIRST && !flag)
			{
				printf("\nP  %8s", "Previous");
				printf("\nD  %8s\tE  %8s", "Delete", "Edit");
				printf("\nQ  %8s\n", "Quit");

				fgets(buff, 255, stdin);
				buff[0] = tolower(buff[0]);
			
				if(buff[1] == '\n')
				{
					switch(buff[0])
					{
						case 'p': current = current -> previous;
							break;
						case 'd': DeleteRec(current);
							quit = TRUE;
							break;
						case 'e': UnlinkRec(current);
							EditRec(current);
							LinkRec(current);
							quit = TRUE;
							break;
						case 'q': quit = TRUE;
							break;
						default: printf("\nError\nPlease enter a valid response.\n");
					}
				}
				else
					printf("\nError\nPlease enter a valid response.\n");

				flag = TRUE;
			}
		}
	}
	else
		printf("\nError\nNo database is open or no records in database.\n");

	GetEnter();
	return;
}
