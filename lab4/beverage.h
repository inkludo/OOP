#ifndef _BEVERAGE_HPP_
#define _BEVERAGE_HPP_

#include <string>

using std::string;

class Beverage
{
private:
	string m_name;
	int m_volume;
	double m_price;

public:
	Beverage(string name, int volume, double price) :
		m_name(name), m_volume(volume), m_price(price) {};

	Beverage(const Beverage &) = delete;
	Beverage & operator = (const Beverage &) = delete;


	double getPrice() const;
	int getVolume() const;
	virtual string getMainIngredient() const = 0;
	virtual bool canBeSold(string allergen, int age, double money) = 0;

	virtual ~Beverage() = default;
};

inline double Beverage::getPrice() const
{ return m_price; }

inline int Beverage::getVolume() const 
{ return m_volume; }



#endif // _BEVERAGE_HPP_