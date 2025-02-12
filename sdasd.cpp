// FILE: Assignment01.cpp
// PROGRAMMER:  Owen Sheikhanzai
// CPSC 1103	Section: 10
// PURPOSE:  Calculate the total cost of a phone plan based on the user’s package choice and data usage
// INPUT:  User inputs a package choice and data usage


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

char package;
int data;
double base;
double dataCost;
double total;
double costA;
double costB;
double costC;
double AB;
double AC;
double BA;
double BC;
double CA;
double CB;

int packageA(){
  base = 39.99;
  if (data > 4){
    dataCost = (data - 4) * 10;
  }
  else{
    dataCost = 0;
  }
  costA = base + dataCost;
  return costA;
}

int packageB(){
  base = 59.99;
  if (data > 8){
    dataCost = (data - 8) * 5;
  }
  else{
    dataCost = 0;
  }
  costB = base + dataCost;
  return costB;
}

int packageC(){
  base = 69.99;
  costC = base;
  return costC;
}

int main(){
  cout << fixed << setprecision(2);

  cout << "Which package did you choose? ";
  cin >> package;
  if (cin.fail() || cin.peek() != '\n') {
    cout << "More than one character! Rerun the code." << endl;
    return 0;
  }
  if (package != 'A' && package != 'B' && package != 'C'){
    cout << "Invalid Package! Rerun the code." << endl;
    return 0;
  }

  cout << "How much data did you use? ";
  cin >> data;
  if (cin.fail() || cin.peek() != '\n') {
    cout << "Not an integer! Rerun the code." << endl;
    return 0;
  }
  if (data < 0){
    cout << "Negative Number! Rerun the code." << endl;
    return 0;
  }

  packageA();
  packageB();
  packageC();

  AB = costA - costB;
  AC = costA - costC;
  BA = costB - costA;
  BC = costB - costC;
  CA = costC - costA;
  CB = costC - costB;

  cout << "Total: $";
  switch (package)
  {
  case 'A':
    cout << costA << endl;
    if (floor(AB) == 0){
      AB = 0;
    }
    if (floor(AC) == 0){
      AC = 0;
    }
    if (AB > 0){
      cout << "Choosing Package B would have saved you: $" << AB << endl;
    }
    if (AC > 0){
      cout << "Choosing Package C would have saved you: $" << AC << endl;
    }
    break;

  case 'B':
    cout << costB << endl;
    if (floor(BA) == 0){
      BA = 0;
    }
    if (floor(BC) == 0){
      BC = 0;
    }
    if (BA > 0){
      cout << "Choosing Package A would have saved you: $" << BA << endl;
    }
    if (BC > 0){
      cout << "Choosing Package C would have saved you: $" << BC << endl;
    }
    break;
    
  case 'C':
    cout << costC << endl;
    if (floor(CA) == 0){
      CA = 0;
    }
    if (floor(CB) == 0){
      CB = 0;
    }
    if (CA > 0){
      cout << "Choosing Package A would have saved you: $" << CA << endl;
    }
    if (CB > 0){
      cout << "Choosing Package B would have saved you: $" << CB << endl;
    }
    break;
  default:
    break;
  }
}