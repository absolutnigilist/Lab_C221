#pragma once
#include <span>
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

template<typename Predicate>
int sum(std::span<const int> span, Predicate condition) {
	int result = 0;
	for (const auto& elem : span) {
		if (condition(elem))
		{
			result += elem;
		}
	}
	return result;
};

// �������� ������� ������ reserve() � ����������
template<typename T>
concept HasReserve = requires(T container, size_t n) {
	container.reserve(n);
};

// ������� ��� ���������� ��������� � ���������
template<typename Container,typename...Args>
void insertElements(Container& container, Args&&...args) {
	if constexpr (HasReserve<container>) 
	{
		container.reserve(container.size() + sizeof...(args)); // ����������� ������, ���� �������� reserve()
	}
	(container.insert(container.end(), std::forward<Args>(args)), ...); // ��������� ��������
}

//�������� ������� std::to_string
template<typename T>
concept HasStdToString = requires(T value) {
	{std::to_string(value)}->std::convertible_to<std::string>;
};

//�������� ������� ������ to_string � ����������������� ����
template<typename T>
concept HasMethodToString = requires(T value) {
	{value.to_string()}->std::convertible_to<std::string>;
};

//�������� �������������� ��������� <<
template<typename T>
concept HasOperatorOStream = requires(std::ostream & os, T value) {
	{os << value}->std::convertible_to<std::ostream&>;
};

//������� ���������� ��������
template<typename T>
void print_any_how(const T& value) {
    if constexpr (HasStdToString<T>) {
        std::cout << std::to_string(value);
    }
    else if constexpr (HasMethodToString<T>) {
        std::cout << value.to_string();
    }
    else if constexpr (HasOperatorOStream<T>) {
        std::cout << value;
    }
    else {
        static_assert(!std::is_same_v<T, T>, "No valid way to print this type.");
    }
}

// ������ ����������������� ����
class Point {
    int m_x, m_y;
public:
    Point(int x, int y) : m_x(x), m_y(y) {}

    std::string to_string() const {
        return "Point(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
    }
};

// ������ ������� ����������������� ���� � ������������� ����������
class A {
    int m_a;
public:
    A(int a) : m_a(a) {}

    friend std::ostream& operator<<(std::ostream& os, const A& a) {
        return os << "A(" << a.m_a << ")";
    }
};