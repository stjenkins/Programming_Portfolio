/**************************************************************************************************
*
*	Function: RecCpy.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Copy a record.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void RecCpy(COURSE* dest, COURSE* source)
{
	strcpy(dest -> number, source -> number);
	strcpy(dest -> title, source -> title);
	dest -> credit = source -> credit;
	dest -> lab = source -> lab;
	dest -> next = source -> next;
	dest -> previous = source -> previous;

	return;
}
