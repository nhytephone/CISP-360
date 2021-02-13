/*****************************************************
Student name: Kelia Hunt
Student ID: w1824157
Course #: CISP360
Section #: 1
Instruction mode: Online
*****************************************************
Assignment #1b - Lab 1&2 10
Source file name: Lab 1&210.cpp
Program description: This will display a the numbers of acres message
*****************************************************/
#include <iostream>
using namespace std;

int main()

{
//Declare variables
double squareFeet= 43560,
totalAcres,
land=389767;

// Calculate total acres
totalAcres= land/squareFeet;

//display total acres
cout<<"The total acres in a plot of land that is 389,767 square feet is:"<<totalAcres<<endl;
return 0;

}
