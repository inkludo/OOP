

#include "organization.hpp"
#include "messages.hpp"
#include "payment.hpp"


Organization::Organization(std::string const & _name, std::string const & _registrationNumber, double _startBalance)
	: m_name(_name), m_registrationNumber(_registrationNumber), m_balance(_startBalance)
{}



void Organization::addIncomePayment(Payment const & _addIncomePayment)
{
	m_incomePayments.insert(std::make_pair(_addIncomePayment.getPaymentId(), &_addIncomePayment));
}



void Organization::addOutcomePayment(Payment const & _addOutcomePayment)
{
	m_outcomePayments.insert(std::make_pair(_addOutcomePayment.getPaymentId(), &_addOutcomePayment));
}


void Organization::forEachIncomePayment(std::function<void(Payment const&_p)> _f)
{
	for (auto p : m_incomePayments)
		_f(*p.second);
}


void Organization::forEachOutcomePayment(std::function<void(Payment const&_p)> _f)
{
	for (auto p : m_outcomePayments)
		_f(*p.second);
}

