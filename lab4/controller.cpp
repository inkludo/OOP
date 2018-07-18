#include <stdexcept>

#include "controller.h"
#include "messages.h"
#include "juice.h"
#include "beer.h"
#include "poison.h"

using std::logic_error;


void Controller::checkIfNameIsEmpty(string _name, const string message)
{
	if (_name.compare("") == 0) {
		throw logic_error(message);
	}
}

void Controller::checkIfNegative(double value, const string message)
{
	if (value < 0) {
		throw logic_error(message);
	}
}

void Controller::checkIfCustomerExists(string _name) const
{
	try {
		m_customers.at(_name);
	}
	catch (std::out_of_range) {
		throw logic_error(Messages::CustomerNameUnknown);
	}
}

void Controller::checkIfBeverageExists(string _name) const
{
	try {
		m_beverages.at(_name);
	}
	catch (std::out_of_range) {
		throw logic_error(Messages::BeverageNameUnknown);
	}
}

void Controller::checkIfCustomerUnique(string _name)
{
	try {
		m_customers.at(_name);
		throw logic_error(Messages::CustomerNameNotUnique);
	}
	catch (std::out_of_range) {

	}
}

void Controller::checkIfBeverageUnique(string _name)
{
	try {
		m_beverages.at(_name);
		throw logic_error(Messages::BeverageNameNotUnique);
	}
	catch (std::out_of_range) {

	}
}

void Controller::checkBeverage(string name, int volume, double price)
{
	checkIfBeverageUnique(name);
	checkIfNameIsEmpty(name, Messages::EmptyBeverageName);
	checkIfNegative(volume, Messages::NonPositiveAmount);
	checkIfNegative(price, Messages::NonPositivePrice);
}

Controller::Controller()
{

}

void Controller::createCustomer(std::string const & _name, int _age, double _money)
{
	checkIfNameIsEmpty(_name, Messages::EmptyCustomerName);
	checkIfCustomerUnique(_name);
	checkIfNegative(_age, Messages::NegativeAge);
	checkIfNegative(_money, Messages::NegativeBalance);

	m_customers.emplace(_name, new Customer(_name, _age, _money));
}

void Controller::makeCustomerAllergicTo(std::string const & _name, std::string const & _ingredient)
{
	checkIfCustomerExists(_name);
	checkIfNameIsEmpty(_ingredient, Messages::EmptyIngredientName);
	m_customers.at(_name)->setAllergen(_ingredient);
}

double Controller::getCustomerBalance(std::string const & _customerName) const
{
	checkIfCustomerExists(_customerName);
	return m_customers.at(_customerName)->getBalance();
}

int Controller::getCustomerAge(std::string const & _customerName) const
{
	checkIfCustomerExists(_customerName);
	return m_customers.at(_customerName)->getAge();
}

std::string Controller::getCustomerAllergicIngredient(std::string const & _customerName) const
{
	checkIfCustomerExists(_customerName);
	return m_customers.at(_customerName)->getAllergen();
}

void Controller::createJuice(std::string const & _name, int _volumeMl, double _price, std::string const & _mainIngredient)
{
	checkBeverage(_name, _volumeMl, _price);
	checkIfNameIsEmpty(_mainIngredient, Messages::EmptyIngredientName);
	m_beverages.emplace(_name, new Juice(_name, _volumeMl, _price, _mainIngredient));
}

void Controller::Controller::createBeer(std::string const & _name, int _volumeMl, double _price)
{
	checkBeverage(_name, _volumeMl, _price);
	m_beverages.emplace(_name, new Beer(_name, _volumeMl, _price));
}

void Controller::createPoison(std::string const & _name, int _volumeMl, double _price)
{
	checkBeverage(_name, _volumeMl, _price);
	m_beverages.emplace(_name, new Poison(_name, _volumeMl, _price));
}

std::string Controller::getBeverageMainIngredient(std::string const & _beverageName) const
{
	checkIfBeverageExists(_beverageName);
	return m_beverages.at(_beverageName)->getMainIngredient();
}

int Controller::getBeverageVolumeMl(std::string const & _beverageName) const
{
	checkIfBeverageExists(_beverageName);
	return m_beverages.at(_beverageName)->getVolume();
}

double Controller::getBeveragePrice(std::string const & _beverageName) const
{
	checkIfBeverageExists(_beverageName);
	return m_beverages.at(_beverageName)->getPrice();
} 

bool Controller::trySelling(std::string const & _customerName, std::string const & _beverageName)
{
	checkIfBeverageExists(_beverageName);
	checkIfCustomerExists(_customerName);
	Beverage* beverage = m_beverages.at(_beverageName);
	Customer* customer = m_customers.at(_customerName);
	return customer->buyBeverage(*beverage);
}

Controller::~Controller()
{
	for (std::pair<string, Customer*> x : m_customers) {
		delete x.second;
	}
	for (std::pair<string, Beverage*> x : m_beverages) {
		delete x.second;
	}
}
