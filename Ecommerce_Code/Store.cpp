

#include <iostream>
#include <iomanip>

#include <conio.h>
#include <string.h>
#include <windows.h>

#include <list> 
#include <iterator>

#include <string>



#include "Store.h"

#define WINWIDTH 113
#define WINHEIGHT 15

using namespace std;


Store::Store()
{
	t = 0;
	obj.ReadFromFile(obj);
}

void Store::add()
{
	system("CLS");
	cout << "\n\t\t\t[press enter after each details]";
	cout << "\nEnter Product name" << endl;
	cin >> pname;

	cout << "\nEnter Product id" << endl;
	cin >> pid;

	cout << "\nEnter Price" << endl;
	cin >> price;

	cout << "\nEnter Total Qty" << endl;
	cin >> tquant;

	cout << "\nEnter Available Qty" << endl;
	cin >> aquant;

	cout << "\nEnter Rack No" << endl;
	cin >> rack;

	//cout << "\nEnter Product name, Product id, Price, Total Qty, Available Qty, Rack No" << endl;
	//cin >> pname >> pid >> price >> tquant >> aquant >> rack;

	obj.add_end(pname, pid, price, tquant, aquant, rack);
}
	
void Store::display() const
{
	
}
	
int Store::getrecs()
{
	return obj.recsnum();
}

void Store::modify()
{
	
}
	
void Store::PrintBill()
{
	system("CLS");
	int choice;
	char sname[] = { "Product Name" };
	char name[30];
	int quantity;
	cout << "\n\nEnter filename for bill with full path and file extension : ";
	cin >> filename;
	FILE* fp;
	fp = fopen(filename, "a");
	for (int i = 0; i < 70; i++)
	{
		fprintf(fp, "*");
	}
	fprintf(fp, "\n");
	//brought to you by code-projects.org
	fprintf(fp, "%-30s\tQty.\tPrice/item\tAmount\n", sname);

	for (int i = 0; i < 70; i++)
	{
		fprintf(fp, "*");
	}
	fprintf(fp, "\n");
	fclose(fp);
	while (1)
	{
		cout << "\nContinue Purchasing Product ?\n1 = yes , 2 = no" << endl;
		cout << "choice : ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nEnter product name and quantity : " << endl;
			cin >> name >> quantity;
			obj.billgen(filename, name, quantity, t);
		}
		else
			break;
	}
	fp = fopen(filename, "app");

}

Product::Product[] getProducts();

void Store::deleteproduct()
{
	system("CLS");
	char name[30];
	cout << "\n\nEnter name of product : ";
	cin >> name;
	obj.delete_node(name);
}
	
void Store::SearchProduct()
{
	obj.Search();
}
	

void Store::totalprinter()
{
	FILE* fp;
	fp = fopen(filename, "a");
	fprintf(fp, "\n");
	for (int i = 0; i < 70; i++)
	{
		fprintf(fp, "*");
	}


	fprintf(fp, "\n");

	for (int i = 0; i < 70; i++)
	{
		fprintf(fp, "*");
	}
	fprintf(fp, "\n");
	fprintf(fp, "Total = %d\n", t);
	for (int i = 0; i < 70; i++)
	{
		fprintf(fp, "*");
	}
	fprintf(fp, "\n");
	fclose(fp);
}

void Store::filler()
{
	for (int i = 0; i < WINWIDTH; i++)
	{
		cout << "*";
	}
	cout << "\a" << endl;
}

void Store::liner()
{
	for (int i = 0; i < WINHEIGHT; i++)
		cout << endl;
}

void Store::exitscreen()
{
	system("CLS");
	char msg[] = "Brought To You By code-projects.org";
	int len = strlen(msg);
	int x;
	x = (WINWIDTH / 2) - (len / 2);
	liner();
	filler();
	cout << setw(len + x) << msg << endl;
	filler();
}

Store::~Store()
{
	cout << "Number of records = " << obj.getcount() << endl;
	obj.SaveToFile();
	exitscreen();
}