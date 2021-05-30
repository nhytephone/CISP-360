#include <iostream>
using namespace std;

void findMin(int userNumbers[]);

int main()
{
int userNumbers[10];

    for (int i = 0; i < 10; i++)
    {
      cout << "Enter value for number " << i+1 << " :";
      cin >> userNumbers[i];
    }

findMin(userNumbers);
}

void findMin(int userNumbers[])
{
  int min = userNumbers[0];
  int place;
  for (int i = 0; i < 10; i++)
  {
    if (userNumbers[i] < min)
    {
      min = userNumbers[i];
      place = i;
    }
  }
   cout << "The smallest number was " << min
        << " and it was number " << place << " in the array but number "
        << place +1 << " in your entered numbers." << endl;
}
