// FILE: Assignment01.cpp
// PROGRAMMER:  Owen Sheikhanzai
// CPSC 1103	Section: 10
// PURPOSE:  Calculate the total cost of a phone plan based on the user’s package choice and data usage
// INPUT:  User inputs a package choice and data usage

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; // Declaring the libraries and namespace

char package; // Declaring the variable for package choice
int globalData; // Global variable for data usage

// Function to calculate the cost of package A
double packageA(){
  double base = 39.99; // Local variable for base cost
  double dataCost = 0.00; // Local variable for additional data cost
  if (globalData > 4){ // If data usage exceeds 4GB
    dataCost = (globalData - 4) * 10; // Calculate additional data cost
  }
  double costA = base + dataCost; // Total cost for package A
  return costA; // Return the total cost
}

// Function to calculate the cost of package B
double packageB() {
  double base = 59.99; // Local variable for base cost
  double dataCost = 0; // Local variable for additional data cost
  if (globalData > 8) { // If data usage exceeds 8GB
    dataCost = (globalData - 8) * 5; // Calculate additional data cost
  }
  double costB = base + dataCost; // Total cost for package B
  return costB; // Return the total cost
}

// Function to calculate the cost of package C
double packageC() {
  double base = 69.99; // Local variable for base cost
  double costC = base; // Total cost for package C (no additional data cost)
  return costC; // Return the total cost
}

int main(){
  cout << fixed << setprecision(2); // Set the output format to fixed with 2 decimal places

  cout << "Which package did you choose? ";
  cin >> package; // Get the package choice from the user
  if (cin.fail() || cin.peek() != '\n') { // Check if the input is valid (only one character)
    cout << "More than one character! Rerun the code." << endl; // Error message for invalid input
    return 0; // Exit the program
  }
  if (package != 'A' && package != 'B' && package != 'C'){ // Check if the package choice is valid (A, B, or C)
    cout << "Invalid Package! Rerun the code." << endl; // Error message for invalid package
    return 0; // Exit the program
  }

  cout << "How many GB's of data did you use? ";
  cin >> globalData; // Get the data usage from the user
  if (cin.fail() || cin.peek() != '\n') { // Check if the input is valid 
    cout << "Not an integer! Rerun the code." << endl; // Error message for invalid input
    return 0; // Exit the program
  }
  if (globalData < 0){ // Check if the data usage is valid
    cout << "Negative Number! Rerun the code." << endl; // Error message for negative data usage
    return 0; // Exit the program
  }

double costA = packageA(); // Calculate the cost for package A
double costB = packageB(); // Calculate the cost for package B
double costC = packageC(); // Calculate the cost for package C

double AB = costA - costB; // Calculate the cost difference between package A and B
double AC = costA - costC; // Calculate the cost difference between package A and C
double BA = costB - costA; // Calculate the cost difference between package B and A
double BC = costB - costC; // Calculate the cost difference between package B and C
double CA = costC - costA; // Calculate the cost difference between package C and A
double CB = costC - costB; // Calculate the cost difference between package C and B

  cout << "Total: $";
  switch (package)
  {
  case 'A': // If the user chose package A
    cout << costA << endl; // Output the total cost for package A
    if (floor(AB) == 0){ // Check if the cost difference between package A and B is zero (using floor function to round down to handle near zero values)
      AB = 0; // Set the cost difference to zero
    }
    if (floor(AC) == 0){ // Check if the cost difference between package A and C is zero
      AC = 0; // Set the cost difference to zero
    }
    if (AB > 0){ // If package B is cheaper than package A
      cout << "Choosing Package B would have saved you: $" << AB << endl; // Output the savings
    }
    if (AC > 0){ // If package C is cheaper than package A
      cout << "Choosing Package C would have saved you: $" << AC << endl; // Output the savings
    }
    break;

  case 'B': // If the user chose package B
    cout << costB << endl; // Output the total cost for package B
    if (floor(BA) == 0){ // Check if the cost difference between package B and A is zero
      BA = 0; // Set the cost difference to zero
    }
    if (floor(BC) == 0){ // Check if the cost difference between package B and C is zero
      BC = 0; // Set the cost difference to zero
    }
    if (BA > 0){ // If package A is cheaper than package B
      cout << "Choosing Package A would have saved you: $" << BA << endl; // Output the savings
    }
    if (BC > 0){ // If package C is cheaper than package B
      cout << "Choosing Package C would have saved you: $" << BC << endl; // Output the savings
    }
    break;
    
  case 'C': // If the user chose package C
    cout << costC << endl; // Output the total cost for package C
    if (floor(CA) == 0){ // Check if the cost difference between package C and A is zero
      CA = 0; // Set the cost difference to zero
    }
    if (floor(CB) == 0){ // Check if the cost difference between package C and B is zero
      CB = 0; // Set the cost difference to zero
    }
    if (CA > 0){ // If package A is cheaper than package C
      cout << "Choosing Package A would have saved you: $" << CA << endl; // Output the savings
    }
    if (CB > 0){ // If package B is cheaper than package C
      cout << "Choosing Package B would have saved you: $" << CB << endl; // Output the savings
    }
    break;
  default:
    break;
  }
  return 0; // Exit the program
}