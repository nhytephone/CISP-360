/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #5 (ch5) - Sum Math Tutor (paired programming)
Source file name: hw5_MathTutor.cpp
Program description: A program that allows the user to select an
addition, subtraction, multiplication, or division problem.
*****************************************************/
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void GetType(int &Choice);
void DisplayMenu(int &Choice);
int Addition();
void DisplayResult(double response, double answer);

int main()
{
    int Choice; // declares Choice as integer.


    do
    {
        DisplayMenu(Choice);
        GetType(Choice);
        switch (Choice)
        {
            case 1: Addition();
                break;
            case 2: Addition();
                break;
            case 3: Addition();
                break;
            case 4: Addition();
                break;
            case 5: exit(0);
        }
    }
    while (Choice != 5);
    cout << "Thank you for using Math Tutor.";
    return 0;
}

void DisplayMenu(int &Choice)
{
    cout << "Math Tutor Menu" << endl <<endl;
    cout << "------------------------------" << endl;
    cout << "1. Addition problem" << endl << endl;
    cout << "2. Subtraction problem" << endl << endl;
    cout << "3. Multiplication problem" << endl << endl;
    cout << "4. Division problem" << endl << endl;
    cout << "5. quit the program" << endl << endl;
    cout << "------------------------------" << endl;
    cout << "Enter your choice (1-5): ";
}
void GetType(int &Choice)
{
  cin >> Choice;
  while (Choice > 5)
  {
    cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
    GetType(Choice);
  }
}

int Addition()
{

  srand (time(NULL));

  int response;
  int answer;
  int num1 = rand() % 999;
  int num2 = rand() % 999;
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
  return response;

}

void DisplayResult(double response, double answer)
{
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
