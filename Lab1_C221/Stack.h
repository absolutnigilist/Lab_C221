#pragma once
#include "Point.h"

template<typename T>
class MyStack {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(const T& value) : data(value), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    MyStack() = default;

    // Вариативный конструктор для принятия нескольких значений

    template<typename... Args>
    MyStack(Args&&... args) {
        push_multiple(std::forward<Args>(args)...);
    }

    // Добавить копию lvalue

    void push(const T& value) {
        auto new_node = std::make_unique<Node>(value);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    // Переместить rvalue в стек
    void push(T&& value) {
        auto new_node = std::make_unique<Node>(std::move(value));
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    // // Добавить несколько значений в порядке следования

    template<typename... Args>
    void push(const T& first, Args&&... rest) {
        push(first);
        push(std::forward<Args>(rest)...);
    }

    // Создать новое значение на месте
    template<typename... Args>
    void push_emplace(Args&&... args) {
        auto new_node = std::make_unique<Node>(T(std::forward<Args>(args)...));
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

private:
    // Вспомогателоьная функция для конструктора с переменным числом параметров
    template<typename First, typename... Rest>
    void push_multiple(First&& first, Rest&&... rest) {
        push(std::forward<First>(first));
        push_multiple(std::forward<Rest>(rest)...);
    }

    // Базовый случай для рекурсивного вариативного шаблона

    void push_multiple() {}
};
