#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using std::string;

class Product 
{
	
	public:
		//default Constructor with no parameters 
		Product();

		//Constructor with three parameters 
		Product(int, string, int);

		//function to set names
		void setName(string);

		//function to set price
		void setPrice(double);

		//function to set quantity
		void setQuantity(int);

		//function to get names
		string getName() const;

		//function to get price
		double getPrice() const;

		//function to get quantity
		int getQuantity() const;


		void display() const;
		
		// static member function
		static int getValue();

	private:
		int id;
		string name;
		double price;
		int quantity;

		//declaration for a static member
		//static int s_value;
		
};

#endif

