//Brandon Pollack
//2375-4365
//Period 5
#include <iostream>

using namespace std;

double changeVelocity(double cV, bool incdec); //bool true is inc
double changeAltitude(double cA, bool incdec);


int main()
{
	char menuChoice; // A-F and 0 for exit
	//double velocityChange; // .1 to 100
	//double altitudeChange; // 200 to 10000
	double currentVelocity = 0; //0 to 650
	double currentAltitude = 1000; // -200 to 40000
	double placeHolder;
	
	do
	{
		cout << "Please provide an input. A: up V, B: down V, C: up A, D: down A, E: up V&A, F: down V&A, 0: Exit";
		cin >> menuChoice;
		menuChoice = tolower(menuChoice);
		switch(menuChoice)
		{
		case 'a':
			placeHolder = changeVelocity(currentVelocity, true);
			if(placeHolder == -1) menuChoice = '0';
			else currentVelocity = placeHolder;
			break;
		case 'b':
			placeHolder = changeVelocity(currentVelocity, false);
			if(placeHolder == -1) menuChoice = '0';
			else currentVelocity = placeHolder;
			break;
		case 'c':
			placeHolder = changeAltitude(currentAltitude, true);
			if(placeHolder == -201) menuChoice = '0';
			else currentAltitude = placeHolder;
			break;
		case 'd':
			placeHolder = changeAltitude(currentAltitude, false);
			if(placeHolder == -201) menuChoice = '0';
			else currentAltitude = placeHolder;
			break;
		case 'e':
			placeHolder = changeVelocity(currentVelocity, true);
			if(placeHolder == -1) menuChoice = '0';
			else currentVelocity = placeHolder;
			placeHolder = changeAltitude(currentAltitude, true);
			if(placeHolder == -201) menuChoice = '0';
			else currentAltitude = placeHolder;
			break;
		case 'f':
			placeHolder = changeVelocity(currentVelocity, false);
			if(placeHolder == -1) menuChoice = '0';
			else currentVelocity = placeHolder;
			placeHolder = changeAltitude(currentAltitude, false);
			if(placeHolder == -201) menuChoice = '0';
			else currentAltitude = placeHolder;
			break;
		case '0':
			cout << "Now exiting, here are your current values: " << endl;
			break;
		default:
			cout << "That is not a menu option" << endl;
			break;
		}		
	}while(menuChoice != '0');

	cout << "Current V = " << currentVelocity << " Current A = " << currentAltitude;
	cout << endl;

	system("Pause");
}

double changeVelocity(double cV, bool incdec) //bool true is inc
{
	double changeV;
	cout << "Please provide the velocity ";
	switch(incdec)
	{
	case true:
		cout << "increase" << endl;
		cin >> changeV;
		if(changeV <= 100 && changeV >= .1)
		{
			cV += changeV;
		}
		else
		{
			cout << "Change in velocity is above max change allowed" << endl;
			return cV;
		}
		break;
	case false:
		cout << "decrease" << endl;
		cin >> changeV;
		if(changeV <= 100 && changeV >= .1)
		{
			cV -= changeV;
		}
		else
		{
			cout << "Change in velocity is above max change allowed" << endl;
			return cV;
		}
		break;
	}

	if(cV <= 650 && cV >= 0)
	{
		return cV;
	}
	else
	{
		if (incdec)
		{
			cout << "Increase to Velocity above max" << endl;
		}
		else
		{
			cout << "Decrease to velocity below 0" << endl;
		}
		return -1;
	}
}

double changeAltitude(double cA, bool incdec) //bool true is inc
{
	double changeA;
	cout << "Please provide the altitude ";
	switch(incdec)
	{
	case true:
		cout << "increase" << endl;
		cin >> changeA;
		if(changeA <= 10000 && changeA >= 200)
		{
			cA += changeA;
		}
		else
		{
			cout << "Change in altitude is above max change allowed" << endl;
			return cA;
		}
		break;
	case false:
		cout << "decrease" << endl;
		cin >> changeA;
		if(changeA <= 10000 && changeA >= 200)
		{
			cA -= changeA;
		}
		else
		{
			cout << "Change in velocity is above max change allowed" << endl;
			return cA;
		}
		break;
	}

	if(cA <= 40000 && cA >= -200)
	{
		return cA;
	}
	else
	{
		if (incdec)
		{
			cout << "Increase to altitude above max" << endl;
		}
		else
		{
			cout << "Decrease to altitude below -200" << endl;
		}
		return -201;
	}
}