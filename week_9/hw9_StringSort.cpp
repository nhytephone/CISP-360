/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #9 (ch8) - SelectionBubbleSorting (paired programming)
Source file name: hw9_StringSort.cpp
Program description: Modification of the SortingOrder program so it sorts an
 array of strings instead of an array of ints.
*****************************************************/

#include<iostream>
#include<string>
using namespace std;

void bubbleSort(string array[], int size);
void selectionSort(string array[], int size);
int main()
{
    const int NUM_NAMES =20;

    string names[NUM_NAMES]={"Collins, Bill", "Smith, Bart", "Allen, Jim",
                             "Giffin, Jim","Stamey, Marty","Rose, Geri",
                             "Taylor, Terri","Johnson, Jill","Allison Jeff",
                             "Looney, Joe","Wolfe, Bob","James, Jean",
                             "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                             "Javens, Renee","Harrison, Rose","Setzer, Cathy",
                             "Pike, Gordon","Holland, Beth"
                             };
    selectionSort(names,NUM_NAMES);
    bubbleSort(names,NUM_NAMES );

}

void displayArray(string array[], int size, int total)
{
    cout << "After pass " << total << ":";
    for (int count = 0; count < (size); count++)
    {
        cout << endl << array[count];
    }
    cout << endl;

}

void bubbleSort(string array[], int size)
{
    bool swap;
    string temp;
    int total = 1;
    cout << "Now performing the bubble sort" << endl
    << "------------------------------" << endl;

    do{
        swap = false;
        for (int count = 0; count < (size -1); count++)
        {
            if (array[count] > array[count+1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }

            total++;
        }

    } while(swap);
    displayArray(array, size, total);

}

void selectionSort(string array[], int size)
{
    int startScan, minIndex;
    string  minValue;
    int total = 1;
    cout << "Now performing the selection sort" << endl
    << "------------------------------" << endl;
    for (startScan = 0; startScan < (size -1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan +1; index < size; index++)
        {
            if (array[index] < array[startScan])
            {
                minValue = array[index];
                minIndex = index;
            }
        }

        total++;
        array[minIndex] = array[startScan];
        array[startScan] = minValue;


    }
    displayArray(array, size, total);
}
