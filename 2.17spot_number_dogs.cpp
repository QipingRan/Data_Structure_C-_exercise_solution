// Imagine that you have 101 Dalmatians; no two Dalmatians have the same number of spots. Suppose that you create an array of 101 integers: 
// The first integer is the number of spots on the first Dalmatian, the second integer is the number of spots 
// on the second Dalmatian, and so on. Your friend wants to know whether you have a Dalmatian with 99 spots. 
// Thus, you need to determine whether the array contains the integer 99.

// If you plan to use a binary search to look for the 99, what, if anything, would you do to the array 
// before searching it?

// What is the index of the integer in the array that a binary search would examine first?

// If none of your Dalmatians have 99 spots, exactly how many comparisons will a binary search require
//  to determine that 99 is not in the array?

#include<iostream>
using namespace std;
//define the function power1 to calculate x power n
double power1(double x, int n)
{
    //Declare variable and assign value
    double result = 1;
    //Iterate until it reaches the value of n==0
    while(n > 0)
    {
        //Perform power calculation
        result *= x;
        //decrement the value of n
        n--;
    }
    //return result
    return result;
}

//Program begins with a main function
int main()
{
    //declare variable
    double x;
    int n;
    //Prompt the x value from keyboard
    cout<<"Enter the value of x:"<<endl;
    //read x value
    cin>>x;
    //prompt the n value from keyboard
    cout<<"Enter the value of n:"<<endl;
    //read n value
    cin>>n;
    //print the result by calling power1 function
    cout<<"x^n:"<<power1(x, n)<<endl;
    //To pause the console window
    system("pause");
    //return statement
    return 0;
}
