#include <iostream>
#include "Date.h"


using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) 
{
	Date d1;
	d1.read();
	// d1.set(2024,12,12);
	d1.print();
	return 0;
}