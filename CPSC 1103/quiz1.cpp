#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int dataUsed;
char package;

double packageA (){
  double base = 39.99;
  double dataCost = 0;
  if (dataUsed > 4){
    dataCost = (dataUsed - 4)*10;
  }
  double costA = base + dataCost;
  return costA;
}

double packageB (){
  double base = 59.99;
  double dataCost = 0;
  if (dataUsed > 8){
    dataCost = (dataUsed - 8)*5;
  }
  double costB = base + dataCost;
  return costB;
}

double packageC (){
  double base = 69.99;
  double costC = base;
  return costC;
}

int main(){
  cout << fixed << setprecision(2);

  cout << "Which package did you choose? ";
  cin >> package;
  if (cin.fail() || cin.peek() != '\n'){
    return 0;
  }
  if (package != 'A' && package != 'B' && package != 'C'){
    return 0;
  }

  cout << "How much data did you use? ";
  cin >> dataUsed;
  if (cin.fail() || cin.peek() != '\n'){
    return 0;
  }
  if (dataUsed < 0){
    return 0;
  }

  cout << "Your total is: $";

  double costA = packageA(); // Calculate the cost for package A
  double costB = packageB(); // Calculate the cost for package B
  double costC = packageC(); // Calculate the cost for package C

  double AB = costA-costB;
  double AC = costA-costC;
  double BA = costB-costA;
  double BC = costB-costC;
  double CA = costC-costA;
  double CB = costC-costB;

  switch (package){
  case 'A':
    cout << costA << endl;
    if (floor(AB) > 0){
      cout << "Choosing package B would have saved you: $" << AB << endl;
    }
    if (floor(AC) > 0){
      cout << "Choosing package C would have saved you: $" << AC << endl;
    }
    return 0;
  case 'B':
    cout << costB << endl;
    if (floor(BA) > 0){
      cout << "Choosing package A would have saved you: $" << BA << endl;
    }
    if (floor(BC) > 0){
      cout << "Choosing package C would have saved you: $" << BC << endl;
    }
    return 0;
  case 'C':
    cout << costC << endl;
    if (floor(CA) > 0){
      cout << "Choosing package A would have saved you: $" << CA << endl;
    }
    if (floor(CB) > 0){
      cout << "Choosing package B would have saved you: $" << CB << endl;
    }
    return 0;
  default:
    return 0;
  }
}