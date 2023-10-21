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
		throw std::runtime_error("Ошибка при чтении суммы, так как поле пусто.");
	}
	try {
		sum_ = stoi(buffer);
	}
	catch (const std::invalid_argument)
	{
		throw std::runtime_error("Не удалось преобразовать сумму в число.");
        return;
	}
	catch (const std::out_of_range)
	{
		throw std::runtime_error("Поле суммы слишком велико.");
        return;
	}

    if (sum_ < 0)
    {
        throw std::runtime_error("Поле суммы не может быть отрицательным.");
        return;
    }
}

bool Income::FindAllowedSourceChar(char ch)
{
    int lenghAllowedCharacters = (sizeof(allowedCharacters) / sizeof(char)) - 1;
    for (int i = 0; i < lenghAllowedCharacters; i++)
    {
        if (allowedCharacters[i] == ch){
            return true;
        }
    }
    return false;
}

bool Income::CheckingValidName()
{
    for (int i = 0; i < source_.length(); i++)
    {
        if (!FindAllowedSourceChar(source_[i]))
        {
            return false;
        }
    }
    return true;
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
		throw std::runtime_error("Ошибка при чтении организации, так как это поле отсутсвует.");
		return;
	}

	if ((source_.at(0) != '"')||(source_).back() != '"') {
		throw std::runtime_error("Ошибка при чтении организации, неверный формат записи.");
		return;
	}
	source_.pop_back();
	source_.erase(source_.begin());

    if (!CheckingValidName())
    {
        throw std::runtime_error("Ошибка, в названии организации используются запрещённые символы");
        return;
    }

}
void Income::ReadIncome(std::istream& ist) {

	std::string buffer;
	std::getline(ist, buffer);
	std::istringstream istStr(buffer);

	date_receip_.ReadDate(istStr);
	ReadSource(istStr);
	ReadSum(istStr);

}
