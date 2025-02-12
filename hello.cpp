#include <iomanip>
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main() {
	double a;
	double n;
	double sum = 0;

	cout << "Enter a positive number: ";
	cin >> a;

	if (!cin) {
		cout << "Unable to accept non-number input! Rerun the code." << endl;
		exit(0);
	}

	while (a <= 0) {
		cout << "Unable to accept number less than 0!" << endl;
		cout << "Enter a positive number: ";
		cin >> a;
	}

	for (n = 1; n <= a; n++) {
		sum += n;
	}
	cout << sum << endl;
	return 0;
}