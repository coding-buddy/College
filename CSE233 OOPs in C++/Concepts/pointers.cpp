#include<iostream>
using namespace std;


main(){
	int number = 20;
	int *p; // wild pointer
	p = &number;

	cout<<*p;
}

// & - address of, referencing
// * - value at address, dereferencing
