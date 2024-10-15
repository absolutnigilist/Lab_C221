#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <map>
#include <string>
#include <ctime>
#include <variant>

// Перечисление для запроса пользователя
enum class What { Year, Month, Day, WeekDay };

// Функция для получения дня недели в строковом виде
std::string get_weekday(int wday);

// Функция, которая возвращает данные в зависимости от запроса пользователя
std::string get_date_part(const std::variant<What>& what);