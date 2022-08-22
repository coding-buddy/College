// The company XYZ is conducting a yearly sports meet for its employees. The interested employees can register by providing their name, employee id, 
// and the years of experience in that particular company. Total 10 employees have participated print the details of all the 10 employees with the 
// counter as id allocated to each employee as they have registered.


#include<iostream>
using namespace std;

class Employee{
	public:
		char name[30];
		int emp_id;
		int yoe;
		
		int reg_no;
		static int total_emps;
	
		Employee(){
			total_emps++;
			reg_no = total_emps;
		}
		
		void get(){
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Employee Id: ";
			cin>>emp_id;
			cout<<"Enter Years of Experience: ";
			cin>>yoe;
		}
};

int Employee::total_emps;

main(){
	char employeesDetails[30];
	cout<<"MANAGEMENT SYSTEM"<<endl;
	while (true){
		int n;
		cout<<"1. Add new Employee               2. View Employees Details"<<endl;
		cout<<"Enter your choice: ";
		cin>>n;
		
		if (n==1){
			Employee p;
			p.get();
			
		}
		else if (n==2){
			cout<<employeesDetails;
		}
	}
}
