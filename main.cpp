#include <fstream>
#include "BMI.h"
#include <iomanip>
using namespace std;

int main()
{
  float temp_height = 0, temp_mass = 0;
  BMI bmi;

  ifstream inFile("file.in",ios::in);
  if(!inFile)
  {
    cout << "file.in open failure." << endl;
    return 0;
  }
  ofstream outFile("file.out",ios::out);
  if (!outFile) 
  {
    cout << "file.out open failure." << endl;
    return 0;
  }
  
  while(1)
  {
    inFile >> temp_height >> temp_mass;
    if (temp_height == 0 && temp_mass == 0) break;
    bmi.setHeight(temp_height);
    bmi.setMass(temp_mass);
    outFile << setprecision(4) << setw(5) << setiosflags(ios::left) << bmi.getBMI(); 
    outFile << "  " << bmi.getCategory() << endl;
  }


  return 0;
}
