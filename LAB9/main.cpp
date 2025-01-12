#include <iostream>
#include <stdexcept>
#include <cstring>

using std::invalid_argument;
using std::cout;
using std::cerr;
using std::endl;

int parse(const char* str) 
{
    double result = 0;
    double p = 1;
    double len = strlen(str);
    if (len == 0)
        throw invalid_argument("parse empty string!");
    for (int i=len-1; i>=0; i--) {
        char c = str[i];
        if (c=='+' && i == 0) continue;
        if (c=='-' && i == 0) {
            result =- result;
            continue;
        };
        if (c >= '0' && c <= '9') {
            result += (c-'0')*p;
            p *= 10;
        }
        else throw invalid_argument("parse invalid symbol");
    }
    return result;
}

void test(const char* s1, const char* s2) {
    try
    {
        double n1 = parse(s1);
        double n2 = parse(s2);

        double n = n1 / n2;

        cout << "Result: " << n << endl;
    }
    catch(const invalid_argument& ex) 
    {
        cerr << ex.what() << endl;
    }
    cout << "continue test\n";
    
}


int main(int argc, char** argv)
{
    test("140", "-7");

    cout << "continue main\n";
    return 0;
}