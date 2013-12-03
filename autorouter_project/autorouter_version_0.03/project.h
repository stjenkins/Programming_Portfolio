//declare only once
#ifndef PROJECT_H
//include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define constants
#define MAX_BOARD_X 5
#define MAX_BOARD_Y 5
#define MAX_LAYERS  2
#define MAX_NETLIST 5

//define structures and new types

//declare global variables
int board[MAX_BOARD_X][MAX_BOARD_Y][MAX_LAYERS];
int choices[3][256];
int point_a[3];
int point_b[3];
int direction;
/***************************
*  Notes on direction:
*
*  Direction     Value
*  Forward       0
*  Right         1
*  Back          2
*  Left          3
*  Up            4
*  Down          5
***************************/

//prototype functions
int autorouter(void);
int find_point_a(int);
int find_point_b(int);
int find_direction(void);

#endif
