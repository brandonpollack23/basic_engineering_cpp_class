/*find some parameters given some paramaters
 Brandon Pollack
 2375-4365
 Period 5 */
#include <iostream>

using namespace std;

int main(void)
{
	float velocity, acceleration, mass, engineRPM;
	
	float impactForce, tenSecondStopDistance;

	cout << "Enter in this order:\nVelocity\nAcceleration\nmass\nengineRPM\n";

	cin >> velocity >> acceleration >> mass >> engineRPM;

	impactForce = mass*acceleration;
	tenSecondStopDistance = velocity*10;

	if(acceleration < -2) cout << "deploy airbags\n";
	if(tenSecondStopDistance < 10) cout << "apply breaks\n";
	if(engineRPM > 12) cout << "engine performance exceeded\n";

	cout << "Parameters calculated:\nImpact Force: " << impactForce << "\nDistance in 10 seconds: " << tenSecondStopDistance << endl;

	//system("Pause");
}
