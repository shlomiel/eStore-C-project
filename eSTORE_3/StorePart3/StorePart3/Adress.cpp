#pragma warning(disable : 4996)
#include "Adress.h"



Adress::Adress(string street, string city, string country, int house_num) throw(const string) : house_num(house_num), street(street), city(city), country(country)
{
	if (house_num < 0)
		throw std::string("Invlaid House number!\n");

	for (string::iterator i = street.begin(); i != street.end(); i++) {
		if ((*i < 'A' || (*i > 'Z' && *i < 'a') || *i>'z') && *i != ' ')
			throw std::string("Invalid Street!\n");

	}

	for (string::iterator i = city.begin(); i != city.end(); i++) {
		if ((*i < 'A' || (*i > 'Z' && *i < 'a') || *i>'z') && *i != ' ')
			throw std::string("Invalid City!\n");

	}

	for (string::iterator i = country.begin(); i != country.end(); i++) {
		if ((*i < 'A' || (*i > 'Z' && *i < 'a') || *i>'z') && *i != ' ')
			throw std::string("Invalid Country!\n");

	}

}

const Adress& Adress:: operator=( Adress &&other) {
	this->country = other.country;
	this->city = other.city;
	this->street = other.street;
	this->house_num = other.house_num;
	return *this;
}
const Adress& Adress:: operator=(const Adress &other) {
	this->country = other.country;
	this->city = other.city;
	this->street = other.street;
	this->house_num = other.house_num;
	return *this;
}
Adress::Adress(ifstream& in) {
	in >> country;
	in >> city;
	in >> street;
	in >> house_num;
}

//Get methods

const string Adress::Get_street()const
{
	return street;
}

const int Adress::Gethouse_num()const
{
	return house_num;
}
const string Adress::Get_City()const
{
	return city;
}
const string Adress::Get_country()const
{
	return country;
}




ostream&  operator<< (ostream &os, const Adress& adr)
{
	if (typeid(os) == typeid(ofstream))
		os << adr.country << " " << adr.city << " " << adr.street << " "<< adr.house_num << " ";
	else//(typeid( os ) == typeid( ostream ))
		os << "Country :" <<adr.country  << "\n" << "City:" << adr.city << "\n" << "Street" <<adr.street << "\n" << "House Number:" << adr.house_num << endl;
	
	return os;

}
