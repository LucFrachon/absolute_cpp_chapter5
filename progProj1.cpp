#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_SPEEDS = 10;
const int NUM_DRIVES = 10;

void fillArray(float arr[], const int size);
//Precondition: 
    //arr is an array of floats of size size
//Postcondition:
    //arr contains size new user-entered values

void fillDrives(float drivesArr[][NUM_SPEEDS], const int numDrives);
//Precondition:
    //drivesArr is an array of arrays of floats, of size numDrives. Each sub-array is of size NUM_SPEEDS.
//Prostcondition:
    //drivesArr is filled with user-enterd mileage values for each drive and each speed.

void printTable(const float avgMileageArr[], const float drivenMileageArr[][NUM_SPEEDS], const int sizeOfavgMileage, const int sizeOfdrivenMileage);
//Precondition:
    //avgMileage is a one-dimensional array containing sizeOfavgMileage (float) values corresponding to average mileage at 
    //  different speeds.
    //driveMileage is a two-dimensional array containing (float) values corresponding to average mileage at 
    //  different speeds, for sizeOfdrivenMileage different test drives.
//Postcondition:
    //The mileage obtained at each speed during each test drive is displayed in a table, along with the average mileage at 
    //  each speed.


int main()
{
    float avgMileage[NUM_SPEEDS];
    float drivenMileage[NUM_DRIVES][NUM_SPEEDS];

    //fill array of average mileages
    fillArray(avgMileage, NUM_SPEEDS);
    
    //fill array of driven mileages
    fillDrives(drivenMileage, NUM_DRIVES);

    //print table of test drives with average for each speed and variance, by 10kph steps
    printTable(avgMileage, drivenMileage, NUM_SPEEDS, NUM_DRIVES);
    
    return 0;
}


void fillArray(float arr[], const int size)
{
    cout << "Enter " << size << " mileage values below. Hit enter between each.\n";
    for (int m = 0; m < size; ++m)
    {
        cout << "Mileage at " << (m + 1) * 10 << " kph: ";
        cin >> arr[m];
    }
    cout << endl;
}

void fillDrives(float drivesArr[][NUM_SPEEDS], const int numDrives)
{
    cout << "Enter mileage for each drive and each speed.\n";
    for (int d = 0; d < numDrives; ++d)
    {
        cout << "Drive " << d << endl;
        fillArray(drivesArr[d], NUM_SPEEDS);
    }
}

void printTable(const float avgMileageArr[], const float drivenMileageArr[][NUM_SPEEDS], const int sizeOfavgMileage, const int sizeOfdrivenMileage)
{
    cout << "Mileage obtained during test drives:\n";
    
    cout << setw(15) << "Test Drive";
    cout << setw(15) << "Speed (kph)";
    cout << setw(15) << "Avg. mileage";
    cout << setw(15) << "Act. mileage";
    cout << setw(15) << "Difference" << endl;

    for (int d = 0; d < sizeOfdrivenMileage; ++d)
    {
        cout << setw(15) << 1;
        for (int s = 0; s < sizeOfavgMileage; ++s)
        {
            cout << setw(15) << d;
            cout << setw(15) << (s + 1) * 10;
            cout << setw(15) << avgMileageArr[s];
            cout << setw(15) << drivenMileageArr[d][s];
            cout << setw(15) << drivenMileageArr[d][s] - avgMileageArr[s] << endl;
        }
    }
}