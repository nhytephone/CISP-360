#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  float weight,
        height,
        bmi;
  cout << "Enter your weight in points: ";
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
