#include "Shape.h"



int main() {
	
	std::vector<ColoredCircle> circles = {
		{Color::BLUE, 1, 2, 5},
		{Color::RED, 3, 4, 10},
		{Color::GREEN, 0, 0, 7}
	};

	//���������� �� �������
	std::ranges::sort(circles, {}, &ColoredCircle::area);

	//���������� �� �����
	std::ranges::sort(circles, {}, &ColoredCircle::getColor);

	//���������� �� ���������� �� ������ ���������
	std::ranges::sort(circles, {}, &ColoredCircle::distanceFromOrigin);

	//����������� ������ �� �������� ������
	int delta_radius = 2;
	auto circleView = circles | std::ranges::views::all;

	std::ranges::transform(circleView, circles.begin(), [delta_radius](ColoredCircle& circle) {
		circle.setRadius(circle.getRadius() + delta_radius);
		return circle; 
		});
	
	//������ ����������
	int dx = 1, dy = -1;
	std::ranges::transform(circleView, circles.begin(), [dx, dy](ColoredCircle& circle) {circle.move(dx, dy);
	return circle;
		});

	// ����� ��� ��������
	for (const auto& circle : circles) {
		circle.print();
	}
	
	//������� ������ ��� ������������� ��������
	std::vector<ColoredCircle>filtredCircles;
	filtredCircles.reserve(circles.size());

	//����������� ������ ������ ���������� � ������ (0,0) � �������� 10
	std::ranges::copy_if(circles, std::back_inserter(filtredCircles), [](const ColoredCircle& circle) {
		return circle.distanceFromOrigin() <= 10; });

	//����������� ������ � �������� ������
	Color targetColor = Color::RED;
	std::ranges::copy_if(circles, std::back_inserter(filtredCircles), [targetColor](const ColoredCircle& circle) {
		return circle.getColor() == targetColor; });
	
	
	std::vector<std::variant<ColoredCircle, ColoredRect>> shapes = {
	ColoredCircle(Color::RED, 1, 1, 5),
	ColoredRect(Color::GREEN, 0, 0, 3, 4),
	ColoredCircle(Color::BLUE, 3, 3, 2),
	ColoredRect(Color::RED, 2, 2, 6, 7)
	};

	//���������� �� �������
	std::ranges::sort(shapes, [](const auto& a, const auto& b) {
		return std::visit([](const auto& shape) {return shape.area(); }, a) <
			   std::visit([](const auto& shape) {return shape.area(); }, b); 
		});

	//���������� �� �����
	std::ranges::sort(shapes, [](const auto& a, const auto& b) {
		return std::visit([](const auto& shape) {return shape.getColor(); }, a) <
			   std::visit([](const auto& shape) {return shape.getColor(); },b);
		
		});


	// 2.a ������� std::vector<ColoredCircle>
	std::vector<ColoredCircle> circles_vv = {
		{RED, 0, 0, 5},
		{BLUE, 1, 1, 3},
		{RED, 2, 2, 4},
		{GREEN, 3, 3, 1},
		{RED, 1, 1, 2}
	};
	std::vector<ColoredCircle> circles_vv_res;
	circles_vv_res.reserve(circles_vv.size());

	double target_radius = 4.0;
	
	// ���������� ����� ��������� � �������� �������� � ���������� � �������� �������� � ������������� �� �������
	auto red_circles = circles_vv
		| std::views::filter([target_radius](const ColoredCircle& circle) {
		return circle.getColor() == RED && circle.getRadius() <= target_radius;
			});

	// �������� ��������������� ������ � ������
	std::vector<ColoredCircle> circles_vv_res(red_circles.begin(), red_circles.end());

	// ��������� ��������������� ������ �� �������
	std::ranges::sort(circles_vv_res, [](const ColoredCircle& a, const ColoredCircle& b) {
		return a.area() < b.area();
		});

	// ���������� ��� Shape ��� std::variant
	using Shape = std::variant<ColoredCircle, ColoredRect>;

		// ������� std::vector, ������� ����� ��������� � ������, � ��������������
		std::vector<Shape> shapes = {
			ColoredCircle{RED, 0, 0, 5},
			ColoredRect{BLUE, 1, 1, 3, 4},
			ColoredCircle{GREEN, 2, 2, 4},
			ColoredRect{RED, 3, 3, 2, 3},
			ColoredCircle{RED, 1, 1, 2}
		};

		double max_area = 20.0;

		// ��������� ����� ������ � ��������, ������� ������� � ����� ������� ������ ��������
		auto filtered_shapes = shapes
			| std::views::filter([](const Shape& shape) {
			return std::visit([](const auto& s) {
				return (std::is_same_v<std::decay_t<decltype(s)>, ColoredCircle> && s.getColor() == RED);
				}, shape);
				})
			| std::views::filter([max_area](const Shape& shape) {
					return std::visit([max_area](const auto& s) {
						return s.area() < max_area;
						}, shape);
				});

				// �������� ��������� � ����� ������
				std::vector<Shape> result_shapes(filtered_shapes.begin(), filtered_shapes.end());

				// ��������� ��������� �� �������
				std::ranges::sort(result_shapes, [](const Shape& a, const Shape& b) {
					return std::visit([](const auto& shape) { return shape.area(); }, a) <
						std::visit([](const auto& shape) { return shape.area(); }, b);
					});

	
	
	return 0;

}