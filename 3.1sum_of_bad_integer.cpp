// Consider a bag of integers.
//  Write a client function that computes the sum of the integers in the bag aBag.

int sumOfBag(ArrayBag<int> & aBag)
{
    int sum = 0;
    int size = aBag.getCurrentSize();
    vector<int> bagContents = aBag.toVector();

    for (int i = 0; i < size; i++)
        sum += bagContents.at(i);

    return sum;
}