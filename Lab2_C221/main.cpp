#include "Header.h"
#include "Point.h"
#include "Book.h"
#include "Library.h"
#include "Calculator.h"

#include <tuple>
#include <string_view>


int main() {
	//1. std::tuple<>, std::tuple_size<>::value,
	//	Реализуйте функцию печати любого tuple, например:
	std::tuple t1{ 1, 2.2, "abc"};
	std::cout << t1;
	printTuple(t1);

	std::tuple t2{ std::string("abc"), 1, 2.2, Point(1,2) };
	printTuple(t2);

	book b1("A","B",123);
	std::cout << b1;

    // Создание библиотеки с книгами
    book my_favorite_book{ "Willims", "Parallel C++", 2014 };
    library l = { {"Straustrup", "C++", 2000}, my_favorite_book };

    // Добавление книг
    l.add({ {"Straustrup", "C++", 2000}, {"Straustrup", "C++", 2010}, {"Golovic", "Advanced", 2008} });

    // Вывод книг по автору
    std::cout << "Books by author:" << std::endl;
    l.ByAuthor();

    // Вывод книг по названию
    std::cout << "Books by title:" << std::endl;
    l.ByTitle();

    // Вывод книг по году
    std::cout << "Books by year:" << std::endl;
    l.ByYear();

    // Удаление книги
    l.remove({ "Straustrup", "C++", 2000 });

    //Call to calculator
    Calc();

    // Используем std::function для хранения лямбда-функции
    std::function<int(int)> sum_natural;

    // Определяем рекурсивную лямбда-функцию для вычисления суммы натурального ряда
    sum_natural = [&sum_natural](int x) {
        if (x<=1)
        {
            return x;// Базовый случай: если x <= 1, возвращаем x
        }
        return x + sum_natural(x - 1); // Рекурсивный случай
        };
    // Пример: вычисляем сумму ряда для числа 5
    int n = 5;
    std::cout << "Sum of natural numbers up to " << n << " is: " << sum_natural(n) << std::endl;


    bool res1=InRange(10, 20, 1, 15, 30);             // --> false 
    bool res2=InRange(10, 20, 11, 12, 13);            // --> true
    bool res3=InRange(5.0, 5.5, 5.1, 5.2, 5.3);       // --> true

	return 0;
}