/**************************************************************************************************
*
*	Function: OpenData.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Open Database.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void OpenData(void)
{
	if(!filename[0])                                         //if database not open
	{
		char buff[255];                                        //Declare variables
		FILE* database;
		BOOLEAN error;
		int dot;
		int i = 0;
		int j = 0;
		int len;

		Header();
		printf("\nOpen Database\n");

		do                                                     //repeat if error
		{
			error = FALSE;
			dot = 0;

			printf("\nDatabases in folder: \n");
			system("dir *.dat");
			printf("\nPlease type the name of the file you wish to open\n");
			printf("If you do not add an extension the .dat file extention will be added for you.\n");
			fgets(filename, 255, stdin);
			for(i = 0; i < 256; i++)
			{
				if(filename[i] == '.')
					dot = i;
				if(filename[i] == '\n')
					filename[i] = '\0';
			}

			if(!dot)
			{
				len = strlen(filename);
				filename[len] = '.';
				filename[len + 1] = 'd';
				filename[len + 2] = 'a';
				filename[len + 3] = 't';
				filename[len + 4] = '\0';
			}

			database = fopen(filename, "rt");                       //open file

			if(!database)                                           //error if file does not exist
			{
				printf("\nError\nThat file does not exist.\n");
				error = TRUE;
			}
		}while(error);

		while(!feof(database))                                 //place values into array until EOF
		{
			buff[0] ='\0';

			fgets(buff, 17, database);
			for(i = 0; i < 17; i++)
			{
				array[j].number[i] = buff[i];
				if(buff[i] == '\n')
					array[j].number[i] ='\0';
			}

			fgets(buff, 65, database);
			for(i = 0; i < 65; i++)
			{
				array[j].title[i] = buff[i];
				if(buff[i] == '\n')
					array[j].title[i] = '\0';
			}

			fgets(buff, 3, database);
			for(i = 0; i < 4; i++)
				if(buff[i] == '\n')
					buff[i] = '\0';
			sscanf(buff, "%d", &array[j].credit);

			fgets(buff, 3, database);
			for(i = 0; i < 4; i++)
				if(buff[i] == '\n')
					buff[i] = '\0';
			sscanf(buff, "%d", &array[j].lab);

			j++;
		}

		fclose(database);                                      //Close file
		for(i = 0; i < 256; i++)                               //Link all elements of array
			if(array[i].number[0])
				LinkRec(&array[i]);
	}
	else
		printf("\nError\nDatabase already open.\n");           //Error if database open

	GetEnter();

	return;
}
