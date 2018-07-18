

#include "juice.h"

Juice::Juice(string name, int volume, double price, string main_ingredient) : Beverage(name, volume, price)
{
	this->m_main_ingredient = main_ingredient;
}

string Juice::getMainIngredient() const
{
	return m_main_ingredient;
}

bool Juice::canBeSold(string allergen, int age, double money)
{
	return m_main_ingredient.compare(allergen) != 0;
}

