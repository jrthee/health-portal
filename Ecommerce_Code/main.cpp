/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++       //
// Final Project                                   //
// Name: Kuohsun Tsai                              //
// Date: 09/16/2019                                //
/////////////////////////////////////////////////////

#include<fstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string.h>
#include <windows.h>
#include <conio.h> // getch()

#include<cctype>
#include <ctime>
#include <cstdlib>


#include <iomanip>
using std::setw;// std::setw

#include <array>
using std::array;


#include "Product.h"
#include "Account.h"

using namespace std;



void intro();
void write_account();	
void display_sp(int);	
void modify_account(int);	
void delete_account(int);	
void display_all();		
void deposit_withdraw(int, int); 
	




int main()
{
	char ch;
	int num;

	
	// Constructor Overloading with 
	// different constructors of class name 
	Product product_1;
	Product product_2;

	//Pointer variables
	Product* productPtr = &product_1;
	
	//Reference variables
	//Product & productPtr = product_2;

	const Product item_1;
	cout << item_1.getName();

	//call function intro()	
	intro();

	//do/while loop
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. NEW ACCOUNT";
		cout << "\n\n\t2. DEPOSIT AMOUNT";
		cout << "\n\n\t3. WITHDRAW AMOUNT";
		cout << "\n\n\t4. BALANCE ENQUIRY";
		cout << "\n\n\t5. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t6. CLOSE AN ACCOUNT";
		cout << "\n\n\t7. MODIFY AN ACCOUNT";
		cout << "\n\n\t8. GO TO PRODUCT WEBSITE";
		cout << "\n\n\t9. GO TO SHOOPING CART";
		cout << "\n\n\t10. EXIT";
		cout << "\n\n\tSelect Your Option (1-10) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
			case '1':
				write_account();
				break;
			case '2':
				cout << "\n\n\tEnter the account No. : "; 
				cin >> num;
				deposit_withdraw(num, 1);
				break;
			case '3':
				cout << "\n\n\tEnter the account No. : "; 
				cin >> num;
				deposit_withdraw(num, 2);
				break;
			case '4':
				cout << "\n\n\tEnter the account No. : "; 
				cin >> num;
				display_sp(num);
				break;
			case '5':
				display_all();
				break;
			case '6':
				cout << "\n\n\tEnter the account No. : "; 
				cin >> num;
				delete_account(num);
				break;
			case '7':
				cout << "\n\n\tEnter the account No. : "; 
				cin >> num;
				modify_account(num);
				break;
			case '8':
				cout << "\n\n\tConnect to Product purchase page";
				break;
			case '9':
				cout << "\n\n\tGo to shopping cart page";
				break;
			case '10':
				cout << "\n\n\tThanks for Using Electronic Store Management System";
				break;
			default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	}while (ch != '10');
	
	return 0;
}


//function to write record in binary file
void write_account()
{
	Account acc;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	acc.create_account();
	outFile.write(reinterpret_cast<char*> (&acc), sizeof(Account));
	outFile.close();
}

//function to display account details given by user
void display_sp(int n)
{
	Account acc;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char*> (&acc), sizeof(Account)))
	{
		if (acc.getAccountNo() == n)
		{
			acc.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";
}

//function to modify record of file
void modify_account(int n)
{
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(Account));
		if (ac.getAccountNo() == n)
		{
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modifyData();
			int pos = (-1) * static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(Account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

//function to delete record of file
void delete_account(int n)
{
	Account acc;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&acc), sizeof(Account)))
	{
		if (acc.getAccountNo() != n)
		{
			outFile.write(reinterpret_cast<char*> (&acc), sizeof(Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	cout << "\n\n\tRecord has Deleted";
}

//function to display all account details
void display_all()
{
	//Create an object of Account class
	Account acc;
	ifstream inFile;
	
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&acc), sizeof(Account)))
	{
		acc.report();
	}
	inFile.close();
}

// function to desposit/withdraw amount for given account
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	Account acc;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&acc), sizeof(Account));
		if (acc.getAccountNo() == n)
		{
			acc.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				acc.depositAct(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = acc.getDeposit() - amt;
				if ((bal < 500 && acc.getType() == 'S') || (bal < 1000 && acc.getType() == 'C'))
				{
					cout << "Insufficience balance";
				}
				else
				{
					acc.drawAct(amt);
				}
					
			}
			int pos = (-1) * static_cast<int>(sizeof(acc));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&acc), sizeof(Account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}



//introductory screen function
void intro()
{
	
	cout << "Loading..." << endl;
	Sleep(100);
	char msg[] = "WELCOME TO ELECTRONIC STORE MANAGEMENT SYSTEM";
	int len = strlen(msg);
	int x;
	cout << endl;
	system("CLS");
	
	
}



