#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
#include <variant>

enum Color {BLUE,GREEN,RED};

class ColoredCircle {
	Color m_col;
	int m_x, m_y, m_r;
public:
    // ��������� �����������
    ColoredCircle() = default;

    // ����������� � �����������
    ColoredCircle(Color col, int x, int y, int r);

    // ���������� �����������
    ColoredCircle(const ColoredCircle& other) = default;

    // �������� ������������
    ColoredCircle& operator=(const ColoredCircle& other) = default;

    // ����������
    ~ColoredCircle() = default;

    void print() const;

    //��������� ������� �����
    double area()const;

    //���������� �� ������ ���������
    double distanceFromOrigin()const;

    //�������
    Color getColor()const;

    int getX()const;

    int getY()const;

    int getRadius()const;

    //C������

    void setRadius(int new_radius);

    void move(int dx, int dy);


};

class ColoredRect {
    Color m_col;
    int m_x, m_y, m_width, m_height;
public:
    // ��������� �����������
    ColoredRect() = default;

    // ����������� � �����������
    ColoredRect(Color col, int x, int y, int width, int height);

    // ���������� �����������
    ColoredRect(const ColoredRect& other) = default;

    // �������� ������������
    ColoredRect& operator=(const ColoredRect& other) = default;

    // ����������
    ~ColoredRect() = default;

    //��������� ������� ��������
    double area() const;

    //��������� �����
    Color getColor()const;

    //������ ���������
    void print()const;

};