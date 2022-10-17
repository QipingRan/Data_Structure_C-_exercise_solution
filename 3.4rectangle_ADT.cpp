// Design and implement an ADT that represents a rectangle.
//  Include typical operations, such as setting and retrieving the dimensions of the rectangle, 
// and finding the area and the perimeter of the rectangle.



/***********************************************************
* This program defines and implements the ADT of the *
* MyRectangle to find rectangle’s perimeter and area. *
***********************************************************/
// File name: MyRectangle.h
/*Header file for class MyRectangle*/
#ifndef _MyRectangle_h
#define _MyRectangle_h
//MyRectangle class
class MyRectangle
{
    //Access specifier.
    private:
    //Declare myRectangleLength.
    double myRectangleLength;
    //Declare myRectangleWidth.
    double myRectangleWidth;
    //Access specifier.
    public:
    //Default constructor.
    MyRectangle();
    //Overloaded constructor.
    MyRectangle(double initLength, double initWidth);
    // Method to set myRectangleLength to newLength.
    void setRectangleLength(double newLength);
    // Method to set myRectangleWidth to newWidt.
    void setRectangleWidth(double newWidt);
    //Method to get myRectangleLength.
    double getRectangleLength();
    //Method to get myRectangleWidth.
    double getRectangleWidth();
    //Method to find the area of MyRectangle.
     double getRectangleArea();
    /*Method to determine the perimeter of the MyRectangle.*/
    double getRectanglePerimeter();
};
#endif
// Comment
// File name: MyRectangle.cpp
//Include the header file MyRectangle.h
#include "MyRectangle.h"
/*Default constructor to set myRectangleLength, myRectangleWidth to default values.*/
MyRectangle::MyRectangle()
{
    //Call the method to set the myRectangleLength.
    setRectangleLength(1.0);
    //Call the method to set the myRectangleWidth.
    setRectangleWidth(1.0);
}
/*Overloaded constructor to set the myRectangleLength and myRectangleWidth to user values.*/
MyRectangle::MyRectangle(double initLength, double initWidth)
{
    //Call the method to set the myRectangleLength.
    setRectangleLength(initLength);
    //Call the method to set the myRectangleWidth.
    setRectangleWidth(initWidth);
}
//Function to set the myRectangleLength.
void MyRectangle::setRectangleLength(double newLength)
{
    //Check newLength.
    if (newLength > 0.0)
    //On success, set myRectangleLength to newLength.
    myRectangleLength = newLength;
}
//Function that sets myRectangleWidth to newWidt.
void MyRectangle::setRectangleWidth(double newWidt)
{
    //Check newWidt > 0.
    if (newWidt > 0.0)
    /*On condition success, set myRectangleWidth to newWidt.*/
    myRectangleWidth = newWidt;
}
//Method to get the myRectangleLength.
double MyRectangle::getRectangleLength()
{
    //Return the myRectangleLength.
    return myRectangleLength;
}
//Method to get the myRectangleWidth.
double MyRectangle::getRectangleWidth()
{
    //Return the myRectangleWidth.
    return myRectangleWidth;
}

//Function to find the MyRectangle's area.
double MyRectangle::getRectangleArea()
{
    /*Calculate myRectangArea by multiplying myRectangleLength with myRectangleWidth.*/
    double myRectangArea = myRectangleLength * myRectangleWidth;
    //Return the myRectangArea.
    return myRectangArea;
}
/*Function to calculate the MyRectangle's perimeter and return it.*/
double MyRectangle::getRectanglePerimeter()
{
    /*Calculate the myRectanglePerimeter */
    double myRectanglePerimeter = 2 * (myRectangleLength + myRectangleWidth);
    //Return the myRectanglePerimeter.
    return myRectanglePerimeter;
}
// Comment
// File name: main.cpp
//Include the MyRectangle.h
#include "MyRectangle.h"
#include<iostream>
#include<cmath>
using namespace std;
//Main
int main()
{
    //Create MyRectangle's object.
    MyRectangle myRec;
    //Declare newLen, newWidth.
    double newLen, newWidth;
    //Prompt the user.
    cout<<"Enter MyRectangle's length, width:";
    //Read the newLen, newWidth values.
    cin>>newLen>>newWidth;
    //Call the method to set the length.
    myRec.setRectangleLength(newLen);
    //Call the method to set the width.
    myRec.setRectangleWidth(newWidth);
    //Display message.
    cout<<"MyRectangle's Area:"<<myRec.getRectangleArea<<endl;
    cout<<"MyRectangle's Perimeter:"<<myRec.getRectanglePerimeter<<endl;
    //Pause the output.
    system("pause");
    return 0;
}
// Comment
// Sample Output:
// Enter MyRectangle's length, width:10 5.5
// MyRectangle's Area:55
// MyRectangle's Perimeter:31
