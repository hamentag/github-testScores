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

    // Display the unsorted list Names/scores 
    displayUnsortedData(names, scores, NUM_SCORES);

    // Sort the list names/scores in ascending order
    sortData(names, scores, NUM_SCORES);

    

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
//***************************************************************************
// The displayUnsortedData function displays the data as read from the file *
//***************************************************************************
void displayUnsortedData(string* arrName, int* arrScr, int size)
{
    cout << "\n------------- Unsorted List -------------" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Student " << (count + 1) << ":\t"
            << left << setw(8) << *(arrName + count) << "\t"
            << *(arrScr + count) << endl;
    }
}
//*****************************************************************************
// The SortData function sorts the list names//test scores in ascending order *
//*****************************************************************************
void sortData(string* arrName, int* arrScr, int size)
{
    int minIndex, minValue; string minValName;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = *(arrScr + start);
        minValName = *(arrName + start);
        for (int index = start + 1; index < size; index++)
        {
            if (*(arrScr + index) < minValue)
            {
                minValue = *(arrScr + index);   minValName = *(arrName + index);
                minIndex = index;
            }
        }
        //swap      
        *(arrScr + minIndex) = *(arrScr + start);   *(arrName + minIndex) = *(arrName + start);
        *(arrScr + start) = minValue;               *(arrName + start) = minValName;
    }
}