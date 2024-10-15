#pragma once

#include "Shape.h"

#include <iostream>
#include <variant>
#include <vector>
#include <string>

// Функция для преобразования значения цвета в строку

std::string colorToString(Color c);

// Вспомогательная структура overload для использования с std::visit
template<typename... Functors>
struct overload : Functors... {
    using Functors::operator()...;
};
// Специализация вывода вектора значений с использованием std::visit
void printVariants(const std::vector<std::variant<int, double, Color>>& values);