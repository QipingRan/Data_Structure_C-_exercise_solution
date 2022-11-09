// Specify and define a method for LinkedBag that removes a random entry from the bag.


// “ remove() ”definition:
// /* Define a method "remove()" to remove a random entry from bag.*/
// template
ItemType LinkedBag::remove()
{
    //Declare variable.
    int randomIndex = abs(rand() % itemCount);
    //Define a node pointer.
    Node* nodePtr = headPtr;
    //Loop until length.
    for (int counter = 0; counter < randomIndex; counter++)
        //Move to next node.
        nodePtr = nodePtr->getNext();
        //Define new node.
        ItemType removedEntry = nodePtr->getItem();
        //Call "remove()" to remove entry.
        remove(removedEntry);
    //Return.
    return removedEntry;
}

// Complete Program:
// Refer for “Listing 4-4” in chapter 4.
// The following code illustrates the operation in a linked bag.
// File Name: Node.h
//Include library.
#ifndef _NODE
#define _NODE
//Define a class "Node" for methods in node.

class Node
{
    //Define access specifier.
    private:
        //Define item.
        ItemType item;
        //Define pointer to next node.
        Node* next;
        //Define access specifier.
    public:
        //Define a constructor.
        Node();
        //Define a constructor with parameters.
        Node(const ItemType& anItem);
        //Define a constructor with parameters.
        Node(const ItemType& anItem, Node* nextNodePtr);
        /*Function Prototypes.*/
        void setItem(const ItemType& anItem);
        void setNext(Node* nextNodePtr);
        ItemType getItem() const ;
        Node* getNext() const ;
};
#endif
// Comment
// File Name: Node.cpp
//Include libraries.
#include "Node.h"
#include<iostream>
//Define a constructor.
Node:: Node() : next(nullptr)
{
}

//Define a constructor with parameters.
Node::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
}

//Define a constructor with parameters.
Node::Node(const ItemType& anItem, Node* nextNodePtr) :item(anItem),
next(nextNodePtr)
{
}

//Define a method "setItem()" to set item.
template void Node::setItem(const ItemType& anItem)
{
    //Set item.
    item = anItem;
}

//Define a method "setNext()" to set next item.
template void Node:: setNext(Node* nextNodePtr)
{
    //Set next.
    next = nextNodePtr;
}

//Define a method "getItem()" to get item.
template ItemType Node::getItem() const
{
    //Return item.
    return item;
}

//Define a method "getNext()" to get next item.
template Node* Node:: getNext() const
{
    //Return.
    return next;
}
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
    //Define access specifier.
    private:
        //Define pointer to head node.
        Node* headPtr;
        //Declare variables.
        int itemCount;
        /*Function Prototype*/
        Node* getPointerTo(const ItemType& target) const;
        //Define access specifier.
    public:
        //Define a constructor.
        LinkedBag();
        //Define a Copy constructor.
        LinkedBag(const LinkedBag& aBag);
      
        //Define a Destructor.
        virtual ~LinkedBag();
        /*Function Prototypes*/
        int getCurrentSize() const;
        bool isEmpty() const;
        bool add(const ItemType& newEntry);
        ItemType remove();
        bool remove(const ItemType& anEntry);
        void clear();
        bool contains(const ItemType& anEntry) const;
        int getFrequencyOf(const ItemType& anEntry) const;
        vector toVector() const;
};
//End of file.
#endif
// Comment
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

LinkedBag::~LinkedBag()
{
    //Clear.
    clear();
}

bool LinkedBag::isEmpty() const
{
    //Return item count.
    return itemCount == 0;
}

int LinkedBag::getCurrentSize() const
{
    //Return count.
    return itemCount;
}

bool LinkedBag::add(const ItemType& newEntry)
{
    //Define a new node.
    Node* newNodePtr = new Node();
    //Set item.
    newNodePtr->setItem(newEntry);
    //Set next item.
    newNodePtr->setNext(nullptr);
    //If bag is empty.
    if (isEmpty())
        //Set new node as head.
        headPtr = newNodePtr;
        //If not empty.
    else
    {
        //Find last node:
        Node* lastNodePtr = headPtr;
        //Loop until count.
        for (int counter = 1; counter < itemCount; counter++)
            //Move to next node.
            lastNodePtr = lastNodePtr->getNext();
            // Link new node to end of chain
            lastNodePtr->setNext(newNodePtr);
    }
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

ItemType LinkedBag::remove()
{
    //Declare variable.
    int randomIndex = abs(rand() % itemCount);
    //Define a node pointer.
    Node* nodePtr = headPtr;
    //Loop until length.
    for (int counter = 0; counter < randomIndex; counter++)
        //Move to next node.
        nodePtr = nodePtr->getNext();
        //Define new node.
        ItemType removedEntry = nodePtr->getItem();
        //Call "remove()" to remove entry.
        remove(removedEntry);
        //Return.
    return removedEntry;
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

/* Define a method "getPointerTo()" to return pointer to node.*/
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
    //Define access specifier.
    public:
        /*Function Prototypes.*/
        virtual ItemType remove() = 0;
        virtual int getCurrentSize() const = 0;
        virtual bool isEmpty() const = 0;
        virtual bool add(const ItemType& newEntry) = 0;
        virtual bool remove(const ItemType& anEntry) = 0;
        virtual void clear() = 0;
        virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
        virtual bool contains(const ItemType& anEntry) const = 0;
        virtual vector toVector() const = 0;
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
    //Display size.
    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
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
    //Display message.
    cout << "Testing the Link-Based Bag:" << endl;
    //Display message.
    cout << "isEmpty: returns " << bag.isEmpty()<< "; should be 1 (true)" << endl;
    //Display bag.
    displayBag(bag);
    //Define items.
    string items[] = {"one", "two", "three", "four", "five", "one"};
    //Display message.
    cout << "Add 6 items to the bag: " << endl;
    //Loop until count.
    for (int i = 0; i < 6; i++)
    {
        //Add each item.
        bag.add(items[i]);
    }
    //Display bag.
    displayBag(bag);
    //Display message
    cout << "remove(): returns " << bag.remove() << "; should be 1 (true)" << endl;
}

//Define main method.
int main()
{
    //Call copy constructor.
    copyConstructorTester();
    //Call bag tester method.
    bagTester();
    //Pause console window.
    system("pause");
    //Return 0.
    return 0;
}
// Comment
// Sample Output:
// Adding zero
// Adding one
// Adding two
// Adding three
// Adding four
// Adding five
// The bag contains 6 items:
// five four three two one zero
// Copy of bag: The bag contains 6 items:
// five four three two one zero
// The copied bag: The bag contains 6 items:
// five four three two one zero
// Testing the Link-Based Bag:
// isEmpty: returns 1; should be 1 (true)
// The bag contains 0 items:
