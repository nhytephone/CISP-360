#include <iostream>
#include <cmath>
using namespace std;

int main() {


long double loanAmount = 250000,
       annualInterestRate = .065;
long double totalYearsToRepay = 30;

// Find the monthly payment.
double monthlyPayment= (loanAmount * (annualInterestRate / 12) * pow((1 +
                        annualInterestRate / 12), (totalYearsToRepay * 12))) / (pow((1
                        + annualInterestRate / 12), (totalYearsToRepay * 12)) - 1);

cout << "Monthly Payment: $" << monthlyPayment << endl;

// cout << (loan * (pow(c*(1+c), n)) / (pow((1+c), n)-1)) << endl;
}
