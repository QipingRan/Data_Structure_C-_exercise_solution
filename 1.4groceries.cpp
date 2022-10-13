// Imagine that you have just left a store with a bag of groceries. 
// You are concerned that the fragile items will not survive the trip home, 
// so when you reach your car, you place those items into their own bag. 
// If Bag is a class of bags, write C++ statements that remove all the items from storeBag 
// and place them into one of two new bags, as follows: Place all occurrences of bread 
// and eggs into fragileBag, and all other items into groceryBag. 
// When you are done, storeBag should be empty. Assume that grocery items are represented by strings.




#include <iostream> 

using namespace std; 

#include <iostream> // For cout and cin 

#include <string> // For string objects 

#include "Bag.h" // For ADT bag 

using namespace std; 

int main() 

{ 

    int y=0; 

    string clubs[] = { "eggs", "eggs", "eggs", "orange", "bread", "bread" }; 

    Bag<string> grabBag; 

    Bag<string> fragileBag; 

    for (int x = 0; x < 6; x++) { 

        grabBag.add(clubs[x]); 

    } 

 
    int count = 0; 
    for (int q = 0; q < 6 ; q++) 

    { 

        if (clubs[y] == "eggs" || clubs[y] == "bread") { 

            fragileBag.add(clubs[y]); 

            if(grabBag.remove("eggs")){ 
                ++count; 
            } 
        } 

        y++; 

    } 

    cout << "fragile bag contains:" << endl; 

    fragileBag.displayBagContents(); 

    cout << "grocery bag contains:" << endl; 

    grabBag.displayBagContents(); 

    cout << "Number of items removed from grocery bag : " << count<<endl; 

    return 0; 

}