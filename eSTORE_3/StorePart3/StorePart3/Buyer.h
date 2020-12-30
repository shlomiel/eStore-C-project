#pragma once

#ifndef _Buyer_
#define _Buyer_



#include <vector>
#include "Product.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include "User.h"
using namespace std;

class Buyer : virtual public User {

public:
	Buyer(string name, string password, const Adress& adr) :User(name, adr, password) {}
	Buyer(const Buyer& b);
	Buyer(ifstream& infile);


private:
	vector<Product> shopping_cart;
	vector<Order> orders;
public:
	//operators
	bool operator>(const Buyer& byr1) const;
	friend ostream& operator<<(ostream &os, const Buyer& byr); // Prints buyer name 
	const Buyer& operator+=(const Product& to_add);//Add product to shopping cart
	const Buyer& operator+=(const Order& to_add);//Add order to order array


	//get methods

	unsigned int getnumof_orders() { return this->orders.size(); };
	vector<Order> get_currentorders() { return orders; };
	vector<Product> getproducts()const { return shopping_cart; };
	unsigned int getCurrentProd()const { return shopping_cart.size(); };//returns number of products in shopping cart
	float getTotalCartPrice()const; //returns total price of products in shopping cart

	bool send_feedback(Seller& seller);//Send feedback on a seller
	void makeorder(); //Make an order , move all products from cart to order status
	void pay(); // Pay for existing order

};


#endif 