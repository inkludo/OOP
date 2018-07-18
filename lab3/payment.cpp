#include "payment.hpp"

Payment::Payment(
	Organization const & _sender, Organization const & _reciever,
	std::string const & _paymentId, std::string const & _purpose,
	DateTime const & _date, double _sum
)
	: m_sender(&_sender), m_reciever(&_reciever)
	, m_paymentId(_paymentId), m_purpose(_purpose)
	, m_date(_date), m_sum(_sum)
{}

