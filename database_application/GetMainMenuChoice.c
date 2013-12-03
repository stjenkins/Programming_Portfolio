/**************************************************************************************************
*
*	Function: GetMainMenuChoice.c
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Get the choice at the main menu.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "stdio.h"

char GetMainMenuChoice(char* prompt)
{
	char (return_value);                                     //Declare variables
	char buff[256];

	printf("\n%s", prompt);                                  //Print Prompt
	fgets(buff, 255, stdin);
	return_value = tolower(buff[0]);                         //lowercase response

	if(buff[1] != '\n')                                      //return null if more than 1 char inputted
		return_value = '\0';
		
	return(return_value);
}
