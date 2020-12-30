#pragma warning(disable : 4996)

#include "User.h"
#include "UserGenerator.h"
const int max_pass_size = 12;
const int min_pass_size = 8;



User::User(string name, const Adress adress, string password)throw(const string) :adress(adress), name(name)

{
	if (password.size() > max_pass_size || password.size() < min_pass_size) {
		throw std::string("Invalid Password");
	}
	this->password = password;

}

User::User(const User& user) :adress(user.adress), password(user.password), name(user.name)
{
}

User::~User() {
}
User::User(ifstream& in) :adress(in) {
	in >> name;
	in >> password;



}

const User& User::operator=(User&&other) 

{
	
	if (this != &other) {
		this->name = other.name;
		this->password = other.password;
	}
	return *this;
}
const User& User:: operator=(const User& other) {

	if (this != &other) {
		this->name = other.name;
		this->password = other.password;
	}
	return *this;
}
User::User(User&& other):adress(other.adress)  {
	this->name = other.name;
	this->password = other.password;
}
ostream& operator<<(ostream& os, const User& user)
{
	if (typeid(os) == typeid(ofstream))
		os << (int)UserGenerator::get_type(&user) << " " << user.adress << " " << user.name << " " << user.password << " ";
	else//(typeid( os ) == typeid( ostream ))
		os << typeid(user).name() + 6 << " --> \name: " << user.name << ", Password: " << user.password << ",Address: " << user.adress << " ";

	return os;
}

