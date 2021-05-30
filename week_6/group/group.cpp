#include <iostream>

bool IsPrime(int num);

int main()
{
  int response;
  std::cout << "Please enter a number :";
  std::cin >> response;

  if (IsPrime(response))
  {
    std::cout << "That's a prime number!";
  }
  else
  {
    std::cout << "That's not a prime number!";
  }
}

bool IsPrime(int num)
{
  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}
