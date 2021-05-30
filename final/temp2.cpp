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
#include <cmath>
#include <string>


#define NEEDS 20

using namespace std;

// Input
void getData(double &apr, int &term, double &loan, double arrayNeed[NEEDS], string need[NEEDS], vector<double> &arrayWant, vector<string> &want);
double validation(string temp);
void getApr(double &apr, int &term, double &loan,double arrayNeed[NEEDS]);
void getNeeds(string need[NEEDS], double arrayNeed[NEEDS]);
void getWants(vector<double> &arrayWant, vector<string> &want);
double calculateMortgage(double apr, double term, double loan);
bool get_yesno(string question, char &answer);
int main()
{
  double apr,
         loan;
  int term;

  double arrayNeed[NEEDS];
  string need[NEEDS];

  vector<double> arrayWant;
  vector<string> want;


  getData(apr, term, loan, arrayNeed, need, arrayWant, want);
//  cout << "APR = " << apr << " Term = " << term << " Loan = " << loan << endl;

}

void getData(double &apr, int &term, double &loan, double arrayNeed[NEEDS], string need[NEEDS], vector<double> &arrayWant, vector<string> &want)
{
  getApr(apr, term, loan, arrayNeed);

  cout << "APR Calculates out to: " << arrayNeed[0] << endl;

  getNeeds(need,arrayNeed);

/*
  for (int i = 0; i < NEEDS; i++)
  {
      cout << "arrayNeed " << i << " is equal to :"<< arrayNeed[i] << endl;
      cout << "need " << i << " is equal to :"<<need[i] << endl;

  }
*/

  getWants(arrayWant, want);


cout << "vector now" << endl;

for (vector<double>::iterator l = arrayWant.begin(); l != arrayWant.end(); l++)
{
    cout << *l << endl;
}
for (vector<string>::iterator l = want.begin(); l != want.end(); l++)
{
    cout << *l << endl;
}


}
void getWants(vector<double> &arrayWant, vector<string> &want)
{
  vector<string> wantData = {"Clothing, jewelry, etc", "Dining out", "Special meals in(steaks for the grill, etc.)", "Alcohol", "Movie concertand event tickets", "Gym or club memberships", "Travel expenses(airline tickets, hotels, rental cars, etc.)", "Cable or streaming packages", "Self - care and personal grooming", "Home decor"};
  for (int i = 0; i < 10; i++)
  {
    cin.clear();
    cin.ignore();
    cout << "How much do you pay for " << wantData[i] << " a month? ";
    string tempWants;
    arrayWant.push_back(validation(tempWants));
    want.push_back(wantData[i]);
  }
  char answer;
  string question = "Input additional Items?";

  while (get_yesno(question, answer))
  {
    string tempWants;
    cout << "Enter the name for the field: ";
    cin.clear();
    cin.ignore();
    getline(std::cin, tempWants);
    want.push_back(tempWants);
    cout << "Enter the value for "<< tempWants << ": ";
    arrayWant.push_back(validation(tempWants));
  }

}

void getNeeds(string need[NEEDS], double arrayNeed[NEEDS])
{
  string needData[NEEDS] = {"Mortgage/Rent", "Homeowners insurance", "Property tax", "Auto insurance",  "Health insurance", "Out of pocket medical costs", "Life insurance", "Electricity and natural gas", "Water", "Sanitation/garbage", "Groceries toiletries and other essentials", "Car payment", "Gasoline", "Public transportation", "Internet", "Cell phone and or landline", "Student loan payments", "Other minimum loan payments", "Child support or alimony payments", "Child care"};
  need[0] = needData[0];
  for (int i = 1; i < NEEDS; i++)
  {
    cout << "How much do you pay for " << needData[i] << " a month? ";
    string tempNeed;

    need[i] = needData[i];
    arrayNeed[i] = validation(tempNeed);;
  }
}

void getApr(double &apr,int &term,double &loan, double arrayNeed[NEEDS])
{
  char answer;
  string question = "Do you pay a mortgage?";
  string tempMortgage;
  cout << "First let's enter  your houseing info" << endl;

  if (get_yesno(question, answer))
  {
    cout << "Please enter the APR on your loan: ";
    apr = validation(tempMortgage);
    cout << "Please enter the term of your loan: ";
    term = validation(tempMortgage);
    cout << "Please enter your total loan amount: ";
    loan = validation(tempMortgage);

    arrayNeed[0]=calculateMortgage(apr, term, loan);
  }
  else
  {
    cout << "What do you pay for housing?" << endl;
    arrayNeed[0] = validation(tempMortgage);
  }
}

double validation(string temp)
{
  do {
    getline(std::cin, temp);
    if (!isdigit(temp[0]))
    {
      cout << "The total must be positive and a number." << endl;
      cin.clear();
    }
  } while (!isdigit(temp[0]));
  return strtod(temp.c_str(), NULL);
}

double calculateMortgage(double apr, double term, double loan)
{
    double c = apr / 100;

    return (loan * (c / 12) * pow((1 + c / 12), (term * 12))) / (pow((1 + c / 12), (term * 12)) - 1);
}

bool get_yesno(std::string question, char &answer)
{
  std::cout << question << ' ';
  std::cin >> answer;
  while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N')
  {
    std::cout << "Please type 'Y' for yes or 'N' for no" << std::endl << std::endl;
    std::cout << question << ' ';
    std::cin >> answer;
    cin.clear();
    cin.ignore();
  }
  if (answer == 'y' || answer == 'Y')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
