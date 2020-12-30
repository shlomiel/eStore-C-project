//Shlomi Eliyahu 203435896
//Artium Kuznetsov 324373828
//Group A , Keren , Sunday 10:15-12:45

#include "Store.h"
#include<iostream>
#include "Adress.h"
#include "Buyer.h"
#include "Seller.h"
#include "FEEDBACK.h"
#include "product.h"
#include "Order.h"
using namespace std;
int const max_store_name = 100;
int main() {
	string store_name;
	cout << "Please enter the store's name \n";
	getline(cin, store_name);

	eStore s1(store_name);



	s1.StartMenu();




}