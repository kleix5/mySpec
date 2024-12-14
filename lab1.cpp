#include <iostream>
#include <cstdlib>


//using namespace std;
using std::cout;
using std::cin;
using std::endl;


struct Date
{
  int year, month, day;
};


struct Time
{
  int hour, min, sec;
};


void set(Date& date, int year, int month, int day)
{ 
  if (year >= 1 && year <= 2100)
  	date.year = year;
  if (month >= 1 && month <= 12)
    date.month = month;
  if (day >= 1 && day <=31)
  	date.day = day;
}

void set(Time& time, int hour, int min, int sec = 0)
{
	if (hour >= 0 && hour <= 23)
	  time.hour = hour;
	if (min >= 0 && min <= 59)
	  time.min = min;
	if (sec >= 0 && sec <= 59)
	  time.sec = sec;
}


void read(Time& time)
{
	cout << "Hour (0-23): ";
	int h;
	cin >> h;
	cout << "Min (0-59): ";
	int m;
	cin >> m;
	set(time, h, m);
}

Date read()
/*
	Данная запись является альтернативной предыдущей функции read(), в данном случае
	функция возвращает структуру Date, предварительно заполнив её поля. То есть в этом
	случае функция возвращает не одно значение, а три!!!
	
*/
{
	Date date;
	cout << "Year (1-2100): ";
	int year;
	cin >> year;
	cout << "Month (1-12): ";
	int month;
	cin >> month;
	cout << "Day (1-31): "; 
	int day;
	cin >> day;
	set(date, year, month, day);
	return date;
}


void print(const Date& date)
{
	cout << date.year << '.' << date.month << '.' << date.day << endl;
}

void print(const Time& time)
{
	cout << time.hour << ':' << time.min << ':' << time.sec << endl;
}
 
                 
int main(int argc, char** argv){
  //Time t;
  //read(t);
  //print(t);
  
  Date d = read(); //Создаём структуру Date, проинициализировав её функцией read.
  //read(d);
  print(d);

  return 0;
}
