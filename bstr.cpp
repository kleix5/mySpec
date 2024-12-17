#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

double square(double x)
{
	return x*x;
}


void print_square()//double x)
{
	double x;
	cout << "Give a digit! \n"; 
	cin >> x;
	cout << "Square of x is: " << square(x) << endl;
}


bool accept()
{
	int tries = 1;
	while (tries<4) {
		cout << "Do you want to proceed(y or n)?\n";
		char answer = 0;
		cin >> answer;

		switch (answer){
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "Sorry, I don't understand that.\n";
			++tries;
		}
	}
	cout << "I'll take that for a no.\n";
			return false;
}


void copy_fct()
{
	int v1[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10];


	for (int i=0; i!=10; ++i)
		v2[i]=v1[i];
	for (int i=9; i!=-1; --i)
		cout << v2[i] << endl;
}
/*
void print()
{
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for (int x : v)
		cout << x << '\n';

	for (char x : {'a', 's', 'd', 'f'})
		cout << x << endl;
}
*/

int main()
{
	// accept();
	// print_square();
	// print();
	copy_fct();
}




































