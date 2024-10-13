#include"Book.h"

book::book(const std::string& author, const std::string& title, int year) :data(author, title, year) {}

// Методы для получения отдельных компонентов книги

const std::string& book::get_author()const {
	return std::get<0>(data);			//Получаем автора
}
const std::string& book::get_title()const {
	return std::get<1>(data);			//Получаем заглавие
}
const int& book::get_year()const {
	return std::get<2>(data);			//Полчаем год издания
}

//Оператор сравнения книг

bool book::operator<(const book& other) const {
	return data < other.data;			//Лексикографическое сравнение кортежей
}
bool book::operator==(const book& other)const {
	return data == other.data;
}

std::ostream& operator<<(std::ostream& os, const book& other) {
	os << "Author: " << other.get_author() << ", Title: " << other.get_title() << ", Year: " << other.get_year()<<std::endl;
	return os;
}