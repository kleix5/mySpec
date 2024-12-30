#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;


class Date;


class Date
{
	private:
		int _year, _month, _day;
			
	public:
	
		Date() : Date(2001,1,1){
			cout << "Default ctor \n";
		}
	
		// Date() {};

		int year() const {return _year;}
		int month() const {return _month;}
		int day() const {return _day;}

		Date(int year, int month, int day)
			: _year(year), _month(month), _day(day)
		{	cout << "ctor with initial param \n";	}


		Date(const Date& r) {
			cout << "ctor by refference \n";
		}
	
		void print() const;
		
		void set(int, int, int);

		void read();
	
};

bool operator == (const Date& d1, const Date& d2);
ostream& operator <<(ostream& s, const Date& d);
istream& operator >>(istream& s, Date& d);

#endif