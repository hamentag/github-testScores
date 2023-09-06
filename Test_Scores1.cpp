//******************************************************************
// Program Name: Test_Scores1.cpp
// Programmer: Hamza Amentag
// Date Turned in: September 5, 2023
// Program Function: This program will sort, display and calculates
// the average of test scores given by the user
// Inputs:  Number of scores N; Values of test scores.
// Outputs: Unsorted test scores; Sorted test scores; Average.
//******************************************************************
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getData(int*, int);
void displayUnsortedData(int*, int);
void sortData(int*, int);
void displaySortedData(int*, int);
void calculateAverage(int*, int);

int main()
{
    int* scores = nullptr;	// To dynamically allocate an array
    int numScores;		   	// To hold the number of test scores

    // Get the number of test scores
    cout << "How many test scores would you like to process? ";
    cin >> numScores;

    // Validate the input (Program does not accept negative values)
    while (numScores <= 0)
    {
        // Explain the error and get the input again
        cout << "You should enter a positive number: ";
        cin >> numScores;
    }

    // Allocate a new array large enough to hold the number of scores
    scores = new int[numScores];

    // Get the test scores
    getData(scores, numScores);

    // Display the unsorted test scores 
    displayUnsortedData(scores, numScores);

    // Sort the test scores in ascending order
    sortData(scores, numScores);

    // Display the sorted test scores 
    displaySortedData(scores, numScores);

    // Calculate the average 
    calculateAverage(scores, numScores);
    
    // Free dynamically allocated memory
    delete[] scores;
    scores = nullptr;
   
    return 0;
}

//*****************************************************************
// The getData function gets the test scores values from the user *
//*****************************************************************
void getData(int* arr, int size)
{
    cout << "Enter the test scores.\n";
    for (int count = 0; count < size; count++)
    {
        cout << "Test " << (count + 1) << ": ";
        cin >> *(arr + count);

        // Validate the input (Program does not accept negative values)
        while (*(arr + count) < 0)
        {
            // Explain the error and get the input again
            cout << "You should enter a positive number.\n"
                << "Test " << (count + 1) << ": ";
            cin >> *(arr + count);
        }
    }
}
//*********************************************************************************
// The displayUnsortedData function displays the test scores as given by the user *
//*********************************************************************************
void displayUnsortedData(int* arr, int size)
{
    cout << "\n------------- Unsorted List -------------" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Test " << (count + 1) << ": "
            << *(arr + count) << endl;
    }
}
//*****************************************************************
// The SortData function sorts the test scores in ascending order *
//*****************************************************************
void sortData(int* arr, int size)
{
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = *(arr + start);
        for (int index = start + 1; index < size; index++)
        {
            if (*(arr + index) < minValue)
            {
                minValue = *(arr + index);
                minIndex = index;
            }
        }
        *(arr + minIndex) = *(arr + start);
        *(arr + start) = minValue;
    }
}
//*****************************************************************
// The displaySortedData function displays the sorted test scores *
//*****************************************************************
void displaySortedData(int* arr, int size)
{
    cout << "\n---- Sorted List in ascending order ----" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Test " << (count + 1) << ": "
            << *(arr + count) << endl;
    }
}
//***************************************************************************
// The calculateAverage function calculates and displays the average scores *
//***************************************************************************
void calculateAverage(int* array, int size)
{
    double average,			 // To hold average scores
        total = 0.0;         // Accumulator
    // Calculate the total 
    for (int count = 0; count < size; count++)
        total += *(array + count);

    // Calculate the average 
    average = total / size;

    // Display the average
    cout << fixed << showpoint << setprecision(2);
    cout << "----------------------------------------\n"
        << "Average Test Scores: " << average << endl;
}
