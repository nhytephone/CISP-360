/*****************************************************
Student name: Gavin Bundy, Benjamin Bunting
Student ID: w1666922, w1926518
Course #: CISP360 
Section #: 
Instruction mode: Online 
*****************************************************
Assignment #2b - Average of values
Source file name: hw2_AverageOfValues.cpp
Program description: This will compute the average of five numbers.
*****************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void number_input(double &number1, double &number2, double &number3, double &number4, double &number5);

void compute_average (double number1, double number2, double number3, double number4, double number5, double&average,double&sum);

void display_average(double average);

//main function
int main()
{
	double number1,
        number2,
        number3,
        number4,
        number5,
        sum,
        average;




number_input(number1, number2, number3, number4, number5);

compute_average(number1, number2, number3, number4, number5, average, sum);

display_average(average);

}

void number_input(double &number1, double &number2, double &number3, double &number4, double &number5)
{
cout << "Number 1: ";
cin >> number1;

cout << "Number 2: ";
cin >> number2;

cout << "Number 3: ";
cin >> number3;

cout << "Number 4: ";
cin >> number4;

cout << "Number 5: ";
cin >> number5;
}

void compute_average (double number1, double number2, double number3, double number4, double number5, double&average, double&sum)
{
  sum= (number1+number2+number3+number4+number5);

  average=sum/5;
}

void display_average(double average)
{
  cout << "Average: " << average << endl;
} 
