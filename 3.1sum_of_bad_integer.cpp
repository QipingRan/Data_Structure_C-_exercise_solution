// Consider a bag of integers.
//  Write a client function that computes the sum of the integers in the bag aBag.

// int sumOfBag(ArrayBag<int> & aBag)
// {
//     int sum = 0;
//     int size = aBag.getCurrentSize();
//     vector<int> bagContents = aBag.toVector();

//     for (int i = 0; i < size; i++)
//         sum += bagContents.at(i);

//     return sum;
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
template
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
        // End of BagInterface.
};
#endif
// Comment
// File name: ArrayBag.h
/*Header file for ADT bag*/
#ifndef _ARRAY_BAG
#define _ARRAY_BAG
//Include the BagInterface.h
#include "BagInterface.h"
//ArrayBag class
template
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
template
ArrayBag::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}
//Method outputs the entries count.
template
int ArrayBag::getCurrentSize() const
{
    //Return the itemCount value.
    return itemCount;
}
//Method outputs true if the bag is clear.
template
bool ArrayBag::isEmpty() const
{
    /*Check itemCount is 0. Return the bool value of the condition.*/
    return itemCount == 0;
}
C
//Method adds newEntry to the bag.
template
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
template
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
template
void ArrayBag::clear()
{
    //Reset the itemCount to 0.
    itemCount = 0;
}
//Method outputs the count of anEntry.
template
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
template
bool ArrayBag::contains(const ItemType& anEntry) const
{
    //Call the method getIndexOf() and check it.
    return getIndexOf(anEntry) > -1;
}
//Method outputs the vector having the bag items.
template
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
template
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
    int numberOfEntries = (int)bagItems.size();
    Comment
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
//Method to find the sum of all entries in the bag.
int bagSum(ArrayBag& aBag)
{
//Declare mySum and initialize it to 0.
int mySum=0;
//Declare myBagSize to store the aBag's size.
int myBagSize=aBag.getCurrentSize();
// Get the aBag contents.
vector myBagContains=aBag.toVector();
/* Use for loop to find the sum of all items in the
abag.*/
for(int kk=0;kk
{
    //Add the current bag content to mySum.
    mySum += myBagContains.at(kk);
}
// Return the mySum
return mySum;
}
//main() method.
int main()
{
    //Create a new bag bag.
    ArrayBag bag;
    //Call the method bagTester().
    bagTester(bag);
    //Display the new line.
    cout<
    //Display the information to the user.
    cout<<"Creating new bag abag:"<
    //Create a new bag aBag.
    ArrayBag aBag;
    //Use loop to add items to the bag.
    for (int i = 0; i < 6; i++)
    {
        //Add an integer item to the bag.
        aBag.add(i+1);
    }
    //Display the information to the user.
    cout<<"abag contains:"<
    //Get the contents of the aBag.
    vector myBagItems = aBag.toVector();
    //Get the number of entries in the bag.
    int numEnt1 = (int)myBagItems.size();
    //Use loop to display the integer entries in the bag.
    for (int i = 0; i < numEnt1; i++)
    {
        //Display the bag entry.
        cout << myBagItems[i] << " ";
    }
    //Display the new line.
    cout << endl << endl;
    //Call the method to find the bag sum.
    int mysum=bagSum(aBag);
    //Now display the bag sum.
    cout<<"The sum is :"<
    cout << "All done!" << endl;
    //To pause the window.
    system("pause");
    //Stop the program.
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
// one two three four five one
// isEmpty: returns 0; should be 0 (false)
// getCurrentSize: returns 6; should be 6
// Try to add another entry: add("extra") returns 0
// Creating new bag abag:
// abag contains:
// 1 2 3 4 5 6
// The sum is :21
