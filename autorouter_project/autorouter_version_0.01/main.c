#include "project.h"

//define the array for the board
int layer[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//define a variable to store the open filename
char filename[256]=" ";

int main(void){
	//variable declarations
	int counter;
	int counter_2;
	int nFiles = 0;
	FILE* my_file=NULL;
	
	//display program name and purpose
	system("clear");
	printf("Autorouter Application\n");
	
	//display the board
	layer[0][0]=1;
	layer[2][2]=1;
	for(counter=0; counter < 5; counter ++){
		for(counter_2=0; counter_2 < 5; counter_2 ++){
			printf("%d\t", layer[counter][counter_2]);
		}
		printf("\n");
	}
	
	//open a board...
	printf("Type in the full path to the file you want to route:\n");
	fgets(filename, 255, stdin);
	filename[strlen(filename)-1]='\0';
	if(strlen(filename)<3){
		printf("ERROR!\n");
	}
	else if(filename[0]==' '){
		printf("ERROR!\n");
	}
	
	//split the job up into several different pieces...
	nFiles=split_job();
	
	//call the autorouter algorithm.
}
