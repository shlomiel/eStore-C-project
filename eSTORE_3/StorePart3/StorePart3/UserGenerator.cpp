#include "UserGenerator.h"
#include "BuyerSeller.h"
#include "Buyer.h"
#include "Seller.h"

User* UserGenerator::load_user(ifstream& infile) {

	usertype type;
	int t;
	infile >> t;
	
	type = (usertype)t;
	if (type == BUYER) {
		return new Buyer(infile);
		
	}
		
	if (type == SELLER)
		return new Seller(infile);
	if (type == BUYERSELLER)
		return new BuyerSeller(infile);
	else
		return nullptr;


}

UserGenerator::usertype UserGenerator::get_type(const User * user) {
	if (typeid(*user) == typeid(Buyer))
		return BUYER;
	if (typeid(*user) == typeid(Seller))
		return SELLER;
	else
		return BUYERSELLER;
}