

#ifndef _JUICE_HPP_
#define _JUICE_HPP_

#include <string>

#include "beverage.h"

using std::string;

class Juice
	: public Beverage
{
private:
	string m_main_ingredient;

public:
	Juice(string name, int volume, double price, string main_ingredient);

	string getMainIngredient() const;
	bool canBeSold(string allergen, int age, double money);

	 ~Juice() = default;
};

#endif // _JUICE_HPP_