#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool isValidNumber(const string& input) {
  for (char c : input) {
    if (!isdigit(c) && c != '.') {
      return false;
    }
  }
  return true;
}

double getLength(){
  bool validInput = false;
  string input;
  double len;
  cout << "Enter the length of the rectangle: ";
  getline(cin, input);
  while (!isValidNumber(input) || stod(input) <= 0){
    cout << "Only able to accept number greater than 0 with no spaces" << endl;
    cout << "Enter the length of the rectangle: ";
    getline(cin, input);
  }
  len = stod(input);
  return len;
}

double getWidth(){
  bool validInput = false;
  string input;
  double wid;
  cout << "Enter the width of the rectangle: ";
  getline(cin, input);
  while (!isValidNumber(input) || stod(input) <= 0){
    cout << "Only able to accept number greater than 0 with no spaces" << endl;
    cout << "Enter the width of the rectangle: ";
    getline(cin, input);
  }
  wid = stod(input);
  return wid;
}

double getArea(double len, double wid){
  double area;
  area = len * wid;
  return area;
}

void displayData(double len, double wid, double area){
  cout << "Your chosen length was: " << len << endl;
  cout << "Your chosen width was: " << wid << endl;
  cout << "This makes your area: " << area << endl;
}
int main(){
  double length = getLength();
  double width = getWidth();
  double area = getArea(length,width);
  displayData(length,width,area);  
}