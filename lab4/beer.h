

#ifndef _BEER_HPP_
#define _BEER_HPP_

#include <string>

#include "beverage.h"

using std::string;

class Beer
	: public Beverage
{
private:
	string m_main_ingredient;

public:
	Beer(string name, int volume, double price);

	string getMainIngredient() const;
	bool canBeSold(string allergen, int age, double money);

	 ~Beer() = default;

};

inline string Beer::getMainIngredient() const
{
	return "Corn";
}


#endif // _BEER_HPP_