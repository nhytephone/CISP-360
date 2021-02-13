/*****************************************************
Student name: Bunting, Benjamin // Bundy, Gavin
Student ID: w1926518, w1666922
Course #: CISP360
Section #:
Instruction mode: Online
*****************************************************
Assignment #ch3 - Box Tax (paired programming)
Source file name: hw3_Box.cpp
Program description: This will calculate a Revenue Report for the data
input by the user for the movie theater
*****************************************************/

#include <iostream>   // provides std::cin, std::cout, std::left, std::right,
                      //          std::endl
#include <string>     // provides std::string
#include <iomanip>    // provides std::setw

#define CHILD_PRICE 6.00  // Cost of a ticket for a child
#define ADULT_PRICE 10.00 // Cost of a ticket for an adult

using namespace std;

void input_data(string &movie_name, int &tickets_adult, int &tickets_child);
float calc_gross(int tickets_adult, int tickets_child);
float calc_net(float gross_profit);
float calc_dist(float net_profit, float gross_profit);
void output_data(string movie_name, int tickets_adult, int tickets_child,
                 float gross_profit, float net_profit, float paid_dist);


int main()
{
  string movie_name;  // Movie title
  int tickets_adult,  // Adult tickets sold
      tickets_child;  // Child tickets sold
  float gross_profit; // Total gross profit
  float net_profit;   // Total net profit
  float paid_dist;    // Total paid to the distributor

  input_data(movie_name, tickets_adult, tickets_child);
  gross_profit = calc_gross(tickets_adult, tickets_child);
  net_profit = calc_net(gross_profit);
  paid_dist = calc_dist(net_profit, gross_profit);
  output_data(movie_name, tickets_adult, tickets_child, gross_profit, net_profit,
              paid_dist);

}

//
// An input module that accepts data from the user for movie name and tickets solld
// following the rubrics formatting guidelines
//
void input_data(string &movie_name, int &tickets_adult, int &tickets_child)
{
  cout << "Enter the name of the movie: ";
  getline(cin, movie_name);
  cout << "Enter the number of adult tickets sold: ";
  cin >> tickets_adult;
  cout << "Enter the number of child tickets sold: ";
  cin >> tickets_child;
}

//
// A processing function that calculates the gross profit
//
float calc_gross(int tickets_adult, int tickets_child)
{
  return((tickets_adult * ADULT_PRICE) + (tickets_child * CHILD_PRICE));
}

//
// A processing function that calculates the net profit
//
float calc_net(float gross_profit)
{
  return(gross_profit * 0.2);
}

//
// A processing function that calculates the amount paid to the distributor
//
float calc_dist(float net_profit, float gross_profit)
{
  return(gross_profit - net_profit);
}

//
// An output module that displays the revenue report and follows the rubric's
// formatting
//
void output_data(string movie_name, int tickets_adult, int tickets_child,
                 float gross_profit, float net_profit, float paid_dist)
{
  cout << endl;
  cout << "Revenue Report" << endl;
  cout << "==============" << endl;
  cout << setw(20) << left << "Movie Name:                  "
       << '"' << movie_name << '"' << endl;
  cout << setw(20) << left << "Adult Tickets Sold:          "
       << setw(8) << right << tickets_adult << endl;
  cout << setw(20) << left << "Child Tickets Sold:          "
       << setw(8) << right << tickets_child << endl;
  cout << setw(20) << left << "Gross Box Office Profit:    $"
       << setw(8) << right  << fixed << setprecision(2) << gross_profit << endl;
  cout << setw(20) << left << "Net Box Office Profit:      $"
       << setw(8) << right  << fixed << setprecision(2) << net_profit << endl;
  cout << setw(20) << left << "Amount Paid to Distributor: $"
       << setw(8) << right  << fixed << setprecision(2) << paid_dist << endl;

}
