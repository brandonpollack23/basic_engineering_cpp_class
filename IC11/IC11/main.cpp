#include <iostream>
using namespace std;

/*These functions place the larger of two numbers into "larger". If the numbers are equal, the first number is placed into "larger"*/
void returnLarger(int& larger,int num1=0, int num2=1);
void returnLarger(double& larger,double num1=2.4, double num2=6.2);

int main()
{
 int numberInt1 = 6;
 int numberInt2 = 4;
 double numberDoub1 = 4.5;
 double numberDoubD2 = 1.5;
 int largerInt = 2;
 double largerDoub = 3.2;
 
 cout << "Output before function calls: " << largerDoub << endl;
 returnLarger(largerInt,numberInt1,numberInt2);
 cout << "The first output is: " << largerInt << endl;
 returnLarger(largerDoub,numberDoub1,numberInt2);
 cout << "The second output is: " << largerDoub << endl;
 returnLarger(largerInt,numberInt2);
 cout << "The third output is: " << largerInt << endl;
 returnLarger(largerDoub,numberDoub1);
 cout << "The last output is: " << largerDoub << endl;
 

 system("Pause");
 return 0;
}

void returnLarger(int& larger,int num1, int num2)
{
	if(num1 >= num2) larger =  num1;
	else if(num2 > num1) larger = num2;
}
void returnLarger(double& larger,double num1, double num2)
{
	if(num1 >= num2) larger =  num1;
	else if(num2 > num1) larger = num2;
}