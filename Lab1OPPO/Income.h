#pragma once
#include "date.h"
#include <string>
#include <iostream>
class Income
{
private:
	Date date_receip_;
	std::string source_;
	int sum_;

	bool ReadSource(std::istream& ist);
	bool ReadSum(std::istream& ist);
public:
	Income() {};
	~Income() {};
	bool ReadIncome(std::istream& ist);
	void PrintIncome(std::ostream& ost);
};
