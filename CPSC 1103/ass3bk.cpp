// FILE:        Assignment03.cpp
// PROGRAMMER:  Owen Sheikhanzai
// CPSC 1103    Section: 10
// PURPOSE:     This program simulates a theatre seating chart where users can buy seats.
//              The seating chart is represented as a 2D array, where each element indicates the price of the seat.
//              The program allows users to buy seats either by specifying the aisle and row or by selecting a price.
//              The program includes input validation to ensure that the user enters valid data.
// INPUT:       User can input aisle and row numbers or a price to buy a seat.
// OUTPUT:      The program displays the seating chart and confirms the purchase of a seat.

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std; // Declaring the libraries and namespace

const int AISLES = 10; //  Constants for the number of aisles
const int ROWS = 10; // Constants for the number of rows

int seatingChart[AISLES][ROWS] = {
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
    {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
    {20, 20, 30, 30, 40, 40, 30, 30, 20, 20},
    {20, 30, 30, 40, 50, 50, 40, 30, 30, 20},
    {30, 40, 50, 50, 50, 50, 50, 50, 40, 30},
    {30, 40, 50, 50, 50, 50, 50, 50, 40, 30}
}; // Initializing the seating chart with prices

// Function to get a validated integer input from the user
int getValidatedInt(string prompt, int min, int max) { 
    string input; // Variable to store user input
    int value; // Variable to store the validated integer

    while (true) {
        cout << prompt; // Display the prompt to the user
        getline(cin, input); // Get the input from the user

        bool isValid = !input.empty(); // Check if the input is not empty

        for (char ch : input) {
            if (!isdigit(ch)) { // Check if each character is a digit
                isValid = false; // Check if the input contains only digits
                break; // Exit the loop if a non-digit character is found
            }
        }

        if (isValid) { 
            stringstream ss(input);  // Create a stringstream object to convert the string to an integer
            ss >> value; // Convert the string input to an integer
            if (value >= min && value <= max) { // Check if the value is within the specified range
                return value; // Return the validated integer
            }
        }

        cout << "Invalid input. Please enter an integer between " << min << " and " << max << ".\n"; // Display an error message if the input is invalid
    }
}

// Display the current seating chart
void displaySeatingChart() {
    cout << "\n          "; 
    for (int r = 1; r <= ROWS; r++) {
        cout << "R" << r << "  "; // Display row numbers
    }
    cout << "\n       --------------------------------------------------\n";

    for (int a = 0; a < AISLES; a++) { 
        cout << "Aisle " << (AISLES - a); // Display aisle numbers
        if (AISLES - a < 10) cout << " "; // align single-digit numbers
        cout << "| ";
        for (int r = 0; r < ROWS; r++) {
            if (seatingChart[a][r] == 0) // Check if the seat is sold
                cout << " 0  "; // Display sold seats as 0
            else if (seatingChart[a][r] < 10) // Check if the price is a single digit
                cout << " " << seatingChart[a][r] << "  "; // Display single-digit prices with space
            else 
                cout << seatingChart[a][r] << "  "; // Display double-digit prices
        }
        cout << "|\n"; // End the row display
    }

    cout << "       --------------------------------------------------\n"; // Display the bottom border of the seating chart
}

// Buy a seat by specific aisle and row
void buySeatByPosition() {
    int aisle = getValidatedInt("Enter aisle number (1-10): ", 1, 10); // Get the aisle number from the user
    int row = getValidatedInt("Enter row number (1-10): ", 1, 10); // Get the aisle row number from the user

    int aisleIndex = AISLES - aisle; // Convert aisle number to index
    int rowIndex = row - 1; // Convert row number to index

    if (seatingChart[aisleIndex][rowIndex] == 0) { // Check if the seat is already sold
        cout << "Sorry, that seat is already sold.\n"; // Message if the seat is already sold
    } else {
        seatingChart[aisleIndex][rowIndex] = 0; // Mark the seat as sold
        cout << "Seat in Aisle " << aisle << ", Row " << row << " successfully purchased!\n"; // Confirm the purchase
    }
}

// Buy a seat by selecting a price
void buySeatByPrice() {
    int price = getValidatedInt("Enter desired price: ", 10, 50); // Get the price from the user

    for (int a = AISLES - 1; a >= 0; a--) { // Bottom-up search
        for (int r = 0; r < ROWS; r++) { // Loop through the seating chart
            if (seatingChart[a][r] == 0) continue; // Skip sold seats
            if (seatingChart[a][r] == price) { // Check if the seat matches the desired price
                seatingChart[a][r] = 0; // Mark the seat as sold
                cout << "Seat at Aisle " << (AISLES - a) << ", Row " << (r + 1) << " purchased at $" << price << ".\n"; // Confirm the purchase
                return; // Exit the function after successful purchase
            }
        }
    }
    cout << "No seats found at that price.\n"; // Message if no seats are available at the specified price
}

// Main loop
int main() {
    int choice; // Variable to store the user's choice
    cout << "Welcome to the Theatre Seating System!\n"; // Welcome message
    cout << "This program allows you to buy seats in a theatre.\n"; // Program description
    cout << "Please select an option from the menu below:\n"; // Instructions for the user
 
    do { 
        displaySeatingChart(); // Display the seating chart
        cout << "\nMenu:\n"; // Display the menu options
        cout << "1. Buy seat by Aisle & Row\n"; // Option to buy by aisle and row
        cout << "2. Buy seat by Price\n"; // Option to buy by price
        cout << "3. Quit\n"; // Option to quit the program
 
        choice = getValidatedInt("Enter your choice (1-3): ", 1, 3); // Get the user's choice

        switch (choice) { 
            case 1: // Buy seat by aisle and row
                buySeatByPosition();
                break;
            case 2: // Buy seat by price
                buySeatByPrice();
                break;
            case 3: // Quit the program
                cout << "Thank you for using the theatre system. Goodbye!\n";
                break;
        }

    } while (choice != 3); // Continue until the user chooses to quit

    return 0; // Return 0 to indicate successful completion
}
