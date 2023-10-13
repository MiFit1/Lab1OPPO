#pragma once
#include <fstream>
#include <string>

class Date {
public:
	Date() : Date(0,0,0) {}
    Date(int year, int month, int day) { year_ = year; month_ = month; day_ = day; }
	~Date() {};
	void ReadDate(std::istream& ist);
	void PrintDate(std::ostream& ost);

private:
	int year_;
	int month_;
	int day_;	
	bool CheckDateCorrect();
	bool CheckLeapYear(int year);
    void SetDate(int year, int month, int day) 
    { year_ = year; month_ = month; day_ = day; }
	friend class Test;
};