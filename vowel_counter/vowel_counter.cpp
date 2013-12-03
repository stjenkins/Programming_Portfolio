#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	//declare variables
	ifstream myfile;
	int num_vowels = 0;
	string buffer;

	//check for correct number of arguments
	if(argc != 2){cerr << "Usage is a.out filename.txt\n"; return -1;}

	//open file and check if the file sucessfully opened
	myfile.open(argv[1]);
	if(!myfile.is_open()){cerr << "File failed to open.\n"; return -1;}

	//read the characters out and check if they're vowels.
	while(getline(myfile, buffer)){
		for(int i = 0; i < buffer.size(); i++){
			switch(buffer.at(i)){
				case 'A': num_vowels ++; break;
				case 'a': num_vowels ++; break;
				case 'E': num_vowels ++; break;
				case 'e': num_vowels ++; break;
				case 'I': num_vowels ++; break;
				case 'i': num_vowels ++; break;
				case 'O': num_vowels ++; break;
				case 'o': num_vowels ++; break;
				case 'U': num_vowels ++; break;
				case 'u': num_vowels ++; break;
				default: break;
			}
		}
	}

	//print out the number of vowels
	cout << num_vowels << endl;

	//do clean-up procedures and return control back to the OS
	myfile.close();
	return num_vowels;
}
