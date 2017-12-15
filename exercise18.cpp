/*
Absolute C++ Chapter 5 Section 3
Self-test exercise 18

Read up to 10 letters into an array and write them back in reverse order.
Do not use functions.
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
    char letterBox[ARRAY_SIZE];

    cout << "Enter up to " << ARRAY_SIZE << " letters.\n"
        << "Enter a period ( . ) to end your list.\n";

    char next;
    int index = 0;
    cin >> next;
        
    while ((next != '.') && (index < ARRAY_SIZE))
    {
        letterBox[index] = next;
        index++;
        cin >> next;
    }

    cout << "You entered:\n";
    for (int i = index - 1; i >= 0; i--)
        cout << letterBox[i] << " ";

    cout << endl;
    return 0;
}