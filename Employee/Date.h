#pragma once
#include<iostream>
#include <ctime>
#include <exception>
using namespace std;

class Date {
private:
	unsigned int _day;
	unsigned int _month;
	int _year;
public:
	Date();
	Date(const string&) noexcept(false);
	Date(unsigned int, unsigned int, int);
	Date(const Date&);
public:
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(int);
	unsigned int day() const;
	unsigned int month() const;
	int year() const;
public:
	static Date parse(string) noexcept(false); 
	string toString();
public:
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
	Date& operator=(const Date&);
	bool isValid();
};