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
#include <chrono>

using namespace std;

void GetType(int &Choice);
void DisplayMenu(int &Choice);
void Addition(float &num1, float &num2, double &answer, double &response);
void Subtraction(float &num1, float &num2, double &answer, double &response);
void Multiplication(float &num1, float &num2, double &answer, double &response);
void Division(float &num1, float &num2, double &answer, double &response);
void DisplayResult(double response, double answer);
void DisplayResultDecimal(double response, double answer);
void RefreshRandom(float &num1, float &num2);
int main()
{
    auto begin = std::chrono::high_resolution_clock::now();

    int Choice; // declares Choice as integer.

    srand (time(NULL));

    double response;
    double answer;
    float num1;
    float num2;



    do
    {
        DisplayMenu(Choice);
        GetType(Choice);
        switch (Choice)
        {
            case 1: Addition(num1, num2, answer, response);
                break;
            case 2: Subtraction(num1, num2, answer, response);
                break;
            case 3: Multiplication(num1, num2, answer, response);
                break;
            case 4: Division(num1, num2, answer, response);
                break;
            case 5: cout << "Thank you for using Math Tutor." << endl << endl
                             << "--------------------------------" << endl;
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                printf("Process exited after %.1f seconds with return value 0\n", elapsed.count() * 1e-9);
                  exit(0);
        }

    }
    while (Choice != 5);



}

void DisplayMenu(int &Choice)
{
    cout << "Math Tutor Menu" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Addition problem" << endl;
    cout << "2. Subtraction problem" << endl;
    cout << "3. Multiplication problem" << endl;
    cout << "4. Division problem" << endl;
    cout << "5. quit the program" << endl;
    cout << "------------------------------" << endl;
    cout << "Enter your choice (1-5): ";
}
void GetType(int &Choice)
{
  cin >> Choice;
  while (Choice > 5 || Choice < 1)
  {
    cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
    GetType(Choice);
  }
}

void Addition(float &num1, float &num2, double &answer, double &response)
{
  RefreshRandom(num1, num2);
  answer = num1 + num2;
  cout << setw(5) << right << fixed << std::setprecision(0) << endl << endl
       << num1 << endl
       << "+ " << num2 << endl
       << " ----"  << endl
       << "  " ;
  cin >> response;
  DisplayResult(response, answer);
}

void Subtraction(float &num1, float &num2, double &answer, double &response)
{
  RefreshRandom(num1, num2);
  answer = num1 - num2;
  cout << setw(5) << right << fixed << std::setprecision(0) << endl << endl
       << num1 << endl
       << "- " << num2 << endl
       << " ----"  << endl
       << "  " ;
  cin >> response;
  DisplayResult(response, answer);
}

void Multiplication(float &num1, float &num2, double &answer, double &response)
{
  RefreshRandom(num1, num2);
  answer = num1 * num2;
  cout << setw(5) << right << fixed << std::setprecision(0) << endl << endl
       << num1 << endl
       << "* " << num2 << endl
       << " ----"  << endl
       << "  " ;
  cin >> response;
  DisplayResult(response, answer);
}

void Division(float &num1, float &num2, double &answer, double &response)
{
  RefreshRandom(num1, num2);
  answer = num1 / num2;
  cout << setw(5) << right << fixed << std::setprecision(0) << endl << endl
       << num1
       << " / " << num2
       << " = ";
  cin >> response;
  DisplayResultDecimal(response, answer);
}

void DisplayResult(double response, double answer)
{
  if (answer == response)
  {
    cout << std::setprecision(0) << fixed << endl
         << "Congratulations! That's right" << endl << endl;
  }
  else
  {
    cout << std::setprecision(0) << fixed << endl
         << "Sorry the correct answer is " << answer << endl << endl;
  }

}

void DisplayResultDecimal(double response, double answer)
{
  if (answer == response)
  {
    cout << std::setprecision(5) << fixed << endl
         << "Congratulations! That's right" << endl << endl;
  }
  else
  {
    cout << std::setprecision(5) << fixed << endl
         << "Sorry the correct answer is " << answer << endl << endl;
  }

}

void RefreshRandom(float &num1, float &num2)
{
  num1 = rand() % 999;
  num2 = rand() % 999;
}
