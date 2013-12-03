/*******************************************************************
*	Function: NewDat.c
*
*	Author: Stephen Jenkins
*	
*	Date: 11/27/12
*
*	Purpose: Makes a new database.
*
*	(c) 2012
*
********************************************************************/

#include "project.h"

void NewDat(void){
	char temp[256] = " ";
	char buffer[262] = "touch ";
	int dot;
	FILE* my_file;
	BOOLEAN error;
	int i;
	int j;
	int len;

	do                                                     //repeat if error
	{
		Header();
		printf("\nNew Database\n");
		printf("\nPlease input a filename for this new database: ");
		fgets(temp, 256, stdin);
		temp[strlen(temp)] = '\0';
		error = FALSE;
		dot = 0;

		for(i = 0; i < 256; i++)
		{
			if(temp[i] == '.')
				dot = i;
			if(temp[i] == '\n')
				temp[i] = '\0';
		}

		if(!dot)
		{
			len = strlen(temp);
			temp[len] = '.';
			temp[len + 1] = 'd';
			temp[len + 2] = 'a';
			temp[len + 3] = 't';
			temp[len + 4] = '\0';
		}
			strcat(buffer, temp);
			printf("%s", buffer);
			GetEnter();
			system(buffer);
			my_file = fopen(temp, "rt");                       //open file
			if(!my_file)                                           //error if file does not exist
		{
			printf("\nError\nThat file does not exist.\n");
			error = TRUE;
		}
	}while(error);
}
