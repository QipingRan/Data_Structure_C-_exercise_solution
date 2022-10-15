// Consider the following recurrence relation:


// f(1)=1; f(2)=1; f(3)=1; f(4)=3; f(5)=5;f(n)=f(n−1)+3×f(n−5) for all n>5.
// Compute f (n) for the following values of n: 6, 7, 12, 15.

// If you were careful, rather than computing f (15) from scratch (the way
// a recursive C++ function would compute it),
// you would have computed f (6), then f (7), then f (8), and so on up to f(15),
// recording the values as you computed them. This ordering would have saved you the effort of
// ever computing the same value more than once. (Recall the iterative version of the rabbit function
//  discussed at the end of this chapter.)

// Note that during the computation, you never need to remember all of the previously computed values—only
// the last five. Taking advantage of these observations, write a C++ function that computes f (n)
// for arbitrary values of n.

// Complete program is as follows:
// The following program demonstrates the functionality of the recursive function “f_Of_n()”:
//Include Header files
#include<iostream>
using namespace std;
//define a function f_Of_n()
int f_Of_n(int n)
{
    //Declare the last 5 values
    int lastFiveValues[5] = {1, 1, 1, 3, 5};
    //Use loop to compute the next values when n>5
    for (int it = 5; it < n; it++)
    {
        /*compute the function f(n-1)+3*f(n-5) which is calculated for 5 values*/
        int fi = lastFiveValues[(it - 1) % 5] + 3 * lastFiveValues[(it - 5) % 5];
        /*Replace the last 5 entries f(i) = f(i - 1) + 3 x f(i - 5)*/
        lastFiveValues[it % 5] = fi;
    }
    //return the next value
    return lastFiveValues[(n - 1) % 5];
}
//Program starts with main
int main()
{
    //Print result statement
    cout<<"Result: "<<endl;
    //Print the result by calling the function
    cout<<"f(15)="<<f_Of_n(16)<<endl;
    //pause the output
    cin.get();cin.get();
    //return 0
    return 0;
}

// Sample Output:
// Result:
// f(15)=320
