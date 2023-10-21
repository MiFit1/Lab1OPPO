#pragma once
#include "date.h"
#include <string>
#include <iostream>
#include <sstream>

namespace TestCore
{
    class Test;
}

class Income
{
private:
	Date date_receip_;
	std::string source_;
	int sum_ = 0;

	void ReadSource(std::istream& ist);
	void ReadSum(std::istream& ist);
    bool FindAllowedSourceChar(char ch);
    bool CheckingValidName();
    static constexpr char allowedCharacters[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890 ";
    friend class TestCore::Test;
public:
	Income(){};
	~Income() {};
	void ReadIncome(std::istream& ist);
	void PrintIncome(std::ostream& ost);
};
