
#ifndef _POISON_HPP_
#define _POISON_HPP_

#include <string>

#include "beverage.h"

using std::string;

class Poison
	: public Beverage
{
public:
	Poison(string name, int volume, double price);

	string getMainIngredient() const;
	bool canBeSold(string allergen, int age, double money);

	 ~Poison() = default;

};

#endif // _POISON_HPP_