// Given two integers, start and end, where end is greater than start, 
// write a recursive C++ function that returns the sum of the integers from start through end, inclusive.


//Include header files
#include<iostream>
using namespace std;
/*define the Function StartEndSum() which inclusively calculates the sum*/
int StartEndSum (int start, int end )
{
    /*if the start value is greater than end then return 0*/
    if (start > end)
        //returns 0
        return 0;
        //else statement
    else
        /*Calculate the sum by recursively calling the StartEndSum()*/
        return start + StartEndSum(start + 1, end);
}
//Program starts with the main
int main()
{
    //Declare variables
    int start;
    int end;
    //Prompt and input the start value from keyboard
    cout<<"Enter the start Value:"<
    //Getting start value
    cin>>start;
    //Prompt and input the end value from keyboard
    cout<<"Enter the end Value:"<
    //Get the end Value
    cin>>end;
    /*Prints sum of start and end by calling the recursive function StartEndSum()*/
    cout<<"Sum:"<
    //To pause the console window
    system("pause");
    //return statement
    return 0;
}
// Sample Output:
// Enter the Start Value:
// 5
// Enter the End Value:
// 10
// Sum:45
// Press any key to continue . . .
// Comment
// 0 0