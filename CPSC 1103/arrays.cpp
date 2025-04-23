#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int numbers [5];
  int sum = 0;

  for (int i=0; i<5; i++){
    cout << "Enter an integer :";
    cin >> numbers[i];
    sum += numbers[i];
  }

  cout << sum << endl;
  return 0;
}