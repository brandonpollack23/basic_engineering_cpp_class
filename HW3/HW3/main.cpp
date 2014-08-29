//Brandon Pollack
//Period 5
//2375-4365
#include <iostream>

using namespace std;

float computePerimeter(float length, float width);
float computeArea(float length, float width);

int main(void)
{
	float length, width, area, perimeter;
	
	cout << "Please enter Length and then Width" << endl;

	cin >> length >> width;

	if(length <= 0 || width <= 0)
	{
		cout << "Those are not valid. Quitting...\n";
		//system("Pause");
		return 0;
	}

	perimeter = computePerimeter(length, width);
	area = computeArea(length, width);

	cout << "Area: " << area << endl << "Perimeter: " << perimeter << endl;

	//system("Pause");
	return 0;
}

float computePerimeter(float length, float width)
{
	return 2*length + 2*width;
}

float computeArea(float length, float width)
{
	return length*width;
}