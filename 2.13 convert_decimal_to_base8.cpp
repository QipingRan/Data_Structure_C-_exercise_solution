// Consider the following function that converts a positive decimal number to base 8 and displays the result.

#include<iostream>
using namespace std;
void displayOctal(int n)
{
   if (n > 0)
   {
      if (n / 8 > 0)
         displayOctal(n / 8);
      std::cout << n % 8;
   }  // end if
}  // end displayOctal

int main(){
    displayOctal(100);
    return 0;

}
