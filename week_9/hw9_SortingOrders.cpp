/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #9 (ch8) - SelectionBubbleSorting (paired programming)
Source file name: hw9_SortingOrders.cpp
Program description: a program that uses two identical arrays of just eight
integers. It should display the contents of the first array, then call a
function to sort the array using an ascending order, bubble sort modified
to print out the array contents after each pass of the sort. Next, the program
should display the contents of the second array, then call a function to sort
the array using an ascending order selection sort modified to print out the
array contents after each pass of the sort.
*****************************************************/
#include <iostream>
using namespace std;
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void displayArray(int array[], int size, int total);

int main()
{
int first_numbers[] {102, 105, 107, 103, 106, 100, 104, 101};
int second_numbers[] {102, 105, 107, 103, 106, 100, 104, 101};

bubbleSort(first_numbers, sizeof(first_numbers)/(sizeof(first_numbers[0])));
selectionSort(second_numbers, sizeof(second_numbers)/(sizeof(second_numbers[0])));
}

void displayArray(int array[], int size, int total)
{
  cout << "After pass " << total << ":";
  for (int count = 0; count < (size); count++)
  {
    cout << " " << array[count];
  }
  cout << endl;
}

void bubbleSort(int array[], int size)
{
  bool swap;
  int temp;
  int total = 1;
  cout << "Now performing the bubble sort" << endl
       << "------------------------------" << endl;
  do {
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
    displayArray(array, size, total);
    total++;
    }
  } while(swap);
  cout << endl;
}

void selectionSort(int array[], int size)
{
  int startScan, minIndex, minValue;
  int total = 1;
  cout << "Now performing the selection sort" << endl
       << "------------------------------" << endl;
  for (startScan = 0; startScan < (size -1); startScan++)
  {
    minIndex = startScan;
    minValue = array[startScan];
    for(int index = startScan +1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    displayArray(array, size, total);
    total++;
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
  cout << endl;
}
