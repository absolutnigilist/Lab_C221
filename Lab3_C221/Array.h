#pragma once

#include <iostream>
#include <array>
#include <stdexcept>

// Шаблонная функция для получения элемента по индексу из std::array
template <typename T, std::size_t N>
T getElement(const std::array<T, N>& arr, std::size_t index) {
    // Проверяем, что индекс корректный
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    // Возвращаем элемент с заданным индексом
    return arr[index];
}
