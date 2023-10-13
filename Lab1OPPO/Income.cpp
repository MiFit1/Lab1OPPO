#include "Income.h"
void Income::PrintIncome(std::ostream& ost) {
	date_receip_.PrintDate(ost);
	ost << source_ << " ";
	ost << sum_ << std::endl;
}
void Income::ReadSum(std::istream& ist) {
	std::string buffer;
	ist >> buffer;
	if (buffer.empty()){
		throw std::runtime_error("������ ��� ������ �����, ��� ��� ���� �����");
	}
	try {
		sum_ = stoi(buffer);
	}
	catch (const std::invalid_argument)
	{
		throw std::runtime_error("�� ������� ������������� ����� � �����");
	}
	catch (const std::out_of_range)
	{
		throw std::runtime_error("���� ����� ������� ������");
	}
}

void Income::ReadSource(std::istream& ist) {
	std::string buffer;
	while (ist >> buffer) {
		source_.append(buffer);
		if (buffer.back() == '"') {
			break;
		}
		source_.append(" ");
	}
	if (buffer.empty()) {
		throw std::runtime_error("������ ��� ������ �����������, ��� ��� ��� ���� ����������");
		return;
	}

	if ((source_.at(0) != '"')||(source_).back() != '"') {
		throw std::runtime_error("������ ��� ������ �����������, �������� ������ ������");
		return;
	}
	source_.erase(--source_.end());
	source_.erase(source_.begin());

}
void Income::ReadIncome(std::istream& ist) {

	std::string buffer;
	std::getline(ist, buffer);
	std::istringstream istStr(buffer);

	date_receip_.ReadDate(istStr);
	ReadSource(istStr);
	ReadSum(istStr);

}
