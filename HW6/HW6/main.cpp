//Brandon Pollack
//2375-4365
//Period 2
#include <iostream>
#define NUM_FIRST 8
#define NUM_EXIT 6
#define NUM_GEN 24
#define NUM_SEATS NUM_FIRST+NUM_EXIT+NUM_GEN
#define NUM_TICK_LINE 10
using namespace std;

class passenger
{
 public:
  passenger(char newFirstN,char newLastN,int newSeat,int newAge);
  passenger();
  void getName(char& firstName,char& lastName);
  int getSeat();
  int getAge();
  void print();
 private:
  char firstN;
  char lastN;
  int seat;
  int age;
};

struct airplane
{
 int flightNum;
 int NumFirst;
 int NumExit;
 int NumGeneral;
 passenger passengers[NUM_SEATS];
 bool checkedIn[NUM_SEATS];
};

void printAirplane(airplane plane);

int main()
{
 airplane flight;
 passenger ticketLine[NUM_TICK_LINE];

 /*Initialize flight*/
 flight.flightNum = 1173;
 flight.NumFirst=0;
 flight.NumExit=0;
 flight.NumGeneral=0;

 for(int loop=0;loop<NUM_SEATS;loop++)
 {/*clear out checkedIn*/
  flight.checkedIn[loop]=0;
 }
 
 /*set up ticket line*/
 ticketLine[0] = passenger('A','Q',2,78);
 ticketLine[1] = passenger('R','C',12,58);
 ticketLine[2] = passenger('A','Q',22,25);
 ticketLine[3] = passenger('A','Z',8,13);
 ticketLine[4] = passenger('G','Z',9,45);
 ticketLine[5] = passenger('F','S',10,42);
 ticketLine[6] = passenger('D','W',29,25);
 ticketLine[7] = passenger('L','G',4,28);
 ticketLine[8] = passenger('P','G',5,32);
 ticketLine[9] = passenger('E','L',33,61);

 /*add passengers to the flight*/

/****!!!! Your main code goes here !!!!****/

 //first loop through line and find underage exit seaters
 for(int i = 0; i < NUM_TICK_LINE; i++)
 {
	 if(ticketLine[i].getAge() < 18 && ticketLine[i].getSeat() < NUM_FIRST+NUM_EXIT && ticketLine[i].getSeat() >= NUM_FIRST)
	 {
		 cout << "***Underage passenger in exit row: ";
		 ticketLine[i].print();
		 cout << endl;
	 }
 }

 //loop through ticket line and add them to the flight as long as they
 //are not underage and sit in an exit row at the same time

 for(int i = 0; i < NUM_TICK_LINE; i++)
 {
	 if(!(ticketLine[i].getSeat() >= NUM_FIRST && ticketLine[i].getSeat() < NUM_FIRST+NUM_EXIT && ticketLine[i].getAge() < 18))
	 {
		 if(ticketLine[i].getSeat() < NUM_FIRST)
		 {
			 flight.NumFirst++; //increase number of FC passengers
		 }
		 else if(ticketLine[i].getSeat() < NUM_FIRST+NUM_EXIT && ticketLine[i].getAge() >= 18)
		 {
			 flight.NumExit++;
		 }
		 else
		 {
			 flight.NumGeneral++;
		 }
		 flight.checkedIn[ticketLine[i].getSeat()] = 1; //check the seat in
		 flight.passengers[ticketLine[i].getSeat()] = ticketLine[i]; //put them in seat
	 }
 }

 printAirplane(flight);

 return 0;
}

/****!!!! Don't forget to define the class member functions here !!!!****/
passenger::passenger(char newFirstN,char newLastN,int newSeat,int newAge)
{
	firstN = newFirstN;
	lastN = newLastN;
	seat = newSeat;
	age = newAge;
}

passenger::passenger()
{
	firstN = 'J';
	lastN = 'D';
	seat = 0;
	age = 25;
}

void passenger::getName(char& firstName,char& lastName)
{
	firstName = firstN;
	lastName = lastN;
}

int passenger::getSeat()
{
	return seat;
}

int passenger::getAge()
{
	return age;
}

void passenger::print()
{
	cout << "Passenger " << firstN << ' ' << lastN << " seat: " << seat << " aged: " << age << endl;
}

void printAirplane(airplane plane)
{
 cout << "The current flight status of flight " << plane.flightNum << " is:" << endl;
 cout << "Plane has " << NUM_FIRST << " first class " << NUM_EXIT << " exit row and " << NUM_GEN << " general seats" << endl;
 cout << "The current status of checked in passengers is..." << endl;
 cout << "There are " << plane.NumFirst << " First class passengers:" << endl;
 for(int loop=0;loop<NUM_FIRST;loop++)
 {
  if(plane.checkedIn[loop])
  {/*if that seat is checked in*/
   plane.passengers[loop].print();
  } else {
  	cout << "Seat " << loop << " empty" << endl;
  }
 }
 cout << "There are " << plane.NumExit << " Exit row passengers:" << endl;
 for(int loop=NUM_FIRST;loop<(NUM_FIRST+NUM_EXIT);loop++)
 {
  if(plane.checkedIn[loop])
  {/*if that seat is checked in*/
   plane.passengers[loop].print();
  } else {
  	cout << "Seat " << loop << " empty" << endl;
  }
 }
  cout << "There are " << plane.NumGeneral << " General seating passengers:" << endl;
 for(int loop=(NUM_FIRST+NUM_EXIT);loop<(NUM_FIRST+NUM_EXIT+NUM_GEN);loop++)
 {
  if(plane.checkedIn[loop])
  {/*if that seat is checked in*/
   plane.passengers[loop].print();
  } else {
  	cout << "Seat " << loop << " empty" << endl;
  }
 }
}