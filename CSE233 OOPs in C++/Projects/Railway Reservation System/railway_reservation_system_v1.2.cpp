// Including all required header files

#include<iostream>
#include<string.h>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include<time.h>

using namespace std;

// Declaration of Global Variables

int addr, found, d, m, i, amt;
float total_amt;


// Class Detail - It includes all the details of the train

class Detail{
	public:
		int tno;
		char tname[50];
		char bp[30];
		char dp[30];
			
		int sc,scfare;
		int c1,c1fare;
		int c2,c2fare;
		int d,m,y,h,min;
		
		void getDetail(){
			cout << "\n--- Add New details ---\n\n";
			cout << "Train no: ";
			cin >> tno;
			cout << "Train Name: ";
			cin.ignore();
			cin.getline(tname, 50);
			cout << "Boarding point: ";
			cin.getline(bp, 30);
			cout << "Destination point: ";
			cin.getline(dp, 30);
			cout << "No of seats in sleeper class & fare per ticket: ";
			cin >> sc >> scfare;
			cout << "No of seats in first class & fare per ticket: ";
			cin >> c1 >> c1fare;
			cout << "No of seats in second class & fare per ticket: ";
			cin >> c2 >> c2fare;
			cout << "Date (dd mm yyyy): ";
			cin >> d >> m >> y;
			cout << "Time (hh mm)(24-hour format): ";
			cin >> h >> min;
		}
		void displayDetail(){
			cout << "---------------------------------------------------------------\n";
			cout << "Train no. : " << tno << "\n";
			cout << "Train name: " << tname << "\n";
			cout << "Boarding Point: " << bp << "\n";
			cout << "Destination Point: " << dp << "\n";
			cout << "Sleeper class: Seats: " << sc << " " << "Fare: " << scfare << "\n";
			cout << "First class: Seats: " << c1 << " " << "Fare: " << c1fare << "\n";
			cout << "Second class: Seats: " << c2 << " " << "Fare: " << c2fare << "\n";
			cout << "Date: " << d << "-" << m << "-" << y << "\n";
			cout << "Time: " << h << ":" << min << "\n";
			cout << "---------------------------------------------------------------\n";
		}
};

// Class res - It includes the reservation details of the passenger/s

class res{
	public:
	int pnr;
	int tno;
	char tname[50];
	char bp[30];
	char dp[30];
	char pname[10][50];
    int age[10];
	char clas[10];
	int nos;
	int i;
	int d,m,y,h,min;
	float amt;
	
	void getResDetail(){
		cout<<"Enter the details correctly: \n";
		cout << "Enter the class:\n";
		cout << "SL-Sleeper Class     FC-First Class     SC-Second Class\n";
		cin.ignore();
		cin.getline(clas, 10);
		cout<<"No of seats required: ";
		cin>>nos;
		for(i=0;i<nos;i++){
			cout<<"Passenger name: ";
			cin.ignore();
			cin.getline(pname[i], 50);
			cout<<"Passenger age: ";
			cin>>age[i];
		}
	}
	
	void displayResDetail(){
		cout << "*******************************************************\n";
		cout<<"Pnr no: "<<pnr;
		cout<<"\nTrain no: "<<tno;
		cout<<"\nTrain name: "<<tname;
		cout<<"\nBoarding point: "<<bp;
		cout<<"\nDestination pt: "<<dp;
		cout<<"\nYour class: "<<clas;
		cout<<"\nNo of seats reserved: "<<nos;
		for(i=0;i<nos;i++){
			cout<<"\nPassenger name: "<<pname[i]<<" | ";
			cout<<"Passenger age: "<<age[i];
		}
		cout<<"\nDate: "<<d<<"-"<<m<<"-"<<y;
		cout<<"\nTime: "<<h<<":"<<min;
		cout<<"\nTotal Amount: "<<amt<<endl;
		cout << "*******************************************************\n";
	}
};

// Class canc - It includes the cancellation details of the passenger/s

class canc
{
    public:
    int pnr;
    int tno;
    char tname[50];
    char bp[30];
    char dp[30];
    char pname[10][50];
    int age[10];
    int i;
    char clas[10];
    int nos;
    int d, m, y, h, min;
    float amt;
    void getCancDetail(){
        cout << "Enter the details as follows\n";
        cout << "Pnr no: ";
        cin >> pnr;
        cout << "Date of cancellation: ";
        cin >> d >> m >> y;
    }
    
    void displayCancDetail(){
    	cout << "*****************************************\n";
        cout << "Pnr no: " << pnr;
        cout << "\nTrain no: " << tno;
        cout << "\nTrain name: ";
        cout << tname;
        cout << "\nBoarding point: ";
        cout << bp;
        cout << "\nDestination pt: ";
        cout << dp;
        cout << "\nYour class: ";
        cout << clas;
        cout << "\nno of seats to be cancelled: " << nos;
        for (i = 0; i < nos; i++){
            cout << "\nPassenger name: ";
            cout << pname[i];
            cout << "\npassenger age: " << age[i];
        }
        cout << "\nDate of cancellation: " << d << "-" << m << "-" << y;
        cout << "\nYou can collect: " << amt << "rs" << endl;
        cout << "\n               THANK YOU               \n";
        cout << "*****************************************\n";
    }
};


// functions

void home();
void database();
void user();
void displayPassDetail();
void changePassword();
void reserve();
void cancel();
void enquiry();
void changeUserPwd();
void modify();



// MAIN FUNCTION

int main(){
	home();
	
	return 0;
}

// home function

void home(){
	int ch;
	while (true){
		system("cls");
		system("Color 07");
		cout << "-------------------- RAILWAY RESERVATION SYSTEM --------------------\n\n";
		cout << "                             1. Admin \n\n                             2. User \n\n                             3. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> ch;
		system("cls");
		switch (ch){
			case 1:
				database();
				break;
			case 2:
				user();
				break;
			case 3:
				exit(0);
			default:
				cout << "Wrong Input!\n\n";
		}
	}
}

// database function - It provides different functions for creating and managing data by the admin

void database(){
	string password;
	string pass;
	// taking password as input from the admin
	cout << "-------------------- ADMIN LOGIN --------------------\n\n";
	cout << "Enter the Password: ";
	cin >> password;
	int ch;
	char c;
	fstream f;
	fstream pwd_f;
	Detail a;
	
	pwd_f.open("admin_password.txt", ios::in);
	pwd_f >> pass;
	pwd_f.close();
	
	if ( password!=pass){
		system("Color 04");
		cout << "\n\nThe password is wrong. Enter the correct password\n\n";
		system("pause");
	}
	else{
		while (true){
			system("cls");
			cout << "--------------------- ADMIN MENU ---------------------\n\n";
			cout << "1. Create Database              2. Modify Database\n\n";
			cout << "3. Display Details              4. Disply Passenger Details\n\n";
			cout << "5. Change Password              6. Return to Main Menu\n\n";
			cout << "Enter your choice: ";
			cin >> ch;
			system("cls");
			switch (ch){
				case 1:
					f.open("data.txt", ios::in|ios::out|ios::app);
					do{
						a.getDetail();
						f.write((char *) &a, sizeof(a));
						cout << "\nDo you want to add one more record?\n";
						cout << "y-Yes\nn-No\n";
						cin >> c;
					}while(c=='y');
					f.close();
					break;
				case 2:
					modify();
					break;
				case 3:
					f.open("data.txt", ios::in|ios::binary);
					while (f.read((char *) &a, sizeof(a))){
						found += 1;
						a.displayDetail();
					}
					if (found == 0){
						cout << "\nNo Data Found\n\n";
					}
					else{
						cout << "\n" << found << " entries found\n\n";
					}
					
					f.close();
					found = 0;
					system("pause");
					break;
				case 4:
					cout << "-----------Passenger Details-------------\n";
					displayPassDetail();
					cout << "-----------------------------------------\n";
					break;
				case 5:
					changePassword();
					break;
				case 6:
					home();
				default:
					cout << "Wrong input...\n\n";
			}
		}
	}
}

// user function - It provides all the features regarding reservation and cancellation of ticket by the user

void user(){
	int ch;
	string id;
	string i;
	string password;
	string pass;
	fstream f;
	f.open("user_id_password.txt",ios::in|ios::out|ios::binary);
	f >> i >> pass;
	
	cout << "Enter your ID : ";
	cin >> id;
	cout << "Enter your Password : ";
	cin >> password;
	
	if (id != i || pass != password){
		system("Color 04");
		cout << "\n\nYou have entered wrong Id or Password.\n\n";
		system("pause");
	}
	else{
		while (true){
			system("cls");
			cout<<"\n---------------------USER MENU----------------------------\n\n";
			cout << "1. Reserve                           2. Cancel\n\n";
			cout << "3. Enquiry                           4. View Ticket\n\n";
			cout << "5. Change Password                   6. Return to Main Menu\n\n";
			cout << "Enter your choice: ";
			cin >> ch;
			system("cls");
			switch (ch){
				case 1:
					reserve();
					break;
				case 2:
					cancel();
					break;
				case 3:
					enquiry();
					break;
				case 4:
					cout << "-----------Your Ticket Details-------------\n";
					displayPassDetail();
					cout << "-------------------------------------------\n";
					break;
				case 5:
					changeUserPwd();
					break;
				case 6:
					home();
					break;
				default:
					cout << "Wrong input\n\n";
			}
		}
	}
}

// modify function - for updating or deleting data from database

void modify(){
	int ch;
	fstream f;
	fstream fn;
	Detail a;
	int tno, d, m, y, s;
	
	cout << "\nPlease select a option:\n\n1. Update\n\n2. Delete\n\n(Press any key to go back)\n\n";
	cout << "Enter your choice: ";
	cin >> ch;
	system("cls");
	
	if (ch==1){
		cout << "Enter train no.: ";
		cin >> tno;
		cout << "Enter Date (dd mm yyyy): ";
		cin >> d >> m >> y;
		f.open("data.txt", ios::in|ios::out|ios::binary);
		while (f.read((char*)&a, sizeof(a))){
			if (a.tno==tno && a.d==d && a.m==m && a.y==y){
				found = 1;
				a.getDetail();
				addr = f.tellp();
				f.seekp(addr - sizeof(a));
				f.write((char*)&a, sizeof(a));
				cout << "\nData successfully updated.\n\n";
				system("pause");
			}
		}
		if (found==0){
			cout << "\n\nSorry, no such train found!\n\n";
			system("pause");
		}
		found = 0;
		f.close();
	}
	else if (ch==2){
		cout << "Enter train no.: ";
		cin >> tno;
		cout << "Enter Date (dd mm yyyy): ";
		cin >> d >> m >> y;
		f.open("data.txt", ios::in|ios::out|ios::binary);
		fn.open("newdata.txt", ios::in|ios::out|ios::binary|ios::app);
		while (f.read((char*)&a, sizeof(a))){
			if (a.tno==tno && a.d==d && a.m==m && a.y==y){
				found = 1;
				cout << "\nData successfully deleted.\n\n";
				cout << "Deleted data is: \n\n";
				a.displayDetail();
				cout << "\n\n";
				system("pause");
			}
			else{
				fn.write((char*)&a, sizeof(a));
			}
		}
		if (found==0){
			cout << "\n\nSorry, no such train found!\n\n";
			system("pause");
		}
		found = 0;
		f.close();
		fn.close();
		remove("data.txt");
		rename("newdata.txt", "data.txt");
	}
}

// displayPassDetail - It will dispaly current passenger details

void displayPassDetail()
{
	fstream f;
	res b;
	f.open("passengerDetails.txt",ios::in|ios::out|ios::binary);
	while(f.read((char *) & b,sizeof(b)))
	{
		found = 1;
		b.displayResDetail();
	}
	if (found == 0){
		cout << "\nSorry, No data available\n";
	}
	found = 0;
	system("pause");
	f.close();
}

// changePassword function - for changing the admin password by admin

void changePassword(){
	string new_pass;
	string confirm;
	fstream f;
	
	cout << "Enter new password: ";
	cin >> new_pass;
	cout << "Enter again to confirm: ";
	cin >> confirm;
	
	if (new_pass != confirm){
		cout << "Password doesn't match.\n\n";
		system("pause");
	}
	else{
		f.open("admin_password.txt", ios::out|ios::binary);
		f << new_pass;
		f.close();
		cout << "New password created successfully\n";
		system("pause");
	}
}

// reserve function - to reserve seat / book ticket for the passengers

void reserve(){
	Detail a;
	res b;
	fstream train_file;
	fstream book_file;
	found = 0;
	char ch;
	
	train_file.open("data.txt", ios::in|ios::out|ios::binary);
	cin.ignore();
	cout << "Enter boarding point: ";
	cin.getline(b.bp, 30);
	cout << "Enter destination point: ";
	cin.getline(b.dp, 30);
	while (train_file.read((char*)&a, sizeof(a))) {
		if ((strcmp(a.bp,b.bp) == 0) && (strcmp(a.dp,b.dp) == 0)) {
			found += 1;
			a.displayDetail();
		}
	}
	train_file.close();
	if (found==0){
		cout << "\nSorry, No train found on this route.\n\n";
		system("pause");
	}
	else{
		cout << "\n" << found << " results found\n\n";
		cout << "\nDo you want to confirm booking?[y/n]\n";
		cin >> ch;
		if (ch=='y'){
			cout << "Enter Train No.: ";
			cin >> b.tno;
			train_file.open("data.txt", ios::in|ios::out|ios::binary);
			while (train_file.read((char*)&a, sizeof(a))) {
				if (a.tno == b.tno){
					b.tno = a.tno;
					strcpy(b.tname, a.tname);
					strcpy(b.bp, a.bp);
					strcpy(b.dp, a.dp);
					b.d = a.d;
					b.m = a.m;
					b.y = a.y;
					b.h = a.h;
					b.min = a.min;
					srand(time(0));
					b.pnr = rand();
					b.getResDetail();
					if ((strcmp(b.clas, "SL") == 0) || (strcmp(b.clas, "FC") == 0) || (strcmp(b.clas, "SC") == 0)){
						if (((strcmp(b.clas, "SL") == 0) && b.nos > a.sc) || ((strcmp(b.clas, "FC") == 0) && b.nos > a.c1) || ((strcmp(b.clas, "SC") == 0) && b.nos > a.c2)){
							cout << "Sorry, required no. of seats are not available.\n";
						}
						else{
							if (strcmp(b.clas, "SL") == 0){
								a.sc -= b.nos;
								b.amt = b.nos*a.scfare;
							}
							else if (strcmp(b.clas, "FC") == 0){
								a.c1 -= b.nos;
								b.amt = b.nos*a.c1fare;
							}
							else if (strcmp(b.clas, "SC") == 0){
								a.c2 -= b.nos;
								b.amt = b.nos*a.c2fare;

							}
							addr = train_file.tellp();
							train_file.seekp(addr - sizeof(a));
							train_file.write((char*) &a, sizeof(a));
							book_file.open("passengerDetails.txt", ios::in|ios::out|ios::binary|ios::app);
							book_file.write((char *) &b, sizeof(b));
							cout << "\n\nYour Ticket Booked Successfully.\n\nHere are your ticket details: \n\n";
							b.displayResDetail();
							book_file.close();
							system("pause");
							break;
						}
					}
					else{
						cout << "\n\nYou have entered some wrong data...\n\n";
						system("pause");
						break;
					}
				}
			}
			train_file.close();	
		}
	}
	found = 0;
}

// enquiry function - It provides all the train details to the user

void enquiry(){
	fstream f;
	Detail a;
	f.open("data.txt", ios::in|ios::binary);
	while (f.read((char *) &a, sizeof(a))){
		found += 1;
		a.displayDetail();
	}
	if (found == 0){
		cout << "\nNo Data Found\n\n";
	}
	else{
		cout << "\n" << found << " entries found\n\n";
	}
	
	f.close();
	found = 0;
	system("pause");
}

// changeUserPwd function - It allows user to change the user password

void changeUserPwd(){
	string new_pass;
	string confirm;
	fstream f;
	string id;
	f.open("user_id_password.txt", ios::in|ios::out);
	f >> id;
	cout << "Enter new password: ";
	cin >> new_pass;
	cout << "Enter again to confirm: ";
	cin >> confirm;
	
	if (new_pass != confirm){
		cout << "Password doesn't match.\n\n";
		system("pause");
	}
	else{
		f << " " << new_pass << endl;
		cout << "New password created successfully\n\n";
		system("pause");
	}
	f.close();
}

// cancel function - This function will allow user to cancel the ticket

void cancel()
{
    Detail a;
    res b;
    canc c;
    fstream f1, f2, f3;
    f1.open("data.txt",ios::in|ios::out|ios::binary);
    f2.open("passengerDetails.txt",ios::in|ios::out|ios::binary);
    f3.open("newFile.txt", ios::in|ios::out|ios::binary|ios::app);
    c.getCancDetail();
    while (!f2.eof()){
    	f2.read((char *) & b,sizeof(b));
        if (b.pnr == c.pnr){
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dp, b.dp);
            c.nos = b.nos;
            for (int j = 0; j < c.nos; j++){
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, "SL")==0){
                while (f1.read((char *)&a, sizeof(a))){
                    if (a.tno == c.tno){
                    	found = 1;
                        a.sc = a.sc + c.nos;
                        d = a.d;
                        m = a.m;
                        total_amt = b.amt;
                        if ((c.d == d) && (c.m == m)){
                            cout << "You are cancelling at the date of departure\n";
                            c.amt = total_amt - ((total_amt * 60) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (c.m == m){
                            cout << "You are cancelling at the month of departure\n";
                            c.amt = total_amt - ((total_amt * 50) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (m > c.m){
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amt = total_amt - ((total_amt * 20) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else{
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displayCancDetail();
                    }
                }
            }
            else if (strcmp(c.clas, "FC")==0){
                while (f1.read((char *)&a, sizeof(a))){
                    if (a.tno == c.tno){
                    	found = 1;
                        a.c1 = a.c1 + c.nos;
                        d = a.d;
                        m = a.m;
                        total_amt = b.amt;
                        if ((c.d == d) && (c.m == m)){
                            cout << "You are cancelling at the date of departure\n";
                            c.amt = total_amt - ((total_amt * 60) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (c.m == m){
                            cout << "You are cancelling at the month of departure\n";
                            c.amt = total_amt - ((total_amt * 50) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (m > c.m){
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amt = total_amt - ((total_amt * 20) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else{
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displayCancDetail();
                    }
                }
            }
            else if (strcmp(c.clas, "SC")==0){
                while (f1.read((char *)&a, sizeof(a))){
                    if (a.tno == c.tno){
                    	found = 1;
                        a.c2 = a.c2 + c.nos;
                        d = a.d;
                        m = a.m;
                        total_amt = b.amt;
                        if ((c.d == d) && (c.m == m)){
                            cout << "You are cancelling at the date of departure\n";
                            c.amt = total_amt - ((total_amt * 60) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (c.m == m){
                            cout << "You are cancelling at the month of departure\n";
                            c.amt = total_amt - ((total_amt * 50) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else if (m > c.m){
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amt = total_amt - ((total_amt * 20) / 100);
                            addr = f1.tellp();
            				f1.seekp(addr - sizeof(a));
            				f1.write((char*)&a, sizeof(a));
                        }
                        else{
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displayCancDetail();
                    }
                }
            }
        }
        else{
        	f3.write((char*)&b, sizeof(b));
		}
    }
    if (found == 0){
        cout << "Enter the correct pnr no\n";
	}
	
	found = 0;
    f1.close();
    f2.close();
    f3.close();
    remove("passengerDetails.txt");
	rename("newFile.txt", "passengerDetails.txt");
	system("pause");
}
