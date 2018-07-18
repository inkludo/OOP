#include"wishlist.hpp"


Wishlist::Wishlist(const std::string & _userName) :m_userName(_userName)
{
	if (_userName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);
}

Wishlist::Wishlist(const std::string & _userName, const std::initializer_list<Wish>& _vectorWish) :m_userName(_userName)
{
	if (_userName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);
	for (auto& it : _vectorWish)
	{
		if (it.first.empty())
			throw std::logic_error(Messages::WishNameEmpty);
		if (it.second < 0)
			throw std::logic_error(Messages::NegativePriority);
		if (m_wishMap.find(it.first) != m_wishMap.end())
			throw std::logic_error(Messages::WishAlreadyExists);

		m_wishMap.insert(it);
		m_wishVector.push_back(it);
	}
}

Wishlist::Wishlist(const std::string & _userName, const std::map<std::string, int>& _list) :m_userName(_userName)
{
	if (_userName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);
	m_wishMap = _list;
	for (auto& it : _list)
		m_wishVector.push_back(it);
}

Wishlist::Wishlist(Wishlist && _wishlist) :m_userName(_wishlist.m_userName), m_wishMap(_wishlist.m_wishMap)
{
	m_wishMap.clear();
}

int Wishlist::getWishPriority(const std::string & _wish) const
{
	if (_wish.empty())
		throw std::logic_error(Messages::WishNameEmpty);

	if (m_wishMap.find(_wish) == m_wishMap.end())
		throw std::logic_error(Messages::WishDoesNotExist);

	return m_wishMap.find(_wish)->second;

}

int Wishlist::correctOwner(const std::string & _userName)
{
	if (_userName.empty())
		throw std::logic_error(Messages::OwnerNameEmpty);

	m_userName = _userName;
}

void Wishlist::addWish(const std::string & wish, int _p)
{
	if (wish.empty())
		throw std::logic_error(Messages::WishNameEmpty);
	if (_p < 0)
		throw std::logic_error(Messages::NegativePriority);
	if (m_wishMap.find(wish) != m_wishMap.end())
		throw std::logic_error(Messages::WishAlreadyExists);

	m_wishMap.insert(std::make_pair(wish, _p));
	m_wishVector.push_back(std::make_pair(wish, _p));
}

void Wishlist::addWish(Wish wish)
{
	if (wish.first.empty())
		throw std::logic_error(Messages::WishNameEmpty);
	if (wish.second < 0)
		throw std::logic_error(Messages::NegativePriority);
	if (m_wishMap.find(wish.first) != m_wishMap.end())
		throw std::logic_error(Messages::WishAlreadyExists);

	m_wishMap.insert(wish);
	m_wishVector.push_back(wish);
}

bool Wishlist::hasWish(const std::string & s) const
{
	return m_wishMap.find(s) != m_wishMap.end();
}

void Wishlist::updateWishPriority(const std::string & _wishName, int _wishPriority) {
	if (_wishName.empty())
		throw std::logic_error(Messages::WishNameEmpty);
	if (m_wishMap.find(_wishName) == m_wishMap.end())
		throw std::logic_error(Messages::WishDoesNotExist);
	if (_wishPriority < 0)
		throw std::logic_error(Messages::NegativePriority);

	auto it = m_wishMap.find(_wishName);
	it->second = _wishPriority;
}

void Wishlist::dropWish(const std::string & _wishName) {
	if (_wishName.empty())
		throw std::logic_error(Messages::WishNameEmpty);
	if (m_wishMap.count(_wishName) == 0)
		throw std::logic_error(Messages::WishDoesNotExist);

	m_wishMap.erase(_wishName);
}

std::vector<std::string> Wishlist::getWishesWithPriority(int _wishPriority) const {
	if (_wishPriority < 0)
		throw std::logic_error(Messages::NegativePriority);

	std::vector <std::string> WishesWithPriority;
	for (auto& _wish : m_wishVector)
	{
		if (_wish.second == _wishPriority)
			WishesWithPriority.push_back(_wish.first);
	}

	return WishesWithPriority;
}

std::vector <std::string> Wishlist::getMostPrioritizedWishes(int _maxCount) const
{
	if (_maxCount <= 0)
		throw std::logic_error(Messages::NonPositiveAmount);

	std::vector<Wish> temp;
	std::vector<std::string> m_wishVectorRes;

	if (!m_wishVector.empty())
	{
		temp = m_wishVector;

		if (_maxCount > m_wishVector.size())
			_maxCount = m_wishVector.size();

		std::sort(temp.begin(), temp.end(),
			[](const Wish &_first, const Wish &_second) -> bool
		{
			return _first.second > _second.second;
		});

		for (int i = 0; i < _maxCount; i++)
			m_wishVectorRes.push_back(temp[i].first);
	}

	return m_wishVectorRes;

}

std::vector <std::string> Wishlist::getLeastPrioritizedWishes(int _minCount) const
{
	if (_minCount <= 0)
		throw std::logic_error(Messages::NonPositiveAmount);

	std::vector<Wish> temp;
	std::vector<std::string> m_wishVectorRes;

	if (!m_wishVector.empty())
	{
		temp = m_wishVector;

		if (_minCount > m_wishVector.size())
			_minCount = m_wishVector.size();

		std::sort(temp.begin(), temp.end(),
			[](const Wish &_first, const Wish &_second) -> bool
		{
			return _first.second < _second.second;
		});

		for (int i = 0; i < _minCount; i++)
			m_wishVectorRes.push_back(temp[i].first);
	}

	return m_wishVectorRes;

}

std::set <std::string> Wishlist::getSimilarWishes(const Wishlist & _wishlist) const {
	std::set <std::string> SimilarWishes;
	for (Wish _wish : _wishlist.m_wishMap) {
		for (Wish _thiswish : m_wishMap) {
			if (_wish.first == _thiswish.first && SimilarWishes.find(_wish.first) == SimilarWishes.end())
				SimilarWishes.insert(_wish.first);
		}
	}
	int i = 0;
	return SimilarWishes;

}

void Wishlist::dropWishesWithPriorityLessThan(const int _minPriority) {
	std::vector<Wish> m_wishVector;
	for (Wish _wish : m_wishMap)
	{
		if (_wish.second < _minPriority)
			m_wishVector.push_back(_wish);
	}
	for (auto& it : m_wishVector)
	{
		m_wishMap.erase(it.first);
	}

}


Wish Wishlist::operator[](int _index) const
{
	if (_index > (int)m_wishMap.size())
		throw std::out_of_range("OUT_OF_RANGE");

	int counter = 0;
	for (auto it = m_wishVector.begin(); it != m_wishVector.end(); ++it)
	{
		if (counter == _index)
			return *it;
		else
			counter++;
	}
}

Wishlist & Wishlist::operator+=(Wish & _wish)
{
	if (_wish.first == "")
		throw std::logic_error(Messages::WishNameEmpty);
	if (_wish.second < 0)
		throw std::logic_error(Messages::NegativePriority);
	if (hasWish(_wish.first))
		throw std::logic_error(Messages::WishAlreadyExists);

	m_wishMap.insert(std::make_pair(_wish.first, _wish.second));
	return *this;
}