#pragma once
#ifndef _Seller_
#define _Seller_
#include<iostream>
#include "User.h"
#include "vector"
#include "FEEDBACK.h"
#include "Product.h"

using namespace std;
class Seller : virtual public User {
public:
	// Constructors
	Seller(string name, string password, const  Adress& adr) :User(name, adr, password) {}
	Seller(const Seller& b);
	Seller(ifstream& infile);

private:
	vector<Product> products;
	vector<feedback> feedb;

public:


	friend ostream& operator<<(ostream &os, const Seller& slr); // Prints buyer name 

	const Seller& operator+=(const Product& to_add);
	const Seller& operator+=(const feedback& to_add);



	vector<Product> getproducts()const { return products; };
	vector<feedback> get_feedbacks()const { return this->feedb; };

	int  getCurrentProducts()const { return products.size(); };




};
#endif	
