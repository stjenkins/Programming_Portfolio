#include "project.h"

int split_job(){
	int nCores=0;
	int nLines=0;
	int nFiles=0;
	char command[256] = " ";
	FILE* my_file = NULL;
	
	//make a new temporary directory and store some files with
	//information pertinent to this project inside.
	system("mkdir temp");
	system("cd temp");
	system("cat /proc/cpuinfo | grep processor | wc -l >> ./temp/nCores.txt");
	sprintf(command, "cat ");
	strcat(command, filename);
	strcat(command, "|wc -l >> ./temp/nLines.txt");
	system(command);
	
	//get the number of cores that the computer has.
	my_file = fopen("./temp/nCores.txt", "rb");
	if(!my_file){
		printf("CRITICAL ERROR! EXITING NOW...\n");
		exit(1);
	}
	else{
		fscanf(my_file, "%d", &nCores);
		fclose(my_file);
	}
	printf("Number of Cores is: %d\n", nCores);
	
	//get the number of lines in the program to be ran.
	my_file = fopen("./temp/nLines.txt", "rb");
	if(!my_file){
		printf("CRITICAL ERROR! EXITING NOW...\n");
		exit(1);
	}
	else{
		fscanf(my_file, "%d", &nLines);
		fclose(my_file);
	}
	printf("Number of Lines is: %d\n", nLines);
	
	system("rm ./temp/nCores.txt ./temp/nLines.txt");
	
	//put together a command to split the files up.
	sprintf(command, "split -l %d %s ./temp/job", nLines/nCores + 1, filename);
	printf("%s\n", command);
	system(command);
	
	//find the number of files to be operated on...
	system("ls -1 ./temp | wc -l >> ./temp/nFiles.txt");
	my_file = fopen("./temp/nFiles.txt", "rb");
	if(!my_file){
		printf("CRITICAL ERROR! EXITING NOW...\n");
		exit(1);
	}
	else{
		fscanf(my_file, "%d", &nFiles);
		fclose(my_file);
	}
	system("rm ./temp/nFiles.txt");
	
	//account for the nFiles.txt file...
	nFiles--;
	
	//print the number of files for debug purposes.
	printf("Number of Files is: %d\n", nFiles);
	
	//return the number of files.
	return(nFiles);
}
