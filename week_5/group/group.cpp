#include <iostream>
using namespace std;

void get_data(int &pop_start, int &days, float &pop_inc);
void pop_sanity(int &pop_start);
void inc_sanity(float &pop_inc);
void days_sanity(int &days);

int main()
{
  int pop_start,
      days;
  float pop_inc;
  get_data(pop_start, days, pop_inc);
}

void get_data(int &pop_start, int &days, float &pop_inc)
{
  cout << "Please enter your starting number of organisms: ";
  cin >> pop_start;
  pop_sanity(pop_start);
  cout << endl << "Please enter their average daily population increase: ";
  cin >> pop_inc;
  inc_sanity(pop_inc);
  cout << endl << "Please enter the number of days they will multiply: ";
  cin >> days;
  days_sanity(days);
}

void pop_sanity(int &pop_start)
{
  while (pop_start < 2 )
  {
    cout << endl << "The starting number of organisms must be at least 2." << endl
         << "Please enter your starting number of organisms: ";
    cin >> pop_start;
  }
}

void inc_sanity(float &pop_inc)
{
  while (pop_inc < 0 )
  {
    cout << endl << "The average daily population increase must be a positive value." << endl
         << "Please enter their average daily population increase: ";
    cin >> pop_inc;
  }
}

void days_sanity(int &days)
{
  while (days < 1 )
  {
    cout << endl << "The number of days must be at least 1." << endl
         << "Please enter the number of days they will multiply: ";
    cin >> days;
  }
}
