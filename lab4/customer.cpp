

#include "customer.h"

bool Customer::buyBeverage(Beverage& beverage)
{
	double price = beverage.getPrice();
	if (m_money >= price && beverage.canBeSold(getAllergen(), getAge(), m_money)) {
		m_money -= price;
		return true;
	}
	else {
		return false;
	}
}