#include <iostream>
#include <iomanip>
#include <string>
#define TRUE 1
#define FALSE 0
/*Car types*/
#define ENGINE "Engine"
#define CABOOSE "Caboose"
#define TANKER "Tanker"
#define BOXCAR "Boxcar"
/*Distances*/
#define BostonToChicago 970
#define ChicagoToCheyenne 960
#define CheyenneToSeattle 1278

using namespace std;

class trainCar
{
 public:
  trainCar(string nType,int nID);
  void addMiles(int miles); /*add miles to the miles traveled by this car*/
  void setNextCar(trainCar *nNextCar);
  void setPrevCar(trainCar *nPrevCar);
  string getType();
  int getID();
  int getMiles();
  trainCar* getNextCar();
  trainCar* getPrevCar();
  void print();
 private:
  string type; /*locomotive, boxcar, tanker, graincar, passenger, caboose, etc.*/
  int ID; /*unique ID for the car*/
  int miles; /*keep track of miles traveled by this car*/
  trainCar *nextCar; /*pointer to the next car*/
  trainCar *prevCar; /*pointer to previous car*/
};

typedef trainCar *trainCarPtr; /*definition of a pointer to a train car*/
trainCar* mergeTrains(trainCar *front,trainCar *yard); /*merges the cars from yard into the train pointed to by front*/
trainCar* addCarToFront(trainCar *front,trainCar *car); /*adds car to front of train and return new front*/
trainCar* addCarToEnd(trainCar *front,trainCar *car); /*adds car to end of train and return new front*/
trainCar* addCarToMid(trainCar *front,trainCar *car,int prevID); /*add car after car with prevID and return new front*/
trainCar* removeCar(trainCar *front,int ID); /*delete the car with this ID and return new front*/
void printTrain(trainCar *car); /*prints train starting at this car*/
trainCar* findCarPositionPtr(trainCar *front,int ID); /*returns pointer to car with this ID number*/
trainCar* findFirstCarPositionPtr(trainCar *front,string firstType);/*returns pointer to first car with this type, NULL if none in train*/
trainCar* findLastCarPositionPtr(trainCar *front,string lastType);/*returns pointer to last car with this type, NULL if none in train*/
void addDistanceToTrainCars(trainCar *front,int distance); /*increments all distances in a train*/

int main()
{
 trainCarPtr frontTrain=NULL; /*define pointer to the start of the train*/
 trainCarPtr frontBostonYard=NULL; /*define pointer to the start of the cars in Boston*/
 trainCarPtr frontChicagoYard=NULL; /*define pointer to the start of the cars in Chicago*/
 trainCarPtr frontCheyenneYard=NULL; /*define pointer to the start of the cars in Cheyenne*/
 trainCarPtr frontSeattleYard=NULL; /*define pointer to the start of the cars in Seattle*/
 trainCarPtr temp=NULL; /*define a temp pointer for operations*/

/*
 cout << "Printing out the train and yards at the beginning:" << endl;
 cout << "Train is:" << endl;
 printTrain(frontTrain);
 cout << "Boston is:" << endl;
 printTrain(frontBostonYard);
 cout << "Chicago is:" << endl;
 printTrain(frontChicagoYard); 
 cout << "Cheyenne is:" << endl;
 printTrain(frontCheyenneYard);
 cout << "Seattle is:" << endl;
 printTrain(frontSeattleYard);
*/

 /*Create and attach initial train cars*/
 temp = new trainCar(ENGINE,87378);
 frontTrain = addCarToFront(frontTrain,temp);
 temp = new trainCar(ENGINE,82289);
 frontTrain = addCarToFront(frontTrain,temp);
 temp = new trainCar(CABOOSE,96378);
 frontTrain = addCarToEnd(frontTrain,temp);

 /*Create cars waiting in each city*/
 /*Boston*/
 temp = new trainCar(BOXCAR,68397); /*to Chicago*/
 frontBostonYard = addCarToFront(frontBostonYard,temp);
 temp = new trainCar(BOXCAR,64252); /*to Chicago*/
 frontBostonYard = addCarToFront(frontBostonYard,temp);
 temp = new trainCar(BOXCAR,60192); /*to Seattle*/
 frontBostonYard = addCarToFront(frontBostonYard,temp);
 temp = new trainCar(BOXCAR,69282); /*to Cheyenne*/
 frontBostonYard = addCarToFront(frontBostonYard,temp);
 temp = new trainCar(BOXCAR,65262); /*to Chicago*/
 frontBostonYard = addCarToFront(frontBostonYard,temp);
 /*Chicago*/
 temp = new trainCar(BOXCAR,69832); /*to Cheyenne*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp);
 temp = new trainCar(BOXCAR,60525); /*to Seattle*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp);
 temp = new trainCar(BOXCAR,61617); /*to Cheyenne*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp);
 temp = new trainCar(BOXCAR,69234); /*to Seattle*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp);
 temp = new trainCar(ENGINE,80526);
 frontChicagoYard = addCarToFront(frontChicagoYard,temp);
 /*Cheyenne*/
 temp = new trainCar(TANKER,54353); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,58282); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,59843); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,50773); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,56483); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,51919); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,58612); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(TANKER,50939); /*to Seattle*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(ENGINE,88298);
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 temp = new trainCar(ENGINE,85727);
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp);
 /*Seattle*/
 /*This city is empty at the start*/
 
 cout << "Print out the train and yards after initialization:" << endl;
 cout << "Train is:" << endl;
 printTrain(frontTrain);
 cout << "Boston is:" << endl;
 printTrain(frontBostonYard);
 cout << "Chicago is:" << endl;
 printTrain(frontChicagoYard); 
 cout << "Cheyenne is:" << endl;
 printTrain(frontCheyenneYard);
 cout << "Seattle is:" << endl;
 printTrain(frontSeattleYard);

 /*Add cars meant to leave Boston -- order engines, box cars, tankers, caboosee*/
 frontTrain = mergeTrains(frontTrain,frontBostonYard);
 frontBostonYard = NULL; /*clear out the yard after merge*/
 
 /*Have the train travel to Chicago -- update distances*/
 addDistanceToTrainCars(frontTrain,BostonToChicago);
 
 /*Add cars meant to leave Chicago -- order engines, box cars, tankers, caboose*/
 frontTrain = mergeTrains(frontTrain,frontChicagoYard);
 frontChicagoYard = NULL; /*clear out the yard after merge*/

 /*Remove cars meant to stay in Chicago -- place them in yard*/
 temp = findCarPositionPtr(frontTrain,64252); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,64252); /*remove from train*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp); /*add car to Chicago Yard*/
 temp = findCarPositionPtr(frontTrain,68397); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,68397); /*remove from train*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp); /*add car to Chicago Yard*/
 temp = findCarPositionPtr(frontTrain,65262); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,65262); /*remove from train*/
 frontChicagoYard = addCarToFront(frontChicagoYard,temp); /*add car to Chicago Yard*/

 /*Have the train travel to Cheyenne -- update distances*/
 addDistanceToTrainCars(frontTrain,ChicagoToCheyenne);

 /*Add cars meant to leave Cheyenne -- order engines, box cars, tankers, caboose*/
 frontTrain = mergeTrains(frontTrain,frontCheyenneYard);
 frontCheyenneYard = NULL; /*clear out the yard after merge*/
 
 /*Remove cars meant to stay in Cheyenne -- place them in yard*/
 temp = findCarPositionPtr(frontTrain,69282); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,69282); /*remove from train*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp); /*add car to Cheyenne Yard*/
 temp = findCarPositionPtr(frontTrain,69832); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,69832); /*remove from train*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp); /*add car to Cheyenne Yard*/
 temp = findCarPositionPtr(frontTrain,61617); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,61617); /*remove from train*/
 frontCheyenneYard = addCarToFront(frontCheyenneYard,temp); /*add car to Cheyenne Yard*/
 
 /*Have the train travel to Seattle -- update distances*/
 addDistanceToTrainCars(frontTrain,CheyenneToSeattle);
 
 /*Remove cars meant to stay in Seattle -- place them in yard*/
 temp = findCarPositionPtr(frontTrain,60192); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,60192); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,60525); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,60525); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,69234); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,69234); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,54353); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,54353); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,58282); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,58282); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,59843); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,59843); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,50773); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,50773); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,56483); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,56483); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,51919); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,51919); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,58612); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,58612); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/
 temp = findCarPositionPtr(frontTrain,50939); /*get next car to remove*/
 frontTrain = removeCar(frontTrain,50939); /*remove from train*/
 frontSeattleYard = addCarToFront(frontSeattleYard,temp); /*add car to Seattle Yard*/

 /*print out the train and all yards*/
 cout << "Printing out the train and yards at the end:" << endl;
 cout << "Train is:" << endl;
 printTrain(frontTrain);
 cout << "Boston is:" << endl;
 printTrain(frontBostonYard);
 cout << "Chicago is:" << endl;
 printTrain(frontChicagoYard); 
 cout << "Cheyenne is:" << endl;
 printTrain(frontCheyenneYard);
 cout << "Seattle is:" << endl;
 printTrain(frontSeattleYard);
 
 return 0;
}

trainCar* mergeTrains(trainCar *front,trainCar *yard)
{/*merges the cars from yard into the train pointed to by front*/
 /*order is engines, box cars, tankers, caboose*/
 trainCarPtr temp=NULL; /*define a temp pointer for operations*/
 trainCarPtr temp2=NULL; /*define a temp pointer for operations*/
 trainCarPtr tempTrain=front; /*define a temp pointer for operations*/
 trainCarPtr tempYard=yard; /*define a temp pointer for operations*/
 if(tempYard==NULL)
 {/*no cars in yard to merge, nothing to do*/
  return tempTrain;
 }
 if(tempTrain==NULL)
 {/*if the train is empty, move the yard to become the new train*/
  return tempYard;
 }
 /*special conditions covered, merge non-empty train with non-empty yard*/
 while(tempYard!=NULL)
 {/*while there are still cars in the yard*/
  if(tempYard->getType().compare(ENGINE)==0)
  {/*if this is an engine add to front*/
   /*pull car from the yard*/
   temp2 = tempYard;
   tempYard = tempYard->getNextCar(); /*advance yard pointer -- NULL ok -- stop condition*/
   temp2->setNextCar(NULL); /*Fix lone car: Clear the next pointer to take it out of the yard*/
   temp2->setPrevCar(NULL); /*Fix lone car: Prev pointer already NULL, clear just in case*/
   /*add to train, also removes the car from the yard because pointers changed*/
   tempTrain = addCarToFront(tempTrain,temp2);
  } else if(tempYard->getType().compare(BOXCAR)==0)
  {/*if this is a box car add after engines*/
   /*find pointer to last engine*/
   temp = findLastCarPositionPtr(tempTrain,ENGINE);
   /*pull car from the yard*/
   temp2 = tempYard;
   tempYard = tempYard->getNextCar(); /*advance yard pointer -- NULL ok -- stop condition*/
   temp2->setNextCar(NULL); /*Fix lone car: Clear the next pointer to take it out of the yard*/
   temp2->setPrevCar(NULL); /*Fix lone car: Prev pointer already NULL, clear just in case*/
   /*add to train, also removes the car from the yard because pointers changed*/
   tempTrain = addCarToMid(tempTrain,temp2,temp->getID());
  } else if(tempYard->getType().compare(TANKER)==0)
  {/*if this is a tanker car add before caboose*/
   /*find pointer to first caboose*/
   temp = findFirstCarPositionPtr(tempTrain,CABOOSE);
   /*pull car from the yard*/
   temp2 = tempYard;
   tempYard = tempYard->getNextCar(); /*advance yard pointer -- NULL ok -- stop condition*/
   temp2->setNextCar(NULL); /*Fix lone car: Clear the next pointer to take it out of the yard*/
   temp2->setPrevCar(NULL); /*Fix lone car: Prev pointer already NULL, clear just in case*/
   /*add to train, also removes the car from the yard because pointers changed*/
   tempTrain = addCarToMid(tempTrain,temp2,temp->getID());
  } else if(tempYard->getType().compare(CABOOSE)==0)
  {/*check for caboose, add to end*/
   temp2 = tempYard;
   tempYard = tempYard->getNextCar(); /*advance yard pointer -- NULL ok -- stop condition*/
   temp2->setNextCar(NULL); /*Fix lone car: Clear the next pointer to take it out of the yard*/
   temp2->setPrevCar(NULL); /*Fix lone car: Prev pointer already NULL, clear just in case*/
   /*add to train, also removes the car from the yard because pointers changed*/
   tempTrain = addCarToEnd(tempTrain,temp2);
  }
  /*tempYard now points to the next car in the yard or NULL if empty -- stop conditions covered*/
  if(tempYard==NULL)
  {/*yard empty, return train pointer*/
   return tempTrain;
  } else { /*Correct the prev pointer for new yard front for next iteration*/
   	 tempYard->setPrevCar(NULL);
  }
 }
 return tempTrain; /*just in case we get here*/
}

trainCar::trainCar(string nType,int nID)
{
/* student to begin filling in code from here..... */ 
	type = nType;
	ID = nID;
	miles = 0;
	nextCar = prevCar = NULL;
}

void trainCar::addMiles(int miles) /*add miles to the miles traveled by this car*/
{
	this->miles += miles;
}

void trainCar::setNextCar(trainCar *nNextCar)
{
	nextCar = nNextCar;
}

void trainCar::setPrevCar(trainCar *nPrevCar)
{
	prevCar = nPrevCar;
}

string trainCar::getType()
{
	return type;
}

int trainCar::getID()
{
	return ID;
}

int trainCar::getMiles()
{
	return miles;
}

trainCar* trainCar::getNextCar()
{
	return nextCar;
}

trainCar* trainCar::getPrevCar()
{
	return prevCar;
}

void trainCar::print()
{
	cout << "ID: " << ID << " Type: " << type << " Miles Traveled: " << miles;
}

trainCar* addCarToFront(trainCar *front,trainCar *car) /*adds car to front of train and return new front*/
{
	car->setNextCar(front);
	return car;
}

trainCar* addCarToEnd(trainCar *front,trainCar *car) /*adds car to end of train and return new front*/
{
	trainCarPtr current;
	for(current = front; current->getNextCar() != NULL; current = current->getNextCar());
	current->setNextCar(car);
	return front;
}

trainCar* addCarToMid(trainCar *front,trainCar *car,int prevID) /*add car after car with prevID and return new front*/
{
	trainCarPtr current;
	for(current = front; current->getNextCar()->getID() != prevID; current = current->getNextCar());
	car->setNextCar(current->getNextCar());
	current->setNextCar(car);
	return front;
}

trainCar* removeCar(trainCar *front,int ID) /*delete the car with this ID and return new front*/
{
	trainCarPtr current;
	for(current = front; current->getNextCar()->getID() != ID; current = current->getNextCar());
	trainCarPtr deleteMe = current->getNextCar();
	current->setNextCar(deleteMe->getNextCar());
	if(deleteMe != front) return front;
	else return front->getNextCar();
}

void printTrain(trainCar *car) /*prints train starting at this car*/
{
	cout << "This train car collection includes:\n";
	int i = 1;
	for(trainCarPtr current = car; current != NULL; current = current->getNextCar())
	{
		cout << "\t" << i++ << ". ";
		current->print();
		cout << endl;
	}
}

trainCar* findCarPositionPtr(trainCar *front,int ID) /*returns pointer to car with this ID number*/
{
	trainCarPtr current;
	for(current = front; current->getNextCar()->getID() != ID; current = current->getNextCar());
	return current->getNextCar();
}

trainCar* findFirstCarPositionPtr(trainCar *front,string firstType)/*returns pointer to first car with this type, NULL if none in train*/
{
	trainCarPtr current;
	for(current = front; current->getType() != firstType; current = current->getNextCar());
	return current;
}

trainCar* findLastCarPositionPtr(trainCar *front,string lastType)/*returns pointer to last car with this type, NULL if none in train*/
{
	trainCarPtr returnMe;
	for(trainCarPtr current = front; current->getNextCar() != NULL; current = current->getNextCar())
	{
		if(current->getType() == lastType) returnMe = current;
	}
	return returnMe;
}

void addDistanceToTrainCars(trainCar *front,int distance) /*increments all distances in a train*/
{
	trainCarPtr current;
	for(current = front; current->getNextCar() != NULL; current = current->getNextCar())
	{
		current->addMiles(distance);
	}
}
/* student to continue code from here..... */ 