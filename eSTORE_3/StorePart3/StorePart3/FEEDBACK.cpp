#pragma warning(disable : 4996) 

#include "FEEDBACK.h"
#include "Product.h"
#include "Buyer.h"




void feedback::setEvaluation()
{

	cout << "Hello , please enter you evaluation of the seller " << endl;
	getline(cin, Evaluation);
	cout << "Thank you for sharing " << endl;
}



void feedback::setdate()

{
	time_t mytime = time(NULL);
	feedback_date = ctime(&mytime);
}




const string feedback::GetEvaluation() const
{
	return Evaluation;
}


const string feedback::GetDate() const
{
	return feedback_date;
}



const string feedback::GetBuyer_name() const
{
	return this->buyer_name;
}

