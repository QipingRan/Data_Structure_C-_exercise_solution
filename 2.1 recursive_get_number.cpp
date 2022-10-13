// The following recursive function getNumberEqual searches the array x of n integers 
// for occurrences of the integer desiredValue . 
// It returns the number of integers in x that are equal to desiredValue . 
// For example, if x contains the ten integers 1, 2, 4, 4, 5, 6, 7, 8, 9, and 12, 
// then getNumberEqual(x, 10, 4) returns the value 2, because 4 occurs twice in x . 

// int getNumberEqual(const int x[], int n, int desiredValue)
// {
//    int count = 0;
//    if (n <= 0)
//       return 0;
//    else
//    {
//       if (x[n − 1] == desiredValue)
//          count = 1;
//       return getNumberEqual(x, n − 1, desiredValue) + count;
//    }  // end else
// }  // end getNumberEqual


