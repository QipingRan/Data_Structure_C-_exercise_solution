// Write a recursive C++ function that writes the digits of a positive decimal integer in reverse order.

// Complete program is as follows:
// The following program demonstrates the functionality of the recursive function
// “ReverseDecimalDigits()”:
//Include the Header files
#include<iostream>
using namespace std;
//Declares the Global variable assigns 10 as base
const int DECIMAL_BASE = 10;
//Defines the function ReverseDecimalDigits to reverse the digits
void ReverseDecimalDigits(int DecimalDigit)
{
    //if the decimal digit greater than 0
    if (DecimalDigit >= 0)
    {
        //check the base value
        if (DecimalDigit < DECIMAL_BASE)
            //print the decimal digit
            cout << DecimalDigit;
            //else statement
        else
        {
            //prints the digit
            cout << DecimalDigit % DECIMAL_BASE;
            /*calls the ReverseDecimalDigits() to reverse the digits*/
            ReverseDecimalDigits(DecimalDigit / DECIMAL_BASE);
        }
    }
}
//program starts with a main function
int main()
{
    //declare the variable
    int DecimalDigit;
    //Prompt and read the decimal digit from keyboard
    cout<<"Enter the digits of a Positive Decimal"
    <<"Integer:"<<"";
    return 0;
}

