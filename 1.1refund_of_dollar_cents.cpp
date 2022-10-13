// The price of an item you want to buy is given in dollars and cents. 
// You pay for it in cash by giving the clerk d dollars and c cents.
//  Write specifications for a function that computes the change, if any, that you should receive. 
//  Include a statement of purpose, 
// the preconditions and postconditions, and a description of the arguments.


void computeChange(int dollarCost, int centsCost, int& d, int& c)
{
    //Convert the dollars of item into cents.
    int allcents1 = dollarCost*CENTSPERDOLLAR;
    //Item's total price in cents.
    int totalPrice = allcents1+centsCost;
    //Convert the dollars paid for item into cents.
    int allcents = d*CENTSPERDOLLAR;
    //Total price paid for the item in cents.
    int totalPaid = allcents+c;
    /*Check whether the paid amount is lesser than the item price.*/
    if (totalPaid < totalPrice)
    {
    //If so, Display a warning message.
        cout<<"You have paid lesser amount!";
    }
    //Otherwise.
    else
    {
    //Display the change.
        int difference=totalPaid-totalPrice;
        if(difference<100){
            cout<<"";
        }
    //Condition check.
        else if(difference==CENTSPERDOLLAR)
        {
        //Display the change.
            cout<<"";
        }
    //Condition check.
        else if(difference>CENTSPERDOLLAR)
        {
        //Declare the variables needed.
            int dol,cen;
            //Compute dollars.
            dol =difference/100;
            //Compute cents.
            cen =difference-(dol*CENTSPERDOLLAR);
            //Display the change.
            cout<<"";
        }
}


//Include the needed header file.
#include<iostream>
using namespace std;
//Declare a constant integer.
int const CENTSPERDOLLAR = 100;
//Function declaration.

void computeChange(int dollarCost, int centsCost, int& d, int& c);
//Driver.
int main()
{
//Read the price of item in dollar and cents.
    cin>>dollarCost>>centsCost;
    //Prompt the user for paid amount.
    cout <<"";
    //Read the price paid in dollar and cents.
    cin>>d>>c;
    //Function call.
    computeChange(dollarCost,centsCost,d,c);
    //Pause the output.
    cin.get();cin.get();
}
