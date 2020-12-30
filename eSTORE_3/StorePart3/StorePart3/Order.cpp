#include"Order.h"
#include"Buyer.h"
#include "Seller.h"
#include "product.h"
#include "User.h"
#pragma warning(disable : 4996)


Order::Order(float price, const string buyer_name, vector<Product> products)
{
	set_buyername(buyer_name);
	set_totalprice(price);

	this->products = products;

	vector<Product>::const_iterator begin = products.begin();
	vector<Product>::const_iterator end = products.end();

	for (; begin != end; begin++) {
		seller_names.insert(begin->get_sellername());
	}

}



void Order::set_buyername(const string buyer_name) {
	this->buyer_name = buyer_name;
}
void Order::set_totalprice(const float price) {
	this->total_price = price;

}
