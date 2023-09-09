#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct date
{
	int year;
	int month;
	int day;
};
struct income
{
	date date;
	string source;
	int sum;
};
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
		string buff;
		in >> buff;
		date date;
		date.year = stoi(buff.substr(0, 4));
		date.month = stoi(buff.substr(5, 7));
		date.day = stoi(buff.substr(8, 9));
		inc.date = date;
		while (true)
		{
			in >> buff;
			inc.source.append(buff + " ");
			if (buff.back() == '"')
			{
				break;
			}
		}
		inc.source.erase(inc.source.end()-2, inc.source.end()--);
		inc.source.erase(inc.source.begin());
		in >> buff;
		inc.sum = stoi(buff);
		dataBase.push_back(inc);
	}
	vector<income>::iterator it;
	for (it = dataBase.begin(); it != dataBase.end(); it++)
	{
		income inc = *it;
		cout << inc.date.year << ".";
		cout << inc.date.month << ".";
		cout << inc.date.day << " ";
		cout << inc.source << " ";
		cout << inc.sum << endl;
	}
	return 0;
}