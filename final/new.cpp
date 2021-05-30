//*****************************************************************************
// budgetCalc.cpp
//
// Description: Gets the user's income, if they have a mortgage, get user's
// apr, loan term and loan amount. Next they user inputs their monthly
// expenses. The expenses then are turned into a percent of total expenses and
// sorted from greatest to least. The program then prints a budget report with
// the users expenses and remaining income as well as a statement on being
// in/out of budget.
//
// Input: APR, Loan Term, Loan Amount, Rent, Homeowners insurance,
// Property tax, Auto insurance,  Health insurance,
// Out of pocket medical costs, Life insurance, Electricity and natural gas,
// Water, Sanitation/garbage, Groceries toiletries and other essentials,
// Car payment, Gasoline, Public transportation, Internet,
// Student loan payments, Other minimum loan payments,
// Cell phoneand /or landline,Child support or alimony payments, Child care.
//  22 Total
//
// Input2: Clothing, jewelry, etc.Dining out,
// Special meals in(steaks for the grill, etc.), Alcohol,
// Movie concert and event tickets, Gym or club memberships,
// Travel expenses(airline tickets, hotels, rental cars, etc.),
// Cable or streaming packages, Self - care and personal grooming,
// Home decor. 10 Total
//
// Output: outfile.txt, percent expense of all inputs, input descriptions,
// expense amount, total expense, remaining income, in/out of budget
//
// Date: 04/15/2021
//
// Student Name(s): Vincent Jiron W1629770, Kamran Khan W1637197,
// Ben Bunting W1926518, Dylan Patel W1893276, Rajesh Reddy W1642297,
// Christopher Flores W1718640
//
// CISP 360
// Spring 2021
// Final Porject

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

#define NEEDS 20

using namespace std;

// Input
void getData(double& apr, double& term, double& loan, double arrayNeed[NEEDS],
    string need[NEEDS], vector<double>& arrayWant, vector<string>& want,
    double &income);
bool get_yesno(std::string question, char &answer);
double validation(string temp);
void getApr(double& apr, double& term, double& loan, double arrayNeed[NEEDS]);
void getNeeds(string need[NEEDS], double arrayNeed[NEEDS]);
void getWants(vector<double>& arrayWant, vector<string>& want);
// Processing
void editDataArray(double& apr, double& term, double& loan, double arrayNeed[NEEDS], string need[NEEDS]);
void editDataVect(vector<double>& arrayWant, vector<string>& want);
double calculateMortgage(double apr, double term, double loan);
double sumElements(double arrayNeed[NEEDS], vector<double> arrayWant);
void calculatePercentage(double arrayNeed[NEEDS], vector<double> arrayWant,
    double needPercent[NEEDS], vector<double> & wantPercent, double sum);
void selectionSort(double arrayNeed[NEEDS], string need[NEEDS],
    double needPercent[NEEDS], vector<string> & want,
    vector<double>& wantPercent, vector<double> & arrayWant);
void swapElementsArray(string need[], double needPercent[], int maxIndex,
    int scan);
// Output
void printResults(ofstream &outfile, string need[NEEDS], vector<string> want,
    double needPercent[NEEDS], vector<double> & wantPercent,
    double arrayNeed[NEEDS], vector<double> arrayWant, double remain,
    double sum, double income);

int main()
{
    // Variable Declarations
    double remain,
           income,
           sum,
           term,
           loan,
           apr;

    // Array Declaration
    string need[NEEDS];

    double arrayNeed[NEEDS],
           needPercent[NEEDS];

    // Vector Declaration
    vector<double> arrayWant;
    vector<double> wantPercent;
    vector<string> want;


    ofstream outfile;

    // Open File
    outfile.open("c:\\temp\\outfile.txt");

    // Validates files opened.
    if (!outfile.is_open())
    {
        std::cout << "Cannot open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Input Section
    getData(apr, term, loan, arrayNeed, need, arrayWant, want, income);

    // Processing Section
    sum = sumElements(arrayNeed, arrayWant);
    remain = (income - sum);
    calculatePercentage(arrayNeed, arrayWant, needPercent, wantPercent, sum);
    selectionSort(arrayNeed, need, needPercent, want, wantPercent, arrayWant);

    // Output Section
    printResults(outfile, need, want, needPercent, wantPercent, arrayNeed,
        arrayWant, remain, sum, income);

    //Close File
    outfile.close();
}

//
// Gets gross income and uses getApr, getNeeds and getWants functions to get
// the required data fromt he user
//
void getData(double& apr, double& term, double& loan, double arrayNeed[NEEDS],
    string need[NEEDS], vector<double>& arrayWant, vector<string>& want,
    double &income)
{
    cout << "What is your monthly gross income?: ";
    string tempIncome;
    income = validation(tempIncome);

    getApr(apr, term, loan, arrayNeed);
    getNeeds(need, arrayNeed);
    editDataArray(apr, term, loan, arrayNeed, need);
    getWants(arrayWant, want);
    cout << arrayWant.size() << endl;
    editDataVect(arrayWant, want);
}

//
// Gets the users's monthly cost for nonessential expenses
//
void getWants(vector<double>& arrayWant, vector<string>& want)
{
    vector<string> wantData = { "Clothing, jewelry, etc", "Dining out",
        "Special meals in", "Alcohol", "Movie concertand event tickets",
        "Gym or club memberships", "Travel expenses",
        "Cable or streaming packages", "Self - care and personal grooming",
        "Home decor" };

    cout << endl << setfill('=') << setw(50) << '=' << endl;
    cout << "Enter your monthly nonessential expenses" << endl;
    cout << setfill('=') << setw(50) << '=' << endl;

    for (int i = 0; i < 10; i++)
    {
        cin.clear();
        cin.ignore();
        cout << i + 1 << ". " << wantData[i] << " expense: ";
        string tempWants;
        arrayWant.push_back(validation(tempWants));
        want.push_back(wantData[i]);
    }
    char answer;
    string question =
        "Input additional Items? (Please type 'Y' for yes or 'N' for no): ";

    while (get_yesno(question, answer))
    {
        string tempWants;
        cout << "Enter the name for the field: ";
        cin.clear();
        cin.ignore();
        getline(cin, tempWants);
        want.push_back(tempWants);
        cout << "Enter the value for " << tempWants << ": ";
        arrayWant.push_back(validation(tempWants));
    }
}

//
//
//
bool get_yesno(string question, char& answer)
{
    std::cout << question;
    std::cin >> answer;
    while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N')
    {
        std::cout << "Please type 'Y' for yes or 'N' for no: ";
        std::cin >> answer;
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

//
// gets user's monthly cost for essential expenses
//
void getNeeds(string need[NEEDS], double arrayNeed[NEEDS])
{
    string needData[NEEDS] = { "Mortgage/Rent", "Homeowners insurance",
        "Property tax", "Auto insurance",  "Health insurance",
        "Out of pocket medical costs", "Life insurance",
        "Electricity and natural gas", "Water", "Sanitation/garbage",
        "Groceries toiletries and other essentials", "Car payment", "Gasoline",
        "Public transportation", "Internet", "Cell phone and or landline",
        "Student loan payments", "Other minimum loan payments",
        "Child support or alimony payments", "Child care" };
    need[0] = needData[0];


    cout << endl << setfill('=') << setw(50) << '=' << endl;
    cout << "Enter your monthly essential expenses" << endl;
    cout << setfill('=') << setw(50) << '=' << endl;
    for (int i = 1; i < NEEDS; i++)
    {
        cout << i << ". " << needData[i] << " expense: ";
        string tempNeed;

        need[i] = needData[i];
        arrayNeed[i] = validation(tempNeed);
    }
}

//
// Asks user if they have a mortgage and if they do, asks for their apr,
// term and loan. If not they are asked for their monthly housing expense.
//
void getApr(double& apr, double& term, double& loan, double arrayNeed[NEEDS])
{
    char answer;
    string tempMortgage;
    cout << "First let's enter  your houseing info" << endl;
    string question = "Do you pay a mortgage? (Please type 'Y' for yes or 'N' for no): ";

    get_yesno(question, answer);

    if (answer == 'y')
    {
        cout << "Please enter the APR on your loan: ";
        apr = validation(tempMortgage);
        cout << "Please enter the term of your loan (in years): ";
        term = validation(tempMortgage);
        cout << "Please enter your total loan amount: ";
        loan = validation(tempMortgage);

        arrayNeed[0] = calculateMortgage(apr, term, loan);
    }
    else
    {
        cout << "What do you pay for housing?: ";
        arrayNeed[0] = validation(tempMortgage);
    }
}

//
// Validates users input as a non negative number
//
double validation(string temp)
{
    int c = 0;

    do
    {
        c = 0;
        cin >> temp;

        for (unsigned int i = 0; i < temp.size(); i++)
        {
            if (!isdigit(temp[i]) && temp[i] != '.') { c = 1; break; }
        }

        if (c == 1)
        {
            cout << "The total must be positive and a number." << endl;
            cout << "Please enter a valid number: ";
            cin.clear();
            cin.ignore();
        }

    } while (c == 1);

    return strtod(temp.c_str(), NULL);
}

//
// Calculates the user's monthly mortgage payment from their apr, term and loan
//
double calculateMortgage(double apr, double term, double loan)
{
    double c = apr / 100;

    return (loan * (c / 12) * pow((1 + c / 12), (term * 12))) /
        (pow((1 + c / 12), (term * 12)) - 1);
}



//
// Sums array and vector and returns sum as a double
//
double sumElements(double arrayNeed[NEEDS], vector<double> arrayWant)
{
    double sum = 0;

    for (int i = 0; i < NEEDS; i++)
    {
        sum += arrayNeed[i];
    }

    for (vector<double>::iterator j = arrayWant.begin();
        j != arrayWant.end(); j++)
    {
        sum += *j;
    }

    return sum;
}

//
// Calculates the percentage of total expenses from each array and vector
// element and stores the percentages in the needPercent array and wantPercent
// vector
//
void calculatePercentage(double arrayNeed[NEEDS], vector<double> arrayWant,
    double needPercent[NEEDS], vector<double> & wantPercent, double sum)
{
    for (int i = 0; i < NEEDS; i++)
    {
        needPercent[i] = (arrayNeed[i] / sum) * 100;
    }

    for (unsigned int k = 0; k < arrayWant.size(); k++)
    {
        wantPercent.push_back((arrayWant[k] / sum) * 100);
    }
}

//
// Sorts the arrays associated with essential expenses parallel to each other
// from greatest to least and sorts the vectors associated with nonessential
// expenses from greatest to least.
//
void selectionSort(double arrayNeed[NEEDS], string need[NEEDS],
    double needPercent[NEEDS], vector<string>& want,
    vector<double>& wantPercent, vector<double>& arrayWant)
{
    int scan,
        maxIndex,
        pass = 0;

    double maxVal;

    for (scan = 0; scan < (NEEDS - 1); scan++)
    {
        maxIndex = scan;
        maxVal = arrayNeed[scan];
        for (int i = scan + 1; i < NEEDS; i++)
        {
            if (arrayNeed[i] > maxVal)
            {
                maxVal = arrayNeed[i];
                maxIndex = i;
            }
        }
        arrayNeed[maxIndex] = arrayNeed[scan];
        arrayNeed[scan] = maxVal;

        swapElementsArray(need, needPercent, maxIndex, scan);
    }

    for (unsigned int j = 0; j < arrayWant.size(); ++j)
    {
        unsigned int max = j;
        for (unsigned int k = j + 1; k < arrayWant.size(); ++k)
        {
            if (arrayWant.at(max) < arrayWant.at(k))
            {
                max = k;
            }

        }
        if (max != j)
        {
            swap(arrayWant.at(j), arrayWant.at(max));
            swap(want.at(j), want.at(max));
            swap(wantPercent.at(j), wantPercent.at(max));
        }

    }
}

//
// Used to swap the arrays parallel to arrayNeed
//
void swapElementsArray(string need[], double needPercent[], int maxIndex,
    int scan)
{
    string tempString;
    double tempPercent;

    tempString = need[maxIndex];
    need[maxIndex] = need[scan];
    need[scan] = tempString;

    tempPercent = needPercent[maxIndex];
    needPercent[maxIndex] = needPercent[scan];
    needPercent[scan] = tempPercent;
}

//
// Prints a budget report to a txt file and the command window with sorted
// descriptions, amount and percentage of expenses as well of user's remaining
// income and a statement telling them if they are within their budget
//
void printResults(ofstream& outfile, string need[NEEDS], vector<string> want,
    double needPercent[NEEDS], vector<double>& wantPercent,
    double arrayNeed[NEEDS], vector<double> arrayWant, double remain,
    double sum, double income)
{

    cout << endl << endl << setw(35) << setfill(' ') << "Budget Report"
        << endl;
    cout << "\nDescription" << setw(39) << "Spending" << setw(25)
        << "Percent" << endl;
    cout << setfill('=') << setw(75) << '=' << endl;
    cout << "Needs" << endl;
    cout << setfill('=') << setw(75) << '=' << endl;
    cout << setfill(' ');

    outfile << setw(35) << "Budget Report" << endl;
    outfile << "\nDescription" << setw(39) << "Spending" << setw(25)
        << "Percent" << endl;
    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << "Needs" << endl;
    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << setfill(' ');

    for (int row = 0; row < NEEDS; row++)
    {

        cout << setw(43) << left << need[row] << right

            << setw(7) << fixed << setprecision(2) << arrayNeed[row]
            << setw(24) << fixed << setprecision(2) << needPercent[row]
            << "%" << endl;

        outfile << setw(43) << left << need[row] << right
            << setw(7) << fixed << setprecision(2) << arrayNeed[row]
            << setw(24) << fixed << setprecision(2) << needPercent[row]
            << "%" << endl;



    }
    cout << setfill('=') << setw(75) << '=' << endl;
    cout << "Wants" << endl;
    cout << setfill('=') << setw(75) << '=' << endl;
    cout << setfill(' ');

    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << "Wants" << endl;
    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << setfill(' ');

    for (unsigned int i = 0; i < arrayWant.size(); i++)
    {
        cout << setw(43) << left << want.at(i) << right

            << setw(7) << fixed << setprecision(2) << arrayWant.at(i)
            << setw(24) << fixed << setprecision(2) << wantPercent.at(i)
            << "%" << endl;

        outfile << setw(43) << left << want.at(i) << right

            << setw(7) << fixed << setprecision(2) << arrayWant.at(i)
            << setw(24) << fixed << setprecision(2) << wantPercent.at(i)
            << "%" << endl;
    }

    cout << setfill('=') << setw(75) << '=' << endl;
    cout << setfill(' ');
    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << setfill(' ');

    cout << "Total monthly expenses: " << sum << endl;
    cout << "Remaining income: " << remain << endl;
    outfile << "Total monthly expenses: " << sum << endl;
    outfile << "Remaining income: " << remain << endl;

    if (income <= sum )
    {
        cout << endl << "You are over budget." << endl;
        outfile << endl << "You are over budget." << endl;
    }
    else
    {
        cout << endl << "Congratulations, you are within your budget." << endl;
        outfile << endl << "Congratulations, you are within your budget."
            << endl;
    }
    cout << setfill('=') << setw(75) << '=' << endl;
    cout << setfill(' ');
    outfile << setfill('=') << setw(75) << '=' << endl;
    outfile << setfill(' ');

}

//
//
//
void editDataArray(double& apr, double& term, double& loan, double arrayNeed[NEEDS], string need[NEEDS])
{
    int choice = 0;

    char answer;

    string question = "Would you like to edit your inputs? (Y/N): ";
    string temp;
    string needData[NEEDS] = { "Mortgage/Rent", "Homeowners insurance",
       "Property tax", "Auto insurance",  "Health insurance",
       "Out of pocket medical costs", "Life insurance",
       "Electricity and natural gas", "Water", "Sanitation/garbage",
       "Groceries toiletries and other essentials", "Car payment", "Gasoline",
       "Public transportation", "Internet", "Cell phone and or landline",
       "Student loan payments", "Other minimum loan payments",
       "Child support or alimony payments", "Child care" };
    need[0] = needData[0];

    do
    {
        get_yesno(question, answer);
        if (answer == 'y')
        {
        cout << "Enter the Item number (enter '0' for Mortgage/Rent): ";
        choice = validation(temp);

        if (choice == 0)
        {
            getApr(apr, term, loan, arrayNeed);
        }
        else
        {
            cout << choice << ". " << needData[choice] << " expense: ";
            string tempNeed;

            need[choice] = needData[choice];
            arrayNeed[choice] = validation(tempNeed);
        }
        }

    } while (answer == 'y');

}

//
//
//
void editDataVect(vector<double>& arrayWant, vector<string>& want)
{
    int choice = 0;

    char answer;

    string question = "Would you like to edit your inputs? (Y/N): ";
    string temp;
    vector<string> wantData = { "Clothing, jewelry, etc", "Dining out",
    "Special meals in", "Alcohol", "Movie concertand event tickets",
    "Gym or club memberships", "Travel expenses",
    "Cable or streaming packages", "Self - care and personal grooming",
    "Home decor" };

    do
    {

        if (get_yesno(question, answer))
        {
            do
            {
            cout << "Enter the Item number: ";
            choice = validation(temp) - 1;

            if (choice >= arrayWant.size())
            {
                cout << "Please enter a valid item number";
            }
          } while (choice >= arrayWant.size());

            cout << choice + 1 << ". " << wantData[choice] << " expense: ";
            string tempWant;

            want[choice] = wantData[choice];
            arrayWant[choice] = validation(tempWant);

        }

    } while (answer == 'y');

}
