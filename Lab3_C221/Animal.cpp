#include "Animal.h"

Cat::Cat(const std::string& name):m_name(name){}

void Cat::meow() const
{
	std::cout << "This is a cat: " << m_name << std::endl;
}



Dog::Dog(const std::string& name):m_name(name){}

void Dog::bark() const
{
	std::cout << "It's a dog: " << m_name << std::endl;
}

//void tell_about_animal(const Animal& animal, int& count_cat, int& count_dog) {
//    // ���������� std::visit ��� ������ ���������������� ������
//    std::visit([&count_cat,&count_dog](auto&& arg) {
//        // ���� �������� - �����, �������� meow, ���� ������ - bark
//        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Cat>) {
//            arg.meow();
//            count_cat++;
//        }
//        else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, Dog>) {
//            arg.bark();
//            count_dog++;
//        }
//        }, animal);
//}
void tell_about_animal(const Animal& animal, NoName& counter) {
	std::visit(counter, animal);
}