
#include<iostream>
#include<fstream>
#include<cctype>

// std::setw
#include<iomanip>


#include "Account.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void Account::create_account()
{
	cout << "\nPlease enter the account number: ";
	cin >> accountNo;
	cout << "\n\nPlease enter the name of the account holder: ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter Type of The account (C/S): ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current): ";
	cin >> deposit;
	cout << "\n\n\nThe Account Has Created";
}

void Account::show_account() const
{
	cout << "\nAccount number: " << accountNo;
	cout << "\nAccount Holder Name: " << name;
	cout << "\nType of Account: " << type;
	cout << "\nBalance amount: " << deposit;
}

void Account::modifyData()
{
	cout << "\nAccount No. : " << accountNo;
	cout << "\nModify Account Holder Name: ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nModify Type of Account: ";
	cin >> type;
	type = toupper(type);
	cout << "\nModify Balance amount: ";
	cin >> deposit;
}


void Account::depositAct(int x)
{
	deposit += x;
}

void Account::drawAct(int x)
{
	deposit -= x;
}

void Account::report() const
{
	cout << accountNo << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}


int Account::getAccountNo() const
{
	return accountNo;
}

int Account::getDeposit() const
{
	return deposit;
}

char Account::getType() const
{
	return type;
}