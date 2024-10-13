#pragma once
#include <iostream>

struct Point {
    int m_x, m_y;
    Point(int x, int y) : m_x(x), m_y(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "Point(" << p.m_x << ", " << p.m_y << ")";
        return os;
    }
};
