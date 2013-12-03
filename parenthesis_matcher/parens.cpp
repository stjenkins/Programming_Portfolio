/********************************************
 *          Parenthesis Error Checker
 *          by Stephen Jenkins
 *
 *          Uses a stack class to determine
 *          whether or not a parenthesis has
 *          a closing parenethesis or not.
 *
 *******************************************/

//Include our necessary libraries.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Stack.h"

//start the program
int main(int argc, char** argv){
    //check for corrent argument count
    if(argc!=2){
        cerr<<"ERROR: Usage parens file.txt"<<endl;
        exit(0);
    }

    //declare some varibles
    int count=0;
    ifstream inf;
    char ch;
    int line=0;

    //open the file.
    inf.open(argv[1]);

    //setup the mode to include white space.
    inf >> noskipws;

    //This is the seemingly logical easy way to solve the problem
    //most of the time. However, this method will fail to
    //catch when this kind of thing happens: "a) bc( d"
    //and so this is garbage. So therefore, I'm going to
    //implement a stack method below it.
    cout << "\n\n\n\n\nHere is my non-stack method. Notice\n"
        << "how it gives the correct answer for\n"
        << "the test file Dr. Lee provided. Had\n"
        << "he included a case such as \"a) bc( d\"\n"
        << "then students would have seen a stack\n"
        << "is necessary.\n";
    do
    {
        //increment the line counter.
        line++;

        //reset the parenthesis counter.
        count = 0;

        //get the first character of the new line.
        inf >> ch;

        //if the first character was a newline, break.
        if(ch == '\n') break;

        //display the information about which line we're on.
        cout << "Line " << line << ": ";

        while (ch != '\n')
        {
            if (ch == '(')
                count++;
            else if (ch == ')')
                count--;
            inf >> ch;
        }

        //Output the results from the while loop.
        if (count < 0) cout << abs(count) << " extra right parenthesis.\n";
        else if (count > 0) cout << count << " extra left parenthesis.\n";
        else cout << "Evenly matched parenthesis.\n";
    }while(!inf.eof());
    inf.close();
    //End no stack method.


    //Here begins my stack method.
    cout<<"\n\nFrom here to the end of the program, I utilize\n"
        <<"the provided stack class. This allows me to detect\n"
        <<"this special condition, although it adds a lot of\n"
        <<"extra program complexity. For most applications,\n"
        <<"the first method is going to be just fine. This\n"
        <<"is a relatively exhaustive method.\n";
    inf.open(argv[1]);//open a file
    inf >> noskipws;
    //Declare a stack.
    Stack buffer;
    //reset my counters
    line=0;
    count=0;
    //make two new counters for mismatched right and left.
    int left = 0;
    int right = 0;
    int mismatch_left=0;
    int mismatch_right=0;
    while(!inf.eof()){
        //increment the line counter
        line++;
        //reset the parenethesis counter.
        count=0;
        right=0;
        left=0;
        mismatch_left=0;
        mismatch_right=0;
        //read in the first character of the line.
        inf >> ch;
        //if the first character of the line was newline, break;
        if(ch=='\n') break;
        //look through a line
        while(ch != '\n')
        {
            if (ch == '(')
                buffer.push('(');
            else if (ch == ')')
                buffer.push(')');
            inf >> ch;
        }
        //check the stack for mismatched parenthesis.
        while(!buffer.empty()){
            while(!buffer.empty()&&buffer.top()==41){
                right++;
                left--;
                count++;
                buffer.pop();
            }
            while(!buffer.empty()&&buffer.top()==40){
                if(count==0||right<=0)mismatch_left++;
                left++;
                right--;
                count++;
                buffer.pop();
            }
        }
        //This is a crazy hack here. I don't know why it
        //works, but it does
        if(abs(right)!=left&&!mismatch_left)mismatch_right=abs(right);
        else if(abs(left)!=right&&right==left){
            mismatch_right=mismatch_left;
        }
        else if(abs(left)!=right){
            mismatch_left=left;
            mismatch_right=0;
        }
        if(left==0 && right==0)mismatch_right=mismatch_left;
        //display what we found.
        if(mismatch_right||mismatch_left)
            cout<<"Line "<<line<<": "<<mismatch_right<<" Extra right parenthesis and "
            <<mismatch_left<<" Extra left parenethesis.\n";
        else cout<<"Line "<<line<<": Evenly matched parenthesis.\n";
    }
    //End of stack method

    //Clean up after oursleves
    inf.close();
    return 0;
}
