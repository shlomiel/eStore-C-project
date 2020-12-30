#pragma warning(disable : 4996)

#include "Buyer.h"
#include "Seller.h"
#include "FEEDBACK.h"


const int max_pass_size = 12;
const int min_pass_size = 8;

Buyer::Buyer(const Buyer& buyer) : User(buyer) {

	this->shopping_cart = buyer.shopping_cart;
	this->orders = buyer.orders;

}
Buyer::Buyer(ifstream& infile) :User(infile) {}



const Buyer& Buyer:: operator+=(const Product& to_add) {
	shopping_cart.push_back(to_add);
	return *this;
}

const Buyer& Buyer:: operator+=(const Order& to_add) {
	orders.push_back(to_add);
	return *this;
}



bool Buyer::send_feedback(Seller& seller) {


	vector<Order>::iterator begin = orders.begin();
	vector<Order>::iterator end = orders.end();

	for (; begin != end; begin++){
		set<string>::iterator begin_names = begin->seller_names.begin();
		set<string>::iterator end_names = begin->seller_names.end();
		for (; begin_names != end_names; begin_names++) {
			if (begin_names->compare(seller.getname()) == 0) {//Only possible to leave feedback if 
				feedback* feed = new feedback(this->name);    //coustomer bought from the seller
				seller += *feed;
				return true;
			}
		}

	}
	return false;





}

void Buyer::makeorder() {
	float price = 0;



	Order* neworder = new Order(getTotalCartPrice(), this->getname(), shopping_cart);
	*this += (*neworder);


}

float Buyer::getTotalCartPrice()const
{
	float price =0;
	vector<Product>::const_iterator begin = shopping_cart.begin();
	vector<Product>::const_iterator end = shopping_cart.end();
	for (; begin != end; begin++) {
		price += begin->getprice();
	}

	return price;
}



void Buyer::pay() {
	
	orders.back().set_paid();
	shopping_cart.clear();
}


bool Buyer::operator>(const Buyer& byr1) const
{
	return (this->getTotalCartPrice() > byr1.getTotalCartPrice());

}


ostream& operator<<(ostream& os, const Buyer& byr)
{
	os << "Name Of Buyer :" << byr.getname() << "\n" << "Address Of Buyer :" << byr.getAdress();

	return os;
}