#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
void Date::PrintDate(std::ostream& ost){
	ost << year_ << ".";
	ost << month_ << ".";
	ost << day_ << " ";
}

bool Date::ReadDate(std::istream& ist){
	string buffer;
	ist >> buffer;
	year_ = stoi(buffer.substr(0, 4));
	month_ = stoi(buffer.substr(5, 7));
	day_ = stoi(buffer.substr(8, 9));
	return true;
}

class Income
{
private:
	Date date_receip_;
	string source_;
	int sum_;
	
	bool ReadSource(std::istream& ist);
	bool ReadSum(std::istream& ist);
public:
	Income() {};
	~Income() {};
	bool ReadIncome(std::istream& ist);
	void PrintDate(std::ostream& ost);
};
void Income::PrintDate(std::ostream& ost){
	date_receip_.PrintDate(ost);
	ost << source_ << " ";
	ost << sum_ << endl;
}
bool Income::ReadSum(std::istream& ist){
	string buffer;
	ist >> buffer;
	sum_ = stoi(buffer);
	return true;
}

bool Income::ReadSource(std::istream& ist){
	string buffer;
	while (true)
	{
		ist >> buffer;
		source_.append(buffer + " ");
		if (buffer.back() == '"'){
			break;
		}
	}
	source_.erase(source_.end() - 2, source_.end()--);
	source_.erase(source_.begin());

	return true;
}
bool Income::ReadIncome(std::istream& ist){
	date_receip_.ReadDate(ist);
	ReadSource(ist);
	ReadSum(ist);

	return true;
}

void PrintDatabase(std::vector<Income>& dataBase)
{
	vector<Income>::iterator it;
	for (it = dataBase.begin(); it != dataBase.end(); it++){
		Income inc = *it;
		inc.PrintDate(cout);
	}
}
bool ReadDatabase(std::vector<Income>& dataBase)
{
	ifstream in("in.txt");
	if (!in.is_open()){
		return false;
	}
	while (!in.eof()){
		Income inc;
		inc.ReadIncome(in);
		dataBase.push_back(inc);
	}
	return true;
}
int main(){
	vector<Income> dataBase;
	ReadDatabase(dataBase);
	PrintDatabase(dataBase);
	return 0;
}