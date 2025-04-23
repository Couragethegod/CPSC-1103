#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function Prototypes
void getData(double& wholesale, double& markup);
double calculateRetail(double wholesale, double markup);
void Display(double wholesale, double markup, double retail);

int main() {

  double wholesale, markup, retail;
  getData(wholesale, markup);
  retail = calculateRetail(wholesale, markup);
  Display(wholesale, markup, retail);
  return 0;

}

bool isValidNumber(const string& input) {
  if (input.empty()) 
    return false;
  for (char c : input) {
    if (!isdigit(c) && c != '.') {
      return false;
    }
  }
  return true;
}

void getData(double& wholesale, double& markup) {
  bool validInput = false;
  string input;

  //Asking for wholesale cost
  cout << "What's the wholesale cost? ";
  getline(cin, input);
  while (!isValidNumber(input) || stod(input) <= 0){
    cout << "Invalid input! Enter a positive number (no spaces)." << endl;
    cout << "What's the wholesale cost? ";
    getline(cin, input);
  }
  wholesale = stod(input);
    
  //Asking for markup percentage
  cout << "What's the markup percentage? ";
  getline(cin, input);
  while (!isValidNumber(input) || stod(input) <= 0){
    cout << "Invalid input! Enter a positive number (no spaces)." << endl;
    cout << "What's the markup percentage? ";
    getline(cin, input);
  }
  markup = stod(input);
}

double calculateRetail(double wholesale, double markup) {
  return wholesale * (markup / 100) + wholesale;

}

void Display(double wholesale, double markup, double retail) {
  cout << fixed << setprecision(2);
  cout << "Given that the wholesale cost is: $" << wholesale << endl;
  cout << "And the markup percentage is: " << markup << "%" << endl;
  cout << "The retail price will be: $" << retail << endl;
}