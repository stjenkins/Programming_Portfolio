/****************************************************
*	Array Editor
*
*	Stephen Jenkins (c) 2012
*
*	Allows the user to enter in 10 floating point
*`	numbers into an array and then stores the result
*	in the array. User is allowed to exit with the
*	enter key when no input has been entered.
*
****************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){
	//declare the variables to be used
	double array_to_be_edited[10];
	int counter;
	int counter_2;
	double temp;
	char continue_prompt;
	char buffer[256];
	double minimum;

	//make the screen look pretty and also display the
	//program name and purpose.
	system("clear");
	printf("Array Editor\nStephen Jenkins");
	
	while(tolower(continue_prompt) != 'y'){
		printf("\nDo you wish to continue? (y/n): ");
		continue_prompt = getchar();
		if(tolower(continue_prompt) == 'n')exit(0);
	}
	
	//clear the input buffer
	continue_prompt = ' ';
	while((continue_prompt = getchar()) != '\n' && continue_prompt != EOF);

	for(counter = 0; counter < 10; counter++){
		//prompt the user
		printf("\nArray element %d or enter to quit: ", counter);
		//scan for a string
		fgets(buffer, 256, stdin);
		//check for enter
		if(buffer[0] == '\n') counter = 10;
		//get a double out of the user input
		sscanf(buffer, "%lf", &array_to_be_edited[counter]);
		//echo back to the user
		printf("\nYou entered: %lf\n", array_to_be_edited[counter]);
	}

	//print out the array
	for(counter = 0; counter < 10; counter++){
		printf("\nArray Element %d = %lf", counter, array_to_be_edited[counter]);
	}

	//sort the array in descending order
	for(counter_2 = 0; counter_2 < 10; counter_2++){
		for(counter = 0; counter < 10; counter ++){
			if(array_to_be_edited[counter] < array_to_be_edited[counter+1]){
				temp = array_to_be_edited[counter];
				array_to_be_edited[counter] = array_to_be_edited[counter+1];
				array_to_be_edited[counter+1] = temp;
			}
		}
		if(array_to_be_edited[9] > array_to_be_edited[0]){
			temp = array_to_be_edited[9];
			array_to_be_edited[9] = array_to_be_edited[0];
			array_to_be_edited[0] = temp;
		}
	}
		
	//print out the minimum
	printf("\n\nMinimum = %lf\n", array_to_be_edited[9]);

	//print out the maximum
	printf("Maximum = %lf\n", array_to_be_edited[0]);

	//calculate the average value of the array
	temp = 0;
	for(counter = 0; counter < 10; counter++){
		temp = temp + array_to_be_edited[counter];
	}
	printf("Average = %.3lf\n", temp/10);

	printf("\n");
}
