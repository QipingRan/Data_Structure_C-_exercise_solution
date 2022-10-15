
// Using “ x ” as value argument:
// Program:
//Include Header files
#include<iostream>
using namespace std;
//Define function recurse()
void recurse(int x, int y)
{
    //if y is greater than 0
    if (y > 0)
    {
        //Increment x value
        x++;
        //Decrement y value
        y--;
        //Print the result
        std::cout<< x << " " << y <<endl;
        //Call recurse()
        recurse(x, y);
        //Print the result
        std::cout << x << " " << y << endl;
    }
}
//Program Begins with a main function
int main()
{
//Passing x=5 and y=3 value to the function
    recurse(5, 3);
    system("pause");
    //Return statement
    return 0;
}
// Comment
// Sample Output:
// 6 2
// 7 1
// 8 0
// 8 0
// 7 1
// 6 2

