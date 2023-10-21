#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Income.h"
using namespace std;

void PrintDatabase(std::vector<Income>& dataBase) {
	vector<Income>::iterator it;
	cout << endl;
	for (it = dataBase.begin(); it != dataBase.end(); it++) {
		Income inc = *it;
		inc.PrintIncome(cout);
	}
}
void PrinError(string str, ostream& out){
	out << "Ошибка в строке " << str << endl;
}

bool ReadDatabase(std::vector<Income>& dataBase, istream& in){
	int cnt = 0;
	while (!in.eof()){
		cnt++;
		Income inc;

		try {
			inc.ReadIncome(in);
		}
		catch(const std::runtime_error& e) {
			PrinError(std::to_string(cnt) + ": " + e.what(), cout);
			continue;
		}

		dataBase.push_back(inc);
	}
	return true;
}

int main(){
	setlocale(LC_ALL, "Rus");
	ifstream in("in.txt");

	if (!in.is_open()) {
		return 1;
	}
	vector<Income> dataBase;

	ReadDatabase(dataBase, in);
	PrintDatabase(dataBase);

	return 0;
}