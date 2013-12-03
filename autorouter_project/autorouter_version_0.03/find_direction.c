//include project header
#include "project.h"

int find_direction(void){
	//declare variables
	int delta_x, delta_y, delta_z;
	int ret_val = 1;

	//calculate the direction
	delta_x = point_a[0] - point_b[0];
	delta_y = point_a[1] - point_b[1];
	delta_z = point_a[2] - point_b[2];
	printf("Delta X = %d\n", delta_x);
	printf("Delta Y = %d\n", delta_y);
	printf("Delta Z = %d\n", delta_z);

	if(delta_x < 0){
	}

	//return
	return(ret_val);
}
