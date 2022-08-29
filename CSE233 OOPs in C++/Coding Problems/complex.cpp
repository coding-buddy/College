// Create a class complex with two data members real and imaginary of type integer. Two member funcitons void getdata(), void setdata(int, int). Create a pointer to class and
// print the values in the form of real + i imaginary part.

#include<iostream>
using namespace std;


class Complex{
    public:
    int real;
    int imaginary;

    void getdata(){
        cout<<real<<" + i"<<imaginary<<endl;
    }
    void setdata(int r, int i){
        real = r;
        imaginary = i;
    }
};

int main(){
    Complex c;
    Complex *pc;
    pc = &c;

    void (Complex::*pf)(int, int) = &Complex::setdata;

    (pc->*pf)(5,6);
    c.getdata();
}