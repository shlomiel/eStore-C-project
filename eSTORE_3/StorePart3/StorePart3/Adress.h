#pragma once

#ifndef _ADR_
#define _ADR_
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Adress {

private:
	string street, city, country;
	int house_num;

public:

	// Constructors
	Adress(string street, string city, string country, int house_num) throw(const string); 
	Adress() = default;
	Adress(const Adress& adr) :house_num(adr.house_num), street(adr.street), city(adr.city), country(adr.country) {};
	Adress(ifstream& in);
		

	friend ostream& operator<<(ostream &os, const Adress& adr);
	virtual const Adress& operator=( Adress &&other);
	virtual const Adress&  operator=(const Adress &other);


	//get methods

	const string Get_street()const;
	const int Gethouse_num()const;
	const string Get_City()const;
	const string Get_country()const;

};
#endif
