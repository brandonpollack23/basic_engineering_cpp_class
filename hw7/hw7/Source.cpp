//Brandon Pollack
//2375-4365
//HW 7
//Period 2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <exception>

#define MAX_NAME_LENGTH 20
#define MAX_ORDER_VALUE 250000
#define NUMBER_OF_MONTHS 12

using namespace std;

class Date
{
private:
	int month;
	int day; //depends on month, always feb 29
	int year; //2000 to 2013

	bool isThirtyDayMonth(int& theMonth)
	{
		if(theMonth == 1 || theMonth == 3 || theMonth == 5 || theMonth == 7 || theMonth == 8 || theMonth == 10 || theMonth == 12)
		{
			return true;
		}
		else return false;
	}

public:
	Date()
	{
		year = 2000;
		month = 1;
		day = 1;
	}

	Date(int initYear, int initMonth, int initDay)
	{
		if(initYear <= 2013 && initYear >= 2000)
		{
			year = initYear;
		}
		else
		{
			throw exception("Year out of bounds");
		}

		if(initMonth >= 1 && initMonth <= NUMBER_OF_MONTHS)
		{
			month = initMonth;
		}
		else
		{
			throw exception("Month out of bounds, setting to 12");
		}

		if(isThirtyDayMonth(month))
		{
			if(initDay >= 0 && initDay <= 31)
			{
				day = initDay;
			}
			else
			{
				throw exception("number of days invalid");
			}
		}
		else
		{
			if(month == 2)
			{
				if(initDay >= 0  && initDay <= 29)
				{
					day = initDay;
				}
				else
				{
					throw exception("number of days invalid");
				}
			}

			else if(initDay >=0 && initDay <= 30)
			{
				day = initDay;
			}
			else
			{
				throw exception("number of days invalid");
			}
		}
	}

	string toString()
	{
		ostringstream answer;
		answer << year << '-' << month << '-' << day;
		return answer.str();
	}

	int getYear()
	{
		return year;
	}

	int getMonth()
	{
		return month;
	}

	int getDay()
	{
		return day;
		}

	bool operator< (Date B)
	{
		if(year < B.getYear())
		{
			return true;
		}
		else if(year == B.getYear())
		{
			if(month < B.getMonth())
			{
				return true;
			}
			else if(month == B.getMonth())
			{
				if(day < B.getDay())
				{
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
};

class Customer
{
private:
	string name;
	string location;
	Date firstOrder;
	Date lastOrder;
	int valueLastOrder;
	int valueOfOrdersToDate;

public:
	Customer()
	{
		name = "";
		location = "";
		valueLastOrder = 0;
		valueOfOrdersToDate = 0;
		firstOrder = Date();
		lastOrder = Date();
	}

	Customer(string initName, string initLocation, int lastOrderVal, int valueOfOrders, Date& firstOrderDate, Date& lastOrderDate)
	{
		if(initName.size() <= MAX_NAME_LENGTH && initLocation.size() <= MAX_NAME_LENGTH)
		{
			name = initName;
			location = initLocation;
		}
		else
		{
			cout << "Name size too long";
			exit(-1);
		}

		if(lastOrderVal >= 0 && lastOrderVal <= MAX_ORDER_VALUE)
		{
			valueLastOrder = lastOrderVal;
		}
		else
		{
			cout << "Order Value is above max!";
			exit(-1);
		}
			
		if(valueOfOrders >= 0 && valueOfOrders <= MAX_ORDER_VALUE)
		{
			valueOfOrdersToDate = valueOfOrders;
		}
		else
		{
			cout << "Order total is above max!";
			exit(-1);
		}

		firstOrder = firstOrderDate;
		lastOrder = lastOrderDate;
	}

	int getTotalOrderValue() const
	{
		return valueOfOrdersToDate;
	}

	int getLastOrderValue()
	{
		return valueLastOrder;
	}

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Location: " << location << endl;
		cout << "Date of first order: " << firstOrder.toString() << endl;
		cout << "Date of last order: " << lastOrder.toString() << endl;
		cout << "Value of last order: " << valueLastOrder << endl;
		cout << "Total value of orders to date: " << valueOfOrdersToDate;
	}

	bool operator< (const Customer& anotherCustomer)
	{
		return valueOfOrdersToDate < anotherCustomer.getTotalOrderValue();
	}

	string getName()
	{
		return name;
	}

	string getLocation()
	{
		return location;
	}

	void addOrder(Date& date, int value)
	{
		if(valueOfOrdersToDate + value <= MAX_ORDER_VALUE && value <= MAX_ORDER_VALUE && date.getYear() <= 2013 && date.getYear() >= 0)
		{
			lastOrder = date;
			valueLastOrder = value;
			valueOfOrdersToDate += value;
		}
		else
		{
			cout << "Cannot add order" << endl;
		}
	}

	Date getLastDate()
	{
		return lastOrder;
	}

	Date getFirstDate()
	{
		return firstOrder;
	}
};

void addOrder(string name, string location, Date& date, int value, vector<Customer>& list)
{
	if(list.size() < 10)
	{
		bool added = false;
		for(vector<Customer>::iterator it = list.begin(); it != list.end(); ++it)
		{
			if(it->getName() == name && it->getLocation() == location)
			{
				//go ahead and add an order to that customer
				it->addOrder(date,value);
				added = true;
			}
		}
		if(!added)
		{
			list.push_back(Customer(name,location,value,value,date,date));
		}
	}
	else
	{
		cout << "There are already 10 customers!" << endl;
	}
}

bool lastDateToFirst(Customer& A, Customer& B)
{
	return !(A.getLastDate() < B.getLastDate());
}

bool firstDateToLast(Customer& A, Customer& B)
{
	return (A.getLastDate() < B.getLastDate());
}

bool largestToSmallestOrder(Customer& A, Customer& B)
{
	return B.getLastOrderValue() < A.getLastOrderValue();
}

bool largestToSmallestTotal(Customer& A, Customer& B)
{
	return A.getTotalOrderValue() > B.getTotalOrderValue();
}


int main(void)
{
	vector<Customer> customerList;

	customerList.push_back(Customer("Boeing","California",10000,50000,Date(2009,3,29),Date(2013,5,13)));
	customerList.push_back(Customer("Boeing","California",25000,130000,Date(2007,10,5),Date(2012,1,23)));
	customerList.push_back(Customer("Lockheed","Denver",100000,120000,Date(2005,7,20),Date(2013,8,11)));
	customerList.push_back(Customer("Lockheed","California",75000,110000,Date(2010,4,29),Date(2012,12,29)));
	customerList.push_back(Customer("Lockheed","Florida",75000,110000,Date(2012,11,2),Date(2012,11,2)));
	customerList.push_back(Customer("Harris","Florida",5000,60000,Date(2011,9,17),Date(2013,2,21)));
	customerList.push_back(Customer("Raytheon","California",100000,200000,Date(2004,6,12),Date(2012,6,30)));
	customerList.push_back(Customer("Northrop","Maryland",30000,120000,Date(2010,7,7),Date(2013,2,15)));
	customerList.push_back(Customer("BAE","Virginia",20000,80000,Date(2011,11,4),Date(2012,9,24)));

	sort(customerList.begin(),customerList.end());
	for(vector<Customer>::reverse_iterator it = customerList.rbegin(); it != customerList.rend(); ++it)
	{
		it->print();
		cout << endl;
	}

	try
	{
		addOrder("Harris","Florida",Date(2013,9,12), 100000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}

	try
	{
		addOrder("Lockheed","Florida",Date(2013,9,12), 35000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Raytheon","California",Date(2013,9,14), 50000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Northrop","Maryland",Date(2013,9,17), 20000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Harris","Florida",Date(2013,9,18), 80000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Boeing","California",Date(2013,9,25), 25000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Northrup","California",Date(2013,9,26), 45000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Lockheed","Denver",Date(2013,9,31), 10000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Harris","Florida",Date(2013,10,2), 25000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Bae","Virginia",Date(2013,10,2), 35000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Boeing","Washington",Date(2013,10,4), 75000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Northrop","California",Date(2013,10,9), 60000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Lockheed","California",Date(2013,10,9), 25000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Bae","Virginia",Date(2013,10,10), 100000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}
	try
	{
		addOrder("Lockheed","Denver",Date(2013,10,11), 130000, customerList);
	}
	catch(exception e)
	{
		cout << e.what();
	}

	sort(customerList.rbegin(),customerList.rend(),firstDateToLast);
	for(vector<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it)
	{
		it->print();
		cout << endl;
	}

	sort(customerList.begin(),customerList.end(),firstDateToLast);
	for(vector<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it)
	{
		it->print();
		cout << endl;
	}

	sort(customerList.begin(),customerList.end(),largestToSmallestOrder);
	for(vector<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it)
	{
		it->print();
		cout << endl;
	}

	sort(customerList.begin(),customerList.end(),largestToSmallestTotal);
	for(vector<Customer>::iterator it = customerList.begin(); it != customerList.end(); ++it)
	{
		it->print();
		cout << endl;
	}
}