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

//void tell_about_animal(const Animal& animal, int& count_cat, int& count_dog);
struct NoName {
	int count_cat = 0;
	int count_dog = 0;
	void operator()(const Dog& dog) { dog.bark(); ++count_dog; };
	void operator()(const Cat& cat) { cat.meow(); ++count_cat; };
};

void tell_about_animal(const Animal& animal, NoName& counter);

