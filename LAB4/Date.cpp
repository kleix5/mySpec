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


bool operator == (const Date& d1, const Date& d2)
{
	return d1.year() == d2.year() && d1.month() == d2.month() &&
		d1.day() == d2.day(); 
} 


ostream& operator <<(ostream& s, const Date& d)
{
	s << d.year() << '.' << d.month() << '.' << d.day() << endl;
}
istream& operator >>(istream& s, Date& d)
{
	int year, month, day;
	cin >> year >> month >> day;
	d.set(year, month, day);
}