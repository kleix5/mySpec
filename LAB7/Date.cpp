#include <iostream>
#include "Date.h"
#include <fstream>


using namespace std;




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
	return s;
}

istream& operator >>(istream& s, Date& d)
{
	int year, month, day;
	s >> year >> month >> day;
	d.set(year, month, day);
	return s;
}

void Date::fprint(const char *fname) const
{
	ofstream w(fname, ios::app);
	w.seekp(0, ios::end);
	w << "The Date is: \n";


	w.close();

}










