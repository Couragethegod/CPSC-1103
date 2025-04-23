//Programmer(s): Owen Sheikhanzai

//Purpose: Get grades from the User, Show the grades, find and show the Highest . Count and show how many had the Highest grades

#include <iostream>

using namespace std;

const int SIZE = 5;

const int SENTINEL = -1;

void getGrades(double[],int,int&);

void showGrades(const double[],int);

double getHighest(const double[], int);

int countHighest(const double[], int, double);

void showHigh_Count(double, int);

int main()
{
  double grades[SIZE];
  int length;
  getGrades(grades, SIZE, length);
  showGrades(grades, length);
  double highest = getHighest(grades, length);
  int count = countHighest(grades, length, highest);
  showHigh_Count(highest, count);
  return 0;
}

void getGrades(double grades[], int size, int& length)
{
  int i = 0;
  double grade;
  cout << "Enter " << size << " grades, or -1 to quit: ";
  cin >> grade;
  while (grade != SENTINEL && i < size)
  {
    grades[i] = grade;
    i++;
    if (i == SIZE)
      cout << "Array is full";
    else
    {
      cout << "Enter " << size << " grades, or -1 to quit: ";
      cin >> grade;
    }
  }
  length = i;
}

void showGrades(const double grades[], int length)
{
  cout << "The grades are: ";
  for (int i = 0; i < length; i++)
  {
    cout << grades[i] << " ";
  }
  cout << endl;
}

double getHighest(const double grades[], int length)
{
  double highest = grades[0];
  for (int i = 1; i < length; i++)
  {
    if (grades[i] > highest)
    {
      highest = grades[i];
    }
  }
  return highest;
}

int countHighest(const double grades[], int length, double highest)
{
  int count = 0;
  for (int i = 0; i < length; i++)
  {
    if (grades[i] == highest)
    {
      count++;
    }
  }
  return count;
}

void showHigh_Count(double highest, int count)
{
  cout << "The highest grade is " << highest << endl;
  cout << "The number of students who got the highest grade is " << count << endl;
}