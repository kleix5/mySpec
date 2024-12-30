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
	
//	d1.read();
	// d1.set(2024,12,12);
//	d1.print();
	return 0;
}
