#include <iostream>
#include "Date.h"


using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) 
{
	cout << "1:  \n";
	Date d21;
	d21.print();
	cout << "2:  \n";
	Date d1(2024,12,12);
	d1.print();
	cout << "3:  \n";
	Date d12 = d21;
	d12.print();
	
	Date d_01(2021, 12, 12);
	Date d_02(2021, 12, 13);
	Date d_03;
	if (d_01 == d_02)
		cout << "d_01 equal d_02 \n";
	else
		cout << "d_01 NOT equal d_02 \n";

	cout << d_01 << endl;
	cin >> d_03;
	cout << d_03 << endl; 

//	d1.read();
	// d1.set(2024,12,12);
//	d1.print();
	return 0;
}
