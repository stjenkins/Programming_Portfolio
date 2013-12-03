/**************************************************************************************************
*
*	Function: EditRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Edit a record.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void EditRec(COURSE* record)
{
	GetNumber(record);
	GetTitle(record);
	GetCredit(record);
	GetLab(record);

	return;
}
