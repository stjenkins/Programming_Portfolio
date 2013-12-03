/**************************************************************************************************
*
*	Function: UnlinkRec.c
*
*	Author: Samuel Horst
*
*	Date November 14, 2012
*
*	Purpose: Remove record from the list.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void UnlinkRec(COURSE* record)
{
	COURSE* record_prev;                                     //declare variables
	COURSE* record_next;
	BOOLEAN flag;

	record_prev = record -> previous;                        //intialize variables
	record_next = record -> next;
	flag = FALSE;

	if(record == FIRST && record == LAST && !flag)           //case: only record
	{
		LAST = NULL;
		FIRST = NULL;
	}

	if(record == FIRST && record != LAST && !flag)           //case: multiple records and first record
	{
		FIRST = record_next;
		record_next -> previous = NULL;
	}

	if(record != FIRST && record != LAST && !flag)           //case: multiple records and not first or last
	{
		record_prev -> next = record_next;
		record_next -> previous = record_prev;
	}

	if(record != FIRST && record == LAST && !flag)           //case: multiple records and last record
	{
		LAST = record_prev;
		record_prev -> next = NULL;
	}
	
	return;
}
