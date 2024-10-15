#pragma once

#include <string>
#include <optional>
#include <iostream>

class Person {
public:
	std::string m_name;
	unsigned int m_age;
	std::optional<std::string> m_nick; // std::optional для никнейма

	Person(const std::string& name, unsigned int age, std::optional<std::string> nick = std::nullopt);
	
	// Метод для отображения информации о человеке
	void print()const;


};
