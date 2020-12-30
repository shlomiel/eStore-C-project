#include "Seller.h"
#pragma warning(disable : 4996) 

const int max_pass_size = 12;
const int min_pass_size = 8;


Seller::Seller(ifstream& infile) :User(infile) {
}

Seller::Seller(const Seller& seller) : User(seller)

{
	this->products = seller.products;
	this->feedb = seller.feedb;
}


const Seller& Seller::operator+=(const Product& to_add) {
	products.push_back(to_add);
	return *this;
}
const Seller& Seller::operator+=(const feedback& to_add) {
	feedb.push_back(to_add);
	return*this;
}

ostream& operator<<(ostream &os, const Seller& slr)
{
	os << "Name Of Seller :" << slr.getname().data() << "\n" << "Address Of Seller:" << slr.getAdress();

	return os;

}