#pragma once

#include <variant>

#include <string>
#include <iostream>

class Cat {
	std::string m_name;
public:
	Cat(const std::string& name);
	void meow()const;
	
	
};

class Dog {
	std::string m_name;
public:
	Dog(const std::string& name);
	void bark()const;

};

// »спользуем std::variant дл€ хранени€ разных типов животных
using Animal = std::variant<Cat, Dog>;

void tell_about_animal(const Animal& animal, int& count_cat, int& count_dog);