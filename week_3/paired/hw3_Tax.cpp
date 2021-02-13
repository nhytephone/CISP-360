/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #ch3 - Box Tax (paired programming)
Source file name: hw3_Tax.cpp
Program description: a program that asks for the actual value of a piece of
                     property and displays the assessment value and property tax.
*****************************************************/

#include <iostream>   // provides std::cin, std::cout, std::left, std::right,
                      //          std::endl
#include <iomanip>    // provides std::setw

using namespace std;

int main()
{
  float prop_val;
  float ass_val;
  float prop_tax;
  cout << "Enter the actual value of the property: ";
  cin >> prop_val;
  ass_val = (prop_val * 0.6);
  prop_tax = ((ass_val / 100) * 0.75);
  cout << endl;
  cout << "Assessment Value: $" << setw(10) << right << fixed << setprecision(2)
       << ass_val << endl;
  cout << "Property Tax:     $" << setw(10) << right << fixed << setprecision(2)
       << prop_tax << endl;
  }
