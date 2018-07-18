
#ifndef _ORGANIZATION_HPP_
#define _ORGANIZATION_HPP_

#include <string>
#include <unordered_map>
#include <functional>

class Payment;

/*****************************************************************************/

class Organization
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/

	Organization(
		std::string const & _name,
		std::string const & _registrationNumber,
		double _startBalance = 0.0
	);

	~Organization() = default;

	std::string const & getName() const;

	std::string const & getRegistrationNumber() const;

	double getBalance() const;

	void changeBalance(double _sum);

	void addIncomePayment(Payment const & _addIncomePayment);

	void addOutcomePayment(Payment const & _addOutcomePayment);

	bool hasIncomePayment(std::string const & _hasIncomePayment) const;

	bool hasOutcomePayment(std::string const & _hasOutcomePayment) const;

	void forEachIncomePayment(std::function<void(Payment const & _p)> _f);

	void forEachOutcomePayment(std::function<void(Payment const & _p)> _f);

/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	std::string m_name;

	std::string m_registrationNumber;

	double m_balance;

	std::unordered_map<std::string, Payment const *> m_incomePayments;

	std::unordered_map<std::string, Payment const *> m_outcomePayments;

/*-----------------------------------------------------------------*/    

};


inline bool Organization::hasIncomePayment(std::string const & _hasIncomePayment) const
{
	return m_incomePayments.find(_hasIncomePayment) != m_incomePayments.end();
}


inline bool Organization::hasOutcomePayment(std::string const & _hasOutcomePayment) const
{
	return m_outcomePayments.find(_hasOutcomePayment) != m_outcomePayments.end();
}


inline std::string const & Organization::getName() const
{
	return m_name;
}


inline std::string const & Organization::getRegistrationNumber() const
{
	return m_registrationNumber;
}


inline double Organization::getBalance() const
{
	return m_balance;
}


inline void Organization::changeBalance(double _sum)
{
	m_balance += _sum;
}


#endif // _ORGANIZATION_HPP_
