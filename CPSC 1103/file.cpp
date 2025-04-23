#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;



int main(){
  ifstream ifile;
  ofstream ofile;

  ifile.open("input.txt");
  if (!ifile.is_open()){
    cout << "Error opening input file" << endl;
    return 0;
  }
  ofile.open("output.txt"); //ios::app
  if (!ofile.is_open()){
    cout << "Error opening output file" << endl;
    return 0;
  }

  int i = 0;
  while (ifile >> i){
    i += i;
    
  }
  ofile << i << endl;

  ifile.close();
  ofile.close();
  return 0;

}