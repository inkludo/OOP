

#include "poison.h"

Poison::Poison(string name, int volume, double price) : Beverage(name, volume, price)
{

}

string Poison::getMainIngredient() const
{
	return "Technical alcohol";
}

bool Poison::canBeSold(string allergen, int age, double money)
{
	return false;
}


