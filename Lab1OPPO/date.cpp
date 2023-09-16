//#include <string>
#include "date.h"

void Date::PrintDate(std::ostream& ost) {
	ost << year_ << ".";
	ost << month_ << ".";
	ost << day_ << " ";
}

bool Date::ReadDate(std::istream& ist) {
	std::string buffer;
	ist >> buffer;
	year_ = stoi(buffer.substr(0, 4));
	month_ = stoi(buffer.substr(5, 7));
	day_ = stoi(buffer.substr(8, 9));
	return true;
}