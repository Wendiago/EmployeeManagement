#include <iostream>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "DailyEmployee.h"
using namespace std;

DailyEmployee::DailyEmployee() :Employee()
{
	_numOfDay = 0;
}

DailyEmployee::DailyEmployee(string id, string name, Date dob, string address, int numOfDay) : Employee(id, name, dob, address), _numOfDay(numOfDay)
{
	//
}

DailyEmployee::DailyEmployee(const DailyEmployee& other):Employee(other._id, other._name, other._dateOfBirth, other._address)
{
	_numOfDay = other._numOfDay;
}

string DailyEmployee::employeeType() const
{
	return "Daily Employee";
}

DailyEmployee& DailyEmployee::operator=(const DailyEmployee& other)
{
	if (this == &other)
	{
		return *this;
	}
	_id = other._id;
	_name = other._name;
	_dateOfBirth = other._dateOfBirth;
	_address = other._address;
	_numOfDay = other._numOfDay;
	return *this;
}

double DailyEmployee::calculateSalary() const
{
	return _numOfDay * 300000.0;
}

void DailyEmployee::setNumOfDay(int value)
{
	_numOfDay = value;
}

int DailyEmployee::numOfDay() const
{
	return _numOfDay;
}

istream& operator>>(istream& in, DailyEmployee& e) 
{
	in >> static_cast<Employee&>(e);
	string num;
	cout << "Enter number of working days: ";
	getline(in, num);
	e.setNumOfDay(stoi(num));
	return in;
}

ostream& operator<<(ostream& out, const DailyEmployee& e)
{
	out << static_cast<const Employee&>(e);
	out << "Number of days working: " << e._numOfDay << endl;
	return out;
}
