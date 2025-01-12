#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <typeinfo>

using std::string;
using std::cout;
using std::endl;
using std::type_info;
using std::boolalpha;

int main()
{
    // std::string str="123"; 
    int digits = 0;
    // char chr = str[1];
    // std::cout << "chr[1]: " << chr << std::endl;
    // digits += (chr - '0');
    // std::cout << "digits: " << digits << std::endl;
    char ch = 'a';
    char& rch = ch;
    char* pch = &ch;

    string s = "abracodabra";
    string sop = "asd";
    digits += 's';

    int op = 6;
    cout << boolalpha;
    cout << typeid(s).name() << endl;
    cout << typeid(digits).name() << endl;
    {
        cout << "Matching ints: ";
        cout << (typeid(op).name() == typeid(digits).name()) << endl;
        cout << "Matching strings: ";
        cout << (typeid(sop).name() == typeid(s).name()) << endl;
    }

    cout << typeid(ch).name() << "  char var -> " << ch << endl;
    cout << typeid(rch).name() << "  refer -> " << rch << endl;
    cout << typeid(pch).name() << "  pointer -> " << pch << endl;
    {
        cout << "Matching char to ref: ";
        cout << (typeid(ch).name() == typeid(rch).name()) << endl;
        cout << "Matching ref to pointer: ";
        cout << (typeid(rch).name() == typeid(pch).name()) << endl;
    }

    return 0;
}