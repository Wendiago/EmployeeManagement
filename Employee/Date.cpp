#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <chrono>
#include <regex>
#include "Date.h"
using namespace std;

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 2023;
}

Date::Date(const string& date)
{
	stringstream ss(date);
	char delimiter = '/';
	if (!(ss >> _day >> delimiter >> _month >> delimiter >> _year) || delimiter != '/')
	{
		throw exception("Invalid input format");
	}
	if (!isValid())
	{
		throw exception("Invalid date");
	}
}

Date::Date(unsigned int day, unsigned int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(const Date& other)
{
	_day = other.day();
	_month = other.month();
	_year = other.year();
}
bool Date::isValid()
{
	try {
		// Construct a year_month_day object from the year, month, and day
		std::chrono::year_month_day date{ std::chrono::year{_year}, std::chrono::month{_month}, std::chrono::day{_day} };

		// Check if the year_month_day object is valid
		return date.ok();
	}
	catch (std::exception&) {
		// Catch any exceptions that may be thrown when constructing the year_month_day object
		return false;
	}
}

void Date::setDay(unsigned int day)
{
	_day = day;
}
void Date::setMonth(unsigned int month)
{
	_month = month;
}
void Date::setYear(int year)
{
	_year = year;
}
unsigned int Date::day() const
{
	return _day;
}
unsigned int Date::month() const
{
	return _month;
}
int Date::year() const
{
	return _year;
}

Date Date::parse(string info)
{
	if (info.length() == 0)
	{
		throw exception("Invalid input");
	}
	else
	{
		regex datePattern(R"((\d{1,2})/(\d{1,2})/(\d{4}))");
		if (regex_match(info, datePattern))
		{
			smatch match; //create a match object store day, month and year
			regex_search(info, match, datePattern); //search for day, month, and year and store in match
			unsigned int day = stoi(match[1]);
			unsigned int month = stoi(match[2]);
			int year = stoi(match[3]);
			Date result(day, month, year);
			if (result.isValid())
			{
				return result;
			}
			else
			{
				throw exception("Invalid input");
			}
		}
		else
		{
			throw exception("Invalid format");
		}
	}
}

string Date::toString()
{
	stringstream builder;
	builder << _day << "/" << _month << "/" << _year;
	string date = builder.str();
	return date;
}

istream& operator>>(istream& in, Date& date)
{
	string info;
	getline(cin, info);
	try
	{
		date = date.parse(info);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	return in;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date._day << "/" << date._month << "/" << date._year;
	return out;
}

Date& Date::operator=(const Date& other)
{
	if (this == &other)
	{
		return *this;
	}
	_day = other.day();
	_month = other.month();
	_year = other.year();
	return *this;
}