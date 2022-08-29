// reference variable

#include<iostream>
using namespace std;


main(){
	int number_of_students_registered = 20;
	int &ns = number_of_students_registered;

	cout<<number_of_students_registered<<endl;
	cout<<ns<<endl;
	cout<<&number_of_students_registered<<endl;
	cout<<&ns<<endl;
	
	number_of_students_registered = 17;
	cout<<number_of_students_registered<<endl;
	cout<<ns<<endl;
	
	ns++;
	cout<<number_of_students_registered<<endl;
	cout<<ns<<endl;
}
