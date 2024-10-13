#include "Header.h"
#include "Point.h"
#include "Book.h"
#include "Library.h"
#include <tuple>

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
	return 0;
}