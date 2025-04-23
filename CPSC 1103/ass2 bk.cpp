// FILE: Assignment02.cpp
// PROGRAMMER:  Owen Sheikhanzai
// CPSC 1103  Section: 10
// PURPOSE:  Calculate the time to pay off a loan and the total amount paid
// INPUT:  User inputs the amount of loan, interest rate, and monthly payment

#include <iostream>  // Include the iostream library for input and output
#include <iomanip>   // Include the iomanip library for output formatting
#include <cctype>    // Include the cctype library for character functions
#include <string>    // Include the string library for string functions
using namespace std; // Use the standard namespace

// Function to set up the table
void table() {
  // Print table headers with specified column widths and left alignment
  cout << left << setw(10) << "Month"
       << left << setw(15) << "Principal" 
       << left << setw(20) << "Interest Paid" 
       << left << setw(20) << "Principal Paid"
       << left << setw(20) << "Remaining Balance" << endl;
  // Print a separator line
  cout << "----------------------------------------------------------------------------------" << endl;
}

// Function to validate if a string is a valid number
bool isValidNumber(const string& input) {
  for (char c : input) {
    if (!isdigit(c) && c != '.') {
      return false;
    }
  }
  return true;
}

// Function to get the loan details and handle errors
void loanDetails(double &principal, double &remainingBalance, double &interestRate, double &payment) {

  bool validInput = false; // Initialize flag for valid input
  string input; // Variable to store user input
  
  while(!validInput) {
    // Prompt user for loan amount and validate input
    cout << "What's the loan amount? $";
    getline(cin, input);
    while (!isValidNumber(input) || stod(input) <= 0) {
      cout << "Unable to accept input other than a number greater than 0!" << endl;
      cout << "What's the loan amount? $";
      getline(cin, input);
    }
    principal = stod(input); // Convert string to double for principal
    remainingBalance = principal; // Set principal to the loan amount

    // Prompt user for yearly interest rate and validate input
    cout << "What's the yearly interest rate? ";
    getline(cin, input);
    while (!isValidNumber(input) || stod(input) <= 0) {
      cout << "Unable to accept input other than a number greater than 0!" << endl;
      cout << "What's the yearly interest rate? $";
      getline(cin, input);
    }
    interestRate = (stod(input) / 12) / 100; // Convert yearly interest rate to monthly

    // Prompt user for monthly payment amount and validate input
    cout << "What amount will be paid monthly? $";
    getline(cin, input);
    while (!isValidNumber(input) || stod(input) <= 0) {
      cout << "Unable to accept input other than a number greater than 0!" << endl;
      cout << "What amount will be paid monthly? $";
      getline(cin, input);
    }
    payment = stod(input); // Convert string to double for payment

    // Ensure the monthly payment is sufficient to cover the interest
    if (principal * interestRate > payment) {
      cout << "Based on the given info, the loan will never be paid off! Please enter different values." << endl;
    }
    else {
      validInput = true;
    }
  }
}

// Function to loop through the calculations and print the table
void loop(double principal, double remainingBalance, double interestRate, double payment) {

  double interestTotal = 0; // Initialize total interest paid
  double principalPaid; // Variable to store principal paid each month
  int i = 0; // Initialize month counter

  // Loop until the remaining balance is paid off
  while (remainingBalance > 0) {
    double interest = remainingBalance * interestRate; // Calculate interest for the month
    interestTotal += interest; // Add interest to total interest paid
    principalPaid = payment - interest; // Calculate principal paid for the month
    remainingBalance = remainingBalance - principalPaid; // Update remaining balance
    i++; // Increment month counter

    // Print the details for the current month
    cout << left << setw(10) << i << "$"
         << left << setw(14) << principal << "$"
         << left << setw(19) << interest << "$"
         << left << setw(19) << principalPaid << "$"
         << left << setw(19) << remainingBalance << endl;

    principal = remainingBalance; // Update principal for the next iteration
  }

  // Print summary of loan repayment
  cout << "Number of payments to pay off the loan: " << i << endl;
  cout << "Total interest paid on loan: $" << interestTotal << endl;
  cout << "You have a credit of: $" << remainingBalance << endl;
}

// Main function to call the other functions
int main() {
  double principal, remainingBalance, interestRate, payment; // Declare variables

  cout << fixed << setprecision(2); // Set output format to fixed-point notation with 2 decimal places

  loanDetails(principal, remainingBalance, interestRate, payment); // Get loan details from user
  table(); // Set up the table
  loop(principal, remainingBalance, interestRate, payment); // Perform calculations and print the table

  return 0; // Exit the program
}