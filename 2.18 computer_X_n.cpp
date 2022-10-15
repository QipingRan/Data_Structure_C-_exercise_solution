// This problem considers several ways to compute xn for some n ≥ 0.
// Write an iterative function power1 to compute xn for n ≥ 0.
// Write a recursive function power2 to compute xn by using the following recursive formulation:
// x0=1xn=x×xn−1 if n>0
// Write a recursive function power3 to compute xn by using the following recursive formulation:
// x0=1xn=(xn/2)2 if n>0 and n is evenxn=x×(xn/2)2 if n>0 and n is odd
// How many multiplications will each of the functions power1, power2, and power3 perform 
// when computing 332? 319?
// How many recursive calls will power2 and power3 make when computing 332? 319?
// Complete program is as follows:
// The following program demonstrates the functionality of the Iterative function “power1()”:
//Include Header files
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


#include<iostream>
using namespace std;
//define the function power2 to calculate x power n
double power2(double x, int n)
{
    //Implements a base case
    if (n == 0)
        //return 1
        return 1;
        // else statement
    else
        /*calls the function recursively to calculate power*/
        return x * power2(x, n-1);
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
    //print the result by calling power2 function
    cout<<"x^n:"<<power2(x, n)<<endl;
    //To pause the console window
    system("pause");
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Enter the value of x:
// 1.4
// Enter the value of n:
// 3
// x^n:2.744

// Complete program is as follows:
// The following program demonstrates the functionality of the recursive function “power3()”:
//Include Header files
#include<iostream>
using namespace std;
//define the function power3 to calculate x power n
double power3(double x, int n)
{
    //if the value of n is equal to 0
    if (n == 0)
    {
        //return 1
        return 1;
    }
    //else statement
    else
    {
        // perform this calculation only once
        double halfPower = power3(x, n/2);
        //check if the n value is even
        if (n % 2 == 0)
        {
            //calculate power value
            return halfPower * halfPower;
        }
        // check if the n value is odd
        else
        {
            //Calulate power value
            return x * halfPower * halfPower;
        }
    }
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
    //print the result by calling power3 function
    cout<<"x^n:"<<power3( x, n)<<endl;
    //To pause the console window
    system("pause");
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Enter the value of x:
// 1.4
// Enter the value of n:
// 3
// x^n:2.744
