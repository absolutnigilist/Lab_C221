#include "Person.h"

Person::Person(const std::string& name, unsigned int age, std::optional<std::string> nick) :
	m_name(name), m_age(age), m_nick(nick) {}

void Person::print() const 
{
	std::cout << "Name: " << m_name << ", Age: " << m_age;
	if (m_nick)
	{
		std::cout << ", Nickname: " << *m_nick;
	}
	else
	{
		std::cout << ", Nicname: (none)";
	}
	std::cout << std::endl;
}
