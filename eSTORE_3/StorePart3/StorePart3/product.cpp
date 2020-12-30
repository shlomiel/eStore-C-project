#pragma warning(disable : 4996) 
#include "Product.h"
#include "Seller.h"
#include "Buyer.h"
int Product::counter = 0;
Product::Product() {
	price = 0;
	type = (enum::eProduct)4;
	id = ++counter;
}



Product::Product(const Product& prod) : name(prod.name),seller_name(prod.seller_name){
	
	this->price = prod.getprice();
	this->id = prod.getid();
	this->type = prod.gettype();
}




void Product::set_price(float price)
{
	this->price = price;
};
void Product::set_type(eProduct type)
{
	this->type = type;
};

float Product::getprice()const
{
	return price;
}


string Product::getname()const
{
	return name;
}

eProduct Product::gettype()const
{
	return type;
}

int Product::getid()const
{
	return id;
}








void Product::PrintProduct_Details() {
	cout << "ID : " << this->getid() << endl;
	cout << "name :" << this->getname() << endl;
	cout << "Price:" << this->getprice() << endl;
	cout << "type :" << this->gettype() << endl;
}


