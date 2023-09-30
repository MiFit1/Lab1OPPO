#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Income.h"
using namespace std;

void PrintDatabase(std::vector<Income>& dataBase) {
	vector<Income>::iterator it;
	for (it = dataBase.begin(); it != dataBase.end(); it++) {
		Income inc = *it;
		inc.PrintIncome(cout);
	}
}

bool ReadDatabase(std::vector<Income>& dataBase, istream& in){
	while (!in.eof()){
		Income inc;
		inc.ReadIncome(in);
		dataBase.push_back(inc);
	}
	return true;
}

int main(){
	ifstream in("in.txt");
	if (!in.is_open()) {
		return false;
	}
	vector<Income> dataBase;
	ReadDatabase(dataBase, in);
	PrintDatabase(dataBase);
	return 0;
}