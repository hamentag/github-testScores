//******************************************************************
// Program Name: testScores3.cpp
// Programmer: Hamza Amentag
// Date Turned in: September 9, 2023
// Program Function: 
//******************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
void getData(string*, int*, int);
void sortData(string*, int*, int);
void displayUnsortedData(string*, int*, int);
void displaySortedData(string*, int*, int);
void calculateAverage(int*, int);

int main()
{
    const int NUM_SCORES = 20;  
    string* names = nullptr;   
    int* scores = nullptr;	    

    // Allocate new arrays large enough to hold names and scores
    names = new string[NUM_SCORES];
    scores = new int[NUM_SCORES];

     // Get the students' name-score pairs 
    getData(names, scores, NUM_SCORES);

    

    // Free dynamically allocated memory
    delete[] scores;
    scores = nullptr;

    return 0;
}
//***************************************************************************
// The getData function gets the names and test scores values from the user *
//***************************************************************************
void getData(string* arrName, int* arrScr, int size)
{
    ifstream inputFile;
    inputFile.open("StudentData.txt");
    cout << "Reading Data from the file...";
    for (int count = 0; count < size; count++)
    {
        inputFile >> *(arrName + count);
        inputFile >> *(arrScr + count);
    }
    inputFile.close();
}
