#pragma once
#include "Point.h"

template<typename T>
class MyStack {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        template<typename N>
        Node(N&& value) :data(std::forward<N>(value)), next(nullptr) {};
    };

    std::unique_ptr<Node> head;

public:
    MyStack() = default;

    // Конструктор для нескольких значений
    template<typename... Args>
    MyStack(Args&&... args) {
        push(std::forward<Args>(args)...);
    }

    // Функция для добавления одного элемента (lvalue и rvalue)
    template<typename U>
    void push(U&& value) {
        auto new_node = std::make_unique<Node>(std::forward<U>(value));
        new_node->next = std::move(head);
        head = std::move(new_node);
        std::cout << (std::is_lvalue_reference<U>::value ? "push lvalue" : "push rvalue") << std::endl;
    }

    // Рекурсивная функция для нескольких значений
    template<typename First, typename... Rest>
    void push(First&& first, Rest&&... rest) {
        push(std::forward<First>(first));  // Обрабатываем первый элемент
        if constexpr (sizeof...(rest) > 0) {  // Условие для продолжения рекурсии
            push(std::forward<Rest>(rest)...);  // Рекурсивно добавляем остальные
            std::cout << "multiple" << std::endl;
        }
    }

    // Создание значения на месте
    template<typename... Args>
    void push_emplace(Args&&... args) {
        auto new_node = std::make_unique<Node>(T(std::forward<Args>(args)...));
        new_node->next = std::move(head);
        head = std::move(new_node);
        std::cout << "emplace" << std::endl;
    }
};
