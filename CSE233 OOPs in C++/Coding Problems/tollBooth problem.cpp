#include<iostream>
#include<conio.h>
using namespace std;

class tollBooth{
	unsigned int no_of_cars = 0;
	double total_money = 0;
	
	public:
	void payingCar(){
		no_of_cars += 1;
		total_money += 0.50;
	}
	void nopayCar(){
		no_of_cars += 1;
	}
	void display(){
		cout<<"Total cars passed: "<<no_of_cars<<endl;
		cout<<"Total money collected: "<<total_money;
	}
};

main(){
	tollBooth obj;
	cout<<"press 1 to add paying car.\npress 2 to add non-paying car.\npress esc to display total cars and money.\n";
	while (true){
		char a;
		a = getch();
		
		if (a=='1'){
			obj.payingCar();
			cout<<"Added\n";
		}
		else if (a=='2'){
			obj.nopayCar();
			cout<<"Added\n";
		}
		else if (a==27){
			obj.display();
			break;
		}
		else{
			cout<<"wrong input";
		}
	}
}
