#pragma once
#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

class ProductEmployee :public Employee {
private:
	int _numOfProduct;
public:
	ProductEmployee();
	ProductEmployee(string id, string name, Date dob, string address, int numOfPro);
	ProductEmployee(const ProductEmployee&);
public:
	void setNumOfProduct(int);
	double calculateSalary() const override;
	int numOfProduct() const;
	string employeeType() const override;
public:
	ProductEmployee& operator=(const ProductEmployee&);
	friend istream& operator>>(istream&, ProductEmployee&);
	friend ostream& operator<<(ostream&, const ProductEmployee&);
};