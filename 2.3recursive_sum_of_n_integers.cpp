// Write a recursive function that will compute the sum of the first n integers 
// in an array of at least n integers. 
// Hint: Begin with the nth integer.


ComputeRecursiveSum() Function:
//Recursive function ComputeRecursiveSum()
int ComputeRecursiveSum(const int ArrayValue[], int n)
{
    //If the n value is lesser than 0 return 0
    if (n <= 0)
        //return statement returns 0
        return 0;
        //else statement
    else
        /*otherwise call the ComputeRecursiveSum()
        recursively to calculate sum*/
        return ArrayValue[n-1] + ComputeRecursiveSum( ArrayValue, n - 1);
}

//Include Header files
#include<iostream>
using namespace std;
//Function Prototype ComputeRecursiveSum()
int ComputeRecursiveSum(const int ArrayValue[],int n);
/*define the function ComputeRecursiveSum() by taking parameters*/
//Program begins with main function
int main()
{
    //Declare n variable and initialize the value as 5
    int n=5;
    //Declare the variable arr include 5 values
    int arr[5]={2,3,4,5,6};
    //call the ComputeRecursiveSum() recursive function
    cout<<"Sum:"<<ComputeRecursiveSum(arr);
    // To pause the console window
    system("pause");
    //Return statement
    return 0;
}
