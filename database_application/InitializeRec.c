/**************************************************************************************************
*
*	Function: InitializeRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Initialize the values of a course record
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void InitializeRec(COURSE* CoursePointer)
{
	CoursePointer -> number[0] = 0;
	CoursePointer -> title [0] = 0;
	CoursePointer -> credit = 0;
	CoursePointer -> lab = FALSE;
	CoursePointer -> next = NULL;
	CoursePointer -> previous = NULL;

	return;
}
