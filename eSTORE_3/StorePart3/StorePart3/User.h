#pragma once
#ifndef _User_
#define _User_

#include "Adress.h"
#include <iostream>

class User {

protected:
	string name;
    const Adress adress;
	string password;

public:
	//constructors
	
	User(string name,  const Adress adress, string password) throw(const string);
	User(const User& other);
	User(User&& other);
	User(ifstream& in);
	virtual ~User();//destructor

	//operators
	friend ostream& operator<<(ostream& os, const User& shape);
	virtual const User& operator=(User&& other);
	virtual const User& operator=(const User& other);

		//getters
	const string getname()const { return name; };
	const string getPass()   const { return password; };
	const Adress getAdress()   const { return adress; };

};

#endif
