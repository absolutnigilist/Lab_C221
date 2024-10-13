#pragma once

#include "Book.h"
#include "Sort.h"`1	
#include <set>
#include <vector>
#include <functional>

extern std::vector<std::function<bool(const book&, const book&)>>comparators;

class library {
	std::multiset<book> books;
public:
	// Конструктор по умолчанию (пустая библиотека)
	library() = default;
	
	// Конструктор с инициализацией книг
	library(std::initializer_list<book> initBooks);

	// Запрещаем копирование и присваивание
	library(const library&) = delete;
	library& operator=(const library&) = delete;

	// Запрещаем перемещение
	library(library&&) = delete;
	library& operator=(library&&) = delete;

	// Добавление книг в библиотеку
	void add(std::initializer_list<book>newBooks) {
		books.insert(newBooks.begin(), newBooks.end());
	}
	// Вспомогательная функция для вывода отсортированной библиотеки
	void printSorted(const std::function<bool(const book&, const book&)>& comp)const;
	
	// Функция для вывода книг 
	void printBook(const std::vector<book>& booksToPrint)const;
	
	// Вывод библиотеки, отсортированной по автору
	void ByAuthor()const;

	// Вывод библиотеки, отсортированной по заглавию
	void ByTitle()const;

	//Вывод библиотеки, отсортированной по году
	void ByYear()const;
	
	// Удаление книги (поиск книги по всем параметрам)
	bool remove(const book& b);
};


