#include <iostream>
#define MAX_SEATS 20
using namespace std;

class course
{
 public:
  course(int newNumber,int newNumStudents, int newNumSections);
  course(int newNumber);
  course();
  void print();
  int number;
 private:
  int numStudents;
  int numSections;
};

int main() {
 course EEL3834(3834), EEL4744;
 
 EEL3834.print();
 EEL4744.print();
 
 EEL3834 = course(3834,70,2);
 EEL4744 = course(4744);

 EEL3834.print();
 EEL4744.print();

 return 0;
}

/****write constructors here -- only code to modify****/

course::course(int newNumber,int newNumStudents, int newNumSections)
{
	number = newNumber;
	numSections = newNumSections;
	numStudents = newNumStudents;
}

course::course(int newNumber)
{
	number = newNumber;
	numSections = 1;
	numStudents = 0;
}

course::course()
{
	number = 1111;
	numSections = 1;
	numStudents = 0;
}

void course::print()
{
 cout << "The course EEL" << number << " has " << numSections << " section(s) and " << numStudents << " student(s)" << endl;
}