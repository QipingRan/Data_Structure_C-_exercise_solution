// Suppose that the class LinkedBag did not have the data member itemCount. 
// Revise the public method getCurrentSize so that it counts the number of nodes 
// in the linked chain
// Iteratively
// Recursively


// Complete Program:
// The replaced code is highlighted in grey color.
// Refer LISTING 4-1 in chapter 4 for “Node.h”.
// Refer LISTING 4-2 in chapter 16 for “Node.cpp”.
// Refer LISTING 4-3 in chapter 4 for “LinkedBag.h”.
// Refer LISTING 1-1 in chapter 1 for “BagInterface.h”.
// The following code illustrates the operation in a linked bag.
// File Name: Node.h
//Include library.
#ifndef _NODE
#define _NODE
//Define a class "Node" for methods in node.

class Node
{
//Add the code from "Node.h".
// .
// .
// .
// End of Node.
};
#endif

// File Name: Node.cpp
//Include libraries.
#include "Node.h"
#include<iostream>
//Add the code from "Node.cpp".
// .
// .
// .
// Comment
// File Name: LinkedBag.h
//Include libraries.
#ifndef _LINKED_BAG
#define _LINKED_BAG
#include "BagInterface.h"
#include "Node.cpp"
//Define a class "LinkedBag" derived from "BagInterface<>"
class LinkedBag : public BagInterface
{
//Add the code from "LinkedBag.h".
// .
// .
// .
};
//End of file.
#endif

// File Name: LinkedBag.cpp
//Include libraries.
#include "LinkedBag.h"
#include "Node.h"
#include<iostream>
//Define a constructor.

LinkedBag::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}

LinkedBag::LinkedBag(const LinkedBag& aBag)
{
    //Define item count.
    itemCount = aBag.itemCount;
    //Define a new node.
    Node* origChainPtr = aBag.headPtr;
    //If new node is null.
    if (origChainPtr == nullptr)
        //Set head as null.
        headPtr = nullptr;
        //If not null.
    else
    {
        // Copy first node
        headPtr = new Node();
        //Set item.
        headPtr->setItem(origChainPtr->getItem());
        // Copy remaining nodes
        Node* newChainPtr = headPtr;
        //Advance original chain pointer.
        origChainPtr = origChainPtr->getNext();
        //Loop until it reaches null.
        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            // Create a new node containing next item
            Node* newNodePtr = new Node(nextItem);
            // Link new node to new chain's end.
            newChainPtr->setNext(newNodePtr);
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }
        // Flag chain's end.
        newChainPtr->setNext(nullptr);
    }
}

//Define a destructor.
LinkedBag::~LinkedBag()
{
    //Clear.
    clear();
}

//Define a method "isEmpty()" to check if bag is empty.
bool LinkedBag::isEmpty() const
{
    //Return item count.
    return itemCount == 0;
}

//Define an iterative version of method "getCurrentSize()".

int LinkedBag::getCurrentSize() const
{
    //Declare variable.
    int count = 0;
    //Define new node.
    Node* curPtr = headPtr;
    //Loop until null is reached.
    while (curPtr != nullptr)
    {
        //Increment count.
        count++;
        //Move to next element.
        curPtr = curPtr->getNext();
    }
    //Return count.
    return count;
}

bool LinkedBag::add(const ItemType& newEntry)
{
    //Define a new node.
    Node* nextNodePtr = new Node();
    //Set item to node.
    nextNodePtr->setItem(newEntry);
    //Make new node point to head.
    nextNodePtr->setNext(headPtr);
    //Set new node as head node.
    headPtr = nextNodePtr;
    //Increment count.
    itemCount++;
    //Return true.
    return true;
}

vector LinkedBag::toVector() const
{
    //Define a bag.
    vector bagContents;
    //Define a node.
    Node* curPtr = headPtr;
    //Declare variable.
    int counter = 0;
    //Loop until pointer reaches null.
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        //Push contents.
        bagContents.push_back(curPtr->getItem());
        //Move to next pointer.
        curPtr = curPtr->getNext();
        //Increment counter.
        counter++;
    }
    //Return contents of bag.
    return bagContents;
}

bool LinkedBag::remove(const ItemType& anEntry)
{
    //Define a new node.
    Node* entryNodePtr = getPointerTo(anEntry);
    //Declare variable.
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    //If item is to be removed.
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        // Delete first node
        Node* nodeToDeletePtr = headPtr;
        //Move to next node.
        headPtr = headPtr->getNext();
        // Return node to system.
        nodeToDeletePtr->setNext(nullptr);
        //Delete node pointer.
        delete nodeToDeletePtr;
        //Set as null.
        nodeToDeletePtr = nullptr;
        //Decrement count.
        itemCount--;
    }
    //Return value.
    return canRemoveItem;
}

void LinkedBag::clear()
{
    //Define a new node.
    Node* nodeToDeletePtr = headPtr;
    //Loop until pointer reaches null.
    while (headPtr != nullptr)
    {
    //Move to next node.
    headPtr = headPtr->getNext();
    //Return node to system.
    nodeToDeletePtr->setNext(nullptr);
    //Delete node.
    delete nodeToDeletePtr;
    //Set head to node pointer.
    nodeToDeletePtr = headPtr;
    }
    //Set count as 0.
    itemCount = 0;
}

int LinkedBag::getFrequencyOf(const ItemType& anEntry) const
{
    //Declare variables.
    int frequency = 0;
    int counter = 0;
    //Define a new node.
    Node* curPtr = headPtr;
    //Loop until pointer reaches null.
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        //If entry matches item.
        if (anEntry == curPtr->getItem())
        {
            //Increment frequency.
            frequency++;
        }
        //Increment count.
        counter++;
        //Move to next node.
        curPtr = curPtr->getNext();
    }
    //Return frequency.
    return frequency;
}

bool LinkedBag::contains(const ItemType& anEntry) const
{
    //Return
    return (getPointerTo(anEntry) != nullptr);
}

Node* LinkedBag::getPointerTo(const ItemType& anEntry) const
{
    //Declare varaibles.
    bool found = false;
    //Define node.
    Node* curPtr = headPtr;
    //Loop until node reaches null.
    while (!found && (curPtr != nullptr))
    {
        //If entry matches.
        if (anEntry == curPtr->getItem())
            //Set boolean variable.
            found = true;
            //If entry not matches.
        else
            //Move to next node.
            curPtr = curPtr->getNext();
    }
    //Retunr current pointer .
    return curPtr;
}
// Comment
// File Name: BagInterface.h
//Include libraries.
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE
#include<iostream>
//Use std namespace.
using namespace std;
//Define a class "BagInterface" to define methods in bag.

class BagInterface
{
//Add the code from "BagInterface.h".
// .
// .
// .
};
//End of file.
#endif
// Comment
// File Name: Main.cpp
//Include libraries.
#include<iostream>
#include<string>
#include "LinkedBag.cpp"
//Use std namespace.
using namespace std;
//Define a function "displayBag()" to display bag items.
void displayBag(LinkedBag& bag)
{
    //Define a bag for items.
    vector bagItems = bag.toVector();
    //Declare variable.
    int numberOfEntries = (int) bagItems.size();
    //Loop until count of entries.
    for (int i = 0; i < numberOfEntries; i++)
    {
        //Display each item.
        cout << bagItems[i] << " ";
    }
    //Display new line.
    cout << endl << endl;
}

/* Define a function "copyConstructorTester()" to copy bag contents.*/
void copyConstructorTester()
{
    //Define a new bag.
    LinkedBag bag;
    //Define items.
    string items[] = {"zero", "one", "two", "three", "four", "five"};
    //Loop until count.
    for (int i = 0; i < 6; i++)
    {
        //Display items.
        cout << "Adding " << items[i] << endl;
        //Declare variable.
        bool success = bag.add(items[i]);
        //If not success.
        if (!success)
        //Display message.
        cout << "Failed to add " << items[i] << " to the bag." << endl;
    }
    //Call "displayBag()" to display bag.
    displayBag(bag);
    //Define new bag.
    LinkedBag copyOfBag(bag);
    //Diplay message.
    cout << "Copy of bag: ";
    //Display copy of bag.
    displayBag(copyOfBag);
    //Display message.
    cout << "The copied bag: ";
    //Display message.
    displayBag(bag);
}

//Define a function "bagTester" to check for bag operations.
void bagTester()
{
    //Define a new bag.
    LinkedBag bag;
    //Define items.
    string items[] = {"one", "two", "three", "four", "five", "six"};
    //Loop until count.
    for (int i = 0; i < 6; i++)
    {
        //Add each item.
        bag.add(items[i]);
    }
    //Display message.
    cout << "The current size of bag is" << bag.getCurrentSize() << endl;
    //Display message
    cout<<"The items in bag are:"<
    //Call "display" to display bag contents.
    bag.display();
}

//Define main method.
int main()
{
    //Call bag tester method.
    bagTester();
    //Pause console window.
    system("pause");
    //Return 0.
    return 0;
}
// Comment
// Sample Output:
// The current size of bag is6
// The items in bag are:
// one two three four five six

// Recursive version of “ getCurrentSize() ”definition:
// //Define a recursive version of "getCurrentSize()" method.
// template
int LinkedBag::getCurrentSize() const
{
    //Make recursive call.
    return recursiveCounter(headPtr);
}

int LinkedBag::recursiveCounter(Node* curPtr) const
{
    //If pointer reaches null.
    if (curPtr == nullptr)
        //Return 0.
        return 0;
        //If not null.
    else
        //Make recursive call to compute size.
        return 1 + recursiveCounter(curPtr->getNext());
}