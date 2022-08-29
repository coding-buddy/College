// Create a class section_detail with data member as section and cgpa. Create a constructor which will initialise secion with E2105 and cgpa with 0.0. Create a function get
// which will ask the cgpa of student and change the section if the student is not from E2105, then void print funciton to print the secion  and cgpa of the student.

#include<iostream>
using namespace std;

class section_detail{
    char *section;
    float cgpa;

    public:
    section_detail(){
        section = "E2105";
        cgpa = 0.0f;
    }

    void get(){
        char q;
        cout<<"Do you want to change your section [y/n]: ";
        cin>>q;
        if (q=='y'){
            cout<<"Enter your section: ";
            cin>>section;
            cout<<"Enter your CGPA: ";
            cin>>cgpa;
        }
        else if (q=='n'){
            cout<<"Enter your CGPA: ";
            cin>>cgpa;
        }
        else{
            cout<<"You entered wrong input"<<endl;
        }
    }

    void print(){
        cout<<"Section: "<<section<<endl<<"CGPA: "<<cgpa;
    }
};

int main(){
    section_detail ob;
    ob.get();
    ob.print();

    return 0;
}