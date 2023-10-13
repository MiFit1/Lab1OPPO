//#include <string>
#include "date.h"
#include <exception>

void Date::PrintDate(std::ostream& ost) {
	ost << year_ << ".";
	ost << month_ << ".";
	ost << day_ << " ";
}

void Date::ReadDate(std::istream& ist) {
	std::string buffer;
	ist >> buffer;

	if (buffer.empty()){
		throw std::runtime_error("Не удалось считать дату, так как строка пустая.");
		return;
	}
	
	try {
		int dotPositionYear = buffer.find_first_of('.');
		int dotPositionMonth = buffer.find_first_of('.',dotPositionYear+1);

		year_ = stoi(buffer.substr(0, dotPositionYear));
		month_ = stoi(buffer.substr(dotPositionYear + 1, (dotPositionMonth - dotPositionYear - 1)));
		day_ = stoi(buffer.substr(dotPositionMonth+1));
	}
	catch (std::out_of_range) {
		throw std::runtime_error("Ошибка при чтении даты, неверный формат записи.");
		return;
	}
	catch (std::invalid_argument){
		throw std::runtime_error("Ошибка при чтении даты, не удалось преобразовать в число.");
		return;
	}

	if (!CheckDateCorrect()){
		throw (std::runtime_error("Неккоректная дата."));
		return;
	}
}
bool Date::CheckLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
		return true;
	}
	else {
		return false;
	}
}

bool Date::CheckDateCorrect()
{
	if ((year_ < 1)||((month_ < 1)||(month_ > 12))||((day_ < 1)||(day_ > 31))){
		return false;
	}

	if ((month_ == 1) || (month_ == 3) || (month_ == 5) || (month_ == 7) ||
		(month_ == 8) || (month_ == 10) || (month_ == 12)){
		if (day_ > 31) {
			return false;
		}
	}

	if ((month_ == 4) || (month_ == 6) || (month_ == 9) || (month_ == 11)) {
		if (day_ > 30){
			return false;
		}
	}

	if (month_ == 2) {
		if (CheckLeapYear(year_))
		{
			if (day_ > 29){
				return false;
			}
		}
		else {
			if (day_ > 28)
			{
				return false;
			}
		}
	}

	return true;
}