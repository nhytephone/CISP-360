//*****************************************************************************
// finalproject.cpp
// Description:
//
// Input: APR, Loan Term, Loan Amount, Homeowners insurance, Property tax,
// Auto insurance,  Health insurance, Out of pocket medical costs,
// Life insurance, Electricity and natural gas, Water, Sanitation/garbage,
// Groceries toiletries and other essentials, Car payment, Gasoline ,
// Public transportation, Internet, Cell phoneand /or landline,
// Student loan payments, Other minimum loan payments,
// Child support or alimony payments, Child care. 22 Total
//
// Input2: Clothing, jewelry, etc.Dining out,
// Special meals in(steaks for the grill, etc.), Alcohol,
// Movie concert and event tickets, Gym or club memberships,
// Travel expenses(airline tickets, hotels, rental cars, etc.),
// Cable or streaming packages, Self - care and personal grooming,
// Home decor. 10 Total
//
// Output: BudgetReport.txt, percent expense of all inputs, remaining funds
// Date: 04/15/2021
// Student Name(s): Vincent Jiron W1629770, Kamran Khan W1637197,
// Ben Bunting W1926518, Dylan Patel W1893276, Rajesh Reddy W1642297,
// Christopher Flores
// CISP 360
// Spring 2021
// Final Porject
#include <iostream>
#include <vector>

#define NEEDS 20

using namespace std;

// Input
void getData(double &apr, int &term, double &loan, double arrayNeed[NEEDS], string need[NEEDS], vector<double> &arrayWant, vector<string> &want);

int main()
{
  double apr,
         loan;
  int    term;
  double arrayNeed[NEEDS];
  vector<double> arrayWant;
  string need[NEEDS];
  vector<string> want;

  getData(apr, term, loan, arrayNeed, need, arrayWant, want);

}

void getData(double &apr, int &term, double &loan, double arrayNeed[NEEDS], string need[NEEDS], vector<double> &arrayWant, vector<string> &want)
{
  double needsData[NEEDS] = {1520.5, 273, 135.2, 73, 45.6, 153.45, 56.23, 48.25, 125.35, 47.86, 125.52, 653.2, 5483.2, 569.52, 152.2, 232.2, 45.8, 456.5, 123.53, 89.5};
  double wantsData[10] = {52.6, 28.54, 17.36, 123.2, 456.5, 485.23, 671.23, 132.56, 452.2, 11.23};
  string needData[NEEDS] = {"Mortgage/Rent", "Homeowners insurance", "Property tax", "Auto insurance",  "Health insurance", "Out of pocket medical costs", "Life insurance", "Electricity and natural gas", "Water", "Sanitation/garbage", "Groceries toiletries and other essentials", "Car payment", "Gasoline", "Public transportation", "Internet", "Cell phone and or landline", "Student loan payments", "Other minimum loan payments", "Child support or alimony payments", "Child care"};
  vector<string> wantData = {"Clothing, jewelry, etc", "Dining out", "Special meals in(steaks for the grill, etc.)", "Alcohol", "Movie concertand event tickets", "Gym or club memberships", "Travel expenses(airline tickets, hotels, rental cars, etc.)", "Cable or streaming packages", "Self - care and personal grooming", "Home decor"};

  apr=3;
  term = 4;
  loan = 5;

  for (int i = 0; i < NEEDS; i++)
  {
      arrayNeed[i] = needsData[i];
      need[i] = needData[i];
  }

  for (int i = 0; i < 10; i++)
  {
      arrayWant.push_back(wantsData[i]);
      want.push_back(wantData[i]);
  }
}
