#include <iostream>
using namespace std;
class processor
{
public:
 void setValues(char vend,int partID,double clock, int cores);
 char getVend();
 int getPartID();
 double getClockSpeed();
 int getCores();
 char vendor;
 int vendorPartID;
private:
 double maxClockSpeed; /*in GHz*/
 int numCores;
};
 
int main()
{
 double userAnswerDoub = -1.0;
 int userAnswerInt = -1;
 processor x68HC11,x8548e,xP4040,xTegra4,xSilverAtom;
 x68HC11.setValues('M',6811,0.002,1);
 x8548e.setValues('F',8548,1.2,1);
 xP4040.setValues('F',4040,1.6,4);
 xTegra4.setValues('N',4,1.4,5);
 xSilverAtom.setValues('I',2013,1.8,22);
 
 cout << "What is your clock speed?" << endl;
 cin >> userAnswerDoub;
 if(userAnswerDoub == x68HC11.getClockSpeed())
 {/*Found old school*/
  cout << "You have the 68HC11 " << endl;
  return 0; /*exit main*/
 }
 
 cout << "How many cores have ye?" << endl;
 cin >> userAnswerInt;
 /*** 2. Use the xP4040 number of cores at this line ***/
 if(userAnswerInt > xP4040.getCores())
 {/*Not Freescale*/
  switch(userAnswerInt)
  {
   case 5:
    cout << "Ye have Nvidia's Tegra 4 with vendor ID:" << xTegra4.getPartID() << endl;
    return 0;
    break;
   case 22:
    cout << "Ye have Intel's Atom Silvermount with vendor ID:" << xSilverAtom.getPartID() << endl;
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
      /*** 3. Use the appropriate processor and value for this line ***/
		 cout << "Ye have Freescale's 8548e with vendor ID:" << x8548e.getPartID() << endl;
      return 0;
      break;
     case 4:
      cout << "Ye have Freescale's P4040 with vendor ID:" << xP4040.getPartID() << endl;
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

void processor::setValues(char vend,int partID,double clock, int cores)
{
 vendor=vend;
 vendorPartID=partID;
 /*** 4. Fill in the appropriate line here to transfer the value of clock speed ***/
 maxClockSpeed = clock;
 numCores=cores;
}

char processor::getVend()
{
 return vendor;
}

int processor::getPartID()
{
 return vendorPartID;
}

double processor::getClockSpeed()
{
 return maxClockSpeed;
}

/*** 5. Fill in the appropriate line here to declare the remaining class member function ***/
int processor::getCores()
{
 return numCores;
}