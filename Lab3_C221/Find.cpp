#include "Find.h"

std::optional<int> find_by_modulo(const std::vector<int>& vec, int value) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (std::abs(vec[i])==std::abs(value))
		{
			return i; // ¬озвращаем индекс, если нашли совпадение
		}
	}
	return {}; // ¬озвращаем nullopt, если ничего не найдено
}