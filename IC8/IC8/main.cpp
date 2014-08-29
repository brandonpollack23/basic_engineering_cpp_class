//IC8 yay
//Brandon Pollack
//2375-4365
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 double userValue = 0;
 double valueCeiling = 0;
 double valueFloor = 0;

 /*Take in user input*/
 cout << "Please provide a number, preferably non-integer" << endl;
 cin >> userValue;

 /*Compute the ceiling then floor using the cmath library and place into the appropriate variable*/
/***** write the two lines of code that would be put here *****/
 valueCeiling = ceil(userValue);
 valueFloor = floor(userValue);


 cout << "Your number: " << userValue << " ceiling: " << valueCeiling << " floor: " << valueFloor << endl;
 return 0;
}