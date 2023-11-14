#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
	int choice;
	cout << "\t\t\t____________________________________________________\n\n\n";
	cout << "\t\t\t              Welcome to the Login Page              \n\n\n";
	cout << "\t\t\t__________________       MENU      	_________________\n\n\n";
	cout << endl;
	cout << "\t Press 1 to LOGIN 					|" << endl;
	cout << "\t Press 2 to Register 					|" << endl;
	cout << "\t Press 3 to if you forgot your PASSWORD 		|" << endl;
	cout << "\t Press 4 to EXIT 					|" << endl;
	cout << "\n\t\t\t Please enter your choice: ";
	cin >> choice;
	cout << endl;
	
	switch(choice){
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout << "\t\t\t Thank You! \n\n";
			break;
		default:
			system("cls");
			cout << "\t\t\t Please select from the options given. \n" << endl;
			main();
	
	}
	
}

void login(){
	int count;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter username and password: " << endl;
	cout << "\t\t\t USERNAME: ";
	cin >> userId;
	cout << "\t\t\t PASSWORD: ";
	cin >> password;
	
	
	ifstream input("records.txt");
	
	while(input >> id >> pass){
		if (id == userId && pass == password){
			count =1;
			system("cls");
		}
	}
	input.close();
	
	if(count == 1){
		cout << userId << "\n Your LOGIN is successful \n Thanks for logging in! \n";
		main();
	} else{
		cout << "\n LOGIN ERROR \n Please check your username and pasword \n";
		main();
	}
}


void registration(){
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter the username: ";
	cin >> ruserId;
	cout << "\t\t\t Enter the password: ";
	cin >> rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1 << ruserId << " " << rpassword << endl;
	system("cls");
	cout << "\n\t\t\t Registration is successfull! \n";
	main();
}

void forgot(){
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password? No worries \n";
	cout << "Press 1 to search your id by username " << endl;
	cout << "Press 2 to go back to the main menu " << endl;
	cout << "\t\t\t Enter your choice: ";
	cin >> option;
	switch(option){
		case 1: {
			int count = 0;
			string suserId, sId, spass;
			cout << "\n\t\t\t Enter the username which you remembered: ";
			cin >> suserId;
			
			ifstream f2("records.txt");
			while(f2 >> sId >> spass){
				if (sId == suserId){
					count = 1;
				}
			}
			f2.close();
			if(count == 1){
				cout << "\n\n Your account is found! \n";
				cout << "\n\n Your Pasword is: " << spass;
				main();
			} else{
				cout << "\n\n Sorry! Your account is not found! \n";
				main();
			}
			break;
		}
		case 2: {
			main();
			
		}
		default: {
			cout << "\t\t\t Wrong choice! Please try again " << endl;
			forgot();
		}
			
			
	}
}
