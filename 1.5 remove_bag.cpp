// Suppose that a bag contains strings that represent various grocery items. 
// Write a C++ function that removes and counts all occurrences of a given string from such a bag. 
// Your function should return this number. Use comments in javadoc style to fully specify your function.
//  Accommodate the possibility 
// that the given bag is either empty or does not contain any occurrences of the given string.


#include <iostream> 

#include <vector> 

#include <string> 

using namespace std; 

vector<string> bags; 

vector<string> TMP; 

int SZ; 

/* Returns if the bag is empty or full*/ 

bool isEmpty() 

{ 

    SZ = sizeof(bags); 

    return (!SZ); 

} 

/* Checks whether the user doesn't need any more inputs*/ 

bool check(string str) 

{ 

    return (str=="NO" || str=="no" || str=="No" || str=="n" ||str=="N"); 

} 

/*This Function takes string str as input and returns the number of removals performed*/ 

int remove_this_string(string str) 

{ 

    int i,del_items=0; 

    TMP.clear(); 

/*The case when the bag is empty*/ 

    if(isEmpty()) 

    { 

        cout<<"No deletion possible. This bag is empty\n"; 

        return 0; 

    } 

/*Store the bag contents other than the one that has to removed in other bag called TMP. Now remove the item you want to remove.*/ 

    SZ = bags.size(); 

    for(i=0;i<SZ;i++) 

    { 

        if(bags[i]!=str) 

            TMP.push_back(bags[i]); 

        else 

            del_items++; // mantain the count 

    } 

    bags.clear(); 

/*Now bring back the items*/ 

    for(i=0;i<TMP.size();i++) 

    { 

        bags.push_back(TMP[i]); 

    } 

/*Restore the new size*/ 

    SZ = bags.size(); 

    /*return the number of deleted items*/ 

    return del_items; 

} 

/*Driver Function*/ 

int main() 

{ 

    int i,count; 

    string str; 

    //Fill the bag 

    while(1) 

    { 

        cout<<"Enter a String (Enter \"No\" to Terminate\") :"; 

        cin>>str; 

        if(check(str)) 

            break; 

        bags.push_back(str); 

        cout<<"Inserted\n"; 

    } 

    cout<<"\nEnter the name of the string to be removed from the bag: "; 

    cin>>str; 

    count = remove_this_string(str); 

    //Display Work 

    if(!count) 

    { 

        cout<<"No items deleted\n"; 

    } 

    else 

    { 

        cout<<count<<" item(s) successfully removed\n"; 

        cout<<"\n\nRefreshed contents are: \n"; 

        for(i=0;i<SZ;i++) 

        { 

            cout<<"Item "<<i+1<<" : "<<bags[i]<<endl; 

        } 

    } 

    return 0; 

} 
 

 