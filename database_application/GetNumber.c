/**************************************************************************************************
*
*	Function: GetNumber.c
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

void GetNumber(COURSE* record)
{
	int i;                                                   //Declare incrementing variable

	printf("Please enter the course number: ");
	fgets(record -> number, 17, stdin);
	
	for(i = 0; i < 17; i++)                                  //Change new line to null and upcase string
	{
		record -> number[i] = toupper(record -> number[i]);
		if(record -> number[i] == '\n')
			record -> number[i] = '\0';
	}
		

	return;
}
