#include <iostream>
using namespace std;

class powerPlant
{
 public:
  void setValues(char newName,int newSupply,bool newOnline);
  void print();
  bool getOnline();
  char name;
  int supply; /*in MW*/
 private:
  bool online;
};

class city
{
 public:
  void setValues(char newName,int newDemand,bool newLighted);
  void print();
  bool getLighted();
  char name;
  int demand; /*in MW*/
 private:
  bool lighted;
};

int main() {
 powerPlant areaPlants[5];
 city areaCities[8];
 int supplySum,demandSum;
 char userIn;
	
 /*Initialize plants*/	
 areaPlants[0].setValues('A',10,1);
 areaPlants[1].setValues('B',20,1);
 areaPlants[2].setValues('C',20,1);
 areaPlants[3].setValues('D',50,1);
 areaPlants[4].setValues('E',90,1);
 
 /*Initialize cities*/	
 areaCities[0].setValues('J',10,1);
 areaCities[1].setValues('K',10,1);
 areaCities[2].setValues('L',10,1);
 areaCities[3].setValues('M',20,1);
 areaCities[4].setValues('N',20,1);
 areaCities[5].setValues('O',20,1);
 areaCities[6].setValues('P',30,1);
 areaCities[7].setValues('Q',30,1);

 cout << "Current power system status:" << endl;
 supplySum=0;
 for(int loop=0;loop<5;loop++)
 {/*print plants*/
  areaPlants[loop].print();
  if(areaPlants[loop].getOnline())
  {/*check online*/
   supplySum = supplySum+areaPlants[loop].supply;
  }
 }
 demandSum = 0;
 for(int loop=0;loop<8;loop++)
 {/*print cities*/
  areaCities[loop].print();
  if(areaCities[loop].getLighted())
  {/*check lighted*/
   demandSum = demandSum+areaCities[loop].demand;
  }
 }
 cout << "Power supply total:" << supplySum << " and demand total: " << demandSum << " MW" << endl;
 if( (supplySum-demandSum)<10)
 {/*if too much demand show warning*/
  cout << "*** Demand exceeds or is close to exceeding supply!!! ***" << endl;
 } else {
 	cout << "All systems nominal" << endl;
 }

 /*Accept user input of a failed plant*/
 userIn = 'Z';
 while(userIn == 'Z')
 {/*loop while user hasn't provided correct input*/
  cout << "Input a plant failure by character name: A,B,C,D or E" << endl;
  cin >> userIn;
  switch(userIn)
  {/*for valid cases update the plant's status*/
   case 'A':
   case 'B':
   case 'C':
   case 'D':
   case 'E':
    for(int loop=0;loop<5;loop++)
    {/*check plants*/
     if(userIn==areaPlants[loop].name)
     {/*Update all values and set to offline by calling correct function*/
      /****!!!!**** Student fill in this one line of code ****!!!!****/
		 areaPlants[loop].setValues(areaCities[loop].name,areaPlants[loop].supply, false);
     }
    }
    break;
   default:
    userIn = 'Z';
    break;
  }
 }
 
 /*print updated values*/
 cout << "Updated power system status:" << endl;
 supplySum=0;
 for(int loop=0;loop<5;loop++)
 {/*print plants*/
  areaPlants[loop].print();
  if(areaPlants[loop].getOnline())
  {/*check online*/
   supplySum = supplySum+areaPlants[loop].supply;
  }
 }
 demandSum = 0;
 for(int loop=0;loop<8;loop++)
 {/*print cities*/
  areaCities[loop].print();
  if(areaCities[loop].getLighted())
  {/*check lighted*/
   demandSum = demandSum+areaCities[loop].demand;
  }
 }
 cout << "Power supply total:" << supplySum << " and demand total: " << demandSum << " MW" << endl;
 if( (supplySum-demandSum)<10)
 {/*if too much demand show warning*/
  cout << "*** Demand exceeds or is close to exceeding supply!!! ***" << endl;
 } else {
 	cout << "All systems nominal";
 }

 return 0;
}

void powerPlant::setValues(char newName,int newSupply,bool newOnline)
{/*set the plants values*/
 name = newName;
 supply = newSupply;
 online = newOnline;
}

void powerPlant::print()
{/*print plant's values*/
 cout << "Plant " << name << " supply " << supply << " MW is:";
 if(online == 1)
 {
  cout << "online" << endl;
 } else {
 	cout << "offline" << endl;
 }
}

bool powerPlant::getOnline()
{/*get private data member value*/
 return online;
}

void city::setValues(char newName,int newDemand,bool newLighted)
{/*set the city's values*/
 name = newName;
 demand = newDemand;
 lighted = newLighted;
}

void city::print()
{/*print city's values*/
 cout << "City " << name << " demand " << demand << " MW is:";
 if(lighted == 1)
 {
  cout << "online" << endl;
 } else {
 	cout << "offline" << endl;
 }
}

bool city::getLighted()
{/*get private data member value*/
 return lighted;
}