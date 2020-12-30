#pragma once
#ifndef _ORDER_
#define _ORDER_
using namespace std;
#include<iostream>
#include <vector>
#include <set>

#include "Product.h"
class Buyer;
class Seller;

class Order {
public:
	Order() = default;// Constructors
	Order(float price, string buyer_name, vector <Product> products);
	vector <Product> products;
	set<string>seller_names;


private:
	float total_price;
	string buyer_name;
	bool paid = false;


public:

	//get methods
	float get_total_price()const { return total_price; };
	vector <Product> get_products()const { return products; };
	string getbuyer_name() { return buyer_name; };
	bool Is_paid() { return paid; };
	set<string> get_seller_names() { return seller_names; };

	//set methods
	void set_totalprice(const float price);
	void set_buyername(string buyer_name);
	void set_paid() { this->paid = true; };


};

#endif

