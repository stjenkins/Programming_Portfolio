/**********************************
*	autorouter.c
*
*	Performs the autorouting task
*	that is desired.
*
*	by Stephen Jenkins (c) 2013
*
************************************/

//include the project header
#include "project.h"

//define the function
int autorouter(void){
	//define variables
	int net = 1;
	int ret_val = 1;

	//show function name
	printf("Autorouting...\n");

	//find the point with the current netvalue
	if(find_point_a(net)) printf("NO NETS FOUND\n");
	else printf("Point A is (%d, %d, %d)\n", point_a[0], point_a[1], point_a[2]);

	//find another point with the same netvalue
	if(find_point_b(net)) printf("NO NETS FOUND\n");
	else printf("Point B is (%d, %d, %d)\n", point_b[0], point_b[1], point_b[2]);

	//find the direction
	if(find_direction()) printf("ERROR FINDING DIRECTION!\n");
	else{
		switch(direction){
		}
	}

	//return
	return(ret_val);
}
