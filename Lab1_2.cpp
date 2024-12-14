#include <iostream>
#include <cstdlib>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;



char* create(int arr_size)
/*
Важный момент!!! Если мы создаём массив, то возвращать функция должна указатель на первый элемент массива!
соответственно мы добавляем '*' после типа, возвращаемого функцией. 

*/
{
	
	char* p_arr = new char[arr_size];
	for (int i=0; i < arr_size; ++i)
		p_arr[i] = '$';
	return p_arr;
}


char* resize(char* p_arr, int new_size)
{
	delete[] p_arr;
	char* newp_arr = new char[new_size];
	for (int i=0; i < new_size; ++i)
		newp_arr[i] = '$';
	return newp_arr;

}


// Назрел актуальный вопрос: мы создаём тут массив при помощи "new". Как нам в данном случае удалить потом этот массив?
int main(int argc, char** argv){
	int arr_size;
	cin >> arr_size;
	char* ref_arr = create(arr_size);
	for (int i=0; i < arr_size; ++i)
		cout << ref_arr[i] << endl;

	resize(ref_arr, 10);
	for (int i=0; i < 10; ++i)
		cout << ref_arr[i] << endl;
	
	return 0;
}



/*
int main(int argc, char** argv){
	
	int* arr = new int[5];
	arr[0] = 789;
	
	cout << arr[0] << endl;
	
	
	return 0;
}
*/

