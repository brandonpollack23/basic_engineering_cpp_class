#include <iostream>
using namespace std;

struct processor
{
 char vendor;
 int vendorPartID;
 double maxClockSpeed; /*in GHz*/
 int numCores;
};
 
int main()
{
 double userAnswerDoub = -1.0;
 int userAnswerInt = -1;
 processor x68HC11 = {'M',6811,0.002,1};
 processor x8548e = {'F',8548,1.2,1};
 processor xP4040 = {'F',4040,1.6,4};
 processor xTegra4 = {'N',4,1.4,5};
 processor xSilverAtom = {'I',2013,1.8,22};
 
 cout << "What is your clock speed?" << endl;
 cin >> userAnswerDoub;
 /*** 1. Use the clock speed of x8548e at this line ***/
 if(userAnswerDoub == .002)
 {/*Found old school*/
  cout << "You have the 68HC11 " << endl;
  return 0; /*exit main*/
 }
 
 cout << "How many cores have ye?" << endl;
 cin >> userAnswerInt;
 /*** 2. Use the xP4040 number of cores at this line ***/
 if(userAnswerInt > 4)
 {/*Not Freescale*/
  switch(userAnswerInt)
  {
   case 5:
    cout << "Ye have Nvidia's Tegra 4 with vendor ID:" << xTegra4.vendorPartID << endl;
    return 0;
    break;
   case 22:
    cout << "Ye have Intel's Atom Silvermount with vendor ID:" << xSilverAtom.vendorPartID << endl;
    return 0;
    break;
   default:
    cout << "Ye took a wrong turn at Albequerque" << endl;
    return -1;
    break;
  }
  } else {
    switch(userAnswerInt)
    {
     case 1:
		 cout << "Ye have Freescale's 8548e with vendor ID:" << x8548e.vendorPartID << endl;
      /*** 3. Use the appropriate processor and value for this line ***/
      return 0;
      break;
     case 4:
      cout << "Ye have Freescale's P4040 with vendor ID:" << xP4040.vendorPartID << endl;
      return 0;
      break;
     default:
      cout << "Ye have a Freescale but none I know" << endl;
      return -2;
      break;
    }
  }
 
 return 0;
}