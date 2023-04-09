#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Date.h"
using namespace std;

//Abstract class
class Employee {
protected:
	string _id;
	string _name;
	Date _dateOfBirth;
	string _address;
public:
	Employee();
	Employee(string, string, Date, string);
	Employee(const Employee&);
	virtual ~Employee();
public:
	void setId(string);
	void setName(string);
	void setDate(Date);
	void setAddress(string);
	string id() const;
	string name() const;
	Date dateOfBirth() const;
	string address() const;
public:
	Employee& operator=(const Employee&);
	friend istream& operator>>(istream&, Employee&) noexcept(false);
	friend ostream& operator<<(ostream&, const Employee&);
public:
//	static bool isNameValid(string);
	static bool isTypeValid(string);
public://Pure virtual functions
	virtual double calculateSalary() const = 0;
	virtual string employeeType() const = 0;
};