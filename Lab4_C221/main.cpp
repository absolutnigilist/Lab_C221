#include "Shape.h"
#include "Header.h"



int main() {
	
	//1. Std::span

	//Реализуйте функцию, которая суммирует только элементы, удовлетворяющие условию.
	//Функция должна принимать в качестве параметров : std::span и условие.
	//Следует учесть :
	//•а может быть ни один элемент не удовлетворяет условию ?
	//• default конструктор deleted ?

	int ar[]{ 5, -3, 0, 8 };
	auto r1 = sum(ar, [](int n) { return n > 0; }); // Суммируем только положительные

	int* p = new int[4] {6, -1, -5, 2};
	auto r2 = sum(std::span(p, 4), [](int n) { return n < 0; }); // Суммируем только отрицательные

	std::array<int, 5> stdAr = { 1, 2, 3, 4, 5 };
	auto r3 = sum(stdAr, [](int n) { return n >= 0 && n <= 3; }); // Суммируем только те, которые принадлежат диапазону [0,3]

	//2. ranges::алгоритмы
	//	1.a  Реализуйте класс
	//	class ColoredCircle {
	//	Color m_col;
	//	int m_x, m_y, m_r;
	//	public:
	//		…
	//};
	//Создайте std::vector< ColoredCircle >.
	//	• с помощью std::ranges::sort() отсортируйте кружки
	//	◦ по площади,
	//	◦ по цвету,
	//	◦ по удалению от начала координат
	//	• с помощью std::ranges::transform()
	//	◦ увеличьте радиус на заданную дельту
	//	◦ модифицируйте координаты центра на заданные значения
	//	• с помощью std::ranges::copy_if()
	//	◦ перепишите в другой контейнер только те кружки, которые лежат в окружности с заданным адресом
	//	◦ только с заданным цветом

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
	
	//1.б Реализуйте класс ColoredRect по аналогии с ColoredCircle
	//Создайте std::vector, который может хранить как кружки, так и прямоугольники.
	//Посредством std::ranges::sort() отсортируйте вектор :
	//◦ по площади,
	//◦ по цвету

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
	//3. ranges::views
	//	3.а Создайте std::vector< ColoredCircle >.
	//	С помощью представлений сформируйте в другом контейнере кружки :
	//  • красные
	//	• находящиеся в окружности с заданным радиусом
	//	• упорядоченные по площади
	//	3.б Создайте std::vector, который может содержать и кружки, и прямоугольники.
	//	С помощью представлений сформируйте в другом контейнере фигуры :
	//• красные
	//	• площадь которых меньше заданной
	//	• упорядоченные по площади

	// 3. Создаем std::vector<ColoredCircle>
	std::vector<ColoredCircle> circles_vv = {
		{RED, 0, 0, 5},
		{BLUE, 1, 1, 3},
		{RED, 2, 2, 4},
		{GREEN, 3, 3, 1},
		{RED, 1, 1, 2}
	};
	
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
		std::vector<Shape> shapes_vv = {
			ColoredCircle{RED, 0, 0, 5},
			ColoredRect{BLUE, 1, 1, 3, 4},
			ColoredCircle{GREEN, 2, 2, 4},
			ColoredRect{RED, 3, 3, 2, 3},
			ColoredCircle{RED, 1, 1, 2}
		};

		double max_area = 20.0;

		// Формируем новый вектор с фигурами, которые красные и имеют площадь меньше заданной
		auto filtered_shapes = shapes_vv
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

		
	//4. If constexpr и requires.
	//	Функция может принимать любой контейнер, для которого реализован метод insert() и 
	// любое количество объектов для вставки.При этом, eсли для этого контейнера реализован метод reserve(), 
	// то прежде, чем вставлять, эффективнее зарезервировать нужный объем памяти
		std::vector<int> v;
		insertElements(v, 1, 3, 4, 0, 3);
		
	//5.Concepts
	//Концепты – реализовать функцию, которая должна печатать значение любого типа, но только если для этого есть хоть какая - то возможность!
	//Возможность можно обеспечить разными способами :
	//1. функцией стандартной библиотеки std::to_string()
	//2. методом имя_пользовательского_типа::to_string()
	//3. перегруженным для данного типа оператором operator<<(std::ostream&, const пользовательский типа&)
	//Например :
	//	class Point {
	//	int m_x, m_y;
	//	public:
	//		…
	//	std::string to_string()const;
	//		…
	//};
	//	class A {
	//	int m_a;
	//public:
	//	A(int a) :m_a(a) {}
	//	friend std::ostream& operator<<(std::ostream&, const A&);
	//	};

		print_any_how(A(1));         // Ожидается вывод: A(1)
		std::cout << std::endl;

		print_any_how(2.2);          // Ожидается вывод: 2.2
		std::cout << std::endl;

		print_any_how(Point(1, 2));  // Ожидается вывод: Point(1, 2)
		std::cout << std::endl;
		return 0;

}