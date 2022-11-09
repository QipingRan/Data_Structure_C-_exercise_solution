// Add a constructor to the class ArrayBag that creates a bag from a given array of entries.


// Complete Code:
// Refer LISTING 1-1 in chapter 1 for “BagInterface.h”.
// Refer LISTING 3-1 in chapter 3 for “ArrayBag.h”.
// Refer LISTING 3-2 in chapter 3 for “main.cpp”.
// The below program illustrates the functionality of the method “ArrayBag()”,
// File name: BagInterface.h
/*Header file for bag interface*/
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE
//Include the header file "vector".
#include<iostream>
using namespace std;
//Generic class BagInterface declaration.

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
        //End of BagInterface.
};
#endif
// Comment
// File name: ArrayBag.h
/*Header file for ADT bag*/
#ifndef _ARRAY_BAG
#define _ARRAY_BAG
//Include the BagInterface.h
#include "BagInterface.h"
#include<iostream>
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
        //Overloaded constructor.
        ArrayBag(ItemType *passedItems, int nn);
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

ArrayBag::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{}

ArrayBag::ArrayBag(ItemType *passedItems,int nn)
{
    //Set itemCount to 0.
    itemCount = 0;
    //Set maxItems to default capacity.
    maxItems = DEFAULT_CAPACITY;
    //Check nn value.
    if(nn<maxItems)
    {
        /*Use loop to copy the entries from passedItems to items.*/
        for(int kk=0;kk<=nn;kk++)
        {
            //Copy the entry.
            items[itemCount] = passedItems[kk];
            //Increment the itemCount.
            itemCount++;
        }
    }
    //Otherwise,
    else
    {
        /*Use loop to copy the entries from passedItems to items.*/
        for(int kk=0;kk<=nn;kk++)
        {
            //Copy the entry.
            items[itemCount] = passedItems[kk];
            //Increment the itemCount.
            itemCount++;
        }
    }
}

int ArrayBag::getCurrentSize() const
{
    //Return the itemCount value.
    return itemCount;
}

bool ArrayBag::isEmpty() const
{
    /*Check itemCount is 0. Then output the bool value of the condition.*/
    return itemCount == 0;
}

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

bool ArrayBag::remove(const ItemType& anEntry)
{
    //Get the index of anEntry.
    int locatedIndex = getIndexOf(anEntry);
    //Check index is valid. Also check bag is not empty.
    bool canRemoveItem = !isEmpty()&&(locatedIndex > -1 );
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

void ArrayBag::clear()
{
    //Reset the itemCount to 0.
    itemCount = 0;
}

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

bool ArrayBag::contains(const ItemType& anEntry) const
{
    //Call the method getIndexOf() and check it.
    return getIndexOf(anEntry) > -1;
}

vector ArrayBag::toVector() const
{
    //Create bagContents.
    vector bagContents;
    //Use loop to add bag items to the bagContents.
    for (int i = 0; i < itemCount; i++)
        //Add the current bag item to bagContents.
        bagContents.push_back(items[i]);
        //Return the bagContents.
    return bagContents;
    // End of toVector().
}

// Private method to get the index of the target.

int ArrayBag::getIndexOf(const ItemType& target) const
{
    //Declare the needed variables.
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    /* Use loop to check the entire bag items for matching target.*/
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

//main() method.
int main()
{
    //Create an array of string items.
    string items[] = {"one", "two", "three", "Four", "Five","Six","Seven"};
    //Create a new bag bag.
    ArrayBag bag(items,6);
    //Display the new line
    cout<
    //Call the method displayBag().
    displayBag(bag);
    //Display message.
    cout << "All done!" << endl;
    //To pause the window.
    system("pause");
    //Stop the program
    return 0;
}

