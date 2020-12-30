#pragma once
#ifndef _BS_
#define _BS_


#include "Buyer.h"
#include "Seller.h"



class BuyerSeller : public Buyer, public Seller {

public:
	BuyerSeller(const Buyer& buyer, const Seller& seller) :User(buyer.getname(), buyer.getAdress(), buyer.getPass()), Buyer(buyer)
		, Seller(seller) {}
	BuyerSeller(ifstream& infile) :Buyer(infile), Seller(infile),User(infile) {}
	



};

#endif // !_BS_
