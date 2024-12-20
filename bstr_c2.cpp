#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;


/*
Let's trying to build a new type!
*/
/*
struct Vector {
    int sz;        // number of elements
    double* elem;  // pointer to elements
};

// Vector v;


void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; //allocate an array of doubles
    v.sz = s;
}


double read_and_sum(int s)
    // read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v,s);            // allocate s elements for v
    for (int i=0; i!=s; ++i)
        cin >> v.elem[i];        // read into elements

    double sum = 0;
    for (int i=0; i!=s; ++i)
        sum+=v.elem[i];
    
    cout << "All the numbers here: \n";
    for (int i=0; i!=s; ++i){
        cout << v.elem[i] << " ";
    }
    cout << endl << "The sum is: ";
    return sum; 
}
*/

class Vector{
public:
    Vector(int s): elem{new double[s]}, sz{s}{}    // construct a Vector
    double& operator[](int i) { return elem[i]; }  // element access: subscripting
    int size() { return sz; }
private:
    double* elem; // pointer to the elements
    int sz;       // the number of elements

    double read_and_sum(int s)
    {
        Vector v(s);                               // meke a vektor of s elements
        for (int i=0; i!=v.size(); ++i)
            cin >> v[i];                           // read into elements

        double sum = 0;
        for(int i=0; i!=v.size(); ++i)        
            sum+=v[i];                             // take the sum of the elements
        return sum;
    }
};



int main()
{  
    int data;
    Vector v;
    // cout << "I need some data! \n";
    // cin >> data; 
    // v.[0]=777;
    // cout << v[0] << endl;
    // v.read_and_sum(5);
    /*
    cout << "Type NUMBER: \n";
    int x;
    cin >> x; 
    cout << read_and_sum(x) << endl;
    */
    /*Тут я просто вычисляю размер массива*/
    // int nums[] = {33,44,55};
    // int size = sizeof(nums) / sizeof(nums[0]);
    // cout << size << endl; 
    


    return 0;
}