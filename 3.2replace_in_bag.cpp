// Write a client function replace that replaces a given item in a given bag with another given item.
//  The function should return a boolean value to indicate whether the replacement was successful.

bool relpace(int x,int location,int *bag[])

{

    int i=0;

    while(i<location) // loop for go to location in bag

    {

        bag++;

        i++;

    }

    i--;

    *bag=x; // replacing value to x;

    return true; // returning true

}

