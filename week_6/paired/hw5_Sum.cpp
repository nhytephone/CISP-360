#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void input(double& present_value, double& interest_rate, double& months);
void calculations(double present_value, double interest_rate, double months, double &future_value);
void output (double future_value);
void repeat_program(char &answer);

int main() {

  double present_value,
        interest_rate,
        months,
        future_value;
  char answer;

do{
input( present_value, interest_rate, months);
calculations( present_value,  interest_rate,  months, future_value);
output (future_value);
repeat_program(answer);
} while ((answer=='Y') || (answer=='y'));
}

void input(double& present_value, double& interest_rate, double& months)
{
cout<< "What is the present value of the account? ";
cin>> present_value;

cout<< "What is the monthly interest rate? ";
cin>> interest_rate;

cout<< "For how many months will the money be left in the account? ";
cin>> months;

}


void calculations(double present_value, double interest_rate, double months, double &future_value)
{

future_value = present_value * (1+ interest_rate)*months;

// idk how to fix this equation tho
}

void output (double future_value)

{

cout<< "The account's future valuye is $"<<future_value;


}

void repeat_program(char &answer)

{

cout<< "Want to try try another set of value? (y=yes)";
cin>>answer;

}
