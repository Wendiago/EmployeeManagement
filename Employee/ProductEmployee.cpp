#include <iostream>
#include <string>
#include "Date.h"
#include "Employee.h"
#include "ProductEmployee.h"
using namespace std;

ProductEmployee::ProductEmployee() :Employee()
{
	_numOfProduct = 0;
}

ProductEmployee::ProductEmployee(string id, string name, Date dob, string address, int numOfPro) : Employee(id, name, dob, address), _numOfProduct(numOfPro)
{
	//
}

ProductEmployee::ProductEmployee(const ProductEmployee& other) : Employee(other._id, other._name, other._dateOfBirth, other._address)
{
	_numOfProduct = other._numOfProduct;
}

string ProductEmployee::employeeType() const
{
	return "Product Employee";
}

ProductEmployee& ProductEmployee::operator=(const ProductEmployee& other)
{
	if (this == &other)
	{
		return *this;
	}
	_id = other._id;
	_name = other._name;
	_dateOfBirth = other._dateOfBirth;
	_address = other._address;
	_numOfProduct = other._numOfProduct;
	return *this;
}

double ProductEmployee::calculateSalary() const
{
	return _numOfProduct * 20000.0;
}

void ProductEmployee::setNumOfProduct(int value)
{
	_numOfProduct = value;
}

int ProductEmployee::numOfProduct() const
{
	return _numOfProduct;
}

istream& operator>>(istream& in, ProductEmployee& e)
{
	in >> static_cast<Employee&>(e);
	string num;
	cout << "Enter number of products: ";
	getline(in, num);
	e.setNumOfProduct(stoi(num));
	return in;
}

ostream& operator<<(ostream& out, const ProductEmployee& e)
{
	out << static_cast<const Employee&>(e);
	out << "Number of products: " << e._numOfProduct << endl;
	return out;
}

