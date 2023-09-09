#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class date {
private:
	int year;
	int month;
	int day;

	bool setDate(int year, int month, int day);
public:
	date() : year(0), month(0), day(0) {}
	bool read(std::istream& ist);
	void print(std::ostream& ost);
};
void date::print(std::ostream& ost)
{
	ost << year << ".";
	ost << month << ".";
	ost << day << " ";
}

bool date::read(std::istream& ist)
{
	string buff;
	ist >> buff;
	year = stoi(buff.substr(0, 4));
	month = stoi(buff.substr(5, 7));
	day = stoi(buff.substr(8, 9));
	return true;
}

class income
{
private:
	date dateReceip;
	string source;
	int sum;
	
	bool readSource(std::istream& ist);
	bool readSum(std::istream& ist);
public:
	bool read(std::istream& ist);
	void print(std::ostream& ost);
};
void income::print(std::ostream& ost)
{
	dateReceip.print(ost);
	ost << source << " ";
	ost << sum << endl;
}
bool income::readSum(std::istream& ist)
{
	string buff;
	ist >> buff;
	sum = stoi(buff);
	return true;
}

bool income::readSource(std::istream& ist)
{
	string buff;
	while (true)
	{
		ist >> buff;
		source.append(buff + " ");
		if (buff.back() == '"')
		{
			break;
		}
	}
	source.erase(source.end() - 2, source.end()--);
	source.erase(source.begin());

	return true;
}
bool income::read(std::istream& ist)
{
	dateReceip.read(ist);
	readSource(ist);
	readSum(ist);

	return true;
}

void printDatabase(std::vector<income>& dataBase)
{
	vector<income>::iterator it;
	for (it = dataBase.begin(); it != dataBase.end(); it++)
	{
		income inc = *it;
		inc.print(cout);
	}
}
int main()
{
	vector<income> dataBase;
	ifstream in("in.txt");
	if (!in.is_open())
	{
		return 1;
	}
	while (!in.eof())
	{
		income inc;
		inc.read(in);
		dataBase.push_back(inc);
	}

	printDatabase(dataBase);
	return 0;
}