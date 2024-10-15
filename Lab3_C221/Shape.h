#pragma once

#include <type_traits>
#include <iostream>
#include <string>

// Перечисление цветов
enum Color{Red,Green,Blue};

// Базовый класс Shape
class Shape {
	Color m_c;
public:
	Shape(Color c);
	// Метод для получения цвета
	Color getColor() const;
	std::string getColorName()const;
	virtual~Shape() = default;
	auto operator<=>(const Shape& other) const = default;
};

// Класс Rect, наследуемый от Shape
class Rect :public Shape {
	int m_l, m_r, m_t, m_b;  // Левый, правый, верхний и нижний края
public:
	// Конструктор
	Rect(int l, int r, int t, int b, Color c);

	//Метод для вычисдения площади
	int area() const;

	// Оператор сравнения <=> для сортировки по площади
	auto operator<=>(const Rect& other) const = default;

	//Функция печати прямоугольника
	void print()const;
};
