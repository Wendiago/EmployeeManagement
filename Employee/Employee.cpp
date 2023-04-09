#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <regex>
#include <iomanip>
#include "Date.h"
#include "Employee.h"
using namespace std;

Employee::Employee() : _id(""), _name(""), _dateOfBirth(), _address("") {}
Employee::Employee(string id, string name, Date dob, string address)
{
	_id = id;
	_name = name;
	_dateOfBirth = dob;
	_address = address;
}
Employee::~Employee(){}
Employee::Employee(const Employee& other)
{
	_id = other._id;
	_name = other._name;
	_dateOfBirth = other._dateOfBirth;
	_address = other._address;
}
Employee& Employee::operator=(const Employee& other)
{
	if (this == &other)
	{
		return *this;
	}
	_id = other._id;
	_name = other._name;
	_dateOfBirth = other._dateOfBirth;
	_address = other._address;
	return *this;
}
void Employee::setId(string id)
{
	_id = id;
}
void Employee::setName(string name)
{
	_name = name;
}
void Employee::setDate(Date dob)
{
	_dateOfBirth = dob;
}
void Employee::setAddress(string address)
{
	_address = address;
}
string Employee::id() const
{
	return _id;
}
string Employee::name() const
{
	return _name;
}
Date Employee::dateOfBirth() const
{
	return _dateOfBirth;
}
string Employee::address() const
{
	return _address;
}
istream& operator>>(istream& in, Employee& employee)
{
	string id;
	cout << "Enter id: ";
	getline(in, id);
	employee.setId(id);
	
	string name;
	cout << "Enter name: ";
	getline(in, name);
	employee.setName(name);
	
	string date;
	cout << "Enter date of birth (dd/mm/yyyy): ";
	getline(in, date);
	Date dob = Date::parse(date);
	employee.setDate(dob);

	string address;
	cout << "Enter address: ";
	getline(in, address);
	employee.setAddress(address);

	return in;
}

ostream& operator<<(ostream& out, const Employee& e)
{
	out << "ID: " << e._id << endl;
	out << "Name: " << e._name << endl;
	out << "Date of Birth: " << e._dateOfBirth << endl;
	out << "Address: " << e._address << endl;
	out << "Employee type: " << e.employeeType() << endl;
	out << "Salary: " << fixed << setprecision(0) << e.calculateSalary() << endl;
	return out;
}

//bool Employee::isNameValid(string name) 
//{
//	std::regex pattern("^[A-Z][a-z]+( [A-Z][a-z]+)+$");
//	return std::regex_match(name, pattern);
//}

bool Employee::isTypeValid(string type)
{
	if (type == "Daily Employee" || type == "Product Employee")
	{
		return true;
	}
	return false;
}