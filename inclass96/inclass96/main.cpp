//use of the switch statement
#include <iostream>

using namespace std;

int main(void)
{
	int x;
	cin >> x;
	switch (x)
	{
	case 4:
	cout << "Your number is an even square\n";
	case 2:	
	case 6:
		cout << "Your number is even\n";
		break;
	case 9:
		cout << "Your number is an even cube\n";
	case 5:
	case 7:	
		cout << "Your number is odd\n";
		break;
	default:
		cout << "Your number is uninteresting\n";
	}
	system("Pause");
	return 0;
}

