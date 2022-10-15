// Consider the problem of finding the greatest common divisor (gcd) of two positive integers a and b.
//  The algorithm presented here is a variation of Euclid’s algorithm,
//   which is based on the following theorem:4

// 4 This book uses mod as an abbreviation for the mathematical operation modulo.
//  In C++, the modulo operator is %.

// Theorem. If a and b are positive integers with a > b such that b is not a divisor of a, 
// then

// gcd(a, b)=gcd(b, a mod b).
// This relationship between gcd(a, b) and gcd(b, a mod b) is the heart of the recursive solution. 
// It specifies how you can solve the problem of computing gcd(a, b) in terms of another problem of the same type. 
// Also, if b does divide a, then b = gcd(a, b), so an appropriate choice for the base case is (a mod b) = 0.

// This theorem leads to the following recursive definition:

 
// gcd(a, b)={bif (a mod b)=0gcd(b, a mod b)otherwise
// The following function implements this recursive algorithm:


// int gcd(int a, int b)
// {
//    if (a % b == 0) // Base case
//       return b;
//    else
//       return gcd(b, a % b);
// } // end gcd
// Prove the theorem.

// What happens if b > a?

// How is the problem getting smaller? (That is, do you always approach a base case?) 
// Why is the base case appropriate?

