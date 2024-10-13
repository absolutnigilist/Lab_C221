#include "Library.h"
#include <vector>
#include <algorithm>

library::library(std::initializer_list<book> initBooks) :books(initBooks) {}

void library::printBook(const std::vector<book>& booksToPrint)const {
	for (const auto& b : booksToPrint) {
		std::cout << b << std::endl;
	}
}
void library::printSorted(const std::function<bool(const book&, const book&)>& comp)const {
	std::vector<book> sortedBooks(books.begin(), books.end());//создаем вектор из мультисета
	std::sort(sortedBooks.begin(), sortedBooks.end(), comp);  //сортировка с заданным предикатом
	printBook(sortedBooks);
}
void library::ByAuthor()const {
	printSorted(comparators[0]);
}

void library::ByTitle() const
{
	printSorted(comparators[1]);
}
void library::ByYear()const {
	printSorted(comparators[2]);
}

bool library::remove(const book& b) {
	auto it = books.find(b);
	if (it!=books.end())
	{
		books.erase(it); 
		return true;
	}
	return false;
}
