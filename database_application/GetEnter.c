/*******************************************************************
*	Function: GetEnter.c
*
*	Author: Stephen Jenkins
*	
*	Date: 11/27/12
*
*	Purpose: Asks for the enter key to be pressed to continue
*
*	(c) 2012
*
********************************************************************/

#include "project.h"

void GetEnter(void){
	char temp[2];

	printf("\nPress [Enter] to continue...");
	fgets(temp, 2, stdin);

}
