#include "Calculator.h"

// Определение глобального объекта для вычитания
std::minus<double> substract;

std::function<double(double, double)>  division = [](const auto& a, const auto& b) {
	if (b==0)
	{
		throw std::invalid_argument("Division by zero");
	}
	return a / b; 
	};

void Calc() {
	double a, b;
	char c;
	//MaxFinder maxfinder;
// Создаем карту операций
	std::map<char, std::function<double(double, double)>> operations;

	operations['+'] = sum<double>;												//инициализация посредством глобальной функции
	operations['-'] = substract;												//инициализация посредством функции стандартной библиотеки std::minus
	operations['*'] = Multiplication();											//инициализация посредством функционального объекта
	operations['/'] = division;													//инициализация посредством лямбды
	operations['^'] = [](double base, double exp) {return std::pow(base, exp); }; //инициализация посредством функции стандартной библиотеки std::pow
	operations['%'] = std::bind(fractional_part, std::bind(std::divides<double>(), std::placeholders::_1, std::placeholders::_2));		//инициализация посредством функции стандартной библиотеки std::bind
	operations['?'] = std::bind(&MaxFinder::maximum, MaxFinder(), std::placeholders::_1, std::placeholders::_2); //инициализация посредством std::bind и метода класса

	// Ввод операндов
	std::cout << "Insert first operand: ";
	std::cin >> a;
	
	// Ввод операции с проверкой
	bool isValid = false;
	do
	{
		std::cout << "Insert operations(+, -, *, /, ^, %, ?): " << std::endl;
		std::cin >> c;
		// Проверяем, является ли введённая операция корректной
		if (operations.find(c) != operations.end())
		{
			isValid = true;
		}
		else
		{
			std::cerr<<"Error: Invalid operation '" << c << "'. Please try again." << std::endl;
		}
	} while (!isValid);// Повторяем цикл, пока не будет введена корректная операция

    // Ввод второго операнда
	
	// Ввод второго операнда
	std::cout << "Insert second operand: ";
	std::cin >> b;
	
	// Выполняем операцию
	try {
		double result = operations[c](a, b);  // Вызываем операцию
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}