/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #5 (ch5) - Sum Math Tutor (paired programming)
Source file name: hw5_Sum.cpp
Program description: A program that asks the user for a positive integer value.
The program then uses a loop to get the sum of all the integers from 1 up to
the number entered
*****************************************************/
#include <iostream>
#include <chrono>
using namespace std;
void response_sanity(int &response);

int main()
{
  auto begin = std::chrono::high_resolution_clock::now();
  int response;
  int sum = 0;
  cout << "Enter a positive integer value: ";
  cin >> response;
  response_sanity(response);
  for (int i = 0; i <= response; i++)
  {
    sum += i;
  }
  cout << endl
       << "The sum of the numbers 1 - " << response << " is " << sum << "."
       << endl << endl
       << "----------------------------------" << endl;


  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf("Process exited after %.1f seconds with return value 0", elapsed.count() * 1e-9);
}

void response_sanity(int &response)
{
  while (response < 0 )
  {
    cout << endl << "The starting number must be positive." << endl
         << "Enter a positive integer value: ";
    cin >> response;
  }
}
