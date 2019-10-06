

#include <iostream>
#include "Product.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Product::Product()
{
	id = 0;
	name = "";
	price = 0.0;
	quantity = 0;
}

Product::Product(int pId, string pName, int pPrice) 
{
	this->id = pId;
	this->name = pName;
	this->price = pPrice;
}


void Product::setName(string prodName) 
{
	name = prodName;
}

//function to get names
string Product::getName() const
{
	return name;
}

/*const
void Product::getName() const {
	cout << name;
}
*/

void Product::setPrice(double itemPrice) 
{
	price = itemPrice;
}

double Product::getPrice() const
{
	return price;
}

void Product::setQuantity(int itemQuantity) 
{
	quantity = itemQuantity;
}

int Product::getQuantity() const
{
	return quantity;
}

//function to print name and price
void Product::display() const {
	cout << id << " " << name << " " << price << endl;
}

/*
int Product::getValue()
{
	return(Product::getValue());
}





//The definition of the static function outside of the class. 
int Product::getValue()
{
	return s_value++;
}

*/