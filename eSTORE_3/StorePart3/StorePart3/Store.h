#pragma once
#ifndef _STORE_
#define _STORE_
#include "Array.h"
#include <string>
#include <typeinfo>
#include <iostream>

class User;
class Buyer;
class Seller;
class BuyerSeller;

class eStore {
private:
	string store_name;

	Array<User*> users;
private:
	int all_users = 0;

public://Constructors
	eStore(const string name);
	eStore(const eStore& store);

	//operators
	bool operator+=(Seller& slr);
	bool operator+=(Buyer& byr);




	//set methods
	void Setname(const string name);

	//get methods
	inline string getname() const { return store_name; };

	//

	bool Add_User(User* user);//Add user to the store , returns true if added successfuly false otherwise

	void StartMenu(); // Starts multii-choice menu

	int getTotalNumberOfProducts() const;//Returns the total number of products in the store 

	Seller* GetSellerByName(string username); //Recieves a sellers name and returns a pointer to the seller data type
	Buyer* GetBuyerByName(string username);  ////Recieves a buyers name and returns a pointer to the buyer data type
	int get_num_ofall() const { return this->all_users; };
	User* get_input();

	void load_users();


	void option1();  //Add buyer  to store
	void option2();  //Add seller to store
	void option3();  //Add a product to an existing seller
	void option4();  //Provide feedback on a seller
	void option5();  //Add a product to your shoping cart
	void option6();  //Make an order
	void option7();  //Pay for an order
	void option8();  //Show names and addresses of all the customers
	void option9();  //Show names and addresses of all the sellers
	void option10(); //Search for a product by name
	void option11();//exit and save data 
	void option12();//add buyer-seller	
	void option13();//search a buyer-seller


	void option14();//add seller with +=	
	void option15();//add bueyr with +=

	void option16();//compare shoppping carts 
	void option17();//print with << (buyers info,sellers,address)


};

#endif
