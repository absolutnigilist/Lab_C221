#include "Time.h"

std::string get_weekday(int wday) {
	static const std::map<int, std::string>weekdays = {
		{0,"Sunday"},{1,"Monday"},{2,"Tuesday"},{3,"Wednesday"},{4,"Thursday"},{5,"Friday"},{6,"Saturday"}
	};
	return weekdays.at(wday);
}

std::string get_date_part(const std::variant<What>& what)
{
	// Получаем текущее время
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

    // Используем std::visit для обработки запроса пользователя
    return std::visit([now](auto&& arg) -> std::string {
        if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, What>) {
            switch (arg) {
            case What::Year:
                return std::to_string(now->tm_year + 1900);  // Год
            case What::Month:
                return std::to_string(now->tm_mon + 1);      // Месяц (от 0 до 11, поэтому прибавляем 1)
            case What::Day:
                return std::to_string(now->tm_mday);         // День месяца
            case What::WeekDay:
                return get_weekday(now->tm_wday);            // День недели
            }
        }
        return "";
        }, what);
}
