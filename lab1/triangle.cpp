#include "triangle.hpp"

double Triangle::getPerimeter() const {
	return (getSide12Length() + getSide23Length() + getSide13Length());
}

double Triangle::getArea() const {
	return std::sqrt(getPerimeter() / 2 * ((getPerimeter() / 2 - getSide12Length()) *
		(getPerimeter() / 2 - getSide23Length()) *
		(getPerimeter() / 2 - getSide13Length())));
}

bool Triangle::operator ==(const Triangle &_t) const {
	return (this->m_p1 == _t.m_p1 && this->m_p2 == _t.m_p2 && this->m_p3 == _t.m_p3);
}

bool Triangle::operator !=(const Triangle &_t) const {

	return !(*this == _t);
}

double Triangle::getAngle1() const {
	double sqr_a = getSide23Length()*getSide23Length();
	double sqr_b = getSide13Length()*getSide13Length();
	double sqr_c = getSide12Length()*getSide12Length();
	return std::acos((sqr_b + sqr_c - sqr_a) / (2 * getSide13Length()*getSide12Length()));
}

double Triangle::getAngle2() const {
	double sqr_a = getSide23Length()*getSide23Length();
	double sqr_b = getSide13Length()*getSide13Length();
	double sqr_c = getSide12Length()*getSide12Length();
	return std::acos((sqr_a + sqr_c - sqr_b) / (2 * getSide23Length()*getSide12Length()));
}

double Triangle::getAngle3() const {
	double sqr_a = getSide23Length()*getSide23Length();
	double sqr_b = getSide13Length()*getSide13Length();
	double sqr_c = getSide12Length()*getSide12Length();
	return std::acos((sqr_a + sqr_b - sqr_c) / (2 * getSide23Length()*getSide13Length()));
}


bool Triangle::isRectangular() const {
	double sqr_a = getSide23Length()*getSide23Length();
	double sqr_b = getSide13Length()*getSide13Length();
	double sqr_c = getSide12Length()*getSide12Length();

	return (equalDoubles(sqr_a, (sqr_b + sqr_c))
		|| equalDoubles(sqr_b, (sqr_a + sqr_c))
		|| equalDoubles(sqr_c, (sqr_a + sqr_b)));
		
}

bool Triangle::isIsosceles() const {
	return (equalDoubles(getSide12Length(), getSide23Length()) ||
		equalDoubles(getSide12Length(), getSide13Length()) ||
		equalDoubles(getSide23Length(), getSide13Length()));
		
}

bool Triangle::isEquilateral() const {
	return (equalDoubles(getSide12Length(), getSide23Length()) &&
		equalDoubles(getSide23Length(), getSide13Length()));
		
}