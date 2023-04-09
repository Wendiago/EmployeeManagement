#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Employee.h"
#include "DailyEmployee.h"
#include "ProductEmployee.h"
#include "Company.h"
using namespace std;

//Implement with vector
//bool Company::compareSalary(const Employee* a, const Employee* b)
//{
//	return a->calculateSalary() > b->calculateSalary();
//}
//
//Company::~Company()
//{
//	//
//}
//
//void Company::enterList()
//{
//	string number;
//	cout << "Enter number of employee: ";
//	getline(cin, number);
//	int numberOfEmployee = stoi(number);
//
//	for (int i = 0; i < numberOfEmployee; i++)
//	{
//		string type;
//		do
//		{
//			cout << "Enter type of employee (Daily Employee / Product Employee): ";
//			getline(cin, type);
//			if (!Employee::isTypeValid(type))
//			{
//				cout << "Invalid type. Try again!" << endl;
//			}
//		} while (!Employee::isTypeValid(type));
//		
//		Employee* e = nullptr;
//		if (type == "Product Employee")
//		{
//			ProductEmployee* productEmp = new ProductEmployee();
//			cin >> *productEmp;
//			e = productEmp;
//		}
//		else
//		{
//			DailyEmployee* dailyEmp = new DailyEmployee();
//			cin >> *dailyEmp;
//			e = dailyEmp;
//		}
//		_listOfEmployee.push_back(e);
//		cout << endl;
//	}
//}
//
//void Company::displayList()
//{
//	if (_listOfEmployee.empty())
//	{
//		return;
//	}
//	for (int i = 0; i < _n; i++)
//	{
//		cout << *_listOfEmployee[i];
//	}
//}
//
//double Company::calculateSumSalary() const
//{
//	double sum = 0.0;
//	for (int i = 0; i < _n; i++)
//	{
//		sum += _listOfEmployee[i]->calculateSalary();
//	}
//	return sum;
//}
//
//Employee* Company::findHighestSalaryEmployee() const
//{
//	if (!_listOfEmployee.empty())
//	{
//		vector<Employee*> copy = _listOfEmployee;
//		sort(copy.begin(), copy.end(), compareSalary);
//		return copy[0];
//	}
//	return nullptr;
//}
//
//double Company::calculateAverageSalary() const
//{
//	double averageSalry = 0.0;
//	if (!_listOfEmployee.empty())
//	{
//		return (this->calculateSumSalary() / _n);
//	}
//}
//
//Employee* Company::findEmployeeByID(string id) const
//{
//	bool found = false;
//	for (int i = 0; i < _n; i++)
//	{
//		if (_listOfEmployee[i]->id() == id)
//		{
//			found = true;
//			return _listOfEmployee[i];
//		}
//	}
//	if (found == false)
//	{
//		cout << "No employee found!";
//	}
//}
//
//vector<Employee*> Company::findEmployeeByName(string name) const
//{
//	vector<Employee*> result;
//	for (int i = 0; i < _n; i++)
//	{
//		if (_listOfEmployee[i]->name() == name)
//		{
//			result.push_back(_listOfEmployee[i]);
//		}
//	}
//	return result;
//}
//
//int Company::count_NumberOfEmployee_BornInMonth(unsigned int month) const
//{
//	int count = 0;
//	for (int i = 0; i < _n; i++)
//	{
//		if (_listOfEmployee[i]->dateOfBirth().month() == month)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//void Company::insertEmployee(Employee* e)
//{
//	_listOfEmployee.push_back(e);
//}
//
//void Company::insert(int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		string type;
//		do
//		{
//			cout << "Enter type of employee (Daily Employee / Product Employee): ";
//			getline(cin, type);
//			if (!Employee::isTypeValid(type))
//			{
//				cout << "Invalid type. Try again!" << endl;
//			}
//		} while (!Employee::isTypeValid(type));
//		if (type == "Product Employee")
//		{
//			Employee* productEmp = new ProductEmployee();
//			cin >> *dynamic_cast<ProductEmployee*> (productEmp);
//			this->insertEmployee(productEmp);
//		}
//		else
//		{
//			Employee* dailyEmp = new DailyEmployee();
//			cin >> *dynamic_cast<DailyEmployee*> (dailyEmp);
//			this->insertEmployee(dailyEmp);
//		}
//	}
//}
//
//void Company::deleteEmployee(string id)
//{
//	for (auto it = _listOfEmployee.begin(); it != _listOfEmployee.end(); ++it)
//	{
//		if ((*it)->id() == id)
//		{
//			_listOfEmployee.erase(it);
//			break;
//		}
//	}
//}
//
//void Company::writeEmployee_LowAverageSalary(string fileName)
//{
//	ofstream writer;
//	writer.open(fileName, ios::out || ios::trunc);
//	if (writer.good())
//	{
//		for (int i = 0; i < _n; i++)
//		{
//			if (_listOfEmployee[i]->calculateSalary() < this->calculateAverageSalary())
//			{
//				writer << *_listOfEmployee[i];
//			}
//		}
//		writer.close();
//		cout << "Write to file successfully" << endl;
//	}
//}

//Implement with dynamic array

Company::Company()
{
	_listOfEmployee = nullptr;
	_n = 0;
}

Company::Company(const Company& other)
{
	_n = other._n;
	this->_listOfEmployee = new Employee * [_n];
	for (int i = 0; i < _n; i++)
	{
		if (other._listOfEmployee[i]->employeeType() == "Daily Employee")
		{
			DailyEmployee* ptr = dynamic_cast<DailyEmployee*>(other._listOfEmployee[i]);
			_listOfEmployee[i] = new DailyEmployee(*ptr);
		}
		else
		{
			ProductEmployee* ptr = dynamic_cast<ProductEmployee*>(other._listOfEmployee[i]);
			_listOfEmployee[i] = new ProductEmployee(*ptr);
		}
	}
}

Company& Company::operator=(const Company& other)
{
	if (_listOfEmployee != nullptr)
	{
		for (int i = 0; i < _n; i++)
		{
			delete _listOfEmployee[i];
		}
		delete[]_listOfEmployee;
	}
	if (this == &other)
	{
		return *this;
	}
	_n = other._n;
	this->_listOfEmployee = new Employee * [_n];
	for (int i = 0; i < _n; i++)
	{
		if (other._listOfEmployee[i]->employeeType() == "Daily Employee")
		{
			DailyEmployee* ptr = dynamic_cast<DailyEmployee*>(other._listOfEmployee[i]);
			_listOfEmployee[i] = new DailyEmployee(*ptr);
		}
		else
		{
			ProductEmployee* ptr = dynamic_cast<ProductEmployee*>(other._listOfEmployee[i]);
			_listOfEmployee[i] = new ProductEmployee(*ptr);
		}
	}
	return *this;
}

Company::~Company()
{
	if (_listOfEmployee != nullptr)
	{
		for (int i = 0; i < _n; i++)
		{
			delete _listOfEmployee[i];
		}
		delete[]_listOfEmployee;
	}
}

void Company::enterList()
{
	string number;
	cout << "Enter number of employee: ";
	getline(cin, number);
	int numberOfEmployee = stoi(number);

	for (int i = 0; i < numberOfEmployee; i++)
	{
		string type;
		do
		{
			cout << "Enter type of employee (Daily Employee / Product Employee): ";
			getline(cin, type);
			if (!Employee::isTypeValid(type))
			{
				cout << "Invalid type. Try again!" << endl;
			}
		} while (!Employee::isTypeValid(type));
		
		Employee* e = nullptr;
		if (type == "Product Employee")
		{
			ProductEmployee* productEmp = new ProductEmployee();
			cin >> *productEmp;
			e = productEmp;
		}
		else
		{
			DailyEmployee* dailyEmp = new DailyEmployee();
			cin >> *dailyEmp;
			e = dailyEmp;
		}
		this->insertEmployee(e);
		cout << endl;
	}
}

void Company::displayList()
{
	for (int i = 0; i < _n; i++)
	{
		cout << *_listOfEmployee[i];
		cout << endl;
	}
}

void Company::insertEmployee(Employee* e)
{
	Employee** newList = new Employee * [_n + 1];
	for (int i = 0; i < _n; i++)
	{
		if (this->_listOfEmployee[i]->employeeType() == "Daily Employee")
		{
			DailyEmployee* ptr = dynamic_cast<DailyEmployee*>(this->_listOfEmployee[i]);
			newList[i] = new DailyEmployee(*ptr);
		}
		else
		{
			ProductEmployee* ptr = dynamic_cast<ProductEmployee*>(this->_listOfEmployee[i]);
			newList[i] = new ProductEmployee(*ptr);
		}
	}
	if (e->employeeType() == "Daily Employee")
	{
		DailyEmployee* ptr = dynamic_cast<DailyEmployee*>(e);
		newList[_n] = new DailyEmployee(*ptr);
	}
	else
	{
		ProductEmployee* ptr = dynamic_cast<ProductEmployee*>(e);
		newList[_n] = new ProductEmployee(*ptr);
	}
	this->deleteList();
	_listOfEmployee = newList;
	_n++;
}

void Company::insert(int num)
{
	for (int i = 0; i < num; i++)
	{
		string type;
		do
		{
			cout << "Enter type of employee (Daily Employee / Product Employee): ";
			getline(cin, type);
			if (!Employee::isTypeValid(type))
			{
				cout << "Invalid type. Try again!" << endl;
			}
		} while (!Employee::isTypeValid(type));
		if (type == "Product Employee")
		{
			Employee* productEmp = new ProductEmployee();
			cin >> *dynamic_cast<ProductEmployee*> (productEmp);
			this->insertEmployee(productEmp);
		}
		else
		{
			Employee* dailyEmp = new DailyEmployee();
			cin >> *dynamic_cast<DailyEmployee*> (dailyEmp);
			this->insertEmployee(dailyEmp);
		}
	}
}

void Company::deleteList()
{
	if (_listOfEmployee != nullptr)
	{
		for (int i = 0; i < _n; i++)
		{
			delete _listOfEmployee[i];
		}
		delete[]_listOfEmployee;
	}
}

void Company::deleteEmployee(string id)
{
	int index = -1;
	for (int i = 0; i < _n; i++) {
		if (_listOfEmployee[i]->id() == id) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		delete _listOfEmployee[index];
		for (int i = index; i < _n - 1; i++) 
		{
			_listOfEmployee[i] = _listOfEmployee[i + 1];
		}
		_n--;
	}
	else
	{
		cout << "ID not found!" << endl;
	}
}

void Company::writeEmployee_LowAverageSalary(string fileName)
{
	ofstream writer;
	writer.open(fileName, ios::out || ios::trunc);
	if (writer.good())
	{
		for (int i = 0; i < _n; i++)
		{
			if (_listOfEmployee[i]->calculateSalary() < this->calculateAverageSalary())
			{
				writer << *_listOfEmployee[i];
			}
		}
		writer.close();
		cout << "Write to file successfully" << endl;
	}
}

double Company::calculateSumSalary() const
{
	double sum = 0.0;
	for (int i = 0; i < _n; i++)
	{
		sum += _listOfEmployee[i]->calculateSalary();
	}
	return sum;
}

Employee* Company::findHighestSalaryEmployee() const
{
	double maxSalary = _listOfEmployee[0]->calculateSalary();
	int maxIndex = 0;
	for (int i = 0; i < _n; i++) 
	{
		if (_listOfEmployee[i]->calculateSalary() > maxSalary)
		{
			maxSalary = _listOfEmployee[i]->calculateSalary();
			maxIndex = i;
		}
	}
	return _listOfEmployee[maxIndex];
}

double Company::calculateAverageSalary() const
{
	double averageSalry = 0.0;
	if (_listOfEmployee != nullptr)
	{
		return (this->calculateSumSalary() / _n);
	}
}

Employee* Company::findEmployeeByID(string id) const
{
	bool found = false;
	for (int i = 0; i < _n; i++)
	{
		if (_listOfEmployee[i]->id() == id)
		{
			found = true;
			return _listOfEmployee[i];
		}
	}
	if (found == false)
	{
		cout << "No employee found!";
		return nullptr;
	}
}

vector<Employee*> Company::findEmployeeByName(string name) const
{
	vector<Employee*> result;
	for (int i = 0; i < _n; i++)
	{
		if (_listOfEmployee[i]->name() == name)
		{
			result.push_back(_listOfEmployee[i]);
		}
	}
	return result;
}

int Company::count_NumberOfEmployee_BornInMonth(unsigned int month) const
{
	int count = 0;
	for (int i = 0; i < _n; i++)
	{
		if (_listOfEmployee[i]->dateOfBirth().month() == month)
		{
			count++;
		}
	}
	return count;
}