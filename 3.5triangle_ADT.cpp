// Design and implement an ADT that represents a triangle.
//  The data for the ADT should include the three sides of the triangle 
//  but could also include the triangle’s three angles. 
//  This data should be in the private section of the class that implements the ADT.

// Include at least two initialization operations: one that provides default values for the ADT’s data, 
// and another that sets this data to client-supplied values. These operations are the class’s constructors.
//  The ADT also should include operations that look at the values of the ADT’s data; 
//  change the values of the ADT’s data; compute the triangle’s area; 
// and determine whether the triangle is a right triangle, an equilateral triangle, or an isosceles triangle.

/***********************************************************
* This program defines and implements the ADT of the *
* MyTriangle to find triangle’s perimeter, area and checks *
* the triangle sides for equilateral, right and isosceles *
* triangle. *
***********************************************************/
// File name: MyTriangle.h
/*Header file for ADT MyTriangle*/
#ifndef _MyTriangle_h
#define _MyTriangle_h
#include
using namespace std;
//MyTriangle class.
class MyTriangle
{
    //Access specifier.
    private:
        //Declare MyTriangle's sides.
        double myTriangleSide1, myTriangleSide2, myTriangleSide3;
        //Access specifier.
    public:
        /*Default constructor that sets myTriangleSide1, myTriangleSide2, myTriangleSide3 values to
        default values.*/
        MyTriangle();
        /*Overloaded constructor that sets MyRectangles's data members with user values.*/
        MyTriangle(double initSide1, double initSide2, double initSide3);
        //Method to set MyTriangle's sides
        void setMyTriangleSides(double newSide1, double newSide2, double newSide3);
        //Method to get myTriangleSide1.
        double getMyTriangleSide1() const;
        //Method to get myTriangleSide2.
        double getMyTriangleSide2() const;
        //Method to get myTriangleSide3.
        double getMyTriangleSide3() const;
        //Method to find MyTriangle's area.
        double getMyTriangleArea();
        //Method to evaluate MyTriangle's perimeter.
        double getMyTrianglePerimeter();
        //Method returns true if MyTriangle is right.
        bool isMyTriangleRight();
        /*Method returns true if MyTriangle is equilateral.*/
        bool isMyTriangleEquilateral();
        /*Method returns true if MyTriangle is isosceles.*/
        bool isMyTriangleIsosceles();
};
#endif
// Comment
// File name: MyTriangle.cpp
//Include the header file MyTriangle.h
#include "MyTriangle.h"
#include<iostream>
#include<cmath>
using namespace std;
/*Default constructor that sets the MyTriangle's values to default values.*/
MyTriangle::MyTriangle()
{
    //Call method to set the MyTriangle's sides.
    setMyTriangleSides(3.0, 4.0, 5.0);
}
//Parameterized constructor that sets MyTriangle's values to user supplied values.*/
MyTriangle::MyTriangle(double initSide1, double initSide2,
double initSide3)
{
    //Call method to set the MyTriangle's sides.
    setMyTriangleSides(initSide1, initSide2, initSide3);
}

//Method to set the MyTriangle's sides
void MyTriangle::setMyTriangleSides(double newSide1, double
newSide2, double newSide3)
{
    //Check the values using condition.
    if ((newSide1 + newSide2 > newSide3) &&
    (newSide1 + newSide3 > newSide2) &&
    (newSide2 + newSide3 > newSide1))
    {
        //On success of the condition set the values.
        myTriangleSide1 = newSide1;
        myTriangleSide2 = newSide2;
        myTriangleSide3 = newSide3;
    }
    //If the condition fails,
    else
        //Display message.
        cout << "For the passed values, triangle cannot be formed. "<< endl;
}
//Method returns the MyTriangle's myTriangleSide1.
double MyTriangle::getMyTriangleSide1() const
{
    //Return the myTriangleSide1.
    return myTriangleSide1;
}
//Method returns the myTriangleSide2.
double MyTriangle::getMyTriangleSide2() const
{
    //Return the myTriangleSide2.
    return myTriangleSide2;
}
//Method returns the myTriangleSide2.
double MyTriangle::getMyTriangleSide3() const
{
    //Return the myTriangleSide3.
    return myTriangleSide3;
}
//Method to evaluate MyTriangle's area.
double MyTriangle::getMyTriangleArea()
{
    //Find the half perimeter.
    double z = (myTriangleSide1 + myTriangleSide2 +
    myTriangleSide3) / 2;
    //Find myTriArea.
    double myTriArea = sqrt(z * (z - myTriangleSide1) *
    (z – myTriangleSide2) *
    (z - myTriangleSide3));
    //Return the myTriArea.
    return myTriArea;
}
//Method to determine the MyTriangle's perimeter.
double MyTriangle::getMyTrianglePerimeter()
{
    //Find the triMyPerimeter.
    double myTriPerimeter= myTriangleSide1 + myTriangleSide2 + myTriangleSide3;
    //Return the myTriPerimeter value.
    return myTriPerimeter;
}
//Method returns true if MyTriangle is Right.
bool MyTriangle::isMyTriangleRight()
{
    //Calculate the squares of the sides.
    double side1Squared = myTriangleSide1 * myTriangleSide1;
    double side2Squared = myTriangleSide2 * myTriangleSide2;
    double side3Squared = myTriangleSide3 * myTriangleSide3;
    //Check square of myTriangleSide1 is equal to the //squares of other 2 sides.
    if (side1Squared + side2Squared == side3Squared)
        //On condition success, return true.
        return true;
        //Check square of myTriangleSide2 is equal to the //squares of other 2 sides.
    else if (side1Squared + side3Squared == side2Squared)
        //On condition success, return true.
        return true;
        //Check square of myTriangleSide2 is equal to the //squares of other 2 sides.
    else if (side2Squared + side3Squared == side1Squared)
        //On condition success, return true.
        return true;
        //On condition failure, return false.
    return false;
}
//Method returns true if MyTriangle is equilateral.
bool MyTriangle::isMyTriangleEquilateral()
{
    //Check the condition for equilateral.
    if ((myTriangleSide1 == myTriangleSide2) && (myTriangleSide1 == myTriangleSide3) &&
    (myTriangleSide2 == myTriangleSide3))
        //On success
        return true;
        //On failure, return false.
    return false;
}
// Method returns true if MyTriangle is isosceles.
bool MyTriangle::isMyTriangleIsosceles()
{
    //Check the condition for isosceles.
    if ( (myTriangleSide1 == myTriangleSide2) ||
    (myTriangleSide1 == myTriangleSide3) ||
    (myTriangleSide2 == myTriangleSide3))
        //On success
        return true;
        //On failure, return false.
    return false;
}
// Comment
// File name: main.cpp
//Include the MyTriangle.h
#include "MyTriangle.h"
#include<iostream>
#include<cmath>
using namespace std;
//Main
int main()
{
    //Create MyTriangle's object.
    MyTriangle myTri(6,8,10);
    //Call the method to get myTri values.
    cout<<"MyTriangle's values:"<<myTri.isMyTriangleRight<<endl;
    cout<<"side1:"<<myTri.getMyTriangleSide1<<endl;
    cout<<"side2:"<<myTri.getMyTriangleSide2<<endl;
    cout<<"side3:"<<myTri.getMyTriangleSide3<<endl;
    //Call the methods and show the values.
    cout<<"MyTriangle's Area:"<<myTri.getMyTriangleArea<<endl;
    cout<<"MyTriangle's Perimeter:"<<myTri.getMyTrianglePerimeter<<endl;
    //Declare new sides.
    double newSide1, newSide2, newSide3;
    //Prompt the user.
    cout<<"Enter MyTriangle's sides:";
    //Read the new sides.
    cin>>newSide1>>newSide2>>newSide3;
    //Call the method to set the sides.
    myTri.setMyTriangleSides(newSide1, newSide2, newSide3);
    //Call the method to get myTri values.

    cout<<"MyTriangle's values:"<<myTri.isMyTriangleRight<<endl;
    cout<<"side1:"<<myTri.getMyTriangleSide1<<endl;
    cout<<"side2:"<<myTri.getMyTriangleSide2<<endl;
    cout<<"side3:"<<myTri.getMyTriangleSide3<<endl;
    //Call the methods and show the values.
    cout<<"MyTriangle's Area:"<<myTri.getMyTriangleArea<<endl;
    cout<<"MyTriangle's Perimeter:"<<myTri.getMyTrianglePerimeter<<endl;
    //Check the other methods also.
    cout<<"Is MyTriangle isosceless:"<<myTri.isMyTriangleIsosceles<<endl;
    cout<<"Is MyTriangle right:"<<myTri.isMyTriangleRight<<endl;
    cout<<"Is MyTriangle equilateral:"<<myTri.isMyTriangleEquilateral<<endl;
    //Pause the output.
    system("pause");
    return 0;
}
// Comment
// Sample Output:
// MyTriangle's values:
// side1:6
// side2:8
// side3:10
// MyTriangle's Area:24
// MyTriangle's Perimeter:24
// Enter MyTriangle's sides:12 5 13
// MyTriangle's values:
// side1:12
// side2:5
// side3:13
// MyTriangle's Area:30
// MyTriangle's Perimeter:30
// Is MyTriangle isosceless:0
// Is MyTriangle right:1
// Is MyTriangle equilateral:0
