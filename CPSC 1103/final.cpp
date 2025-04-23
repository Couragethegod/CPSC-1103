#include <iomanip>
#include <cctype>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*const int AISLE = 10;
const int ROW = 10;
int seats[AISLE][ROW] = {
  {10	10	10	10	10	10	10	10	10	10},
  {10	10	10	10	10	10	10	10	10	10},
  {10	10	10	10	10	10	10	10	10	10},
  {10	10	20	20	20	20	20	20	10	10},
  {10	10	20	20	20	20	20	20	10	10},
  {10	10	20	20	20	20	20	20	10	10},
  {20	20	30	30	40	40	30	30	20	20},
  {20	30	30	40	50	50	40	30	30	20},
  {30	40	50	50	50	50	50	50	40	30},
  {30	40	50	50	50	50	50	50	40	30}
};
void displayseats();
void buyseatbylocation();
void buyseatbyprice();

int main(){
  int choice;

  do{
    displayseats();
    switch(choice){
      case 1:
        buyseatbylocation();
      case 2:
        buyseatbyprice();
      case 3:

    }
  }
  return 0;
  
}

void displayseats(){
  for()
}
void buyseatbylocation(){

}
void buyseatbyprice(){
  
}*/

//BUBBLE SORT
/*int main(){
  const int SIZE = 4;
  int arr[SIZE] = {5,1,4,0};

  for(int i = 0; i < SIZE-1; i++){
    for(int j = 0; j < SIZE-i-1; j++){
      if(arr[j] > arr[j+1])
        swap(arr[j],arr[j+1]);
    }
  }
  for(int i = 0; i < SIZE; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}*/

/*SELECTION SORT
int main(){
  const int SIZE = 12;
  int arr[SIZE] = {4,5,1,2,0,-1,2,22,20,100,-2,1000};
  int min;
  
  for(int i = 0; i < SIZE; i++){
    min = i;
    for(int j = i+1; j < SIZE; j++){
      if(arr[j] < arr[min]){
        swap(arr[j],arr[min]);
      }
    }
  }

  for(int i = 0; i < SIZE; i++)
    cout << arr[i] << "  ";
}*/

/*LINEAR SEARCH
int main(){
  const int SIZE = 4;
  int arr[SIZE] = {2, 4, 5, 1};
  int value;
  cout << "What value would you like to search for: ";
  cin >> value;

  for(int i = 0; i < SIZE; i++){
    if(value == arr[i])
      value = i;
  }
  if(value >= 0)
    cout << "The value was found in index: " << value << endl;
  else
    cout << "The value was not found." << endl;
}*/

/*BINARY SEARCH
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // if x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // if x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // if we reach here, then element was not present
    return -1;
}
int main(){
  const int SIZE = 7;
  int arr[SIZE] = {1,5,3,2,9,10,0};

  for(int i=0; i < SIZE - 1; i++){
    for(int j=0; j < SIZE - i - 1 ; j++){
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);    
    }
  }

  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  if(result == -1) cout << "Element is not present in array";
  else cout << "Element is present at index " << result;
  return 0;
}*/

/*PASSWORD VERIFICATION
Bool isValid(const string& password){
  if(password.length() < 6)
    return false;
  Bool hasUpper() = false;
  Bool hasLower() = false;
  Bool hasDigit = false;

  for(char ch: password){
  if(isupper(ch) = hasUpper = true;
  if(islower(ch) = hasLower = true;
  if(isdigit(ch) = hasDigit = true;
  }
  return hasUpper, hasLower, hasDigit;
}
int main(){
  string password;
  cin >> password;
  if(isValid(password))
    cout << “Valid” << endl;
  else
    cout << “Invalid” << endl;
}
*/

/*DISPLAY TABLE
const int NUMEMP = 20;
// Displays all the data in tabular form using sets to two decimal places.
void showresults(const int id[], const string name[], const double pay[], const string status[], double total);

void showresults(const int id[], const string name[], const double pay[], const string status[], double total){
  cout << fixed << setprecision(2);
  cout << left << setw(15) << "ID"
       << left << setw(15) << "NAME"
       << left << setw(15) << "PAY"
       << left << setw(15) << "STATUS" << endl;
  
  cout << string(50, '-') << endl;
  for(int i = 0; i < NUMEMP; i++){
    cout << left << setw(15) << id[i]
         << left << setw(15) << name[i]
         << left << setw(15) << pay[i]
         << left << setw(15) << status[i] << endl;
  }
  cout << "\nTotal Pay: $" << total << endl;
}*/

/*DETERMINE STATUS
const int NUMEMP = 20;
// Calculates "bonus" for >= 100 weekly or "regular" for less than 100.
void calStatus(const double pay[], string status[]);

void calStatus(const double pay[], string status[]){
  for(int i = 0; i < NUMEMP; i++){
    if(pay[i] >= 100)
      status[i] = "bonus";
    else
    status[i] = "regular";
  }
}*/

/*CALCULATE TOTAL PAy
const int NUMEMP = 20;
double total = 0;
double calTotal(const double pay[]);

double calTotal(const double pay[]){
  for(int i = 0; i < NUMEMP; i++){
    total += pay[i];
  }
  return total;
}*/

/*VALIDATE PAY
get employee data to make sure all employees have valid pay between 0 and 200.
const int NUMEMP = 20;
void getdata(int id[], string name[], double pay[]);

void getdata(int id[], string name[], double pay[]){
  for(int i = 0; i < NUMEMP; i++){
    cout << "Eneter ID for employee #" << i+1;
    cin >> id[i];
    cout << "Eneter name for employee #" << i+1;
    getline(cin,name[i]);

    do{
      cout << "Please enter pay between 0 and 200 for employee #" << i+1;
      cin >> pay[i];
    }
    while(pay[i] < 0 || pay[i] > 200);
  }
}*/

/*Write a program that stores 10 integers in an array and calculates the sum and average. Output the results.
int main(){
  const int SIZE = 10;
  int arr[SIZE];
  double sum = 0;
  double avg = 0;

  for(int i = 0; i < SIZE; i++){
    cout << "Please enter a value for index #" << (i+1) << ": ";
    cin >> arr[i];
    sum += arr[i];
  }
  avg = sum/SIZE;
  cout << "Sum is: " << sum << endl;
  cout << "Average is: " << avg << endl;
}*/

/*Write a program that asks for 5 names and then displays the one that comes first and last alphabetically.
int main(){
  const int SIZE = 5;
  string name;
  string arr[SIZE];

  for(int i = 0; i < SIZE; i++){
    cout << "Please enter a name: ";
    getline(cin,arr[i]);
  }

  for(int i = 0; i < SIZE-1; i++){
    for(int j = 0; j < SIZE-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
  }
  cout << "The first name is: " << arr[0] << endl;
  cout << "The last name is: " << arr[SIZE-1] << endl;
  return 0;
}*/

/* Recursive factorial function
int factorial(int n) {
  if (n <= 1) // base case: 0! = 1, 1! = 1
    return 1;
  else
    
    return n * factorial(n-1); // recursive call
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << num << " is " << factorial(num) << endl;

    return 0;
}*/

/*Seating Chart
int main(){
  const int a = 10;
  const int r = 10;
  int seats[a][r];

  for(int i = 0; i < a; i++){
    for(int j = 0; j < r; j++){
      seats[a][r]=1;
    }
  }
  for(int i = 0; i < a; i++){
    for(int j = 0; j < r; j++){
      cout << seats[a][r] << "  ";
    }
    cout << endl;
  }
  return 0;
  
}*/

/*int sumOfDigits(int n){
  if(n == 0){
    return 0;
  }
  else{
    return (n % 10) + sumOfDigits(n / 10);
  }
}
int main(){
  int n;
  cout << "Please enter a number to find the sum of: ";
  cin >> n;
  cout << "The sum is: " << sumOfDigits(n) << endl;
}*/

/* A teacher has asked all her students to line up according to their first name. 
int main(){
  int number;
  string name;
  string first;
  string last;

  cout << "How many students are there (1 to 25)? ";
  cin >> number;
  while(cin.fail() || number < 1 || number > 25){
    cin.clear();
    cin.ignore();
    cout << "How many students are there (1 to 25)? ";
    cin >> number;
  }

  cout << "Please enter the name of student #1: ";
  cin.ignore();
  cin.clear();
  getline(cin,name);

  first = name;
  last = name;

  for(int i = 2; i <= number; i++){
    cout << "Please enter the name of student #" << i << ": ";
    cin.clear();
    getline(cin,name);
    if(first > name)
      first = name;
    if(last < name)
      last = name;
  }

  cout << "The first student is: " << first << endl;
  cout << "The last student is: " << last << endl;

  return 0;
}*/

/*Write a C++ program with a loop to enter 10 employees (id as an int,  name as string, hours as double, rate as constant 25.5). Make sure that the hours are valid between 0 and 8 inclusive.  As you process each employee keep a grand total of the pay. Output the employee's id, name, hours. and pay inside the loop.  At the end of the process output the average pay correct to 2 decimal place. Show all the libraries needed for a correct C++ program. Comments are not necessary.

int main(){
  int SIZE = 2;
  int id;
  string name;
  double hours;
  double pay;
  double total;
  double average;
  const double rate = 25.5;

  cout << fixed << setprecision(2);

  for(int i = 0; i < SIZE; i++){
    cout << "Please enter the ID for employee #" << (i+1) << ": ";
    cin >> id;
    cout << "Please enter the name for employee #" << (i+1) << ": ";
    cin >> name;
    cout << "Please enter the hours for employee #" << (i+1) << ": ";
    cin >> hours;
    while(cin.fail() || hours < 0 || hours > 8){
      cin.clear();
      cin.ignore();
      cout << "Please enter the hours for employee #" << (i+1) << ": ";
      cin >> hours;
    }
    pay = hours*rate;
    total += pay;

    cout << "For employee with ID: " << id << ", Name: " << name << ", Hours: " << hours << ", the pay will be: $" << pay << "!" << endl; 
  }

  average = total/SIZE;
  cout << "The average pay is: $" << average << "!" << endl;

}*/

/*C++. Write a function given a password which verifies that: The password should be at least 6 characters long. Should contain at least one uppercase and one lowercase letter. Should have at least one digit

bool verifyPass(string& password){
  if(password.length() < 6)
    return false;

  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;

  for(char ch : password){
    if(isupper(ch)) hasUpper = true;
    if(islower(ch)) hasLower = true;
    if(isdigit(ch)) hasDigit = true;
  }

  return hasUpper && hasLower && hasDigit;
}

int main(){
  string password;
  cout << "Please enter a password to verify: ";
  cin >> password;

  if(verifyPass(password))
    cout << "Password Valid" << endl;
  else
    cout << "Password Invalid" << endl;
  
    return 0;
}*/

/*Given the global constant and prototype write the function definition for function showresults. Displays all the data in tabular form using sets to two decimal places.

const int NUMEMP = 20;
void showresults(const int id[], const string name[], const double pay[], const string status[], double total);

void showresults(const int id[], const string name[], const double pay[], const string status[], double total){
  cout << fixed << setprecision(2);
  cout << left << setw(10) << "ID" << left << setw(20) << "NAME" << left << setw(10) << "PAY" << left << setw(10) << "STATUS" << endl;

  cout << "___________________________________________________________" << endl;

  for(int i = 0; i < NUMEMP; i++){
    cout << left << setw(10) << id[i] << left << setw(20) << name[i] << left << setw(10) << pay[i] << left << setw(10) << status[i] << endl;
  }

  cout << "The total is: $" << total << endl;
}*/

/* Calculates "bonus" for >= 100 weekly or "regular" for less than 100.
const int NUMEMP = 20;
void calStatus(const double pay[], string status[]);

void calStatus(const double pay[], string status[]){
  for(int i = 0; i < NUMEMP; i++){
    if(pay[i] >= 100){
      status[i] = "bonus";
    }
    else{
      status[i] = "regular";
    }
  }
}*/

/* calculates total pay for all employees.
const int NUMEMP = 20;
double calTotal(const double pay[]);

double calTotal(const double pay[]){
  double total;
  for(int i = 0; i < NUMEMP; i++){
    total += pay[i];
  }

  return total;
}*/

/* get employee data to make sure all employees have valid pay between 0 and 200.
const int NUMEMP = 2;
void getdata(int id[], string name[], double pay[]);

void getdata(int id[], string name[], double pay[]){
  for(int i = 0; i < NUMEMP; i++){
    cout << "Please enter the ID for employee #" << (i+1) << ": ";
    cin >> id[i];
    cout << "Please enter the name for employee #" << (i+1) << ": ";
    cin >> name[i];
    cout << "Please enter the pay for employee #" << (i+1) << ": ";
    cin >> pay[i];
    while(cin.fail() || pay[i] < 0 || pay[i] > 200){
      cin.clear();
      cin.ignore();    
      cout << "Please enter the pay for employee #" << (i+1) << ": ";
      cin >> pay[i];
    }
  }
}
int main(){
  int id[NUMEMP];
  string name[NUMEMP];
  double pay[NUMEMP];
  getdata(id,name,pay);
}*/

/*int main(){
  const int r = 4;
  const int c = 4;
  int seats[r][c];
  
  
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(i == j)
        seats[i][j] = 0;
      else
        seats[i][j] = 1;
    }
  }

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << seats[i][j] << "  ";
    }
    cout << endl;
  }
}*/

/*int wordCount(string name){
  int count = 1;
  for(int i = 0; i < name.length(); i++){
    if(name[i] == ' '){
      count++;
    }
  }
  if(name.length() == 0)
    count = 0;
  return count;
}
int main(){
  string name;
  cout << " Please enter a string: ";
  getline(cin,name);

  cout << "Your string had " << wordCount(name) << " words." << endl;
}*/

/*int main(){

  const int SIZE = 4;
  int arr[SIZE][SIZE];

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      arr[i][j] = 1;
    }
  }

  srand(time(0));
  int num1 = rand() % SIZE;
  int num2 = rand() % SIZE;
  int num3 = rand() % SIZE;
  int num4 = rand() % SIZE;
  
  arr[num1][num2] = 0;
  arr[num3][num4] = 0;

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}*/

