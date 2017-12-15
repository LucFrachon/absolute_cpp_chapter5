/* 
Absolute C++ Chapter 5 Section 3
Self-test exercise 17

Read 10 non-negative numbers into an array and write them back on screen.
Do not use any functions.
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
    double numberArray[ARRAY_SIZE];

    cout << "Enter up to " << ARRAY_SIZE << " positive numbers.\n"
        << "Enter a negative number to end your list.\n";

    int next, index = 0;
    cin >> next;

    while ((next >= 0) && (index < ARRAY_SIZE))
    {
        numberArray[index] = next;
        index++;
        cin >> next;
    }

    cout << "You entered:\n";
    for (int i = 0; i < index; i++)
        cout << numberArray[i] << " ";

    cout << endl;
    return 0;
}