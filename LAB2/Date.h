#ifndef _DATE_H_
#define _DATE_H_

class Date;


class Date
{
	private:
		int _year, _month, _day;
			
	public:
		Date(int year=1, int month=1, int day=1)
			: _year(year), _month(month), _day(day)
		{}
	
	
		void print() const;
		
		void set(int, int, int);

		void read();
	
};





#endif
