#include "Shape.h"

Shape::Shape(Color c):m_c(c){}

Rect::Rect(int l, int r, int t, int b, Color c) :Shape(c){
	if (l < r) std::swap(l, r);
	m_l = l;
	m_r = r;
	if (b < t) std::swap(b, t);
	m_b = b;
	m_t = t;
}

void Rect::print() const
{
	std::cout<< "Rect(m_l=" << m_l << ", m_r=" << m_r << ", m_t=" << m_t << ", m_b=" << m_b
		<< ", area=" << area() << ")\n";
}

int Rect::area()const {
	return (m_r - m_l) * (m_t - m_b);
}
