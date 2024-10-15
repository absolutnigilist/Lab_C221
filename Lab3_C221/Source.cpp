#include "Header.h"


std::string colorToString(Color c) {

	switch (c)
	{
	case Red:return "Red";
		break;
	case Green: return "Green";
		break;
	case Blue: return "Blue";
		break;
	default:
		break;
	}
}

void printVariants(const std::vector<std::variant<int, double, Color>>& values) {
	for (const auto& value : values) {
		std::visit(overload{
			[](int val) { std::cout << "int: " << val << " "; },
			[](double val) { std::cout << "double: " << val << " "; },
			[](Color val) { std::cout << "Color: " << colorToString(val) << " "; }
			}, value);
	}
}