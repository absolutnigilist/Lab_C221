#include"Stack.h"



Point::Point(int x, int y)noexcept: m_x(x), m_y(y) {
    std::cout << "Point constructed: (" << x << ", " << y << ")\n";
}
Point::Point(const Point& other) noexcept : m_x(other.m_x), m_y(other.m_y) {
    std::cout << "Point copied: (" << m_x << ", " << m_y << ")\n";
}
Point::Point(Point&& other) noexcept : m_x(other.m_x), m_y(other.m_y) {
    std::cout << "Point moved: (" << m_x << ", " << m_y << ")\n";
    other.m_x = other.m_y = 0;
}
Point::~Point() {
    std::cout << "Point destroyed: (" << m_x << ", " << m_y << ")\n";
}
void Point::print() const {
    std::cout << "Point: (" << m_x << ", " << m_y << ")\n";
}
std::ostream& operator<<(std::ostream& os, const Point& pt) {
    os << "(" << pt.m_x << ", " << pt.m_y << ")";
    return os;
}