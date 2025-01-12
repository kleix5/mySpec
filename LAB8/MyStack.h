#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;



// #define max_size 100
template<typename T = int, int max_size = 100>
class MyStack {
private:
    T* stack;
    int top;
public:
    MyStack(int size = max_size) : top(0) {
        stack = new T[size];
    }

    virtual ~MyStack() {
        cout << "~MyStack() ";
        delete []stack;
    }

    void push(const T& x)
    {
        if (!isFull()) {
            stack[top++] = x;
        } else cerr << "***Stack Overflow***\n"; 
    }
    
    int pop() 
    {
        if (!isEmpty()) {
            return stack[--top];
        } else {
            cerr << "***Stack is Empty***\n";
          } 
        return T();
    };

    int amount() { return top; }

    bool isEmpty() { return amount() == 0; }
    
    bool isFull() { return amount() == max_size; }

    int get(int position) { return stack[position]; }
    
};

// template<class T>
/*class MyStack {
private:
    int _top;
    int _size;
    int* _arr;

public:
    MyStack(int size) : _size(size), _top(-1) { 
        _arr = new int[_size]; 
    };
    ~MyStack() {
        delete[] _arr;
    }

    void push(int value)
    {
        if (this->_top >= (this->_size-1)) {
            std::cout << "Stack Overflow\n";
            return;
        }
        this->_arr[++this->_top] = value;   
    }

    int pop()
    {
        return this->_arr[_top--];
    }

    int get(int position) const
    {
        return this->_arr[position];
    }
};*/









#endif