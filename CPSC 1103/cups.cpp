#include <iostream>
#include <iomanip> 

using namespace std;

void showintro(){
  cout << "This program will convert cups to ounces" << endl;
}

double getCups(){
  double cups;
  cout << "How many cups are you looking to buy? ";
  cin >> cups;
  return cups;
}
  
double cupsToOunces(double cups){
  double ounces;
  ounces = cups * 8;
  return ounces;
}
void display(double cups,double ounces){
  cout << "You chose to go with " << cups << " cups" << endl;
  cout << "This would give you " << ounces << " ounces" << endl;
}

int main(){
  cout << fixed << showpoint << setprecision(2);
  
  showintro();
  double cups = getCups();
  double ounces = cupsToOunces(cups);
  display(cups,ounces);

  return 0;
}