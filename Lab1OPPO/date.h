#pragma once
#include <fstream>
#include <string>
class Date {
public:
	Date() : year_(0), month_(0), day_(0) {}
	~Date() {};
	bool ReadDate(std::istream& ist);
	void PrintDate(std::ostream& ost);
private:
	int year_;
	int month_;
	int day_;

	bool SetDate(int year_, int month_, int day_);
};