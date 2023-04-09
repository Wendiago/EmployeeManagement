#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <regex>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Employee.h"
#include "DailyEmployee.h"
#include "ProductEmployee.h"
using namespace std;

//Implement with vector
//class Company {
//private:
//	vector<Employee*> _listOfEmployee;
//public:
//	static bool compareSalary(const Employee*, const Employee*);
//public:
//	Company() = default;
//	~Company();
//public:
//	void enterList();
//	void displayList();
//	double calculateSumSalary() const;
//	Employee* findHighestSalaryEmployee() const;
//	double calculateAverageSalary() const;
//	Employee* findEmployeeByID(string id) const;
//	vector<Employee*> findEmployeeByName(string name) const;
//	int count_NumberOfEmployee_BornInMonth(unsigned int month) const;
//	void insertEmployee(Employee* e);
//	void insert(int);
//	void deleteEmployee(string id);
//	void writeEmployee_LowAverageSalary(string fileName);
//};

//Implement with dynamic array
class Company {
private:
	Employee** _listOfEmployee;
	int _n;
public:
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	~Company();
public:
	void enterList();
	void displayList();
	double calculateSumSalary() const;
	Employee* findHighestSalaryEmployee() const;
	double calculateAverageSalary() const;
	Employee* findEmployeeByID(string id) const;
	vector<Employee*> findEmployeeByName(string name) const;
	int count_NumberOfEmployee_BornInMonth(unsigned int month) const;
	void insertEmployee(Employee* e);
	void insert(int);
	void deleteList();
	void deleteEmployee(string id);
	void writeEmployee_LowAverageSalary(string fileName);
};