#include "Shape.h"

ColoredCircle::ColoredCircle(Color col, int x, int y, int r) : m_col(col), m_x(x), m_y(y), m_r(r) {}

void ColoredCircle::print() const {
    std::cout << "Color: " << m_col << ", X: " << m_x << ", Y: " << m_y << ", Radius: " << m_r << std::endl;
}

double ColoredCircle::area() const
{
    return 3.14*m_r*m_r;
}

double ColoredCircle::distanceFromOrigin() const
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

Color ColoredCircle::getColor() const
{
    return m_col;
}

int ColoredCircle::getX() const
{
    return m_x;
}

int ColoredCircle::getY() const
{
    return m_y;
}

int ColoredCircle::getRadius() const
{
    return m_r;
}

void ColoredCircle::setRadius(int new_radius)
{
    m_r = new_radius;
}

void ColoredCircle::move(int dx, int dy)
{
    m_x += dx;
    m_y += dy;
}

ColoredRect::ColoredRect(Color col, int x, int y, int width, int height): m_col(col), m_x(x), m_y(y), m_width(width), m_height(height){}

double ColoredRect::area() const
{
    return m_width*m_height;
}

Color ColoredRect::getColor() const
{
    return m_col;
}

void ColoredRect::print() const
{
    std::cout << "Color: " << static_cast<int>(m_col) << ", X: " << m_x << ", Y: " << m_y
        << ", Width: " << m_width << ", Height: " << m_height << '\n';
}

