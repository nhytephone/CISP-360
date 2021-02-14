/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #4 (ch4) - BMI Math Tutor (paired programming)
Source file name: hw4_MathTutor.cpp
Program description: The program that displays two random
numbers that are to be added.
*****************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{

  srand (time(NULL));
  int num1 = rand();
  int num2 = rand();
  int response;
  int answer;
  num1 = rand() % 1000;
  num2 = rand() % 1000;
  answer = num1 + num2;
  cout << setw(5) << right << fixed << num1 << endl
       << "+ " << num2 << endl
       << "-----" << endl << endl
       << "Enter your answer here: ";
  cin >> response;
  if (answer == response)
  {
    cout << endl << "Congratulations!" << endl << "The answer is " << answer << endl;
  }
  else
  {
    cout << "Sorry that is incorrect." << endl
         << "The answer is " << answer << endl;
  }

}
