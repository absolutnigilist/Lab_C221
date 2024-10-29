#include "Shape.h"



int main() {
	
	std::vector<ColoredCircle> circles = {
		{Color::BLUE, 1, 2, 5},
		{Color::RED, 3, 4, 10},
		{Color::GREEN, 0, 0, 7}
	};

	//Сортировка по площади
	std::ranges::sort(circles, {}, &ColoredCircle::area);

	//Сортировка по цвету
	std::ranges::sort(circles, {}, &ColoredCircle::getColor);

	//Сортировка по расстоянию от начала координат
	std::ranges::sort(circles, {}, &ColoredCircle::distanceFromOrigin);

	//Увеличиваем радиус на заданную дельту
	int delta_radius = 2;
	auto circleView = circles | std::ranges::views::all;

	std::ranges::transform(circleView, circles.begin(), [delta_radius](ColoredCircle& circle) {
		circle.setRadius(circle.getRadius() + delta_radius);
		return circle; 
		});
	
	//Меняем координаты
	int dx = 1, dy = -1;
	std::ranges::transform(circleView, circles.begin(), [dx, dy](ColoredCircle& circle) {circle.move(dx, dy);
	return circle;
		});

	// Вывод для проверки
	for (const auto& circle : circles) {
		circle.print();
	}
	
	//Создаем вектор для фильтрованных значений
	std::vector<ColoredCircle>filtredCircles;
	filtredCircles.reserve(circles.size());

	//Копирование кругов внутри окружности с цетром (0,0) и радиусом 10
	std::ranges::copy_if(circles, std::back_inserter(filtredCircles), [](const ColoredCircle& circle) {
		return circle.distanceFromOrigin() <= 10; });

	//Копирование кругов с заданным цветом
	Color targetColor = Color::RED;
	std::ranges::copy_if(circles, std::back_inserter(filtredCircles), [targetColor](const ColoredCircle& circle) {
		return circle.getColor() == targetColor; });
	
	
	std::vector<std::variant<ColoredCircle, ColoredRect>> shapes = {
	ColoredCircle(Color::RED, 1, 1, 5),
	ColoredRect(Color::GREEN, 0, 0, 3, 4),
	ColoredCircle(Color::BLUE, 3, 3, 2),
	ColoredRect(Color::RED, 2, 2, 6, 7)
	};

	//Сортировка по площади
	std::ranges::sort(shapes, [](const auto& a, const auto& b) {
		return std::visit([](const auto& shape) {return shape.area(); }, a) <
			   std::visit([](const auto& shape) {return shape.area(); }, b); 
		});

	//Сортировка по цвету
	std::ranges::sort(shapes, [](const auto& a, const auto& b) {
		return std::visit([](const auto& shape) {return shape.getColor(); }, a) <
			   std::visit([](const auto& shape) {return shape.getColor(); },b);
		
		});


	// 2.a Создаем std::vector<ColoredCircle>
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
	
	// Сформируем новый контейнер с красными кружками в окружности с заданным радиусом и упорядоченные по площади
	auto red_circles = circles_vv
		| std::views::filter([target_radius](const ColoredCircle& circle) {
		return circle.getColor() == RED && circle.getRadius() <= target_radius;
			});

	// Копируем отфильтрованные кружки в вектор
	std::vector<ColoredCircle> circles_vv_res(red_circles.begin(), red_circles.end());

	// Сортируем отфильтрованные кружки по площади
	std::ranges::sort(circles_vv_res, [](const ColoredCircle& a, const ColoredCircle& b) {
		return a.area() < b.area();
		});

	// Определяем тип Shape как std::variant
	using Shape = std::variant<ColoredCircle, ColoredRect>;

		// Создаем std::vector, который может содержать и кружки, и прямоугольники
		std::vector<Shape> shapes = {
			ColoredCircle{RED, 0, 0, 5},
			ColoredRect{BLUE, 1, 1, 3, 4},
			ColoredCircle{GREEN, 2, 2, 4},
			ColoredRect{RED, 3, 3, 2, 3},
			ColoredCircle{RED, 1, 1, 2}
		};

		double max_area = 20.0;

		// Формируем новый вектор с фигурами, которые красные и имеют площадь меньше заданной
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

				// Копируем результат в новый вектор
				std::vector<Shape> result_shapes(filtered_shapes.begin(), filtered_shapes.end());

				// Сортируем результат по площади
				std::ranges::sort(result_shapes, [](const Shape& a, const Shape& b) {
					return std::visit([](const auto& shape) { return shape.area(); }, a) <
						std::visit([](const auto& shape) { return shape.area(); }, b);
					});

	
	
	return 0;

}