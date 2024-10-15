#include "Split.h"

std::vector<std::string_view>split_string(const char* s) {

	std::string_view sv(s); //Оборачиваем строку в string_view
	std::vector<std::string_view> result;

	while (!sv.empty())
	{
		size_t space_pos = sv.find(' ');
		//Если пробел не найден, добавляем остаток строки
		if (space_pos == std::string_view::npos) {
			result.push_back(sv);
			break;
		}
		// Добавляем слово перед пробелом
		if (space_pos>0)
		{
			result.push_back(sv.substr(0, space_pos));
		}
		// Удаляем обработанную часть строки
		sv.remove_prefix(space_pos + 1);
	}
	return result;
}
	