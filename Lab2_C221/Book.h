#pragma once
#include <iostream>
#include <tuple>
#include <string>



class book {
	std::tuple<std::string, std::string, int> data;
	
public:
	// Конструктор с инициализацией кортежа
	book(const std::string& author, const std::string& title, int year);

	// Методы для получения отдельных компонентов книги
	
	const std::string& get_author()const;		//Получаем автора
	
	const std::string& get_title()const; 		//Получаем заглавие
	
	const int& get_year()const;						//Полчаем год издания
	
	//Оператор сравнения книг

	bool operator<(const book& other) const;	//Лексикографическое сравнение кортежей
	
	bool operator==(const book& other) const;	// Проверка на равенство кортежей

	// Оператор вывода для книги
	friend std::ostream& operator<<(std::ostream& os, const book& other);
	
};
