// Consider the following recursive definition:
// Acker(m, n)={n+1if m=0Acker(m−1, 1)if n=0Acker(m−1, Acker(m,n−1))otherwise
// This function, called Ackermann’s function, is of interest
// because it grows rapidly with respect to the sizes of m and n.
//  What is Acker(1, 2)? Implement the function in C++ and do a box trace of Acker(1, 2).
//  (Caution: Even for modest values of m and n, Ackermann’s function requires many recursive calls.)


//Include Header files.
#include<iostream>
using namespace std;
//Define a function Acker.
int Acker(int m, int n)
{
    //Declare a variable.
    int resultVal;
    //If m is equal to 0.
    if (m == 0)
        //Assign n+1 as result value.
        resultVal = n+1;
        //if n value is equal to 0.
    else if (n == 0)
        //Recursively call the result value.
        resultVal = Acker(m-1, 1);
        //Otherwise
    else
        //Recursively call the result value.
        resultVal = Acker(m-1, Acker(m, n-1));
        //Return the result value.
    return resultVal;
}
//Program begins with a main function
int main()
{
    //Statement to print Answer.
    cout<<"Answer:"<<Acker(4,0)<<endl;
    //To pause console window.
    system("pause");
    //Return statement.
    return 0;
}
// Sample Output:
// Answer:4
