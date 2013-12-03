/**************************************************************************************************
*
*	Function:	WriteRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Save the record to a file
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void WriteRec(COURSE* CoursePointer)
{
	FILE* record;                                            //Declare file pointer

	record = fopen("Record.txt", "wt");                      //Open file
	fprintf(record, "%s\n", CoursePointer -> number);
	fprintf(record, "%s\n", CoursePointer -> title);
	fprintf(record, "%d\n", CoursePointer -> credit);
	fprintf(record, "%d\n", CoursePointer -> lab);

	fclose(record);                                          //Close file

	return;
}
