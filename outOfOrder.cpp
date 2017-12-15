#include <iostream>

using namespace std;

int outOfOrder(const double a[], int size);
//Precondition: a[0] through a[size - 1] have values.
//Postcondition: returns the index of the first out-of-order element of a[]
//or -1 if a[] is sorted.


int main()
{
    double myArray[] = { 0.8, 2.5, 8.2, 10.3, 25.1, 30.5, 31.2 };
    cout << outOfOrder(myArray, 7) << endl;
    return 0;
}

int outOfOrder(const double a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] > a[i + 1])  //fetch a[i+1] for each i
            return i + 1;
    }
    return -1;
}