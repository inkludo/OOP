#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

#include <string>

#include "beverage.h"

using std::string;

class Customer
{
private:
	string m_name;
	string m_allergen;
	int m_age;
	double m_money;

public:
	Customer(string name, int age, double money, string allergen = "")
		: m_name(name), m_age(age), m_money(money), m_allergen(allergen) {};

	Customer(const Customer &) = delete;
	Customer & operator = (const Customer &) = delete;

	void setAllergen(string allergen) { this->m_allergen = allergen; }

	 string getAllergen() const;
	 int getAge() const;
	 double getBalance() const;
     bool buyBeverage(Beverage& beverage);
};

inline string Customer::getAllergen() const 
{ return m_allergen; }

inline int Customer::getAge() const 
{ return m_age; }

inline double Customer::getBalance() const 
{ return m_money; }


#endif // _CUSTOMER_HPP_