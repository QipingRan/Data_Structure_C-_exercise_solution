// Write iterative versions of the following recursive functions:
//  fact, writeBackward, binarySearch, and kSmall.

// Complete program is as follows:
// The following program demonstrates the functionality of the Iterative function “fact()”:
//Include Header files
#include<iostream>
using namespace std;
//Define function fact()
long fact(int n)
{
    //Declare variable it
    int it;
    //Declare variable resultValue
    long resultValue;
    //if the value of n is lesser than 1
    if (n < 1)
    {
        //assign value as 0
        resultValue = 0;
    }
    //else statement
    else
    {
        //assign a value as 1
        resultValue = 1;
        //Use loop to compute factorial
        for (it = 2; it <= n; it++)
        //calculate fact
            resultValue *= it;
    }
    //return the result
    return resultValue;
}

//Program begins with a main function
int main()
{
    //Print the result by calling the function
    cout<<"Factorial Value:"<<fact(10)<<endl;
    //To pause window
    cin.get();cin.get();
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Factorial Value:120

#include<iostream>
#include<string>
using namespace std;
//define a function writeBackward
void writeBackward(string strValue)
{
    //Use loop to print in backward order
    for (int it = strValue.size() - 1; it >= 0; it--)
        //Print the result
        cout << strValue[it];
        //Print the next line
    cout << endl;
}

//Program begins with a main
int main()
{
    //Print a statement
    cout<<"Value:";
    //Call the function writeBackward by passing a value
    writeBackward("123456");
    //To pause the result
    cin.get();cin.get();
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Value:654321


// Complete program is as follows:
// The following program demonstrates the functionality of the Iterative function “binarySearch()”:
// //include Header files
#include<iostream>
using namespace std;
//Define a function binarySearch()
int binarySearch(int anArray[], int key, int low, int high)
{
    //declare variables
    int mid, resultValue;
    //Use while loop
    while (low < high)
    {
        //Calculate the mid term
        mid = (low + high)/2;
        //if element is equal to key
        if (anArray[mid] == key)
        {
            //Assign mid as low
            low = mid;
            //Assign mid as high
            high = mid;
        }
        //else if element lesser than key
        else if (anArray[mid] < key)
            //Check the upper half
            low = mid + 1;
            //else statement
        else
            //check the lower half
            high = mid - 1;
    }
    //if the low is greater than high
    if (low > high)
        //return -1
        resultValue = -1;
        //else if low not equal to key
    else if (anArray[low] != key)
        //return -1
        resultValue = -1;
        //else statement
    else
        //Assign the result as low
        resultValue = low;
        //return the result
    return resultValue;
}
//Program begins with a main function
int main()
{
    //Declare the required variables
    int anArray[50],low,mid,high,it,n,key;
    //Prompt the array size
    cout<<"Enter the Array Size:"<<endl;
    //get the size
    cin>>n;
    //Prompt the number of elements in sorted order
    cout<<"Enter the array values in sorted order:"<
    //Use loop to get n values
    for(it=0;it<=n;i++)
    {
        //get the array elements
        cin>>anArray[it];
    }
    //Prompt the key element
    cout<<"Enter the value to search in the Array:"<<endl;
    //get the key value
    cin>>key;
    //Assign low as 0
    low=0;
    //High as n-1
    high=n-1;
    //Print the result by calling binarySearch()
    cout<<"Value is found at position:"<
    //to pause the result
    cin.get();cin.get();
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Enter the Array Size:
// 5

#include<iostream>
using namespace std;
//Define function kSmall()
int kSmall(int k, int anArray[], int n)
{
    //Use for loop to check k
    for (int it=0; it<n;it++)
        //Use for loop to check size
        for (int jt = it+1; jt < n; jt++)
            //compare the values
            if (anArray[jt] < anArray[it])
                //call the swap function
                swap(anArray[it], anArray[jt]);
                //return the element
    return anArray[k-1];
}
//Define a function swap()
void swap( int aVal, int bVal)
{
    //Declare variable
    int tmp;
    //perform swap operation
    tmp=aVal;
    //assign b value to a
    aVal=bVal;
    //assign temp as b
    bVal=tmp;
}
//Program begins with a main function
int main()
{
    //Declare the required variables
    int anArray[50];
    int k,n;
    //Prompt the array size
    cout<<"Enter the Array Size:"<<endl;
    //get the size
    cin>>n;
    //Prompt the number of elements in sorted order
    cout<<"Enter the elements:"<<endl;
    //Use loop to get n values
    for(int it=0;it<n;i++)
    {
        //get the array elements
        cin>>anArray[it];
    }
    //Prompt the k element
    cout<<"Enter k value:"<<endl;
    //get the key
    cin>>k;
    //print the result by calling kSmall
    cout<<"Kth smallest element:"<<endl;
    //pause the console window
    cin.get();cin.get();
    //return statement
    return 0;
}
// Comment
// Sample Output:
// Enter the Array Size:
// 4
// Enter the elements:
// 1
// 6
// 3
// 8
// Enter k value:
// 3
// Kth smallest element:6
