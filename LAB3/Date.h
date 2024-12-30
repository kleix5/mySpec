#ifndef _DATE_H_
#define _DATE_H_

using std::cout;
using std::endl;

//class Date;


class Date
{
	private:
		int _year, _month, _day;
			
	public:
		Date() : Date(2001,1,1){
			cout << "Default ctor \n";
		}

		
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





#endif
