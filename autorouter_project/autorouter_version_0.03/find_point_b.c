//include project header
#include "project.h"

int find_point_b(int net){
	//declare variables
	int i,j,k;
	int ret_val = 1;

	//find the point
	for(i = 0; i < MAX_BOARD_X; i++){
		for(j = 0; j < MAX_BOARD_Y; j++){
			for(k = 0; k < MAX_LAYERS; k++){
				if(board[i][j][k] == net && !(point_a[0] == i && point_a[1] == j && point_a[2] == k)){
					point_b[0] = i;
					point_b[1] = j;
					point_b[2] = k;
					ret_val = 0;
				}
			}
		}
	}

	//return
	return(ret_val);
}
