#include<iostream>
using namespace std;

class Student{
    int reg;
    float marks;
    int *p = &reg;

    void get(){
        cout<<"Enter registration number: ";
        cin>>*p;
        cout
    }
};