#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int NUM_SPEEDS = 3;
const int NUM_DRIVES = 3;
const int MAX_DISPLAY = 10;  //max number of asterisks to display

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

void printGraph(const float avgMileageArr[], const float drivenMileageArr[][NUM_SPEEDS], const int sizeOfavgMileage, const int sizeOfdrivenMileage);
//Precondition:
    //avgMileage is a one-dimensional array containing sizeOfavgMileage (float) values corresponding to average mileage at 
    //  different speeds.
    //driveMileage is a two-dimensional array containing (float) values corresponding to average mileage at 
    //  different speeds, for sizeOfdrivenMileage different test drives.
    //Postcondition:
    //The mileage obtained at each speed during each test drive is displayed as a bar chart, along with the average mileage at 
    //  each speed.

float findMax(const float arr[], const int size);
//Precondition:
    //arr is an one-dimensional array of floats of size size.
    //size in the integer size of arr.
//Postcondition:
    //The highest value of arr is returned.


float findMax(const float arr[][NUM_SPEEDS], const int size);
//Precondition:
    //arr is an bi-dimensional array of floats of size size. Each sub-array is of size NUM_SPEEDS.
    //size in the integer size of arr.
//Postcondition:
    //The highest value of arr is returned.

void printAsterisks(const float value, const float maxValue, const int maxDisplay);
//Precondition:
    //value is a float that contains the value to represent as a bar of asterisks
    //maxValue is the value to scale value by.
    //maxDisplay is the maximum amount of asterisks that the user would like to display.
//Postcondition:
    //value is represented by a row of asterisks of proportional length.

char userMenu();
//Precondition: None.
//Postcondition: User chose either 'T', 'G' or 'Q' for table, graph or quit respectively; their choice is returned by the function.

int main()
{
    float avgMileage[NUM_SPEEDS];
    float drivenMileage[NUM_DRIVES][NUM_SPEEDS];

    //fill array of average mileages
    fillArray(avgMileage, NUM_SPEEDS);
    
    //fill array of driven mileages
    fillDrives(drivenMileage, NUM_DRIVES);
    
    //ask user whether they want a table or a bar graph
    char choice = userMenu();

    while (choice != 'q' && choice != 'Q')
    {
        if ('t' == choice || 'T' == choice)
        {
            //print table of test drives with average for each speed and variance, by 10kph steps
            printTable(avgMileage, drivenMileage, NUM_SPEEDS, NUM_DRIVES);
        } else if ('g' == choice || 'G' == choice)
        {
            //print a graph of test drive mileages vs average mileages
            printGraph(avgMileage, drivenMileage, NUM_SPEEDS, NUM_DRIVES);
        }
        choice = userMenu();
    }
    
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
        cout << setw(15) << d;
        for (int s = 0; s < sizeOfavgMileage; ++s)
        {
            if(0 != s) cout << setw(15) << " ";
            cout << setw(15) << (s + 1) * 10;
            cout << setw(15) << avgMileageArr[s];
            cout << setw(15) << drivenMileageArr[d][s];
            cout << setw(15) << drivenMileageArr[d][s] - avgMileageArr[s] << endl;
        }
    }
}

void printGraph(const float avgMileageArr[], const float drivenMileageArr[][NUM_SPEEDS], const int sizeOfavgMileage, const int sizeOfdrivenMileage)
{
    cout << "Mileage obtained during test drives:\n";

    //find greatest mileage value in all drives at all speeds and save as maxMileage
    float maxAvgMileage = findMax(avgMileageArr, sizeOfavgMileage);
    float maxDrivenMileage = findMax(drivenMileageArr, sizeOfdrivenMileage);
    float maxMileage = max(maxAvgMileage, maxDrivenMileage);  //used to scale the graphs

    //print title row
    cout << setw(10) << "Drive";
    cout << setw(10) << "Speed";
    cout << setw(10) << "Mileage" << endl;    
    
    //for each drive:
    for (int d = 0; d < sizeOfdrivenMileage; ++d)
    {
        cout << setw(10) << d;
        //for each speed:
        for (int s = 0; s < sizeOfavgMileage; ++s)
        {
            if (0 != s) cout << setw(10) << "";
            cout << setw(10) << s;
            //print numAsterisksDrive asterisks
            cout << setw(10) << "driven: ";
            printAsterisks(drivenMileageArr[d][s], maxMileage, MAX_DISPLAY);
            cout << endl;
            cout << setw(20) << " ";
            //print numAsterisksAvg asterisks
            cout << setw(10) << "average: ";
            printAsterisks(avgMileageArr[s], maxMileage, MAX_DISPLAY);
            cout << endl;
        }
    }
}

float findMax(const float arr[], const int size)
//Definition for one-demensional arrays
{
    float maxValue = -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > maxValue) maxValue = arr[i];
    }
    return maxValue;
}

float findMax(const float arr[][NUM_SPEEDS], const int size)
//Definition for bi-dimensional arrays
{
    float maxValue = -1;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < NUM_SPEEDS; ++j)
        {
            if (arr[i][j] > maxValue) maxValue = arr[i][j];
        }
    }
    return maxValue;
}

void printAsterisks(const float value, const float maxValue, const int maxDisplay)
{
    //calculate value of a single asterisk
    float asteriskValue = maxValue / maxDisplay;
    
    //divide and round value by asterisk value and store as numAsterisks
    float numAsterisks = static_cast<int>(floor(value + 0.5));

    //for i in {0,.., numAsterisks}, print "*"
    for (int i = 0; i < numAsterisks; ++i)
    {
        cout << "*";
    }
}

char userMenu()
{
    char choice;
    do
    {
        cout << "Would you like to see the data as a table ('t') or a graph ('g')? To quit enter 'q'.\n";
        cin >> choice;
    } while('t' != choice && 'T' != choice && 'g' != choice && 'G' != choice && 'q' != choice && 'Q' != choice);

    return choice;
}
