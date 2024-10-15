#pragma once

#include <type_traits>
#include <iostream>

// ������������ ������
enum Color{Red,Green,Blue};

// ������� ����� Shape
class Shape {
	Color m_c;
public:
	Shape(Color c);
	virtual~Shape() = default;
};

// ����� Rect, ����������� �� Shape
class Rect :public Shape {
	int m_l, m_r, m_t, m_b;  // �����, ������, ������� � ������ ����
public:
	// �����������
	Rect(int l, int r, int t, int b, Color c);

	//����� ��� ���������� �������
	int area() const;

	// �������� ��������� <=> ��� ���������� �� �������
	auto operator<=>(const Rect& other) const = default;

	//������� ������ ��������������
	void print()const;
};