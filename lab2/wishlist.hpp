#define _WISHLIST_HPP_

#include<map>
#include<string>
#include"messages.hpp"
#include<vector>
#include<set>
#include<algorithm>

typedef
std::pair< std::string, int >
Wish;

class Wishlist
{
private:
	std::string m_userName;
	std::map<std::string, int> m_wishMap;
	std::vector<Wish> m_wishVector;
public:
	Wishlist(const std::string  &_m_userName);
	Wishlist(const std::string  &_m_userName, const std::initializer_list<Wish>  &_vectorWish);
	Wishlist(const std::string  &_m_userName, const std::map <std::string, int> &_list);
	Wishlist(Wishlist &&_wishlist);
	std::string getOwner() const;
	int getWishesCount() const;
	int getWishPriority(const std::string & _wish) const;
	int correctOwner(const std::string & _m_userName);
	void addWish(const std::string & wish, int _p);
	void addWish(Wish wish);
	bool hasWish(const std::string & s) const;
	void updateWishPriority(const std::string & _wishName, int _wishPriority);
	void dropWish(const std::string & _wishName);
	std::vector <std::string> getWishesWithPriority(int _wishPriority) const;
	std::vector <std::string> getMostPrioritizedWishes(int _maxCount) const;
	std::vector <std::string> getLeastPrioritizedWishes(int _minCount) const;
	std::set <std::string> getSimilarWishes(const Wishlist & _wishlist) const;
	void dropWishesWithPriorityLessThan(const int _minPriority);
	void clean();
	Wish operator [] (int _index) const;                  
	Wishlist & operator += (Wish & _wish); 
};
inline std::string Wishlist::getOwner() const
{
	return m_userName;
}
inline int Wishlist::getWishesCount() const
{
	return (int)m_wishMap.size();
}


inline void Wishlist::clean()
{
	m_wishMap.clear();
}