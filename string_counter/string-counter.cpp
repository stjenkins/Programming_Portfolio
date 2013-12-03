#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int string_counter(string&, string&);

int main(int argc, char* argv[]){
	//declare variables
        ifstream myfile;
        string buffer;
	string search;

        //check for correct number of arguments
        if(argc != 3){cerr << "Usage is a.out filename.txt search_string\n"; return -1;}

        //open file and check if the file sucessfully opened
        myfile.open(argv[1]);
        if(!myfile.is_open()){cerr << "File failed to open.\n"; return -1;}

	if(!myfile.eof()) do{
		//get the string we're searching from the file
		getline(myfile, buffer);
		
		//initialize search string with data from command line
		search=argv[2];
		
		//call my string search counter function
		string_counter(buffer,search);
	}while(!myfile.eof());

	return 0;
}

int string_counter(string& input_string, string& search_string){
	int counter=0;
	size_t next = 0;
	size_t pos = 0;
	int length=search_string.length();

	do{
		next=input_string.find(search_string, pos);
		if(next==0)pos+=length;
		else pos=next+length;
		if(next!=string::npos)counter++;
	}while(next!=string::npos);

	cout << "The search string was found " << counter << " times in the provided string." << endl;

	return 0;
}
