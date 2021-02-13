// Geometry Calculator

#include <iostream>
#include <cmath>

#define PI 3.14159

using namespace std;

void GetType(int &Choice);
double AreaCirlce();
double AreaRectangle();
double AreaTriangle();
void DisplayResult(double Area);

int main()
{
    int Choice; // declares Choice as integer.

    GetType(Choice);

    switch (Choice)
    {
        case 1: DisplayResult(AreaCirlce());
            break;
        case 2: DisplayResult(AreaRectangle());
            break;
        case 3: DisplayResult(AreaTriangle());
            break;
        case 4: exit(0);
        default: std::cout << "The valid choices are 1 through 4. Run the ";
                 std::cout << "program again and select one of those." << endl;
    }

    return 0;
}

//
// Input module, gets a choice from the user.
//
void GetType(int &Choice)
{
    std::cout << "Geometry Calculator" << endl <<endl;
    std::cout << "1. Calculate the area of a Circle" << endl << endl;
    std::cout << "2. Calculate the area of a Rectangle" << endl << endl;
    std::cout << "3. Calculate the area of a Triangle" << endl << endl;
    std::cout << "4. Quit" << endl << endl;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> Choice;
    std::cout << endl;
}

//
// Processing module, gets radius and calculates area of a circle.
//
double AreaCirlce()
{
    double Radius; // declares radius as float

    do
    {
        std::cout << "Enter the radius: ";
        std::cin >> Radius;

        if (Radius < 0)
        {
            std::cout << "The radius can not be less than zero."
                << endl <<endl;
        }
    } while (Radius < 0);

    return PI * pow(Radius, 2);
}

//
// Processing module, gets length and width and calculates area of a rectangle.
//
double AreaRectangle()
{
    double Length, // declares length and width as float
           Width;
    do
    {
        std::cout << "Enter the length: ";
        std::cin >> Length;

        if (Length < 0)
        {
            std::cout << "The length can not be less than zero."
                << endl << endl;
        }
    } while (Length < 0);

    do
    {
        std::cout << "Enter the width: ";
        std::cin >> Width;

        if (Width < 0)
        {
            std::cout << "The width can not be less than zero."
                << endl << endl;
        }
    } while (Width < 0);

    return Length * Width;
}

//
// Processing module, gets base and height and calculates area of a triangle.
//
double AreaTriangle()
{
    double Base,   // declares base and height as float
           Height;

    do
    {
        std::cout << "Enter the base: ";
        std::cin >> Base;

        if (Base < 0)
        {
            std::cout << "The base can not be less than zero."
                << endl << endl;
        }
    } while (Base < 0);

    do
    {
        std::cout << "Enter the height: ";
        std::cin >> Height;

        if (Height < 0)
        {
            std::cout << "The height can not be less than zero."
                << endl << endl;
        }
    } while (Height < 0);

    return Base * Height * 0.5;
}

//
// Output module, displays area of chosen geometry.
//
void DisplayResult(double Area)
{
    std::cout << endl << "Area = " << Area << endl;
}
