#include <iostream>
#include <string>
using namespace std;

int main()
{
  string name, city, college, profession, animal, pet, age;

  cout << "Please enter your name: ";
  getline(cin, name);
  cout << "Please enter the name of a city: ";
  getline(cin, city);
  cout << "Please enter your age: ";
  getline(cin, age);
  cout << "Please enter the name of a college: ";
  getline(cin, college);
  cout << "Please enter a profession: ";
  getline(cin, profession);
  cout << "Please enter a type of animal: ";
  getline(cin, animal);
  cout << "Please enter a pet's name: ";
  getline(cin, pet);

  cout << endl << "There once was a person named " << name << " who lived in "
       << city << ".  At the age of " << age << ", " << name
       << " went to college at " << college << ".  " << name
       << " graduated and went to work as a " << profession << ".  Then, "
       << name << " adopted a(n) animal named " << pet
       << ".  They both lived happily ever after!";
}
