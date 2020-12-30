#pragma once
#ifndef _Prod_
#define _Prod_
#include<iostream>
using namespace std;
enum eProduct { KIDS, ELECTRICITY, OFFICE, CLOTHING, DEFAULT };
class Buyer;
class Seller;

class Product
{

public:
	Product();// Constructors
	Product(eProduct type, string name, float price, string seller_name) :name(name),seller_name(seller_name)
	{
		id = ++counter;
		this->type = type;
		this->price = price;

	};
	Product(const Product& prod);
 
private:
	eProduct type;
	string name;
	float price;
	static int counter;
	int id;
	string seller_name;

public:
	//set methods

	void set_type(eProduct type);
	void set_price(float pricec);;

	//get methods

	int getid()const;
	float getprice()const;
	string getname()const;
	eProduct gettype()const;
	string get_sellername()const { return seller_name; };

	//print product details
	void PrintProduct_Details();



};



#endif