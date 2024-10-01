#pragma once
#include <iostream>
#include <utility>//std::forward
#include <memory>//std::unique_ptr

class Point{
    int m_x, m_y;
public:
    Point(int x=0, int y=0) noexcept;
    Point(const Point& other) noexcept;
    Point(Point&& other) noexcept;
    ~Point();
    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const Point& pt);   
};
