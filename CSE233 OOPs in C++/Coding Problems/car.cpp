// Create a class car with the data members brand, model and year. Use constructor overloading and print the details of two such cars. Also copy the brand and year of the car 1
// to car 3 and take the model name from the user using copying constructor.

#include <iostream>
#include <string>
using namespace std;

class Car{
    string brand, model;
    int year;

    public:
    Car(string b, string m, int y){
        brand = b;
        model = m;
        year = y;
    }

    Car(Car &c){
        brand = c.brand;
        year = c.year;
        cout<<"Enter model name: ";
        cin>>model;
    }

    void print(){
        cout<<"Brand: "<<brand<<endl<<"Model: "<<model<<endl<<"Year: "<<year<<endl;
    }
};

int main(){
    Car car1("Tesla", "S", 2009);
    car1.print();
    Car car2("Audi", "X", 2015);
    car2.print();
    Car car3(car1);
    car3.print();
}