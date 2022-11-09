// If headPtr is a pointer variable that points to the first node of a linked chain of at least two nodes, 
// write C++ statements that delete the second node and return it to the system.

// nodePtr del_second(nodePtr headPtr){ //nodePtr is defined type for node pointers

//     nodePtr temp;

//     temp=headPtr->next;

//     headPtr->next=(headPtr->next)->next;

//     return temp;

// }


/****************************************************************
* This program shows implementation of a program to delete *
* second node of a singly linked chain *
****************************************************************/
//Include libraries.
#include<iostream>
//Use std namespace
using namespace std;
//Define node structure.
struct node
{
    //Define node data.
    int data;
    //Define next node pointer.
    struct node *lnext;
};

//Define "deleteNode()" to delete a node.
void deleteNode(struct node *headPtr, struct node *n)
{
    //If head is to be deleted.
    if(headPtr == n)
    {
        //If next of head pointer is null.
        if(headPtr->lnext == NULL)
        {
            //Display message.
            cout<<"Single node is in list ";
            return;
        }
        //Copy next node data to headPtr.
        headPtr->data = headPtr->lnext->data;
        //Store address of next node.
        n = headPtr->lnext;
        //Remove next node link.
        headPtr->lnext = headPtr->lnext->lnext;
        //Free memory.
        free(n);
        //Return.
        return;
    }
    //Set head to previous.
    struct node *lprev = headPtr;
    /* Loop until next previous is not null and next of previous is not "n".*/
    while(lprev->lnext != NULL && lprev->lnext != n)
        //Move to next node.
        lprev = lprev->lnext;
    //If node is null.
    if(lprev->lnext == NULL)
    {
    //Display message.
    cout<<"\n Given node is not present in Linked List";
    //Return.
    return;
    }
    // Remove node from Linked List.
    lprev->lnext = lprev->lnext->lnext;

    // Free memory.
    free(n);
    //Return.
    return;
}

//Define "push()" to insert node.
void push(struct node **lhead_ref, int lnew_data)
{
    //Define new node.
    struct node *lnew_node = (struct node *)malloc(sizeof(struct node));
    //Set data to new node.
    lnew_node->data = lnew_data;
    //Set next node reference.
    lnew_node->lnext = *lhead_ref;
    //Set new node to reference.
    *lhead_ref = lnew_node;
}

//Define a function "lprintList()" to display all elements.
void lprintList(struct node *headPtr)
{
    //Loop until head reaches null
    while(headPtr!=NULL)
    {
        //Display data
        cout<data<<" ";
        //Update head pointer
        headPtr=headPtr->lnext;
    }
    //Display new line
    printf("\n");
}

//Display main method to test all methods
int main()
{
    //Initialize head to null
    struct node *headPtr = NULL;
    //Create a list
    push(&headPtr,3);
    push(&headPtr,2);
    push(&headPtr,6);
    push(&headPtr,3);
    push(&headPtr,2);
    push(&headPtr,6);
    //Display list.
    cout<<"Given Linked List: ";
    //Call "lprintList()" to display elements.
    lprintList(headPtr);
    //Display message
    cout<<"Deleting second node "<<endl;
    //Call "deleteNode()" to delete second node.
    deleteNode(headPtr, headPtr->lnext);
    //Display message
    cout<<"Modified Linked List: "<<endl;
    //Call "lprintList()" to display result.
    lprintList(headPtr);
    //Pause console window
    system("pause");
    //Return 0
    return 0;
}
// Comment
// Sample Output:
// Given Linked List: 6 2 3 6 2 3
// Deleting second node
// Modified Linked List:
// 6 3 6 2 3
