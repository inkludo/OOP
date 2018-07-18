#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_


#include "point.hpp"
#include "triangle.hpp"



class Triangle
{
public:

	Triangle::Triangle(double _x0, double _y0, double _x1, double _y1, double _x2, double _y2)
		: m_p1(_x0, _y0), m_p2(_x1, _y1), m_p3(_x2, _y2)
	{
	}

	Triangle::Triangle(Point _p1, Point _p2, Point _p3)
		: m_p1(_p1), m_p2(_p2), m_p3(_p3)
	{
	}


	Point getPoint1() const;
	Point getPoint2() const;
	Point getPoint3() const;
	
	double getSide12Length() const;
	double getSide23Length() const;
	double getSide13Length() const;
	
	double getPerimeter()const;
	double getArea()const;
	
	double getAngle1()const;
	double getAngle2()const;
	double getAngle3()const;
	
	bool operator ==(const Triangle &_t)const;
	bool operator !=(const Triangle &_t)const;

	bool isRectangular()const;
	bool isIsosceles()const;
	bool isEquilateral()const;


private:

	Point m_p1;
	Point m_p2;
	Point m_p3;
	
	
};

inline Point Triangle::getPoint1() const
{
	return m_p1;
}

inline Point Triangle::getPoint2() const
{
	return m_p2;
}

inline Point Triangle::getPoint3() const
{
	return m_p3;
}

inline	double Triangle::getSide12Length() const {
	return m_p1.distanceTo(m_p2);
}

inline	double Triangle::getSide23Length() const {
	return m_p2.distanceTo(m_p3);
}

inline	double Triangle::getSide13Length() const {
	return m_p1.distanceTo(m_p3);
}



#endif //  _TRIANGLE_HPP_