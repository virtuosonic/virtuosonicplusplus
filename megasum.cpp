/****************************
Autor:	Gabriel Espinoza <virtuosonic@users.sf.net>
Fecha:	21-Feb-2017
****************************/
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	auto start = chrono::steady_clock::now();
	double res;

	start = chrono::steady_clock::now();
	for(unsigned long i = 0; i < 1e9; i++)
		res = 3.14+3.14;
	cout << chrono::duration<double>(
		chrono::steady_clock::now() - start).count()
		<< " s" << endl;
	return 0;
}
