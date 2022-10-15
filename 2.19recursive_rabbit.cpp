// Modify the recursive rabbit function so that it is visually easy to follow the flow of execution.
// Instead of just adding “Enter” and “Leave” messages, indent the trace messages according
// to how “deep” the current recursive call is. For example, the call rabbit(4) should
// produce the output

// Enter rabbit: n = 4
//     Enter rabbit: n = 3
//        Enter rabbit: n = 2
//        Leave rabbit: n = 2 value = 1
//        Enter rabbit: n = 1
//        Leave rabbit: n = 1 value = 1
//     Leave rabbit: n = 3 value = 2
//     Enter rabbit: n = 2
//     Leave rabbit: n = 2 value = 1
// Leave rabbit: n = 4 value = 3


// The function that is included to the code is highlighted in grey colour.
// Program:
//Include Header files.
#include<iostream>
#include<string>
using namespace std;
//Function Prototype.
int rabbit(int n, int TabSpace);
//Program Begins with a main function.
int main()
{
    //Call the rabbit() function.
    rabbit(5, 0);
    //To pause the result.
    cin.get();cin.get();
    //Return 0
    return 0;
}

//Define the rabbit() function.
int rabbit(int n, int TabSpace)
{
    //Declare a variable.
    int value;
    //Use a for loop to print indented result.
    for(int it = 0; it < TabSpace; it++)
    {
        //Print a statement.
        cout << " ";
    }
    //Print a statement.
    cout << "Enter rabbit: n = " << n << endl;
    //If n is lesser than equal to 2.
    if(n <=2)
    {
        //Assign the value is 1.
        value = 1;
    }
    //else statement.
    else
    {
        //Recursively call the Rabbit function.
        value = rabbit(n - 1, TabSpace + 1) + rabbit(n - 2, TabSpace + 1);
    }
    //Use a for loop to print the indented result.
    for(int it = 0; it < TabSpace; it++)
    {
        //Print a statement.
        cout << " ";
    }
    //Print a statement.
    cout << "Leave rabbit: n = " << n << " value = " << value << endl;
    //Return statement.
    return value;
}
// Comment
// Sample Output:
// Enter rabbit: n = 4
// Enter rabbit: n = 3
// Enter rabbit: n = 2
// Leave rabbit: n = 2 value = 1
// Enter rabbit: n = 1
// Leave rabbit: n = 1 value = 1
// Leave rabbit: n = 3 value = 2
// Enter rabbit: n = 2
// Leave rabbit: n = 2 value = 1
// Leave rabbit: n = 4 value = 3
