/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #4 (ch4) - BMI Math Tutor (paired programming)
Source file name: hw4_BMI.cpp
Program description: A program that calculates and displays
a person’s body mass index (BMI).
*****************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  float weight,
        height,
        bmi;
  cout << "Enter your weight in pounds: ";
  cin >> weight;
  cout << "Enter your height in inches: ";
  cin >> height;
  bmi = weight * 703 / pow(height,2);
  cout << "Your BMI is " << bmi << endl;

  if (bmi < 18.5)
  {
    cout << "Congratulations! Your weight is underweight.";
  }
  else if (bmi >= 18.5 && bmi <= 25)
  {
    cout << "Congratulations! Your weight is optimal.";
  }
  else
  {
    cout << "Congratulations! Your weight is overweight.";
  }

}
