/**************************************************************************************************
*
*	Function: DisplayMainMenu.c
*
*	Author: Samuel Horst
*
* Date: November 6, 2012
*
*	Purpose: Display the main menu.
*
*	Copyright (c) 2012, Samuel Horst
*
**************************************************************************************************/

#include "project.h"

char DisplayMainMenu(void)
{
	char return_value;                                       //Declare return value variable

	Header();
	printf("\nO\tOpen database");                             //Display Menu
	printf("\nA\tAdd new record");
	printf("\nS\tSearch for a record");
	printf("\nB\tBrowse the database");
	printf("\nE\tEdit a Record");
	printf("\nD\tDelete a record");
	printf("\nC\tClose the database");
	printf("\nQ\tQuit\n");

	return_value = GetMainMenuChoice("Please enter your choice: ");

	return(return_value);
}
