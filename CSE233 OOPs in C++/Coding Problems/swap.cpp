// write a program to swap to numbers. create a function swap, its return type is int and it will take 2 arguments both integers

#include<iostream>
using namespace std;

// call by value

//void swap(int, int);
//
//main(){
//	int a = 6;
//	int b = 2;
//	cout<<"Before swaping:\na = "<<a<<"\nb = "<<b<<endl;
//	swap(a, b);
//	cout<<"After swaping:\na = "<<a<<"\nb = "<<b<<endl;
//}
//
//void swap(int v1, int v2){
//	int c = v1;
//	v1 = v2;
//	v2 = c;
//}



// call by reference

//void swap(int &, int &);
//
//main(){
//	int a = 6;
//	int b = 2;
//	cout<<"Before swaping:\na = "<<a<<"\nb = "<<b<<endl;
//	swap(a, b);
//	cout<<"After swaping:\na = "<<a<<"\nb = "<<b<<endl;
//}
//
//void swap(int &v1, int &v2){
//	int c = v1;
//	v1 = v2;
//	v2 = c;
//}


// call by address

void swap(int *, int *);

main(){
	int a = 6;
	int b = 2;
	cout<<"Before swaping:\na = "<<a<<"\nb = "<<b<<endl;
	swap(&a, &b);
	cout<<"After swaping:\na = "<<a<<"\nb = "<<b<<endl;
}

void swap(int *v1, int *v2){
	int c = *v1;
	*v1 = *v2;
	*v2 = c;
}
