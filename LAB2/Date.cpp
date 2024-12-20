#include <iostream>
#include "Date.h"

using std::cin;
using std::cout;
using std::endl;





void Date::print() const
{
	cout << _year << '.' << _month << '.' << _day << endl;
}



void Date::set(int year, int month, int day)
		{ 
		  if (year >= 1 && year <= 2100)
		  	_year = year;
		  if (month >= 1 && month <= 12)
		    _month = month;
		  if (day >= 1 && day <=31)
		  	_day = day;
		}




void Date::read()
	{
		cout << "Year (1-2100): ";
		int year;
		cin >> year;
		cout << "Month (1-12): ";
		int month;
		cin >> month;
		cout << "Day (1-31): "; 
		int day;
		cin >> day;
		set(year, month, day);
	}
