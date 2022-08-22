// Polymorphism in C++
// poly = many, morph = forms

#include<iostream>
using namespace std;

class poly{
	public:
	void calculate(int a, int b){    // function overloading
		cin>>a>>b;
		cout<<a+b;
	}
	void calculate(int a, int b, int c){    // function overloading
		cin>>a>>b>>c;
		cout<<a+b+c;
	}
	void calculate(float a, float b){    // function overloading
		cin>>a>>b;
		cout<<a+b;
	}
};

main(){
	poly obj;
	obj.calculate(10, 20);
}
