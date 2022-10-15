// Consider the following program:
// Show the exact output of the program. What argument values,
// if any, could you pass to the function f to cause the program to run forever?

#include<iostream>
using namespace std;
int f(int n);
int main()
{
   std::cout << "The value of f(8) is " << f(8) << std::endl;
   return  0;
}  // end main

int f(int n)
{
   std::cout << "Function entered with n = " << n << std::endl;
   switch (n)
   {
      case 0: case 1: case 2:
         return n + 1;
      default:
         return f(n−2) * f(n−4);
   }  // end switch
}  // end f
