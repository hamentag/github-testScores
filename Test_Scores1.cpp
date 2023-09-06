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
