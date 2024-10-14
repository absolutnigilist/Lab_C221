#include "Shape.h"
#include <vector>
#include <algorithm>
#include <compare>


int main() {
    
    // Создаем массив прямоугольников
    std::vector<Rect> rectangles = {
        Rect(0, 10, 0, 5, Red),
        Rect(0, 3, 0, 3, Green),
        Rect(0, 8, 0, 4, Blue),
        Rect(0, 5, 0, 5, Red)
    };
    std::sort(rectangles.begin(), rectangles.end(), [](const Rect& a, const Rect& b) {return a.area() < b.area(); });
    
    // Выводим отсортированные прямоугольники
    std::cout << "Rectangles sorted by area:\n";
    for (const auto& a : rectangles) {
        a.print();
    }
	return 0;
}