#include <iostream>
#include <cstring>

#include "MyStack.h"


using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

bool verifyPar(const char* s)
{   
    int len = strlen(s);
    MyStack<char>* st = new MyStack<char>(len);
    for (int i=0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[')
            st->push(ch);
        if (ch == ')' || ch == ']') {
            if (st->isEmpty()) return false;
            else {
                char ch2 = st->pop();
                if( !((ch2 == '(' && ch == ')') || (ch2 == '[' && ch == ']') ))
                return false;
            }
        }

    }
    bool result = st->isEmpty();
    delete st;
    return result;
}


int main(int argc, char** argv)
{
    MyStack<int>* stack = new MyStack<int>;

    stack->push(1);
    stack->push(2);
    stack->push(3);
    // stack.push(222);
    // stack.push(111);
    // stack.push(000); // overflow here.
    // stack->pop();
    // cout << stack->get(0) << endl 
    //      << stack->get(1) << endl 
    //      << stack->get(2) << endl; 
    cout <<  "amount: " << stack->amount() << endl;
    cout <<  "empty: " << boolalpha << stack->isEmpty() << endl;
    cout <<  "full: " << boolalpha << stack->isFull() << endl;

    while (!stack->isEmpty()) {
        cout << stack->pop() << endl;
    }

    delete stack;

    const char* str = "( ( [ + ] )  - [ ] * () )";
    cout << "For string '" << str << "': "
         <<  verifyPar(str) << endl;

    return 0;
}