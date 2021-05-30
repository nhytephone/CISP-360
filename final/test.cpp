#include <iostream>
using namespace std;

void swapnum(int *num1, int *num2);

int main()
{
int num1, num2;
cout << "Enter first number: " << endl;
cin >> num1;
cout << "Enter second number: " << endl;
cin >> num2;
cout << "Pre Swap: " << num1  << " " << num2 << endl;
swapnum(&num1, &num2);
cout << "Post Swap: " << num1  << " " << num2 << endl;
}

void swapnum(int *num1, int *num2)
{
  int i;
  i = *num1;
  *num1 = *num2;
  *num2 = i;
}
