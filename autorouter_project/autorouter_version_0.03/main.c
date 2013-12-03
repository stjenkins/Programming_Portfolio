/**************************************
*	main.c
*	defines the programs main function
*	that basically just calls all the
*	other functions in the right
*	order.
*
*	by Stephen Jenkins (c) 2013
*
**************************************/

//include project header file
#include "project.h"

//define main
int main(void){
	//define variables
	int i,j,k;

	//print out program purpose
	system("clear");
	printf("Autorouter Version 0.03\n");
	printf("by Stephen Jenkins\n");

	//open the board
	for(i=0; i<MAX_BOARD_X; i++){
		for(j=0; j<MAX_BOARD_Y; j++){
			for(k=0; k<MAX_LAYERS; k++){
				board[i][j][k]=0;
			}
		}
	}
	board[1][0][0] = 1;
	board[3][1][2] = 1;

	//call autorouter
	if(autorouter()) printf("ROUTING ERROR!\n");

	//return with no errors
	return(0);
}
