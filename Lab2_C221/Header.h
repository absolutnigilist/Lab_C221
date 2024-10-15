#pragma once
#include <iostream>
#include <tuple>
#include <string>

//#define VAR1
//#define VAR2
#define VAR4


#ifdef VAR1

// Шаблонная функция для печати кортежа с использованием лямбды и std::apply

template<typename...Types>
void printTuple(const std::tuple<Types...>& t) {
	auto lamda = [](const auto&...args) {
		((std::cout << args << (sizeof...(args)>1 ? ", " : "")), ...); 
		};
	std::apply(lamda, t);
	std::cout << std::endl;
}
#endif VAR1


//Вспомогательная функция для перегрузки оператора<<

template<typename Tuple, std::size_t...Indices>
void printTupleIndeces(std::ostream& os, const Tuple& t, std::index_sequence<Indices...>) {
	((os<<(Indices==0 ? "" : ", ") <<std::get<Indices>(t)), ...);
	std::cout << std::endl;
}
// Перегрузка оператора <<
template<typename...Types>
std::ostream& operator<<(std::ostream& os, const std::tuple<Types...>& t) {
	printTupleIndeces(os, t, std::make_index_sequence<sizeof...(Types)>{});
	return os;
}


#ifdef VAR2

//Использование std::tuple_size и рекурсии

template<std::size_t Index=0,typename...Args>
void printTuple(const std::tuple<Args...>& t) {
	if constexpr (Index < sizeof...(Args)) {
		std::cout << std::get<Index>(t);
		if constexpr (Index < sizeof...(Args) - 1) {

			std::cout << ", "; //разделитель
		}
		printTuple<Index + 1>(t);//Рекурсивный вызов для следующего элемента
	}
	else
	{
		std::cout << std::endl;//Переход на новую строку после после последнего элемента
	}
	
}
#endif VAR2

#ifdef VAR4

template<typename T, size_t t = std::tuple_size_v<T> -1>
void printTuple(const T& tpl) {
	if constexpr (t == 0)
	{
		//Базовый метод
		std::cout << std::get<0>(tpl) << '\n';
	}
	else
	{
		// Рекурсивный случай: выводим элемент t и продолжаем рекурсию
		printTuple<T, t - 1>(tpl);
		std::cout << std::get<t>(tpl) << '\n';
	}
}
#endif // VAR4

template<typename T>
bool InRange(const T& minVal, const T& maxVal, const T& value) {
	return value >= minVal && value <= maxVal;
}
template<typename T, typename...Args>
bool InRange(const T& minVal, const T& maxVal, const T& firstVal, const Args&...restVal) {
	return InRange(minVal, maxVal, firstVal) && InRange(minVal, maxVal, restVal...);
}