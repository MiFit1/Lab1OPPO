// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Income.h"
#include <memory>
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
	while (!in.eof() && in.good()){
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

void CheckMemoryLeaks() {
//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
//_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
//_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
}

int main(){
    atexit(CheckMemoryLeaks);
	setlocale(LC_ALL, "Rus");
	ifstream in("in.txt");

	if (!in.is_open()) {
		return 1;
	}
	vector<Income> dataBase;

	ReadDatabase(dataBase, in);
	PrintDatabase(dataBase);
    in.close();
    dataBase.clear();
    return 0;
}