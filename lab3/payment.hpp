
#ifndef _PAYMENT_HPP_
#define _PAYMENT_HPP_


#include <string>
#include "datetime.hpp"

class Organization;


class Payment
{


public:


	Payment(
		Organization const & _sender, Organization const & _reciever,
		std::string const & _paymentId, std::string const & _purpose,
		DateTime const & _date, double _summary
	);

	~Payment() = default;

	std::string const & getPaymentId() const;

	std::string const & getPurpose() const;

	Organization const & getReceiver() const;

	Organization const & getSender() const;

	double getSummary() const;

	void changeSummary(double _newSum);

	DateTime const & getDateTime() const;


private:

	Organization const * m_sender, * m_reciever;

	std::string m_paymentId;

	std::string m_purpose;

	DateTime m_date;

	double m_sum;

};


inline std::string const & Payment::getPaymentId() const
{
	return m_paymentId;
}

inline std::string const & Payment::getPurpose() const
{
	return m_purpose;
}

inline Organization const & Payment::getReceiver() const
{
	return * m_reciever;
}

inline Organization const & Payment::getSender() const
{
	return *m_sender;
}

inline double Payment::getSummary() const
{
	return m_sum;
}

inline void Payment::changeSummary(double _newSum)
{
	m_sum = _newSum;
}

inline DateTime const & Payment::getDateTime() const
{
	return m_date;
}

#endif // _PAYMENT_HPP_
