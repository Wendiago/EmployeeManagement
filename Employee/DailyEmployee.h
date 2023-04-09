#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

class DailyEmployee : public Employee{
private:
	int _numOfDay;
public:
	DailyEmployee();
	DailyEmployee(string id, string name, Date dob, string address, int numOfDay);
	DailyEmployee(const DailyEmployee&);
public:
	void setNumOfDay(int);
	double calculateSalary() const override;
	int numOfDay() const;
	string employeeType() const override;
public:
	DailyEmployee& operator=(const DailyEmployee&);
	friend istream& operator>>(istream&, DailyEmployee&);
	friend ostream& operator<<(ostream&, const DailyEmployee&);
};