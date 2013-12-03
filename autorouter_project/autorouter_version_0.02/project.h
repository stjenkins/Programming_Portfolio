//header guard
#ifndef PROJECT_H
#define PROJECT_H

//include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_BOARD_SIZE 5

//declare funtions
int split_job(void);
void autorouter(int);

//declare global variables
extern char filename[256];
extern int layer[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
extern int nFiles;

#endif
