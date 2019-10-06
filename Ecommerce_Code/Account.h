#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
	
	public:
		//Account();
		
		//function to get data from user
		void create_account();	
		
		//function to show data on screen		
		void show_account() const;	
		
		//function to add new data
		void modifyData();	
		
		//function to accept amount and add to balance amount
		void depositAct(int);	
		
		//function to accept amount and subtract from balance amount
		void drawAct(int);	
		
		//function to show data in tabular format
		void report() const;	
		
		//function to return account number
		int getAccountNo() const;	
		
		//function to return balance amount
		int getDeposit() const;	
		
		//function to return type of account
		char getType() const;	

	private:
		int accountNo;
		char name[50];
		int deposit;
		char type;
};

#endif
