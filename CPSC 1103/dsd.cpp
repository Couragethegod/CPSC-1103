#include <iostream>
using namespace std;

void getValues(double value[], int size);
void displayValues(const double value[], int size);
double largest(const double value[], int size);
double smallest(const double value[], int size);
void displayLargestSmallest(double largestValue, double smallestValue);

int main() {
  const int SIZE = 10;
  double numbers[SIZE];

  getValues(numbers, SIZE);
  displayValues(numbers, SIZE);
  double maxVal = largest(numbers, SIZE);
  double minVal = smallest(numbers, SIZE);
  displayLargestSmallest(maxVal, minVal);

  return 0;
}

// Function definitions
void getValues(double value[], int size) {
  cout << "Enter " << size << " numbers:" << endl;
  for (int i = 0; i < size; i++) {
    cout << "Number " << (i + 1) << ": ";
    cin >> value[i];
  }
}

void displayValues(const double value[], int size) {
  cout << "\nYou entered:\n";
  for (int i = 0; i < size; i++) {
    cout << value[i] << " ";
  }
  cout << endl;
}

double largest(const double value[], int size) {
  double maxVal = value[0];
  for (int i = 1; i < size; i++) {
    if (value[i] > maxVal) {
      maxVal = value[i];
    }
  }
  return maxVal;
}

double smallest(const double value[], int size) {
  double minVal = value[0];
  for (int i = 1; i < size; i++) {
    if (value[i] < minVal) {
      minVal = value[i];
    }
  }
  return minVal;
}

void displayLargestSmallest(double largestValue, double smallestValue) {
  cout << "\nThe largest value is: " << largestValue << endl;
  cout << "The smallest value is: " << smallestValue << endl;
}
