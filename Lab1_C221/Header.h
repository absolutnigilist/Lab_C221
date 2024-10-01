#pragma once
#include<vector>
#include<iostream>
#include<type_traits>
#include <algorithm>
#include <functional>

template<typename T> void fV(std::vector<T>& v) {
	for (auto& x : v) {
		++x; }
}
// Основная шаблонная функция insertunique
template<typename T, typename... Args>
void insertunique(std::vector<T>& v, Args&&... args) {};

// Вспомогательная функция для вставки одного значения
template<typename T, typename U>
void insert_single_unique(std::vector<T>& v, U&& value) {
    // Проверка: можно ли привести U к T
    if constexpr (std::is_convertible_v<std::decay_t<U>, T>) {
        // Приводим значение и проверяем, есть ли оно уже в векторе
        T converted_value = static_cast<T>(value);
        if (std::find(v.begin(), v.end(), converted_value) == v.end()) {
            v.push_back(converted_value); // Добавляем, если его ещё нет
        }
    }
}

// Рекурсивная вариативная функция для вставки нескольких значений
template<typename T, typename First, typename... Rest>
void insertunique(std::vector<T>& v, First&& first, Rest&&... rest) {
    insert_single_unique(v, std::forward<First>(first));  // Обрабатываем первый аргумент
    insertunique(v, std::forward<Rest>(rest)...);         // Рекурсивно обрабатываем остальные
}

// Базовый случай для рекурсии (когда нет аргументов)
template<typename T>
void insertunique(std::vector<T>&) {
    // Базовый случай ничего не делает
}


// Базовый случай: когда нет больше функций для применения
template<typename T>
void apply_actions(T& value) {
    // Базовый случай ничего не делает
}

// Рекурсивная функция для применения последовательности callable-объектов к значению
template<typename T, typename Callable, typename... Callables>
void apply_actions(T& value, Callable&& action, Callables&&... actions) {
// Применяем текущее действие
    std::forward<Callable>(action)(value);

// Рекурсивно вызываем оставшиеся действия
    apply_actions(value, std::forward<Callables>(actions)...);
}
// Функция, использующая fold expressions для применения действий
template<typename T, typename... Callables>
void apply_actions(T& value, Callables&&... actions) {
    // Используем fold expression для применения каждого callable к значению
    (..., std::forward<Callables>(actions)(value));
}