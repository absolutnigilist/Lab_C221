#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
#include <variant>

enum Color {BLUE,GREEN,RED};

class ColoredCircle {
	Color m_col;
	int m_x, m_y, m_r;
public:
    // Дефолтный конструктор
    ColoredCircle() = default;

    // Конструктор с параметрами
    ColoredCircle(Color col, int x, int y, int r);

    // Копирующий конструктор
    ColoredCircle(const ColoredCircle& other) = default;

    // Оператор присваивания
    ColoredCircle& operator=(const ColoredCircle& other) = default;

    // Деструктор
    ~ColoredCircle() = default;

    void print() const;

    //Получение площади круга
    double area()const;

    //Расстояние от начала координат
    double distanceFromOrigin()const;

    //Геттеры
    Color getColor()const;

    int getX()const;

    int getY()const;

    int getRadius()const;

    //Cеттеры

    void setRadius(int new_radius);

    void move(int dx, int dy);


};

class ColoredRect {
    Color m_col;
    int m_x, m_y, m_width, m_height;
public:
    // Дефолтный конструктор
    ColoredRect() = default;

    // Конструктор с параметрами
    ColoredRect(Color col, int x, int y, int width, int height);

    // Копирующий конструктор
    ColoredRect(const ColoredRect& other) = default;

    // Оператор присваивания
    ColoredRect& operator=(const ColoredRect& other) = default;

    // Деструктор
    ~ColoredRect() = default;

    //Получение площади квадрата
    double area() const;

    //Получение цвета
    Color getColor()const;

    //Печать элементов
    void print()const;

};