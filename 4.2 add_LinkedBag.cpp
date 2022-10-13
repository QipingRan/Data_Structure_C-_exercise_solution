// Revise the public method add in the class LinkedBag 
// so that the new node is inserted at the end of the linked chain.

public void add(NODE *node1,int x)

{

    while(node1->next!=null)

    {

        node1++;

    }

    node1->value=x;

    node1->next=null;

}