#pragma once

#include <functional>
#include <map>
#include <cmath>
#include <iostream>

//Посредствщм шаблона глобальной функции
template<typename T> T sum(const T& a, const T& b) {

	return a + b;
}

// Глобальный объект std::minus для вычитания
extern std::minus<double> substract;

//Посредством функционального объекта
struct Multiplication {

	template<typename T> 
	T operator()(const T& a, const T& b) {
		return a * b;
	}
};

//Посредством лямбды
extern std::function<double(double, double)> division;


// Класс для нахождения максимума
class MaxFinder {
public:
	double maximum(double a, double b)const {
		return a > b ? a : b;
	}
};

// Функция для вычисления дробной части
inline double fractional_part(double a) {
	return a - static_cast<int>(a);
}

void  Calc();



