// A date consists of a month, day, and year. Consider the class Date of such dates.
//  Suppose that Date represents the month, day, and year as integers. For example, July 4, 1776, 
//  is month 7, day 4, and year 1776.
// Write specifications for a method within Date that advances any given date by one day. 
// Include a statement of purpose, the preconditions and postconditions, a description of the arguments, 
// and a description of any return value.

// Write a C++ implementation of this method. Design and specify any other method that you need. 
// Include comments that will be helpful to someone who will maintain your implementation in the future.


#include <iostream> 
#include <cmath> 
using namespace std; 

class Date 
{ 
public: 
    Date (); 
    Date ( int mn, int day, int yr); // constructor 
    void display(); // function to display date 
    int GetMonth(); 
    void SetMonth(int mn); 
    ~Date(); 
private: 
    int month, day, year; 
}; 

// constructor definition 
Date::Date () 
{ 
    month = day = year = 1; 
} 

Date::Date (int mn, int dy, int yr) 
{ 
    static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 

    month = mn; 
    day = dy; 
    year = yr; 

} 

void Date::display() 
{ 
    static string name[] = {"nothing", "January", "February", "March", "April", 
    "May", "June", "July", "August", "September", "October", 
    "November", "December" }; 

    cout << '\n' << name[month] << ' ' << day << "," << year << '\n'; 
} 

Date::~Date() 
{ 
    cout << "Thank You for using DateLine Services and have a nice date\n"; 
} 

int Date::GetMonth() 
{ 
    return month; 
} 

// Precondition: 1 <= mn <= 12 
void Date::SetMonth(int mn) 
{ 
    month = mn; 
} 

int main() 
{ 
    Date mydate(1, 2, 1993); 
    Date date2(4,12,1994); 
    Date date3; 

    mydate.display(); 
    date2.display(); 
    
    date3.display(); 
} 