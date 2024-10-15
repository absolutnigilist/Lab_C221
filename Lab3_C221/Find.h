#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <cmath>  // Для функции std::abs

// Функция для поиска индекса элемента по модулю
std::optional<int> find_by_modulo(const std::vector<int>& vec, int value);