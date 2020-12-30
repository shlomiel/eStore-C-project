#pragma once
#ifndef __FEEDBACK_h
#define __FEEDBACK_h
#include <iostream>
#include <ctime>
using namespace std;


class Buyer;
class Product;

class feedback
{

private:
	string buyer_name;
	string feedback_date;
	string Evaluation;

public:
	feedback(string buyer_name) :buyer_name(buyer_name)
	{
		setdate();
		setEvaluation();
	}
	;// Constructors
	feedback(const feedback& fb):buyer_name(fb.GetBuyer_name()), feedback_date(fb.GetDate()), Evaluation(fb.GetEvaluation()) {};

	//set methods
	void setdate();
	void setEvaluation();

	//get methods

	const string GetEvaluation() const;
	const string GetDate() const;
	const string GetBuyer_name() const;

};











#endif //FEEDBACK.h