/**************************************************************************************************
*
*	Function: GetTitle.c
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

void GetTitle(COURSE* record)
{
	int i;                                                   //Declare incrementing variable

	printf("Please enter the course title: ");                //print prompt
	fgets(record -> title, 65, stdin);                       //get response
	
	for(i = 0; i < 65; i++)                                 //place null at end of string
		if(record -> number[i] == '\n')
			record -> number[i] = '\0';

	return;
}
