/*****************************************
Name:	cout_null.cpp
Autor:	Gabriel Espinoza
License:	MIT
Date:	28-Jun-2018
******************************************/
#include <iostream>
#include <sstream>
#include <cstddef>

using namespace std;

int main()
{
	const char* c1 = nullptr;
	ostringstream os;
	os << c1;
	cout << os.str() << endl;
	cout << "null\n";
	cout << "\0";
	cout << c1;
	cout << "exit\n";
	return 0;
}

