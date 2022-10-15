// Write a recursive C++ function writeLine that writes a character repeatedly
//  to form a line of n characters. For example, writeLine('*', 5) produces the line *****.

// Now write a recursive function writeBlock that uses writeLine to write m lines of n characters each.
// For example, writeBlock('*', 5, 3) produces the output

// *****

// *****

// *****


// Complete program is as follows:
// The following program demonstrates the functionality of the recursive function “writeLine()”:
//Include Header files
//#include<iostream>
//using namespace std;
////Defines the function writeLine()
//void writeLine(char chr, int n)
//{
//    //If the n value is lesser than 0
//    if (n <= 0)
//    {
//        //Prints a empty line
//        cout << endl;
//    }
//    //else statement
//    else
//    {
//        //Prints the chr
//        cout << chr;
//        //calls the function writeLine recursively
//        writeLine(chr, n - 1);
//    }
//}
////Program begins with the main function
//int main()
//{
//    //Statement to print
//    cout<<"Line of n characters"<<endl;
//    //calls the writeLine() passing parameters
//    writeLine('*',5);
//    //To pause the console window
//    system("pause");
//    //return statement
//    return 0;
//}
// Comment
// Sample Output:
// Line of n characters
// *****

// Complete program is as follows:
// The following program demonstrates the functionality of the recursive function “writeLine()”:
//Include Header files
#include<iostream>
using namespace std;
//Defines the function writeLine()
void writeLine(char chr, int n)
{
    //If the n value is lesser than 0
    if (n <= 0)
    {
        //Prints a empty line
        cout << endl;
    }
    //else statement
    else
    {
        //Prints the chr
        cout << chr;
        //calls the function writeLine recursively
        writeLine(chr, n - 1);
    }
}
//Define the writeBlock() function to print m lines of n characters
void writeBlock(char ch, int n,int m)
{
    //if the m value is greater than 0
    if (m > 0)
    {
        /*calls the writeLine function to write the first line*/
        writeLine(ch, n);
        //calls the writeBlock() recursively
        writeBlock(ch,n,m-1);
    }
    else
    {
        //do nothing
        cout<<endl;
    }
}
//Program begins with the main function
int main()
{
    cout<<"Line of n characters"<<endl;

    //calls the writeLine() passing parameters
    writeBlock(' *' , 5, 3);
    //To pause the console window

    system("pause");
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Line of n characters
// *****
// *****
// *****
