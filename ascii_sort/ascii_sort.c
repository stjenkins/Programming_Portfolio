/**************************************************************
*	ASCII Sorter
*
*	Sorts a string into ascending ascii code order.
*
*	Stephen Jenkins (c) 2012
*
*************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	//define the variables
	char continue_prompt = ' ';
	char user_input[256] = " ";
	char buffer[256] = " ";
	int i = 0;
	int j = 0;
	int counter = 1;

	//do the beginning pleasentries
	system("clear");
	printf("ASCII Sorter\n\n");
	printf("Takes a user defined string and sorts it\n");
	printf("into ascending ASCII values.\n");
	printf("Stephen Jenkins (c) 2012)\n\n");

	//ask the user for a confirmation to continue	
	printf("\nDo you wish to continue? (Y/n): ");
	continue_prompt = getchar();
	if(tolower(continue_prompt) == 'n') exit(0);
	else if(tolower(continue_prompt) != 'y') main();

	//clear the input buffer
	continue_prompt = ' ';
	while((continue_prompt = getchar()) != '\n' && continue_prompt != EOF);
	
	//prompt the user with clear instructions for a string of size
	//<256 for processing...
	printf("\nEnter a string to be sorted: ");
	fgets(user_input, 256, stdin);
	printf("\nYou typed in: \n%s\n", user_input);

	//load the buffer with a magical ascending ascii order
	for(counter = 1; counter < 256; counter ++){
		i = 0;
		while(user_input[i]){
			if(user_input[i] == counter) {
				buffer[j] = user_input[i];
				j++;
			}
			i++;
		}
	}

	printf("The result is: %s\n", buffer);

	//prompt the user if they want to run the program a second time
	while(continue_prompt != 'n'){
		printf("\nDo you wish to quit? (Y/n) ");
		continue_prompt=getchar();
		if(tolower(continue_prompt) == 'y') exit(0);
	}
	
	//good, you answered no! I knew you liked me! :P
	//but seriously, we got some work to do before the program can
	//start again.... we gotta start by clearing the buffers.... :(
	continue_prompt = ' ';
	while((continue_prompt = getchar()) != '\n' && continue_prompt != EOF);

	//and now we restart the program! :)
	main();
}
