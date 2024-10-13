#pragma once
#include "Book.h"
#include <vector>
#include <functional>
#include <tuple>
#include <string>

// Функции для сравнения книг
bool Author(const book& b1, const book& b2);

bool Title(const book& b1, const book& b2);

bool Year(const book& b1, const book& b2);

