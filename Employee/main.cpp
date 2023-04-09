#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include "Date.h"
#include "Employee.h"
#include "ProductEmployee.h"
#include "DailyEmployee.h"
#include "Company.h"
using namespace std;

int main()
{
	try
	{
		Company myCompany;
		//Enter list of company
		myCompany.enterList();
		cout << endl;

		//Print list of employee
		myCompany.displayList();
		
		//Find sum of employee salary
		cout << "Sum of salary: " << fixed << setprecision(0) <<  myCompany.calculateSumSalary() << endl;

		//Find average salary
		cout << "Average salary: " << fixed << setprecision(0) << myCompany.calculateAverageSalary() << endl;

		//Find employee with the highest salary
		cout << "Employee who has the highest salary is: " << endl;
		cout << *myCompany.findHighestSalaryEmployee() << endl;

		//Find the employee with id 
		string idToFind;
		cout << "Enter id to find: ";
		getline(cin, idToFind);
		cout << "Employee with id = " << idToFind << ": " << endl;
		cout << *myCompany.findEmployeeByID(idToFind) << endl;

		//Find employees with name
		string nameToFind;
		cout << "Enter name to find: ";
		getline(cin, nameToFind);
		cout << "Employees with name (" << nameToFind << "): " << endl;
		vector<Employee*> nameFounded = myCompany.findEmployeeByName(nameToFind);
		for (Employee* e : nameFounded)
		{
			cout << *e;
			cout << endl;
		}

		//Count number of employees who were born in May
		int month = 05;
		cout << "Number of employees who were born in May is " << myCompany.count_NumberOfEmployee_BornInMonth(month) << endl;
		cout << endl;

		//Insert new Employee into Company
		string numberOfEmployeeForInsert;
		cout << "Enter number of employee to insert: ";
		getline(cin, numberOfEmployeeForInsert);
		int number = stoi(numberOfEmployeeForInsert);
		myCompany.insert(number);

		cout << endl;
		cout << "List of employee: " << endl;
		myCompany.displayList();

		//Delete an Employee from Company
		cout << endl;
		string idToDelete;
		cout << "Enter an id to delete: ";
		getline(cin, idToDelete);

		myCompany.deleteEmployee(idToDelete);

		cout << endl;
		cout << "List of employee: " << endl;
		myCompany.displayList();

		//Write employees whose salary are lower than the average salary of company into a file named "emp_LowerAvgSalary.dat"
		string fileName = "emp_LowerAvgSalary.dat";
		myCompany.writeEmployee_LowAverageSalary(fileName);
	}
	catch(exception ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
	
}