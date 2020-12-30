#pragma warning(disable : 4996)
#include "Store.h"
#include "Product.h"
#include "Order.h"

#include "User.h"

#include "BuyerSeller.h"
#include "UserGenerator.h"
using namespace std;



eStore::eStore(const string name) {
	Setname(name);
	users= Array<User*>(1);
	
	

}
eStore::eStore(const eStore& other) {
	this->store_name = other.store_name;
	if (other.get_num_ofall() > 0) {

		(*this).users = other.users;
	}

	else
	{
		users = nullptr;
	}

}

bool eStore::Add_User(User *user) {

	//lets check if user is either seller buyer or both . 

	Buyer *buyer = dynamic_cast<Buyer*>(user);
	Seller *seller = dynamic_cast<Seller*>(user);
	BuyerSeller* buyerseller = dynamic_cast<BuyerSeller*>(user);

	//if (users.getArr() != NULL) {
	for (int i = 0; i < all_users; i++) {//same user isnt allowed
		if (users.getArr()[i]->getname().compare(user->getname()) == 0) {
			return false;
		}
	}

	users += user;
	++all_users;
	return true;
	

}



void eStore::Setname(const string name) {

	this->store_name = name;
}



Buyer* eStore::GetBuyerByName(string username)
{
	if (!this->users.getArr())
		return nullptr;


	for (int i = 0; i < this->all_users; i++) {

		{
			if ((this->users.getArr()[i]->getname().compare(username) == 0) && dynamic_cast<Buyer*>(users.getArr()[i]))
				return dynamic_cast<Buyer*>(users.getArr()[i]); // buyer exsit in store 
		}

	}
	return nullptr;  // no buyer of that username

}



Seller* eStore::GetSellerByName(string username)
{
	if (!this->users.getArr())
		return nullptr;


	for (int i = 0; i < this->all_users; i++)
	{
		if ((this->users.getArr()[i]->getname().compare(username) == 0) && dynamic_cast<Seller*>(users.getArr()[i])) {
			return dynamic_cast<Seller*>(users.getArr()[i]);   // seller exsit in store 
		}
	}



	return nullptr;// no seller of that username
}

User* eStore::get_input() {//get input from user
	string username;
	string password;
	string street;
	string city;
	string country;
	int housenum;
	cin.ignore();
	getline(cin, username);
	cout << "Insert password(8 - 12 CHARACTERS) :\n";
	getline(cin, password);
	cout << "Please enter the adress :\n" << "Enter street :\n";
	getline(cin, street);
	cout << "Enter city :\n ";
	getline(cin, city);
	cout << "Enter country :\n ";
	getline(cin, country);
	cout << "Enter house number :\n ";
	cin >> housenum;

	try {
		Adress *address = new Adress(street, city, country, housenum);
		User *new_user = new User(username, *address, password);
		return new_user;

	}
	catch ( const std::string msg) {
		cout << msg;
		return nullptr;


	}
}


void eStore::option11() {//save data to text file

	string filename = "users.txt";
	ofstream outFile(filename, ios::trunc);

	outFile << all_users << " ";
	for (int i = 0; i < all_users; ++i)
		outFile << *users.getArr()[i];

	outFile.close();
	
}

void eStore::load_users() {//laod users from file 
	string filename = "users.txt";
	ifstream in_file;
	in_file.open(filename, ios::in);
	in_file >>all_users;

	User * input;
	
	for (int i = 0; i < all_users; ++i)
		users += UserGenerator::load_user(in_file);
		

	in_file.close();

}


void eStore::option1()
{	cout << "Please provide us with the buyers name :\n";

	User* input = get_input();//gets input from user 1. if no error occures returns user
	                                                 //2.else nullptr, function does nothing except returning a message

	if (input != nullptr) {
		Buyer* new_b = new Buyer(input->getname(), input->getPass(), input->getAdress());
		if (this->Add_User(new_b))
			cout << "Buyer added successfully\n";

		else
			cout << "Buyer add failed -  username allready exist in system\n";

	}

}




void eStore::option2()
{
	cout << "Please provide us with the sellers name :\n";

	User* input = get_input();

	if (input != nullptr) {
		input = new Seller(input->getname(), input->getPass(), input->getAdress());
		if (this->Add_User(input))
			cout << "Seller added successfully\n";

		else
			cout << "Seller add failed -  username allready exist in system\n";

	}
}



void eStore::option3()
{
	string username;
	string productname;
	float price;

	int type;//eProduct

	cin.ignore();
	cout << "Please enter the name of the seller you wish to add a product to: \n";
	getline(cin, username);
	Seller* slr = this->GetSellerByName(username);//if exists
	if (!slr) {

		cout << "There is no such seller in the store";

	}

	else {
		cout << "enter product type KIDS(0), ELECTRICITY(1), OFFICE(2), CLOTHING(3), DEFAULT(4): \n";
		cin >> type;
		if (0 > type || type > 4) {
			cout << "Invalid catergory choosen (numbers between 0 and 4 Only)\n";
			return;
		}
		cin.ignore();
		cout << "enter product name: \n";
		getline(cin, productname);
		cout << "enter product price: \n";
		cin >> price;

		if (price < 0)
		{
			cout << "Price cannot be negative\n";
			return;
		}


		Product theproduct((eProduct)type, productname, price, slr->getname());

		*slr += theproduct;
		cout << "Product added successfully\n";
	}

}

void eStore::option4()
{
	cin.ignore();
	string buyer_username;
	string productname;
	string seller_name;
	Seller* slr;
	Buyer* byr;
	cout << "Please enter your username :" << endl;
	getline(cin, buyer_username);
	byr = this->GetBuyerByName(buyer_username);
	if (!byr) {
		cout << "No Buyer of that names exists\n";
	}

	else {
		cout << "Please enter the name of the seller you wish to leave a feedback on :\n";
		getline(cin, seller_name);
		slr = this->GetSellerByName(seller_name);

		if (!slr)
			cout << "No seller of that names exists\n";



		//verify seller matches buyer 

		else {
			if (!byr->send_feedback(*slr)) {
				cout << "You cant leave feedback unless you bought from that seller" << endl;
			}
			else {
				cout << "You sent the feedback successfully" << endl;
			}

		}
	}

}

int eStore::getTotalNumberOfProducts() const
{
	int res = 0;
	if (this->users.getArr() == nullptr) {
		return 0;
	}


	else {
		for (int i = 0; i < all_users; i++) {
			Seller *temp = dynamic_cast<Seller*>(users.getArr()[i]);
			if (temp)
				res += temp->getCurrentProducts();

		}
		return res;
	}
}

void eStore::option5()
{
	cin.ignore();
	string username;
	cout << "Please enter your username :\n";
	getline(cin, username);

	Buyer* byr = GetBuyerByName(username);
	if (!byr) {
		cout << "No Username in the system matches this name \n";
		return;
	}
	if (byr->getnumof_orders() > 0) {
		if (!byr->get_currentorders().back().Is_paid())
		{
			cout << "Can`t add any more products to cart until your current order is paid for.\n";
			return;
		}
	}

	int type, index = 0, counter = 1, selection;
	cout << "Please choose a catergory KIDS(0), ELECTRICITY(1), OFFICE(2), CLOTHING(3), GENERAL(4) : \n";
	cin >> type;
	if (0 > type || type > 4) {
		cout << "Invalid catergory choosen (numbers between 0 and 4 Only)\n";
		return;
	}
	vector<Product> Productz4You;



	if (0 == all_users) {//buyer shouldnt know if there are sellers or not
		cout << "Sorry,There are no products of that type in the store at the time .\n";
		return;
	}


	for (int i = 0; i < all_users; i++) {
		Seller* slr = dynamic_cast<Seller*>(users.getArr()[i]);
		if (slr) {
			int seller_numofprod = slr->getCurrentProducts();
			for (int j = 0; j < slr->getCurrentProducts(); j++) {
				if (slr->getproducts()[j].gettype() == (eProduct)type) {
					Productz4You.push_back(slr->getproducts()[j]);
					index++;

				}

			}
		}
	}
		if (index == 0) {
			cout << "Sorry,There are no products of that type in the store at the time .\n";
		}
		else {
			cout << "Please choose a product (enter product number):\n";
			vector<Product>::const_iterator begin = Productz4You.begin();
			vector<Product>::const_iterator end = Productz4You.end();
			for (; begin != end; begin++) {
				cout << counter << ")" << begin->getname() << " price: " << begin->getprice() << endl;
				cout << "Seller : " << begin->get_sellername() << endl;
				counter++;
			}
			cin >> selection;
			if (selection < 1 || selection > index) {
				cout << "Invalid selection , please choose a product from the list\n";
				return;
			}
			*byr += Productz4You[selection - 1];
			cout << "Product added to cart successfuly\n";
		}
	
}


void eStore::option6()
{
	cin.ignore();
	string username;
	cout << "Please enter your username :\n";
	getline(cin, username);
	Buyer* byr = GetBuyerByName(username);
	if (!byr) {
		cout << "no user of that name exists " << endl;
		return;
	}
	if (byr->getnumof_orders() != 0) {
		vector<Order> ordr = byr->get_currentorders();
		int num_of_orders = byr->getnumof_orders();

		if (ordr[num_of_orders - 1].Is_paid() == false) {
			cout << "you must complete you'r current order first\n";
			return;
		}
	}



	if (byr->getCurrentProd() == 0) {
		cout << "Sorry,But it seems you dont have any products in your shopping cart" << endl;;
		return;
	}
	cout << "Here is your shopping cart :\n";
	vector<Product> byr_products = byr->getproducts();
	vector<Product>::const_iterator begin = byr_products.begin();
	vector<Product>::const_iterator end = byr_products.end();
	for (; begin != end; begin++) {
		cout << "  Product : " << begin->getname() << "  Price : " << begin->getprice() << endl;
	}

	cout << "Total price is :" << byr->getTotalCartPrice() << endl;

	byr->makeorder();
	cout << "Order is succesfull" << endl;

}


void eStore::option7()
{
	cin.ignore();
	string username;
	cout << "Please enter the username you wish to pay for : \n";
	getline(cin, username);
	Buyer* byr = GetBuyerByName(username);


	if (!byr) {
		cout << "no user of that name exists \n";
		return;
	}

	if (byr->getnumof_orders() == 0) {
		cout << "No current orders to pay for\n";
		return;
	}


	if (byr->getTotalCartPrice() == 0) {
		cout << "No current orders to pay for\n";
		return;
	}





	if (!(byr->get_currentorders().back().Is_paid()))
	{
		cout << byr->getTotalCartPrice() << " Will be charged from your account thank you \n";
		byr->pay();

		cout << "Payment successful \n";
		return;
	}


	else {
		cout << "No current orders to pay for\n";
	}

}

void eStore::option8()
{

	int count = 0;
	if (all_users == 0) {
		cout << "Sorry,There are no customers registered at this time\n ";
		return;
	}
	else {
		Buyer *byr;
		
		for (int i = 0; i < all_users; i++)
		{
			byr = dynamic_cast <Buyer*>(users.getArr()[i]);
			if (byr) {
				cout << "Here Are the names and adresses of all our customers :\n";
				cout << "Customer name : " << byr->getname();

				cout << "  Customer adress : ";
				cout << byr->getAdress() << endl;
				count++;
			}
		}
	}
	if (count == 0)
		cout << "Sorry there are no customers registered right now \n ";
}


void eStore::option9()
{


	int count = 0;
	if (all_users == 0) {
		cout << "Sorry there are no sellers registered right now \n ";
		return;
	}
	else {
		Seller *slr;
		for (int i = 0; i < all_users; i++)
		{
			slr = dynamic_cast <Seller*>(users.getArr()[i]);
			if (slr) {
				cout << "Here Are the names and adresses of all our sellers :\n";
				cout << "Seller name : " << slr->getname() << endl;

				cout << "  Seller adress : ";
				cout << slr->getAdress() << endl;
				count++;
			}
		}
	}
	if(count==0)
		cout << "Sorry there are no sellers registered right now \n ";

}


void eStore::option10()//product by name
{
	cin.ignore();
	string productname;
	cout << "Please enter product name : \n";
	getline(cin, productname);
	int current_products = this->getTotalNumberOfProducts();
	int index = 0;
	bool flag = false;
	if (current_products == 0) {
		cout << "Sorry,There are no products of that name in the store at the time .\n";
	}

	else {
		Seller *slr;
		vector<Seller>sellerz;
		int slr_size = 0;

		for (int i = 0; i < all_users; i++)
		{
			slr = dynamic_cast <Seller*>(users.getArr()[i]);
			if (slr)
			{
				sellerz.push_back(*slr);
			}
		}


		cout << "Loading our selection of " << productname << " ..." << endl;
		vector<Seller>::iterator begin = sellerz.begin();
		vector<Seller>::iterator end = sellerz.end();
		for (; begin != end; begin++) {
			int seller_numofprod = begin->getCurrentProducts();
			for (int j = 0; j < seller_numofprod; j++) {
				if (begin->getproducts()[j].getname().compare(productname) == 0) {
					cout << "Price : " << begin->getproducts()[j].getprice();
					cout << "  Seller : " << begin->getname() << endl;
					flag = true;
				}

			}
		}
		if (!flag)
			cout << "Sorry,There are no products of that name in the store at the time .\n";



	}

}

void eStore::option12()//Add Buyer-Seller
{

	cout << "Please provide us with the Buyer-sellers name :\n";

	User* input = get_input();

	if (input != nullptr) {
		Buyer* buyr = new Buyer(input->getname(), input->getPass(), input->getAdress());
		Seller* slr = new Seller(input->getname(), input->getPass(), input->getAdress());
		input = new BuyerSeller(*buyr, *slr);
		if (this->Add_User(input))
			cout << "BuyerSeller added successfully\n";

		else
			cout << "BuyerSeller add failed -  username allready exist in system\n";
	}


}




void eStore::option13()//Show Details of all buyer-sellers
{

	BuyerSeller **bs = new BuyerSeller*[all_users];
	int logsize = 0;
	BuyerSeller *temp;

	for (int i = 0; i < all_users; i++)
	{
		temp = dynamic_cast<BuyerSeller*>(users.getArr()[i]);
		if (temp) {
			bs[logsize] = temp;
			logsize++;
		}
	}
	if (logsize == 0) {
		cout << "Sorry,There are no buyer-sellers registered at this time\n ";
	}
	else {
		cout << "Here Are the names and adresses of all our customers :\n";
		for (int i = 0; i < logsize; i++)
		{

			cout << "Customer name : " << bs[i]->getname();

			cout << "  Customer adress : ";
			cout << bs[i]->getAdress() << endl;
		}
	}
}

void eStore::option14() {//add using operator

	cout << "Please provide us with the sellers name :\n";
	User* input = get_input();

	if (input != nullptr) {
		Seller* slr = new Seller(input->getname(), input->getPass(), input->getAdress());

		if ((*this) += (*slr))
		{
			cout << "Seller Added Successfully \n";
			return;

		}
		cout << "this user already exists\n";

	}
}

void eStore::option15() {//add using operator
	cout << "Please provide us with the buyers name :\n";
	User* input = get_input();

	if (input != nullptr) {
		Buyer* byr = new Buyer(input->getname(), input->getPass(), input->getAdress());

		if ((*this) += (*byr))
		{
			cout << "Buyer Added Successfully \n";
			return;

		}
		cout << "this user already exists\n";

	}
}





void eStore::option16() {//compare 2 carts

	cin.ignore();
	string username_check;
	string username_compare;
	string sellername;

	Buyer* byr_check;
	Buyer* byr_compare;
	cout << "Please enter the buyer that you want to compare to" << endl;
	getline(cin, username_check);
	byr_check = this->GetBuyerByName(username_check);
	if (!byr_check) {
		cout << "No Buyer of that names exists\n";
		return;
	}
	cout << "Please enter the buyer that you want to compare with" << endl;
	getline(cin, username_compare);
	byr_compare = this->GetBuyerByName(username_compare);
	if (!byr_compare) {
		cout << "No Buyer of that names exists\n";
		return;
	}

	if (*byr_check > *byr_compare) {
		cout << byr_check->getname() << "has greater shopping cart value \n";
		return;
	}
	else if (*byr_compare > *byr_check)
		cout << byr_compare->getname() << "has greater shopping cart value \n";
	
	else
		cout << "Shopping cart values are equal";







}


void eStore::option17()//print with operator
{
	cin.ignore();
	string username;
	cout << "Please provide us with the buyers name :\n";
	getline(cin, username);
	Buyer* byr = GetBuyerByName(username);
	if (byr)
	{
		cout << *byr << endl;
	}
	else {
		cout << "No buyer matches that username\n";
		return;
	}
	cout << "Please provide us with the sellers name :\n";
	getline(cin, username);
	Seller* slr = GetSellerByName(username);
	if (slr)
	{
		cout << *slr << endl;
	}
	else
	{
		cout << "No seller matches that username\n";
		return;
	}

}

bool eStore:: operator+=(Seller &slr)
{
	return this->Add_User((User*)&slr);
}

bool eStore:: operator+=(Buyer & byr)
{
	return this->Add_User((User*)&byr);
}




void eStore::StartMenu()
{
	cout << "Hello and welcome to  " << this->getname() << endl;
	bool keepgoing = true;
	short int selection;
	load_users();
	while (keepgoing)
	{
		cout << "\n";

		cout << "Please select an Action : \n";
		cout << "1.Add buyer\n";
		cout << "2.Add Seller\n";
		cout << "3.Add a product to a seller\n";
		cout << "4.Provide feedback on a seller (for customers who bought products from said seller only)\n";;
		cout << "5.Add a product to your shoping cart\n";
		cout << "6.Make an order\n";
		cout << "7.Payment\n";
		cout << "8.Show detailes of all the customers\n";
		cout << "9.Show detailes of all sellers\n";
		cout << "10.Search for product by name\n";
		cout << "11.Exit(User information will be stored in users.txt)\n";
		cout << "12.Add Buyer-Seller\n";
		cout << "13.Show detailes of all buyer-sellers\n";
		cout << "14.Add a seller with += operator to the users array\n";
		cout << "15.Add a buyer with += operator to the users array\n";
		cout << "16.Compare 2 customers shopping carts with > operator\n";
		cout << "17.print user details , and seller details using << operator\n";


		cin >> selection;


		switch (selection)
		{
		case 1:
			option1();
			break;
		case 2:
			option2();
			break;
		case 3:
			option3();
			break;

		case 4:
			option4();
			break;

		case 5:
			option5();
			break;

		case 6:
			option6();
			break;

		case 7:
			option7();
			break;

		case 8:
			option8();
			break;

		case 9:
			option9();
			break;

		case 10:
			option10();
			break;

		case 11:
			option11();
			cout << "Bye bye..." << endl;
			keepgoing = false;
			break;

		case 12:
			option12();
			break;

		case 13:
			option13();
			break;
		case 14:
			option14();
			break;
		case 15:
			option15();
			break;
		case 16:
			option16();
			break;

		case 17:
			option17();
			break;


		default:
			cout << "Invalid selection , please select an option from the menu (1-17) :\n" << endl;
			cin.clear();	// get rid of cin failure state
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// discard characters 



		}
	}
}
