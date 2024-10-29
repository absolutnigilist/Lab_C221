#include "Shape.h"

Shape::Shape(Color c):m_c(c){}

Color Shape::getColor() const {
	return m_c;
}
std::string Shape::getColorName()const
{
	switch (m_c)
	{
	case Red:
		return std::string("Red");
		break;
	case Green:
		return std::string("Green");
		break;
	case Blue:
		return std::string("Blue");
		break;
	default:
		return std::string("Unknown");
		break;
	}
}

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
		<< ", area=" << area() <<" "<< "Color: "<<Shape::getColorName()<<")\n";
}

int Rect::area()const {
	return (m_r - m_l) * (m_t - m_b);
}

auto Rect::operator<=>(const Rect& other) const{
	// Сравниваем по площади, если площади равны, сравниваем по цвету
	if (auto cmp = area() <=> other.area();cmp!=0) {
		return cmp;
	}
	return Shape::operator<=> (other); // Здесь вызов базового класса
}
bool Rect::operator<(const Rect& other) const {
	return (this->operator<=>(other)) < 0;
}