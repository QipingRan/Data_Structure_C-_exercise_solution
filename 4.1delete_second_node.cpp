// If headPtr is a pointer variable that points to the first node of a linked chain of at least two nodes, 
// write C++ statements that delete the second node and return it to the system.

nodePtr del_second(nodePtr headPtr){ //nodePtr is defined type for node pointers

    nodePtr temp;

    temp=headPtr->next;

    headPtr->next=(headPtr->next)->next;

    return temp;

}