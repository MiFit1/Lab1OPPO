#include "Income.h"
void Income::PrintIncome(std::ostream& ost) {
	date_receip_.PrintDate(ost);
	ost << source_ << " ";
	ost << sum_ << std::endl;
}
bool Income::ReadSum(std::istream& ist) {
	std::string buffer;
	ist >> buffer;
	sum_ = stoi(buffer);
	return true;
}

bool Income::ReadSource(std::istream& ist) {
	std::string buffer;
	while (true) {
		ist >> buffer;
		source_.append(buffer + " ");
		if (buffer.back() == '"') {
			break;
		}
	}
	source_.erase(source_.end() - 2, source_.end()--);
	source_.erase(source_.begin());

	return true;
}
bool Income::ReadIncome(std::istream& ist) {
	date_receip_.ReadDate(ist);
	ReadSource(ist);
	ReadSum(ist);

	return true;
}
