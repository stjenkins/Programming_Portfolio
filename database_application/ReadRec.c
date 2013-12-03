/**************************************************************************************************
*
*	Function: ReadRec.c
*
*	Author: Samuel Horst
*
*	Date:	November 6, 2012
*
*	Purpose: to read the record from the file.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void ReadRec(COURSE* CoursePointer)
{
	FILE* record;                                            //Declare variables
	int i = 0;
	
	record = fopen("Record.txt", "rt");                      //Open file

	fgets(CoursePointer -> number, 17, record);             //read number
	for(i = 0; i <= 17; i++)
		if(CoursePointer -> number[i] == '\n')
			CoursePointer -> number[i] = '\0';

	fgets(CoursePointer -> title, 65, record);               //read title
	for(i = 0; i <= 65; i++)
		if(CoursePointer -> title[i] == '\n')
			CoursePointer -> title[i] = '\0';

	fscanf(record, "%d", &CoursePointer -> credit);          //read credit
	fscanf(record, "%d", &CoursePointer -> lab);             //read lab

	fclose(record);                                          //close file

	return;
}
