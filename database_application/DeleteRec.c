/**************************************************************************************************
*
*	Function: DeleteRec.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Delete a record.
*
* Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

void DeleteRec(COURSE* record)
{
	Header();
	printf("\nDelete a Record\n");
	UnlinkRec(record);
	InitializeRec(record);

	printf("\nRecord Deleted Sucessfully!\n");

	GetEnter();
	return;
}
