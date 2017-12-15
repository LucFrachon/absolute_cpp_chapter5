//Reads data and displays a bar graph showing productivity for each plant. 
#include <iostream> 
//#include <cmath> 

//using namespace std; 
const int NUMBER_OF_PLANTS = 4; 

void inputData(int a[], int lastPlantNumber); 
//Precondition: lastPlantNumber is the declared size of the array a. 
//Postcondition: For plantNumber = 1 through lastPlantNumber: 
//a[plantNumber-1] equals the total production for plant number 
//plantNumber. 

void scale(int a[], int size); 
//Precondition: a[0] through a[size-1] each has a nonnegative value. 
//Postcondition: a[i] has been changed to the number of 1000s (rounded to 
//an integer) that were originally in a[i], for all i such that 0 <= i 
//<= size-1. 

void graph(const int asteriskCount[], int lastPlantNumber); 
//Precondition: a[0] through a[lastPlantNumber-1] have nonnegative values. 
//Postcondition: A bar graph has been displayed saying that plant 
//number N has produced a[N-1] 1000s of units, for each N such that 
//1 <= N <= lastPlantNumber 

void getTotal(int& sum); 
//Reads nonnegative integers from the keyboard and 
//places their total in sum. 

/*int round(double number); 
//Precondition: number >= 0. 
//Returns number rounded to the nearest integer.
*/

void printAsterisks(int n);
//Prints n asterisks to the screen. 

int main() 
{ 
    int production[NUMBER_OF_PLANTS]; 

    std::cout << "This program displays a graph showing\n" 
        << "production for each plant in the company.\n"; 
    inputData(production, NUMBER_OF_PLANTS); 
    scale(production, NUMBER_OF_PLANTS); 
    graph(production, NUMBER_OF_PLANTS); 
    return 0;
} 

void inputData(int a[], int lastPlantNumber) 
{ 
    for (int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++) 
    { 
        std::cout << std::endl 
            << "Enter production data for plant number " 
            << plantNumber << std::endl; 
        getTotal(a[plantNumber - 1]);
    } 
}

void getTotal(int& sum) 
{ 
    std::cout << "Enter number of units produced by each department.\n" 
        << "Append a negative number to the end of the list.\n"; 
    sum = 0; 
    int next; 
    std::cin >> next; 
    while (next >= 0) 
    { 
        sum = sum + next; 
        std::cin >> next; 
    } 
    std::cout << "Total = " << sum << std::endl;
} 

void scale(int a[], int size)
{
    for (int index = 0; index < size; index++)
        a[index] = round(a[index] / 1000.0); 
} 

/*
int round(double number) 
{ 
    return static_cast<int>(floor(number + 0.5));
}
*/

void graph(const int asteriskCount[], int lastPlantNumber) 
{ 
    std::cout << "\nUnits produced in thousands of units:\n\n"; 
    for (int plantNumber = 1; plantNumber <= lastPlantNumber; plantNumber++) 
    { 
        std::cout << "Plant #" << plantNumber << "";
        printAsterisks(asteriskCount[plantNumber - 1]);
        std::cout << std::endl; 
    }
} 

void printAsterisks(int n) 
{ 
    for (int count = 1; count <= n; count++) 
        std::cout << "*"; 
}

