#pragma once
#include "date.h"
#include <string>
#include <iostream>
#include <sstream>
class Income
{
private:
	Date date_receip_;
	std::string source_;
	int sum_ = 0;

	void ReadSource(std::istream& ist);
	void ReadSum(std::istream& ist);
    friend class Test;
public:
	Income(){};
	~Income() {};
	void ReadIncome(std::istream& ist);
	void PrintIncome(std::ostream& ost);
};
