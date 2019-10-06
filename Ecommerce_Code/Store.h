#pragma once

#ifndef STORE_H
#define STORE_H

#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>

#include <conio.h>
#include <string.h>
#include <windows.h>

#define WINWIDTH 113
#define WINHEIGHT 15

#include "Customer.h"
#include "Product.h"

using std::string;

class Store
{
	
	public:
		
		//default Constructor with no parameters 
		Store();
		
		void add();
				
		void display() const;
		
		int getrecs();
		
		void modify();
		
		void PrintBill();

		Product[] getProducts();
		
		void deleteproduct();
		
		void SearchProduct();
		
		void totalprinter();

		void exitscreen();

		void filler();

		void liner();

		~Store();
		

	private:
		std::list<int> obj;
		int t;
		string pname;
		int pid;
		double price;
		int tquant;
		int aquant;
		int rack;
		char filename[50];
		Product products[20];

};
#endif
