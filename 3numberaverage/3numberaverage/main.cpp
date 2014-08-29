//an average of 3 numbers
#include <iostream>

using namespace std;

template <int N>
float average(float (&x) [N]);

int main()
{
	float x[3];
	cout << "Enter 3 numbers you wish to average" << endl;
	for(int i = 0; i < 3; i++)
	{
		cin >> x[i];
	}
	
	cout << "The 3 numbers you entered were:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << x[i] << endl;
	}
	cout << "And their average is:" << endl;
	cout << average(x) << endl;

	system("Pause");
}

template <int N>
float average(float (&x) [N])
{
	//int numberOfElements = sizeof(x)/sizeof(float);
	float average = 0;
	for (int i = 0; i < N; i++)
	{
		average += x[i];
	}
	average /= 3;
	return average;
}