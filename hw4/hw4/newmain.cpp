//Brandon Pollack
//2375-4365
//Period 5
/*#include <iostream>

using namespace std;

void changeVelocity(double &currentV, double &velocityChange, bool incdec);
void changeAltitude(double &currentA, double &altitudeChange, bool incdec);
void checkVC(double &VC);
void checkAC(double &AC);

int main()
{
	char menuChoice; // A-F and 0 for exit
	double velocityChange; // .1 to 100
	double altitudeChange; // 200 to 10000
	double currentVelocity = 0; //0 to 650
	double currentAltitude = 1000; // -200 to 40000
	
	do
	{
		cout << "Please provide an input. A: up V, B: down V, C: up A, D: down A, E: up V&A, F: down V&A, 0: Exit";
		cin >> menuChoice;
		menuChoice = tolower(menuChoice);
		switch(menuChoice)
		{
		case 'a':
			
			break;
		case 'b':
			cout << "Please provide the velocity decrease" << endl;
			do
			{
				cin >> velocityChange;
				checkVC(velocityChange);
				if(velocityChange == 0)
				{
					cout << "Invalid deacrease to V value received.  Try again." << endl;
				}
				else changeVelocity(currentVelocity, -velocityChange);
			}while(velocityChange != 0);
			break;
		case 'c':
			cout << "Please provide the altitude increase" << endl;
			do
			{
				cin >> altitudeChange;
				checkAC(altitudeChange);
				if(altitudeChange == 0)
				{
					cout << "Invalid increase to A value received.  Try again." << endl;
				}
				else changeAltitude(currentAltitude, altitudeChange);
			}while(altitudeChange != 0);
			break;
		case 'd':
			cout << "Please provide the altitude deacrease" << endl;
			do
			{
				cin >> altitudeChange;
				checkAC(altitudeChange);
				if(altitudeChange == 0)
				{
					cout << "Invalid decrease to A value received.  Try again." << endl;
				}
				else changeAltitude(currentAltitude, -altitudeChange);
			}while(altitudeChange != 0);
			break;





		}


	}(while menuChoice != '0');

}

void changeVelocity(double &currentV, double &velocityChange, bool incdec) //add or subtract this value
{
	double newV;
	cout << "Please provide the velocity ";
	switch (incdec)
	{
	case true:
		cout << "increase" << endl;
		break;
	case false:
		cout << "decrease" << endl;
		break;
	}
		do
		{
			cin >> velocityChange;
			checkVC(velocityChange);
			if(velocityChange == 0)
			{
				cout << "Invalid increase to V value received.  Try again." << endl;
			}
			else
			{
				switch (incdec)
				{
				case true:
					newV = currentV + velocityChange;
					break;
				case false:
					newV = currentV - velocityChange;
					break;
				}

				//new check if newV is in range, if it is then just set currentV to it and you are done, if not say it is out of range and exit the program

				if(newV >= 0 || newV <= 650) currentV = newV;
				else
				{
					cout << "Exit: Increase to altitude above max."; // TODO
				}


		}while(velocityChange != 0);
}

void changeAltitude(double &currentA, double change)
{

}

void checkVC(double &VC) //check the bounds, if within just return it again, if not return 0
{

}

void checkAC(double &AC)
{

}
*/