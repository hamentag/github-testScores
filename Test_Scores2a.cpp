#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
void getData(int*, int); // +names

int main()
{
    string* names = nullptr;   // To dynamically allocate an array for names
    int* scores = nullptr;	   // To dynamically allocate an array for scores
    int numScores;		   	   // To hold the number of test scores

    // Get the number of test scores
    cout << "How many test scores would you like to process? ";
    cin >> numScores;
    //

    // Validate the input (Program does not accept negative values)
    while (numScores <= 0)
    {
        // Explain the error and get the input again
        cout << "You should enter a positive number: ";
        cin >> numScores;
        //
    }

    // Allocate a new array large enough to hold names and scores
    names = new string[numScores];
    scores = new int[numScores];

    
    // Free dynamically allocated memory
    delete[] scores;
    scores = nullptr;

    return 0;
}