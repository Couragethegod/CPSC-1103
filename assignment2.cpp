#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

  double amount;
  double interestRate;
  double payment;
  double remainingBalance;
  double principlePaid;
  double interestPaid;
  double paidTotal;
  double paid;
  int i;

  cout << "What's the loan amount? ";
  cin >> amount;
  remainingBalance = amount;

  cout << "What's the yearly interest rate? ";
  cin >> interestRate;
  interestRate = (interestRate / 12)/100;

  cout << "What's amount will be paid monthly? ";
  cin >> payment;

  paid = payment - (interestRate*remainingBalance);

  /*while(remainingBalance > 0){

    amount = 

    remainingBalance =  remainingBalance - (payment - (interestRate*remainingBalance));
    i++;
  }*/

  cout << paid;

}