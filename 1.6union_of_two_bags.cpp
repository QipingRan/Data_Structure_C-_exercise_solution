// The union of two bags is a new bag containing the combined contents of the original two bags.
//  Design and specify a method union for the ADT bag that returns as a new bag 
//  the union of the bag receiving the call to the method and the bag that is the method’s one argument. 
//  Include sufficient comments to fully specify the method.
// Note that the union of two bags might contain duplicate items. For example, if object x occurs five times in one bag and twice in another, the union of these bags contains x seven times. Specifically, suppose that bag1 and bag2 are bags; bag1 contains the strings a, b, and c; and bag2 contains the strings b, b, d, and e. The expression bag1.union(bag2) returns a bag containing the strings a, b, b, b, c, d, and e. 
// Note that union does not affect the contents of bag1 and bag2.

// File Name: BagInterface.h
//Include the needed header files.
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE
#include<iostream>
using namespace std;
//Class.
templateclass BagInterface
{
//Access specifier.
    public:
        /*Pure virtual function declaration getCurrentSize().*/
        virtual int getCurrentSize() const = 0;
        //Pure virtual function declaration isEmpty().
        virtual bool isEmpty() const = 0;
        //Pure virtual function declaration add().
        virtual bool add(const ItemType& newEntry) = 0;
        //Pure virtual function declaration remove().
        virtual bool remove(const ItemType& anEntry) = 0;
        //Pure virtual function declaration clear().
        virtual void clear() = 0;
        /*Pure virtual function declaration getFrequencyOf().*/
        virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
        //Pure virtual function declaration contains().
        virtual bool contains(const ItemType& anEntry) const = 0;
        //Pure virtual function declaration toVector().
        virtual vector toVector() const = 0;
};
#endif
// File Name: MyBag.h
//Include the needed header files.
#ifndef _MYBAG_H
#define _MYBAG_H
#include "BagInterface.h"
//Derived class.
templateclass MyBag : public BagInterface{
    static const int DEFAULTBAGSIZE = 10;
    //Declare an array for items.
    ItemType items[DEFAULTBAGSIZE];
    //Declare an integer for item count.
    int itemCounter;
    //Declare an integer for maximum number of items.
    int maximumItems;
    //Declare an integer for index of item.
    int getIndexOf(const ItemType& targetItem) const;
    //Access specifier.
    public:
    //Constructor.
        MyBag();
        //Function declaration getCurrentSize().
        int getCurrentSize() const;
        //Function declaration is empty().
        bool isEmpty() const;
        //Function declaration add().
        bool add(const ItemType& newEntry);
        //Function declaration remove().
        bool remove(const ItemType& anEntry);
        //Function declaration clear().
        void clear();
        //Function declaration contains().
        bool contains(const ItemType& anEntry) const;
        //Function declaration getFrequencyOf().
        int getFrequencyOf(const ItemType& anEntry) const;
        //Function declaration toVector().
        vector toVector() const;
        //Function declaration Union().
        MyBag Union(MyBag Bag2);
};
#endif

// File Name: MyBag.cpp
//Include the needed header files.
#include "MyBag.h"
#include<iostream>
using namespace std;
//Constructor.
template
MyBag::MyBag() : itemCounter(0), maximumItems(DEFAULTBAGSIZE);
//Function returns the number of items.
templateint MyBag::getCurrentSize() const
{
//Return.
    return itemCounter;
}
//Function returns whether the bag is empty or not.
templatebool MyBag::isEmpty() const
{
//Return.
    return itemCounter == 0;
}
/*Function returns whether we can add items to the bag or not.*/
templatebool MyBag::add(const ItemType& newEntry)
{
//Declare and initialize a boolean variable.
    bool hasRoom = (itemCounter < maximumItems);
    //Condition check.
    if (hasRoom)
    {
    //Add items.
        items[itemCounter] = newEntry;
        //Increment item count.
        itemCounter++;
    }
    //Return.
    return hasRoom;
}
/*Function returns whether we can remove items from the bag or not.*/
templatebool MyBag::remove(const ItemType& anEntry)
{
    //Declare and initialize an integer variable.
    int locatedIdx = getIndexOf(anEntry);
    //Declare and initialize a boolean variable.
    //Decrement item count.
    itemCounter--;
    //Delete item.
    items[locatedIdx] = items[itemCounter];
}
//Return.
return canRemove;

//Function to clear the contents of the bag.
templatevoid MyBag::clear()
{
//Set item count to zero.
    itemCounter = 0;
}
//Function returns the frequency of the item in the bag.
template
int MyBag::getFrequencyOf(const ItemType& anEntry) const
{
//Declare and initialize a variable for frequency.
    int itemFrequency = 0;
    //Declare and initialize a variable for search index.
    int searchIdx = 0;
    //While loop().
    while (searchIdx < itemCounter)
    {
    //Condition check.
        if (items[searchIdx] == anEntry)
        {
        //Increment itemFrequency.
            itemFrequency++;
        }
        //Increment search index.
        searchIdx++;
    }
//Return.
    return itemFrequency;

//Function returns the whether the bag has the item or not.
template
bool MyBag::contains(const ItemType& anEntry) const
{
//Return.
    return getIndexOf(anEntry) > -1;
}
//Function to print the contents as vector data.
templatevector MyBag::toVector() const
{
    //Declare a vector for bag items.
    vector contentsOfBag;
    //For loop to iterate.
    for (int i = 0; i < itemCounter; i++)
    //Add items to the bag.
        contentsOfBag.push_back(items[i]);
    //Return the contents of the bag.
    return contentsOfBag;
}

//Function to get the index of the item in the bag.
templateint MyBag::getIndexOf(const ItemType& targetItem) const
{
    //Declare and initialize a boolean variable.
    bool isFound = false;
    //Declare and initialize an integer variable.
    int resultant = -1;
    //Declare and initialize an integer variable.
    int searchIdx = 0;
    //While loop.
    while (!isFound && (searchIdx < itemCounter))
    {
    //Condition check.
        if (items[searchIdx] == targetItem)
        {
        //Update the isFound.
            isFound = true;
            //Update the resultant.
            resultant = searchIdx;
        }
        searchIdx++;
    }
}
//Return.
return resultant;

//Function to perform union operation on two bags.
template MyBag MyBag::Union(MyBag myBag2)
{
    //Create a new instance.
    MyBag newBag;
    //Get bag 1 items as vector.
    vector myVector1 = toVector();
    /*Use a loop to copy the items from the bag 1 to new bag.*/
    for (int index = 0; index < getCurrentSize(); index++)
    //Copy the items.
        newBag.add(myVector1.at(index));
        //Get bag2 items as vector.
        vector myVector2 = myBag2.toVector();
        /*Use a loop to copy the items from the bag 2 to new bag.*/
        for (int index = 0; index < myBag2.getCurrentSize(); index++)
        //Copy the items.
            newBag.add(myVector2.at(index));
            //Return the new bag.
    return newBag;
}

// File Name: Main.cpp
//Include the needed header files.
#include<iostream>
#include"Mybag.h"
#include "MyBag.cpp"
//Display message.
cout << "The bag has " << myBag1.getCurrentSize() << " items:" << endl;
/*Function call to toVector() to show bag contents as vector.*/
vector bItems1 = myBag1.toVector();
//Get the number of items in the bag.
int noOfItems = (int)bItems1.size();
//For loop to iterate till last item in the bag.
for (int i = 0; i < noOfItems; i++)
{
//Display the bag items.
    cout << bItems1[i] << " ";
}
//Print new line.
cout << endl;
}

//Function to test the bag.
void bagTester(MyBag& myBag1)
{
    //Create an array of string items.
    string bItems1[] = {"a", "b", "c"};
    //Use a loop to add items to the bag.
    for (int i = 0; i <=2; i++)
    {
        //Add string items to the bag.
        myBag1.add(bItems1[i]);
    }
    //Function call to display the items in the bag.
    printContentsOfBag(myBag1);
}

//Driver.
int main()
{
    //Create a new instance.
    MyBag myBag1;
    //Function call to bagTester().
    MyBag myBag2;
    //Declare an array of string items.
    string bItems12[]={"b","b","d","e"};
    //Use loop to add items to the bag 2.
    for(int i=0;i<=3;i++)
    {
    //Add items to the bag 2.
        myBag2.add(bItems12[i]);
    }
    //Function call to print the contents of bag 2.
    printContentsOfBag(myBag2);
    //Function call to union() method.
    MyBag myBag3=myBag1.Union(myBag2);
    //Display message.
    cout<
    //Function call to print the contents of new bag.
    printContentsOfBag(myBag3);
    //Pause the console.
    cin.get();cin.get();
    //Exit.
    return 0;
}
// Sample Output:
// The bag has 3 items:
// a b c
// The bag has 4 items:
// b b d e
// Union of two bags
// Comment
// The bag has 7 items:
// a b c b b d e





