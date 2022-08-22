#include<iostream>
using namespace std;

class test{
	public:
	int s_no;
	static int total_objs;
	
	test(){
		total_objs++;
		s_no = total_objs;
	}
	
	void get_s_no(){
		cout<<"I am object number "<<s_no<<endl;
	}
};
int test::total_objs;

main(){
	test ob1;
	test ob2;
	test ob3;
	
	ob1.get_s_no();
	ob2.get_s_no();
	ob3.get_s_no();
}
