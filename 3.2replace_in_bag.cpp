// Write a client function replace that replaces a given item in a given bag with another given item.
//  The function should return a boolean value to indicate whether the replacement was successful.

// bool relpace(int x,int location,int *bag[])

// {

//     int i=0;

//     while(i<location) // loop for go to location in bag

//     {

//         bag++;

//         i++;

//     }

//     i--;

//     *bag=x; // replacing value to x;

//     return true; // returning true

// }


//Method to replace inp1 by inp2.
// bool replace(ArrayBag& bag, string inp1, string inp2)
// {
//     //Call the method remove to delete inp1 from bag.
//     bool isDel=bag.remove(inp1);
//     /*check isDel is true. If isDel is true, add inp2 to the bag.*/
//     if(isDel==true)
//     {
//         //Add the inp2 to the bag.
//         bag.add(inp2);
//         //On success, return true.
//         return true;
//     }
//     //on failure return false.
//     return false;
// }
// Complete Code:
// The complete code is as follows,
// File name: BagInterface.h
/*Header file for bag interface*/
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE
//Include the header file "vector".
#include<iostream>
using namespace std;
//Generic class BagInterface declaration.
// template
class BagInterface
{
    //Access specifier.
    public:
        //Return the items count in the bag.
        virtual int getCurrentSize() const = 0;
        //Method outputs true if the bag is clear.
        virtual bool isEmpty() const = 0;
        /*Method outputs true if newEntry is inserted to the bag.*/
        virtual bool add(const ItemType& newEntry) = 0;
        /*Method outputs true if anEntry is erased from the bag.*/
        virtual bool remove(const ItemType& anEntry) = 0;
        //Method removes all the bag entries.
        virtual void clear() = 0;
        //Method to find the count of anEntry.
        virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
        /*Method outputs true if anEntry is existing in the bag.*/
        virtual bool contains(const ItemType& anEntry) const = 0;
        //Method outputs bag contents as vector.
        virtual vector toVector() const = 0;
};// end of BagInterface
#endif
// Comment
// File name: ArrayBag.h
//ArrayBag.h
/*Header file for ADT bag*/
#ifndef _ARRAY_BAG
#define _ARRAY_BAG
//Include the BagInterface.h
#include "BagInterface.h"
//ArrayBag class
class ArrayBag : public BagInterface
{
    //Access specifier.
    private:
        //Declare the default bag capacity.
        static const int DEFAULT_CAPACITY = 6;
        //Create an array items to hold bag items.
        ItemType items[DEFAULT_CAPACITY];
        //Declare itemCount.
        int itemCount;
        //Declare maximum items in the bag.
        int maxItems;
        //Method outputs the index of the target.
        int getIndexOf(const ItemType& target) const;
        //Access specifier.
    public:
        //Default constructor.
        ArrayBag();
        //Method outputs the current entries count.
        int getCurrentSize() const;
        //Method outputs true if the bag is clear.
        bool isEmpty() const;
        //Method inserts newEntry to the bag.
        bool add(const ItemType& newEntry);
        //Method removes anEntry from the bag.
        bool remove(const ItemType& anEntry);
        //Method clears the bag contents.
        void clear();
        /*Method outputs true if anEntry is existing in the bag.*/
        bool contains(const ItemType& anEntry) const;
        //Method outputs the count of anEntry.
        int getFrequencyOf(const ItemType& anEntry) const;
        //Method returns bag contents as vector.
        vector toVector() const;
};
//Implementation code for ArrayBag.h
//Include the "ArrayBag.h"
#include "ArrayBag.h"
#include<iostream>
/*Default constructor that assigns the values to default values.*/
ArrayBag::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}
//Method outputs the entries count.
int ArrayBag::getCurrentSize() const
{
    //Return the itemCount value.
    return itemCount;
}
//Method outputs true if the bag is clear.

bool ArrayBag::isEmpty() const
{
    /*Check itemCount is 0. Return the bool value of the condition.*/
    return itemCount == 0;
}
//Method adds newEntry to the bag.

bool ArrayBag::add(const ItemType& newEntry)
{
    //Check space is existing to store the newEntry.
    bool hasRoomToAdd = (itemCount < maxItems);
    //If space is available,
    if (hasRoomToAdd)
    {
        //Add the newEntry.
        items[itemCount] = newEntry;
        //Increment the itemCount.
        itemCount++;
    }
    //Return the hasRoomToAdd
    return hasRoomToAdd;
}
//Method to delete anEntry from bag.

bool ArrayBag::remove(const ItemType& anEntry)
{
    //Get the index of anEntry.
    int locatedIndex = getIndexOf(anEntry);
    //Check index is valid. Also check bag is not empty.
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    //If the condition is true,
    if (canRemoveItem)
    {
        //Decrement the itemCount by 1.
        itemCount--;
        /*Store the end item entry at the deleted item place.*/
        items[locatedIndex] = items[itemCount];
    }
    //Return the canRemoveItem.
    return canRemoveItem;
}
//Method clears the bag contents.

void ArrayBag::clear()
{
    //Reset the itemCount to 0.
    itemCount = 0;
}
//Method outputs the count of anEntry.

int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
    //Declare frequency and set it to 0.
    int frequency = 0;
    //Declare curIndex and set it to 0.
    int curIndex = 0;
    //Use loop to check the bag entries.
    while (curIndex < itemCount)
    {
        //If the current item matches with anEntry.
        if (items[curIndex] == anEntry)
        {
            //Increment the frequency by 1.
            frequency++;
        }
        //Move to next entry.
        curIndex++;
    }
    //Return the frequency.
    return frequency; 
}
//Method outputs true if anEntry is in the bag.

bool ArrayBag::contains(const ItemType& anEntry) const
{
    //Call the method getIndexOf() and check it.
    return getIndexOf(anEntry) > -1;
}
//Method outputs the vector having the bag items.

vector ArrayBag::toVector() const
{
    //Create a vector bagContents.
    vector bagContents;
    //Use loop to add bag items to the bagContents.
    for (int i = 0; i < itemCount; i++)
        //Add the current bag item to bagContents.
        bagContents.push_back(items[i]);
        //Return the bagContents.
    return bagContents;
    // end of toVector().
}
// Private method to get the index of the target.

int ArrayBag::getIndexOf(const ItemType& target) const
{
    //Declare the needed variables.
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    // Use loop to check the entire bag items for matching target.
    while (!found && (searchIndex < itemCount))
    {
        /*If the current item is matching the target, then store the searchIndex.*/
        if (items[searchIndex] == target)
        {
            //Set the found to true.
            found = true;
            //Store the searchIndex in result.
            result = searchIndex;
        }
        /*If the current item is not matching with the target,*/
        else
        {
            //Move to next item.
            searchIndex++;
        }
    }
    //Return the result.
    return result;
}
#endif
// Comment
// File name: main.cpp
//Include the needed header files
#include<iostream>
#include<string>
#include "ArrayBag.h"
using namespace std;
//Method to display the bag.
void displayBag(ArrayBag& bag)
{
    //Display information about the bag.
    cout << "The bag contains " << bag.getCurrentSize()
    << " items:" << endl;
    //Get the bag contents as vector.
    vector bagItems = bag.toVector();
    //Get the number of entries in the bag.
    Comment
    int numberOfEntries = (int)bagItems.size();
    //Use loop to display all entries in the bag.
    for (int i = 0; i < numberOfEntries; i++)
    {
        //Display the bag entries.
        cout << bagItems[i] << " ";
    }
    //Display newline
    cout << endl << endl;
    // end of displayBag().
}
//Method to test on the bag.
void bagTester(ArrayBag& bag)
{
    /*Call the method "isEmpty()" and display its return value.*/
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 1 (true)" << endl;
    /*Display the bag by calling the method "displayBag()".*/
    displayBag(bag);
    //Create an array of string items.
    string items[] = {"one", "two", "three", "four", "five", "one"};
    //Display information to the user.
    cout << "Add 6 items to the bag: " << endl;
    //Use loop to add items to the bag.
    for (int i = 0; i < 6; i++)
    {
        //Add the string item to the bag.
        bag.add(items[i]);
    }
    //Display the bag contents using "displayBag()".
    displayBag(bag);
    //Call the method "isEmpty()" and display its return value
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 0 (false)" << endl;
    //Display the current size of the bag.
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
    << "; should be 6" << endl;
    //Add one extra item to the bag.
    cout << "Try to add another entry: add(\"extra\") returns "
    << bag.add("extra") << endl;
}
//Method to replace inp1 by inp2.
bool replace(ArrayBag& bag, string inp1, string inp2)
{
    //Call the method remove to delete inp1 from bag.
    bool isDel=bag.remove(inp1);
    /*check isDel is true. If isDel is true, add inp2 to the bag.*/
    if(isDel==true)
    {
        //Add the inp2 to the bag.
        bag.add(inp2);
        //On success, return true.
        return true;
    }
    //On failure return false.
    return false;
}
//main() method.
int main()
{
    //Create a new bag bag.
    ArrayBag bag;
    //Display the information to the user.
    cout << "Testing the Array-Based Bag:" << endl;
   
    cout << "The initial bag is empty." << endl;
    //Call the method bagTester()
    bagTester(bag);
    //Display the new line
    cout<<end;
    //Declare inp1.
    string inp1="five";
    //Declare inp2.
    string inp2="fifteen";
    //Display the information.
    cout<<"Replacing five with fifteen:"<
    //Call the method replace().
    cout<<"Replaced successfully:"<<endl;
    //Call the method displayBag().
    displayBag(bag);
    cout << "All done!" << endl;
    //To pause the window.
    system("pause");
    //Stop the program
    return 0;
}
// Comment
// Sample Output:
// Testing the Array-Based Bag:
// The initial bag is empty.
// isEmpty: returns 1; should be 1 (true)
// The bag contains 0 items:
// Add 6 items to the bag:
// The bag contains 6 items:
