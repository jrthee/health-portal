
#include "ShoppingCart.h"
#include "Product.h"
#include <iostream>



ShoppingCart::ShoppingCart() 
{
	//arraylist = 0;
}

void ShoppingCart::addItem(Product* currentItem) {
	itemArray[arraylist] = currentItem;
	arraylist++;
}

double ShoppingCart::totalPrice() {
	double totalPrice = 0.0;

	for (int i = 0; i < 100; i++) {
		if (itemArray[i] != NULL) {
			totalPrice += itemArray[i]->getPrice() * itemArray[i]->getQuantity();
		}
		else {
			break;
		}
	}

	return totalPrice;
}


/*
for (int i = 0; i < 100; i++) {
	itemArray[i] = { NULL };
}

*/