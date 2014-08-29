//Brandon Pollack
//Period 5
//2375-4365
#include <iostream>


//1. average an array of any size
template <class T,int N>
double averageArray(T (&arr)[N])
{
	double sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	return sum/N;
}

//2. return smallest number
template <class T, int N>
int smallestElement(T (&arr)[N])
{
	T smallest = arr[0];
	for(int i = 1; i < N; i++)
	{
		if(arr[i] < smallest)
		{
			smallest = arr[i];
		}
	}
	return smallest;
}

//3. return largest number
template <class T, int N>
int largestElement(T (&arr)[N])
{
	T largest = arr[0];
	for(int i = 1; i < N; i++)
	{
		if(arr[i] > largest)
		{
			largest = arr[i];
		}
	}
	return largest;
}

using namespace std;

int main(void)
{
	int list1[] = { 3, 12, 45, 59, 2, 38, 99, 24, 81, 12 };
	int list2[] = { 6, 81, 72, 28, 59 };

	cout << "List 1 average, smallest, and largest" << endl;
	cout << averageArray(list1) << endl;
	cout << smallestElement(list1) << endl;
	cout << largestElement(list1) << endl;
	cout << "Elements: ";
	for(int i = 0; i < sizeof(list1)/sizeof(int); i++)
	{
		cout << list1[i] << " ";
	}
	cout << endl << "List 2 average, smallest, and largest" << endl;
	cout << averageArray(list2) << endl;
	cout << smallestElement(list2) << endl;
	cout << largestElement(list2) << endl;
	cout << "Elements: ";
	for(int i = 0; i < sizeof(list2)/sizeof(int); i++)
	{
		cout << list2[i] << " ";
	}

	int list3[(sizeof(list1)+sizeof(list2))/sizeof(int)];
	for(int i = 0; i < sizeof(list1)/sizeof(int); i++)
	{
		list3[i] = list1[i];
	}

	{
		int j = 0;
		for(int i = sizeof(list1)/sizeof(int); i < (sizeof(list1)/sizeof(int) + sizeof(list2)/sizeof(int)); i++, j++)
		{
			list3[i] = list2[j];
		}
	}

	cout << endl << "List 3 average, smallest, and largest" << endl;
	cout << averageArray(list3) << endl;
	cout << smallestElement(list3) << endl;
	cout << largestElement(list3) << endl;
	cout << "Elements: ";
	for(int i = 0; i < sizeof(list3)/sizeof(int); i++)
	{
		cout << list3[i] << " ";
	}

	cout << endl;
    //system("Pause");
}

