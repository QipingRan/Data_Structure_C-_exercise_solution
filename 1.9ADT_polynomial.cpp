// Consider the ADT polynomial—in a single variable x—whose operations include the following:

// degree() // Returns the degree of a polynomial. 
// coefficient(power) // Returns the coefficient of the  xpower term. 
// changeCoefficient(newCoefficient, power) // Replaces the coefficient of 
//                                          // the  xpower term with  newCoefficient.
// For this problem, consider only polynomials whose exponents are nonnegative integers. For example, p = 4x5 + 7x3 − x2 + 9

// The following examples demonstrate the ADT operations on this polynomial.

// p.degree() is 5 (the highest power of a term with a nonzero coefficient)

// p.coefficient(3) is 7 (the coefficient of the x3 term)

// p.coefficient(4) is 0 (the coefficient of a missing term is implicitly 0)

// p.changeCoefficient(–3, 7) changes the polynomial p to –3x7 + 4x5 + 7x3 − x2 + 9

// Using these ADT operations, write statements to perform the following tasks:

// Display the coefficient of the term that has the highest power.

// Increase the coefficient of the x3 term by 8.

// Compute the sum of two polynomials.



// Program:
// The following code illustrates the ADT operations such as “degree()”, “coefficient()” ,
// “changeCoefficient()” and “polyAddition()”.
// File name: PolynomialADT.h
//Include the needed header files.
#ifndef POLYNOMIALADT_H
#define POLYNOMIALADT_H
#include<iostream>
#include<string>
using namespace std;
class MyPolynomialClass
{
    //Access specifier.
    private:
        //Vector of coefficients.
        vector polyCoeff;
        //Declare variable for degree.
        int polyDeg;
        //Access specifier.
    public:
        //Constructor.
        MyPolynomialClass();
        //Constructor.
        MyPolynomialClass(const MyPolynomialClass& anotherPoly);
        //Constructor.
        MyPolynomialClass(int degree, vector pcVector);
        //Function setPolynomial().
        void setPolynomial();
        //Function degree().
        int degree();
        //Function coefficient().
        int coefficient(int power) const;
        //Function changeCoefficient().
        void changeCoefficient(int newCoefficient, int power);
        //Function polyAddition()
        MyPolynomialClass polyAddition(MyPolynomialClass mypoly);
        //Function printPolynomial().
        void printPolynomial();
        //Function isValidInput().
        int isValidInput();
        //Function isPositive().
        int isPositive();
};
#endif
// Comment
// File name: PolynomialADT.cpp
//Include the needed header files.
#include "PolynomialADT.h"
#include<iostream>
#include<string>
using namespace std;
//Constructor definition.
MyPolynomialClass::MyPolynomialClass(){}
//Constructor definition.
MyPolynomialClass::MyPolynomialClass(const MyPolynomialClass& anotherPoly)
{
    //Initialize degree.
    polyDeg = anotherPoly.polyDeg;
    //Initialize coefficient.
    polyCoeff.resize(polyDeg + 1);
    //For loop() to iterate.
    for (int idx = polyDeg; idx >= 0; idx--)
    {
        //Update polynomial coefficient.
        polyCoeff[idx] = anotherPoly.polyCoeff[idx];
    }
}
//Constructor definition.
MyPolynomialClass::MyPolynomialClass(int degree, vector pcVector)
{
    //Initialize degree.
    polyDeg = degree;
    //Initialize coefficient.
    polyCoeff = pcVector;
}
//Function definition - setPolynomial().
void MyPolynomialClass::setPolynomial()
{
    //Display message.
    cout <<"";
    cout<<"(Degree has to be higher than 3 to work): ";
    //Update degree.
    polyDeg = isPositive();
    //Update coefficient.
    polyCoeff.resize(polyDeg + 1);
    //For loop() to iterate.
    for (int idx = polyDeg; idx >= 0; idx--)
    {
        //Prompt the user for coefficient.
        cout << "Enter the coefficient for term x^" << idx
        << ": ";
        //Read coefficient.
        polyCoeff[idx] = isValidInput();
    }
    //While loop().
    while (polyCoeff[polyDeg] == 0)
    {
        //Update degree.
        polyDeg -= 1;
        //Update coefficient.
        polyCoeff.resize(polyDeg + 1);
    }
}
//Function definition - degree().
int MyPolynomialClass::degree()
{
    //Return degree.
    return polyDeg;
}
//Function definition - coefficient().
int MyPolynomialClass::coefficient(int power) const
{
    //Return coefficient.
    return (polyCoeff[power]);
}
//Function definition - changeCoefficient().
void MyPolynomialClass::changeCoefficient(int newCoefficient, int power)
{
    //Update coefficient.
    polyCoeff[power] = newCoefficient;
}

//Function definition - polyAddition().
MyPolynomialClass MyPolynomialClass::polyAddition(MyPolynomialClass mypoly)
{
    //Create instance for first polynomial.
    MyPolynomialClass p1(polyDeg, polyCoeff);
    //Create instance for second polynomial.
    MyPolynomialClass p2(mypoly);
    //Condition check.
    if (p1.polyDeg < p2.polyDeg)
    {
        //Update coefficient.
        p1.polyCoeff.resize(p2.polyDeg + 1);
        //Update degree.
        p1.polyDeg = p2.polyDeg;
    }
    //Condition check.
    if (p1.polyDeg > p2.polyDeg)
    {
    //Update coefficient.
        p2.polyCoeff.resize(p1.polyDeg + 1);
        //Update degree.
        p2.polyDeg = p1.polyDeg;
    }   
    //Create instance for resultant.
    MyPolynomialClass resultant;
    //Update coefficient.
    resultant.polyCoeff.resize(p1.polyDeg + 1);
    //Update degree.
    resultant.polyDeg = p1.polyDeg;
    //For loop() to iterate.
    for (int idx = resultant.polyDeg; idx >= 0; idx--)
    {
        //Update coefficient.
        resultant.polyCoeff[idx] = p1.polyCoeff[idx] +
        p2.polyCoeff[idx];
    }
    //Return result.
    return resultant;
}

//Function definition - printPolynomial().
void MyPolynomialClass::printPolynomial()
{
    //Display message.
    cout << endl << " ";
    //For loop() to iterate.
    for (int idx = polyDeg; idx >= 0; idx--)
    {
    //Condition check.
        if (idx == polyDeg && idx != 0 && idx != 1)
            //Display message.
            cout << polyCoeff[idx] << "x^" << idx;
            //Condition check.
        else if (idx == polyDeg && idx == 1)
        {
            //Display message.
            cout << polyCoeff[idx] << "x";
        }
        //Condition check.
        else if (idx == polyDeg && idx == 0)
        {
            //Display message.
            cout << polyCoeff[idx];
        }
        //Condition check.
        else if (idx == 0 && idx != polyDeg)
        {
            //Condition check.
            if (polyCoeff[idx] < 0)
                //Display message.
                cout << polyCoeff[idx];
                //Condition check.
            if (polyCoeff[idx] > 0)
                //Display message.
                cout << "+" << polyCoeff[idx];
        }
        //Condition check.
        else if (idx == 1 && idx != polyDeg)
        {
            //Condition check.
            if (polyCoeff[idx] < 0)
            //Display message.
            cout << polyCoeff[idx] << "x";
            //Condition check.
            if (polyCoeff[idx] > 0)
            //Display message.
            cout << "+" << polyCoeff[idx] << "x";
        }
        //Otherwise
        else
        {
            //Condition check.
            if (polyCoeff[idx] < 0)
                //Display message.
                cout << polyCoeff[idx] << "x^" << idx;
                //Condition check.
            if (polyCoeff[idx] > 0)
                //Display message.
                cout << "+" << polyCoeff[idx] << "x^" <<
                idx;
        }
    }
    //Print new line.
    cout << endl;
}
int MyPolynomialClass::isValidInput()
{
    //Declare a variable.
    int number;
    //Read the input.
    cin >> number;
    //While loop().
    while (cin.fail())
    {
        //Clear the input.
        cin.clear();
        //Ignore input.
        cin.ignore(numeric_limits::max(), '\n');
        //Display message.
        cout << "Invalid entry. Enter an integer value: ";
        //Read a new input.
        cin >> number;
    }
    //Return the new input.
    return number;
}

//Function definition - isPositive().
int MyPolynomialClass::isPositive()
{
    //Declare a variable.
    int number;
    //Read the input.
    Comment
    cin >> number;
    //While loop().
    while (cin.fail() || number < 0)
    {
        //Clear the input.
        cin.clear();
        //Ignore input.
        cin.ignore(numeric_limits::max(), '\n');
        //Display message.
        cout << "Invalid entry. Enter a positive integer value: ";
        //Read a new input.
        cin >> number;
    }
    //Return the new input.
    return number;
}
// Comment
// File name: PolynomialADTTester.cpp
//Include the needed header files.
#include "PolynomialADT.h"
#include<iostream>
using namespace std;
//Driver.
int main()
{
    //Create an instance.
    MyPolynomialClass mypoly;
    //Function call.
    mypoly.setPolynomial();
    //Display message.
    cout <<"";
    //Function call.
    mypoly.printPolynomial();
    //Display message.
    cout <<"";
    mypoly.degree() << endl;
    // a. To display coefficient of the highest power.
    //Display message.
    cout <<"";
    //Function call.
    cout << endl<<"Coefficient for the term x^3 : " <
    // b. Increase the coefficient of the x3
    // term by 8.
    //Function call.
    mypoly.changeCoefficient(8, 3);
    //Display message.
    cout <<"";
    //Function call.
    mypoly.printPolynomial();
    //Display message.
    cout <<"";
    //Create an instance.
    MyPolynomialClass mypoly1;
    //Function call.
    mypoly1.setPolynomial();
    //Display message.
    cout << "Another polynomial ";
    //Function call.
    mypoly1.printPolynomial();
    //Display message.
    cout <
    //Function call.
    mypoly.printPolynomial();
    //Function call.
    mypoly1.printPolynomial();
    //Display message.
    cout <<"";
    // c. Computing the sum of two polynomials
    // Comment
    // Function call.
    mypoly.polyAddition(mypoly1).printPolynomial();
    //Pause the output.
    cin.get(); cin.get();
    //Exit.
    return 0;
}
// Comment
// Sample Output:
// Enter the degree of the polynomial
// (Degree has to be higher than 3 to work): 4
// Enter the coefficient for term x^4: 1
// Enter the coefficient for term x^3: 2
// Enter the coefficient for term x^2: 3
// Enter the coefficient for term x^1: 4
// Enter the coefficient for term x^0: 5
// Input polynomial
// 1x^4+2x^3+3x^2+4x+5
// Degree of the input polynomial : 4
// Coefficient of the term that has the highest power : 1
// Coefficient for the term x^3 : 1
// New polynomial:
// 1x^4+8x^3+3x^2+4x+5
// Another polynomial:
// Enter the degree of the polynomial
// (Degree has to be higher than 3 to work): 4
// Enter the coefficient for term x^4: 5
// Enter the coefficient for term x^3: 4
// Enter the coefficient for term x^2: 3
// Enter the coefficient for term x^1: 2
// Enter the coefficient for term x^0: 1
