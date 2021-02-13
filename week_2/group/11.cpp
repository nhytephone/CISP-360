/*****************************************************
Student name: Kelia Hunt
Student ID: w1824157
Course #: CISP360
Section #: 1
Instruction mode: Online
*****************************************************
Assignment #1b - Lab 1&2 10
Source file name: Lab 1&210.cpp
Program description: This will display a the ocean levels message
*****************************************************/
#include <iostream>
using namespace std;
int main()
{
//Declare variables
double oceanLevel=1.5,
yearF=5,
yearS=7,
yearT=10,
totalF,
totalS,
totalT;

// Calculate ocean level in five years
totalF=oceanLevel*yearF;

// Calculate ocean level in seven years
totalS=oceanLevel*yearS;

// Calculate ocean level in ten years
totalT=oceanLevel*yearT;


//display ocean level
cout<<"The ocean level is "<<totalF<<" millimeters higher in 5 years"<<endl;
cout<<"The ocean level is "<<totalS<<" millimeters higher in 7 years"<<endl;
cout<<"The ocean level is "<<totalT<<" millimeters higher in 10 years"<<endl;

return 0;

}
