/**************************************************************************************************
*
*	File: project.h
*
*	Author: Samuel Horst
*
*	Date: November 6, 2012
*
*	Purpose: Define constants, typedefs, and protype functions.
*
*	Copyright (c) Samuel Horst, 2012
*
**************************************************************************************************/

#ifndef PROJECT_H
	
	#define PROJECT_H
	#define TRUE -1
	#define FALSE 0

	#include "stdio.h"
	#include "string.h"
	#include "stdlib.h"

	struct RECORD
	{
		char number[17];
		char title[65];
		int	credit;
		int lab;
		struct RECORD* next;
		struct RECORD* previous;
	};
	
	typedef struct RECORD COURSE;
	typedef int BOOLEAN;

	void Header(void);
	void GetEnter(void);
	void NewDat(void);

	void OpenData(void);
	void AddRec(void);
	void SearchData(void);
	void BrowseData(void);
	void EditRec(COURSE*);
	void DeleteRec(COURSE*);
	void CloseData(void);
	BOOLEAN QuitProgram(void);

	char DisplayMainMenu(void);
	char GetMainMenuChoice(char*);

	void InitializeRec(COURSE*);

	void GetNumber(COURSE*);
	void GetTitle(COURSE*);
	void GetCredit(COURSE*);
	void GetLab(COURSE*);

	void WriteRec(COURSE*);
	void ReadRec(COURSE*);
	void DisplayRec(COURSE*);

	void LinkRec(COURSE*);
	void UnlinkRec(COURSE*);

	extern COURSE array[255];
	extern COURSE* FIRST;
	extern COURSE* LAST;
	extern char filename[255];

#endif

