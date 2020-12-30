#pragma once
#ifndef _UserG_
#define _UserG_
class User;
#include <fstream>
using namespace std;


class UserGenerator {
public:
	enum usertype{BUYER,SELLER,BUYERSELLER};
	static User* load_user(ifstream& infile);
	static usertype get_type(const User * user);
};


#endif