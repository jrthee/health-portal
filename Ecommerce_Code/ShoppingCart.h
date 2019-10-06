#pragma once

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h"
#include <iostream>
using namespace std;

class ShoppingCart 
{
	public:
		// Constructors
		ShoppingCart();
		
		void addItem(Product*);
		double totalPrice();

	private:
		Product* itemArray[100];
		int arraylist;

};
#endif