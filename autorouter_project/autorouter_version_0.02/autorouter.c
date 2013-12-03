#include "project.h"

void autorouter(int piece){
	//define variables
	int points[MAX_BOARD_SIZE*MAX_BOARD_SIZE/nFiles];
	int counter = 0;
	int counter_2 = 0;
	int counter_3 = 0;
	int offset = 0;

	//calculate the offset position
	offset=piece*((MAX_BOARD_SIZE/nFiles)+1);
	printf("%d\n", offset);

	//print the functions purpose
	printf("Autorouter Function\n");
	printf("Press enter to continue...\n");
	getchar();
	
	//populate the array with the coordinates of similar nets.
	printf("%d\n", ((MAX_BOARD_SIZE*MAX_BOARD_SIZE/nFiles)/MAX_BOARD_SIZE)+1);
	for(counter=0; counter<((MAX_BOARD_SIZE*MAX_BOARD_SIZE/nFiles)/MAX_BOARD_SIZE)+1; counter++){
		for(counter_2=offset; counter_2<MAX_BOARD_SIZE; counter_2++){
			points[counter_3]=layer[counter][counter_2];
			counter_3++;
		}
	}

	//display points for debug purposes.
	counter_3=0;
	for(counter=0; counter<((MAX_BOARD_SIZE*MAX_BOARD_SIZE/nFiles)/MAX_BOARD_SIZE)+1; counter++){
		for(counter_2=0; counter_2<MAX_BOARD_SIZE; counter_2++){
			printf("%d\t", points[counter_3]);
			counter_3++;
		}
		printf("\n");
	}
}
