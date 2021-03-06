/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #7 (ch7) - LargestSmallest (paired programming)
Source file name: hw7_LargestSmallest.cpp
Program description: A program that lets the user enter 10 values into an array
and then displays the largest and smallest values in the array.
*****************************************************/

#include <iostream>
using namespace std;

int main()
{
    const int lotto_size = 10;
    int response;
    bool found = false;
    int position = 0;
    int lotto_numbers[lotto_size] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

    cout << "Please enter this week's 5-digit winning lottery number: ";
    cin >> response;

    while((found == false) && (position < lotto_size)){
        if (response == lotto_numbers[position]){
            found = true;
        }
        position++;
    }
    if (found == true){
        cout << "You have a winning ticket." << endl;
    }
    else{
        cout << "You did not win this week." << endl;
    }
}
