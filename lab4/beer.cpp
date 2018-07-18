
#include "beer.h"

Beer::Beer(string name, int volume, double price) : Beverage(name, volume, price)
{

}


bool Beer::canBeSold(string allergen, int age, double money)
{
	return age >= 18 && getMainIngredient().compare(allergen) != 0;
}

