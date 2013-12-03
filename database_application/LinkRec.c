/**************************************************************************************************
*
*	Function: LinkRec.c
*
*	Author: Samuel Horst
*
*	Date: November 8, 2012
*
*	Purpose: Link the record into the list.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void LinkRec(COURSE* new)
{
	COURSE* next_rec;                                        //Declare variables
	COURSE* prev_rec;

	if(!FIRST)                                              //if no records currently exist
	{
		FIRST = new;
		LAST = new;
		new->next = NULL;
		new->previous = NULL;
	}
	else
	{
		if(strcmp(new->number, FIRST->number) == -1)           //case new record will be first
		{
			new->previous = NULL;
			new->next = FIRST;
			FIRST->previous = new;
			FIRST = new;
		}
		
		if(strcmp(new->number, LAST->number) == 1)             //case new record will be last
		{
			new->next = NULL;
			new->previous = LAST;
			LAST->next = new;
			LAST = new;
		}

		if(strcmp(new->number, FIRST->number) == 1 && strcmp(new->number, LAST->number) == -1)         //case new record is in the middle
		{
			next_rec = FIRST;
			do
			{
				next_rec = (next_rec->next);
			}while(strcmp(next_rec->number, new->number) != 1);
				
		prev_rec = (next_rec->previous);
		(next_rec->previous) = new;
		(prev_rec->next) = new;
		new->next = next_rec;
		new->previous = prev_rec;				
		}
	}
	return;
}
