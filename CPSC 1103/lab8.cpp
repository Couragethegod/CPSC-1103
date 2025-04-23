#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_NAMES = 20;

void getNames(string names[], int marks[], int& numElts);
void displayData(const string names[], const int marks[], int numElts);
int linearSearch(const string names[], int numElts,string who);
void selectionSort(string names[], int marks[],int numElts);
int binarySearch(const string names[], int numElts, string who);

int main(){

  string names[NUM_NAMES];
  int marks[NUM_NAMES];

	int numElts;
  int index;
	string searchWho;

  getNames(names, marks, numElts);
  displayData(names, marks, numElts);

  cout << "Enter a name to search (linear search): ";
  cin >> searchWho;
  index = linearSearch(names, numElts, searchWho);
  if (index != -1) {
    cout << searchWho << "'s mark: " << marks[index] << endl << endl;
  } 
  else {
    cout << "Name not found!" << endl << endl;
  }

  selectionSort(names, marks, numElts);
  cout << "Here's the sorted list:" << endl;
  displayData(names, marks, numElts);

  cout << "Enter a name to search for (binary search): ";
  cin >> searchWho;

  index = binarySearch(names, numElts, searchWho);
  if (index != -1){
    cout << searchWho << "'s mark: " << marks[index] << endl;
  }
  else {
    cout << "Name not found!" << endl;
  }
  return 0;
}

void getNames(string names[], int marks[], int& numElts) {
  ifstream inputFile("names_marks.txt");
  if (!inputFile) {
    cout << "Error opening file!" << endl;
    exit(1);
  }
  numElts = 0;
  while (numElts < NUM_NAMES && inputFile >> names[numElts] >> marks[numElts]) {
    numElts++;
  }
  if(numElts == 0){
    cout << "File is empty" << endl;
    exit(1);
  }
  inputFile.close();
}

void displayData(const string names[], const int marks[], int numElts){
  for (int i = 0; i < numElts; i++){
    cout << names[i] << "\t" << marks[i] << endl;
  }
  cout << endl;
}

int linearSearch(const string names[], int numElts,string who){
  for (int i = 0; i < numElts; i++){
    if (names[i] == who){
      return i;
    }
  }
  return -1;
}

void selectionSort(string names[], int marks[], int numElts){
  for(int i = 0; i < numElts - 1; i++){
    int minIndex = i;
    for(int j = i + 1; j < numElts; j++){
      if (names[j] < names[minIndex]){
        minIndex = j;
      }
    }
    swap(names[i], names[minIndex]);
    swap(marks[i], marks[minIndex]);
  }
}

int binarySearch(const string names[], int numElts, string who){
  int left = 0, right = numElts - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (names[mid] == who) {
      return mid;
    } 
    else if (names[mid] < who) {
      left = mid + 1;
    } 
    else {
      right = mid - 1;
    }
  }
  return -1;
}