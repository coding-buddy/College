// Write a program to find the area of square, rectangele, circle using function overloading

#include<iostream>
using namespace std;

class shape{
	public:
	void area(int a){
		cout<<"Area of Square: "<<a*a;
	}
	void area(int a, int b){
		cout<<"Area of Rectangle: "<<a*b;
	}
	void area(float r){
		cout<<"Area of Circle: "<<3.14*r*r;
	}
};

main(){
	shape obj;
	obj.area(5);
	obj.area(6, 5);
	obj.area(5.6f);
}
