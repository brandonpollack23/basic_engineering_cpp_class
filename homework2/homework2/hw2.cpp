//Brandon Pollack
//Period 5
//IC7
//xt = x0 * (1+r)^t
//x0 initial value
//xt value of x after tim t
//r is percentagegrowth in a time period (seconds)
#include <iostream>

using namespace std;

float findTime(float &x0,float &rate,float &time);

int main(void)
{
    char dopantType = '-';
	float stopTime, x0, rate, xt;
	for(;dopantType == '-';)
	{
		cout << "Please enter a dopant type followed by a stoptime: \n";
		cin >> dopantType;
		cin >> stopTime;
		switch (toupper(dopantType))
		{
		case 'A':
			x0 = .1;
			rate = .1;
			break;
		case 'B':
			x0 = 2.0;
			rate = .3;
			break;
		case 'C':
			x0 = 4;
			rate = .2;
		case 'D':
			x0 = 6;
			rate = .4;
			break;
		case '0':
			x0 = 0;
			rate= 0;
			break;
		default:
			cout << "That dopant type is not valid! Try again!" << endl;
			dopantType = '-';
			break;
		}
	}
	
	//xt = findTime(x0, rate, stopTime);
    
    xt = 1;
   // int i = 0;
    for (int i = 0; i <= stopTime; i++)
    {
        xt *= (1+rate);
    }
    xt *= x0;
    
	
	cout << "X0 = " << x0 << "\nXt = " << xt << "\nRate = " << rate << "\ntime = " << stopTime << "\nDopant type = " << dopantType << endl;
	
	if(xt > 20) cout << "Xt is more than 20";
	else cout << "Xt is less than or equal to 20\n";

	system("Pause");
	
}
